#include "audio/SoundSource.hpp"

#include <loaders/LoaderSDT.hpp>
#include <rw/types.hpp>

extern "C" {
#include <libavformat/avformat.h>
#include <libavformat/avio.h>
#include <libavutil/opt.h>
#include <libswresample/swresample.h>
}

#if LIBAVFORMAT_VERSION_INT < AV_VERSION_INT(57, 80, 100)
#define avio_context_free av_freep
#endif

#define HAVE_CH_LAYOUT (LIBAVUTIL_VERSION_INT >= AV_VERSION_INT(57, 28, 100))

constexpr int kNumOutputChannels = 2;
constexpr AVSampleFormat kOutputFMT = AV_SAMPLE_FMT_S16;
constexpr size_t kNrFramesToPreload = 50;

bool SoundSource::allocateAudioFrame() {
    RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "allocateAudioFrame\n"));
    frame = av_frame_alloc();
    if (!frame) {
        RW_ERROR("Error allocating the audio frame");
        RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "alloc frame error \n"));
        return false;
    }
    return true;
}

bool SoundSource::allocateFormatContext(const std::filesystem::path& filePath) {
    formatContext = nullptr;
    if (avformat_open_input(&formatContext, filePath.string().c_str(), nullptr,
                            nullptr) != 0) {
        av_frame_free(&frame);
        RW_ERROR("Error opening audio file (" << filePath << ")");
        return false;
    }
    return true;
}

namespace {
/// Low level function for copying data from handler (opaque)
/// to buffer.
int read_packet(void* opaque, uint8_t* buf, int buf_size) {
    auto* input = reinterpret_cast<InputData*>(opaque);
    buf_size = std::min(buf_size, static_cast<int>(input->size));
    /* copy internal data to buf */
    memcpy(buf, input->ptr, buf_size);
    input->ptr += buf_size;
    input->size -= buf_size;
    return buf_size;
}
}  // namespace

bool SoundSource::prepareFormatContextSfx(LoaderSDT& sdt, size_t index,
                                          bool asWave) {
    RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG),
             (TFile, "SoundSource::prepareFormatContextSfx, index = %d, asWave = %d\n",
              (INT32) index, (INT32)asWave));

    /// Now we need to prepare "custom" format context
    /// We need sdt loader for that purpose
    RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "start to load to memory\n"));
    raw_sound = sdt.loadToMemory(index, asWave);
    RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "done load to memory\n"));
    if (!raw_sound) {
        RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "not raw sound, error, freeing for now...\n"));
        av_frame_free(&frame);
        RW_ERROR("Error loading sound");
        return false;
    }

    /// Prepare input
    input.size = sizeof(WaveHeader) + sdt.assetInfo.size;
    RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "loaded to mem, input.size = %lu\n", input.size));

    /// Store start ptr of data to be able freed memory later
    inputDataStart = std::make_unique<uint8_t[]>(input.size);
    input.ptr = inputDataStart.get();

    RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "input.ptr = %0.llx\n", (UINT64) input.ptr));

    /// Alocate memory for buffer
    /// Memory freeded at the end
    static constexpr size_t ioBufferSize = 4096;
    auto ioBuffer = static_cast<uint8_t*>(av_malloc(ioBufferSize));

    RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "ioBuffer = %0.llx\n", (UINT64) ioBuffer));

    /// Cast pointer, in order to match required layout for ffmpeg
    input.ptr = reinterpret_cast<uint8_t*>(raw_sound.get());

    RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "start to avio_alloc_context\n"));
    /// Finally prepare our "custom" format context
    avioContext = avio_alloc_context(ioBuffer, ioBufferSize, 0, &input,
                                     &read_packet, nullptr, nullptr);
    RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "done avio, start to avformat_alloc_context\n"));
    formatContext = avformat_alloc_context();
    formatContext->pb = avioContext;

    RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "done all alloc, open input SDT file.\n"));
    if (avformat_open_input(&formatContext, "SDT", nullptr, nullptr) != 0) {
        RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "SDT file open failed...\n"));
        av_free(formatContext->pb->buffer);
        avio_context_free(&formatContext->pb);
        av_frame_free(&frame);
        RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "Freeded everything\n"));
        RW_ERROR("Error opening audio file (" << index << ")");
        return false;
    }
    RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "SDT file open success, returning...\n"));
    return true;
}

bool SoundSource::findAudioStream(const std::filesystem::path& filePath) {
    RW_UNUSED(filePath);  // it's used by macro

    if (avformat_find_stream_info(formatContext, nullptr) < 0) {
        av_frame_free(&frame);
        avformat_close_input(&formatContext);
        RW_ERROR("Error finding audio stream info");
        return false;
    }

    // Find the audio stream
    int streamIndex = av_find_best_stream(formatContext, AVMEDIA_TYPE_AUDIO, -1,
                                          -1, nullptr, 0);
    if (streamIndex < 0) {
        av_frame_free(&frame);
        avformat_close_input(&formatContext);
        RW_ERROR("Could not find any audio stream in the file " << filePath);
        return false;
    }

    audioStream = formatContext->streams[streamIndex];
    codec = avcodec_find_decoder(audioStream->codecpar->codec_id);
    return true;
}

bool SoundSource::findAudioStreamSfx() {
    RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG),
             (TFile, "SoundSource::findAudioStreamSfx begin, formatContext = %0.llx\n",
              (UINT64) formatContext));
    if (avformat_find_stream_info(formatContext, nullptr) < 0) {
        RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "SoundSource::findAudioStreamSfx find stream info failed.\n"));
        av_free(formatContext->pb->buffer);
        avio_context_free(&formatContext->pb);
        av_frame_free(&frame);
        avformat_close_input(&formatContext);
        RW_ERROR("Error finding audio stream info");
        return false;
    }

    RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "SoundSource::findAudioStreamSfx start to find_best_stream\n"));
    // Find the audio stream
    int streamIndex = av_find_best_stream(formatContext, AVMEDIA_TYPE_AUDIO, -1,
                                          -1, nullptr, 0);
    if (streamIndex < 0) {
        av_free(formatContext->pb->buffer);
        avio_context_free(&formatContext->pb);
        av_frame_free(&frame);
        avformat_close_input(&formatContext);
        RW_ERROR("Could not find any audio stream in the file ");
        return false;
    }
    RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "SoundSource::findAudioStreamSfx start to find_decoder\n"));
    audioStream = formatContext->streams[streamIndex];
    codec = avcodec_find_decoder(audioStream->codecpar->codec_id);
    RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "SoundSource::findAudioStreamSfx end\n"));
    return true;
}

#if LIBAVCODEC_VERSION_INT < AV_VERSION_INT(57, 5, 0)
bool SoundSource::prepareCodecContextLegacy() {
    codecContext = audioStream->codec;
    codecContext->codec = codec;

    // Open the codec
    if (avcodec_open2(codecContext, codecContext->codec, nullptr) != 0) {
        av_frame_free(&frame);
        avformat_close_input(&formatContext);
        RW_ERROR("Couldn't open the audio codec context");
        return false;
    }
    return true;
}

bool SoundSource::prepareCodecContextSfxLegacy() {
    AVCodecContext* codecContext = audioStream->codec;
    codecContext->codec = codec;

    // Open the codec
    if (avcodec_open2(codecContext, codecContext->codec, nullptr) != 0) {
        av_free(formatContext->pb->buffer);
        avio_context_free(&formatContext->pb);
        av_frame_free(&frame);
        avformat_close_input(&formatContext);
        RW_ERROR("Couldn't open the audio codec context");
        return false;
    }
    return true;
}

#endif

bool SoundSource::prepareCodecContextWrap() {
#if LIBAVCODEC_VERSION_INT < AV_VERSION_INT(57, 5, 0)
    return prepareCodecContextLegacy());
#else
    return prepareCodecContext();
#endif
}

bool SoundSource::prepareCodecContext() {
    // Initialize codec context for the decoder.
    codecContext = avcodec_alloc_context3(codec);
    if (!codecContext) {
        av_frame_free(&frame);
        avformat_close_input(&formatContext);
        RW_ERROR("Couldn't allocate a decoding context.");
        return false;
    }

    // Fill the codecCtx with the parameters of the codec used in the read file.
    if (avcodec_parameters_to_context(codecContext, audioStream->codecpar) !=
        0) {
        avcodec_free_context(&codecContext);
        avformat_close_input(&formatContext);
        RW_ERROR("Couldn't find parametrs for context");
        return false;
    }

    // Initialize the decoder.
    if (avcodec_open2(codecContext, codec, nullptr) != 0) {
        avcodec_free_context(&codecContext);
        avformat_close_input(&formatContext);
        RW_ERROR("Couldn't open the audio codec context");
        return false;
    }
    return true;
}

bool SoundSource::prepareCodecContextSfxWrap() {
    RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "SoundSource::prepareCodecContextSfxWrap begin\n"));
    bool x = false;
#if LIBAVCODEC_VERSION_INT < AV_VERSION_INT(57, 5, 0)
    x = prepareCodecContextSfxLegacy();
#else
    x = prepareCodecContextSfx();
#endif
    RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "SoundSource::prepareCodecContextSfxWrap end, return = %d\n", (INT32) x));
    return x;
}

bool SoundSource::prepareCodecContextSfx() {
    // Initialize codec context for the decoder.
    codecContext = avcodec_alloc_context3(codec);
    if (!codecContext) {
        av_free(formatContext->pb->buffer);
        avio_context_free(&formatContext->pb);
        av_frame_free(&frame);
        avformat_close_input(&formatContext);
        RW_ERROR("Couldn't allocate a decoding context.");
        return false;
    }

    // Fill the codecCtx with the parameters of the codec used in the read file.
    if (avcodec_parameters_to_context(codecContext, audioStream->codecpar) !=
        0) {
        av_free(formatContext->pb->buffer);
        avio_context_free(&formatContext->pb);
        avcodec_free_context(&codecContext);
        avformat_close_input(&formatContext);
        RW_ERROR("Couldn't find parametrs for context");
        return false;
    }

    // Initialize the decoder.
    if (avcodec_open2(codecContext, codec, nullptr) != 0) {
        av_free(formatContext->pb->buffer);
        avio_context_free(&formatContext->pb);
        avcodec_free_context(&codecContext);
        avformat_close_input(&formatContext);
        RW_ERROR("Couldn't open the audio codec context");
        return false;
    }

    return true;
}

#if LIBAVCODEC_VERSION_INT < AV_VERSION_INT(57, 37, 100)
void SoundSource::decodeFramesLegacy(size_t framesToDecode) {
    while ((framesToDecode == 0 || decodedFrames < framesToDecode) &&
           av_read_frame(formatContext, readingPacket) == 0) {
        if (readingPacket->stream_index == audioStream->index) {
            AVPacket decodingPacket = *readingPacket;

            while (decodingPacket.size > 0) {
                // Decode audio packet
                int gotFrame = 0;
                int len = avcodec_decode_audio4(codecContext, frame, &gotFrame,
                                                &decodingPacket);

                if (len >= 0 && gotFrame) {
                    std::lock_guard<std::mutex> lock(mutex);
                    // Write samples to audio buffer
                    for (size_t i = 0;
                         i < static_cast<size_t>(frame->nb_samples); i++) {
                        // Interleave left/right channels
                        for (size_t channel = 0; channel < channels;
                             channel++) {
                            int16_t sample = reinterpret_cast<int16_t*>(
                                frame->data[channel])[i];
                            data.push_back(sample);
                        }
                    }

                    decodingPacket.size -= len;
                    decodingPacket.data += len;
                } else {
                    decodingPacket.size = 0;
                    decodingPacket.data = nullptr;
                }
            }
        }
        av_free_packet(readingPacket);
        ++decodedFrames;
    }
}
#endif

void SoundSource::decodeFramesSfxWrap() {
#if LIBAVCODEC_VERSION_INT < AV_VERSION_INT(57, 37, 100)
    decodeFramesLegacy(kNrFramesToPreload);
#else
    decodeFrames(kNrFramesToPreload);
#endif
}

void SoundSource::decodeFrames(size_t framesToDecode) {
    while ((framesToDecode == 0 || decodedFrames < framesToDecode) &&
           av_read_frame(formatContext, readingPacket) == 0) {
        if (readingPacket->stream_index == audioStream->index) {
            AVPacket decodingPacket = *readingPacket;

            int sendPacket = avcodec_send_packet(codecContext, &decodingPacket);
            int receiveFrame = 0;

            while ((receiveFrame =
                        avcodec_receive_frame(codecContext, frame)) == 0) {
                // Decode audio packet

                if (receiveFrame == 0 && sendPacket == 0) {
                    std::lock_guard<std::mutex> lock(mutex);
                    // Write samples to audio buffer
                    for (size_t i = 0;
                         i < static_cast<size_t>(frame->nb_samples); i++) {
                        // Interleave left/right channels
                        for (size_t channel = 0; channel < channels;
                             channel++) {
                            int16_t sample = reinterpret_cast<int16_t*>(
                                frame->data[channel])[i];
                            data.push_back(sample);
                        }
                    }
                }
            }
        }
        av_packet_unref(readingPacket);
        ++decodedFrames;
    }
}

void SoundSource::decodeFramesWrap(const std::filesystem::path& filePath) {
#if LIBAVCODEC_VERSION_INT < AV_VERSION_INT(57, 37, 100)
    decodeFramesLegacy(kNrFramesToPreload);
#else
    decodeAndResampleFrames(filePath, kNrFramesToPreload);
#endif
}

void SoundSource::decodeAndResampleFrames(const std::filesystem::path& filePath,
                                          size_t framesToDecode) {
    RW_UNUSED(filePath);  // it's used by macro
    AVFrame* resampled = av_frame_alloc();
    int err = 0;

    while ((framesToDecode == 0 || decodedFrames < framesToDecode) &&
           av_read_frame(formatContext, readingPacket) == 0) {
        if (readingPacket->stream_index == audioStream->index) {
            int sendPacket = avcodec_send_packet(codecContext, readingPacket);
            av_packet_unref(readingPacket);
            int receiveFrame = 0;

            while ((receiveFrame =
                        avcodec_receive_frame(codecContext, frame)) == 0) {
                if (!swr) {
#if HAVE_CH_LAYOUT
                    AVChannelLayout out_chlayout = AV_CHANNEL_LAYOUT_STEREO;
                    err = swr_alloc_set_opts2(
                        &swr, &out_chlayout, kOutputFMT, frame->sample_rate,
                        &frame->ch_layout,  // input channel layout
                        static_cast<AVSampleFormat>(
                            frame->format),  // input format
                        frame->sample_rate,  // input sample rate
                        0, nullptr);

                    if (err < 0) {
                        RW_ERROR(
                            "Resampler has not been successfully allocated.");
                        return;
                    }
#else
                    if (frame->channels == 1 || frame->channel_layout == 0)
                        frame->channel_layout =
                            av_get_default_channel_layout(1);

                    swr = swr_alloc_set_opts(
                        nullptr,
                        AV_CH_LAYOUT_STEREO,    // output channel layout
                        kOutputFMT,             // output format
                        frame->sample_rate,     // output sample rate
                        frame->channel_layout,  // input channel layout
                        static_cast<AVSampleFormat>(
                            frame->format),  // input format
                        frame->sample_rate,  // input sample rate
                        0, nullptr);
#endif
                    if (!swr) {
                        RW_ERROR(
                            "Resampler has not been successfully allocated.");
                        return;
                    }
                    swr_init(swr);
                    if (!swr_is_initialized(swr)) {
                        RW_ERROR(
                            "Resampler has not been properly initialized.");
                        return;
                    }
                }

                // Decode audio packet
                if (receiveFrame == 0 && sendPacket == 0) {
                    // Write samples to audio buffer
#if HAVE_CH_LAYOUT
                    resampled->ch_layout = AV_CHANNEL_LAYOUT_STEREO;
#else
                    resampled->channel_layout = AV_CH_LAYOUT_STEREO;
                    resampled->channels = kNumOutputChannels;
#endif
                    resampled->sample_rate = frame->sample_rate;
                    resampled->format = kOutputFMT;

                    swr_config_frame(swr, resampled, frame);

                    if (swr_convert_frame(swr, resampled, frame) < 0) {
                        RW_ERROR("Error resampling " << filePath << '\n');
                    }

                    std::lock_guard<std::mutex> lock(mutex);
                    for (size_t i = 0;
                         i <
                         static_cast<size_t>(resampled->nb_samples) * channels;
                         i++) {
                        data.push_back(
                            reinterpret_cast<int16_t*>(resampled->data[0])[i]);
                    }
                    av_frame_unref(resampled);
                }
            }
        }

        ++decodedFrames;
    }

    /// Free all data used by the resampled frame.
    av_frame_free(&resampled);

    /// Free resampler
    swr_free(&swr);
}

void SoundSource::cleanupAfterSoundLoading() {
    /// Free all data used by the frame.
    av_frame_free(&frame);

    /// Free the context itself.
    avcodec_free_context(&codecContext);

    /// We are done here. Close the input.
    avformat_close_input(&formatContext);
}

void SoundSource::cleanupAfterSfxLoading() {
    /// Free all data used by the frame.
    av_frame_free(&frame);

    /// Free the context itself.
    avcodec_free_context(&codecContext);

    /// Free our custom AVIO.
    av_free(formatContext->pb->buffer);
    avio_context_free(&formatContext->pb);

    /// We are done here. Close the input.
    avformat_close_input(&formatContext);
}

void SoundSource::exposeSoundMetadata() {
    channels = kNumOutputChannels;
    sampleRate = static_cast<size_t>(codecContext->sample_rate);
}

void SoundSource::exposeSfxMetadata(LoaderSDT& sdt) {
#if HAVE_CH_LAYOUT
    channels = static_cast<size_t>(codecContext->ch_layout.nb_channels);
#else
    channels = static_cast<size_t>(codecContext->channels);
#endif
    sampleRate = sdt.assetInfo.sampleRate;
}

void SoundSource::decodeRestSoundFramesAndCleanup(const std::filesystem::path& filePath) {
#if LIBAVCODEC_VERSION_INT < AV_VERSION_INT(57, 37, 100)
    decodeFramesLegacy(0);
#else
    decodeAndResampleFrames(filePath, 0);
#endif

    cleanupAfterSoundLoading();
}

void SoundSource::decodeRestSfxFramesAndCleanup() {
#if LIBAVCODEC_VERSION_INT < AV_VERSION_INT(57, 37, 100)
    decodeFramesLegacy(0);
#else
    decodeFrames(0);
#endif

    cleanupAfterSfxLoading();
}

void SoundSource::loadFromFile(const std::filesystem::path& filePath, bool streaming) {
    RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG),
             (TFile, "SoundSource::loadFromFile (%s) streaming = %d ....\n",
              filePath.c_str(), (INT32) streaming));
    if (allocateAudioFrame() && allocateFormatContext(filePath) &&
        findAudioStream(filePath) && prepareCodecContextWrap()) {
        exposeSoundMetadata();
        RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "done expose, start alloc\n"));
        readingPacket = av_packet_alloc();

        RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "done alloc, start to decodeFrames\n"));
        decodeFramesWrap(filePath);
        RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "done decodeFrames\n"));
        if (streaming) {
            RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "creating async to load file, return for now\n"));
            loadingThread = std::async(
                std::launch::async,
                &SoundSource::decodeRestSoundFramesAndCleanup, this, filePath);
        } else {
            decodeRestSoundFramesAndCleanup(filePath);
            RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "load file successful, returning\n"));
        }
    } else {
        RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "SoundSource::loadFromFile failed, continuing...\n"));
    }
}

void SoundSource::loadSfx(LoaderSDT& sdt, size_t index, bool asWave,
                          bool streaming) {
    RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG),
             (TFile, "SoundSource::loadSfx (index = %u), asWave = %d, "
              "streaming = %d ....\n", (UINT32) index, (INT32) asWave,
              (INT32) streaming));
    if (allocateAudioFrame() && prepareFormatContextSfx(sdt, index, asWave) &&
        findAudioStreamSfx() && prepareCodecContextSfxWrap()) {
        RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "start to exposeSfxMetadata\n"));
        exposeSfxMetadata(sdt);
        RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "expose done, start to alloc pack\n"));
        readingPacket = av_packet_alloc();

        RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "start to decodeSfx\n"));
        decodeFramesSfxWrap();
        RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "decodeFramesSfx finished\n"));

        if (streaming) {
            loadingThread =
                std::async(std::launch::async,
                           &SoundSource::decodeRestSfxFramesAndCleanup, this);
        } else {
            decodeRestSfxFramesAndCleanup();
        }
    }
    RW_TRACE(Tracing(RWC_SOUNDMAN, TRACE_DEBUG), (TFile, "loadSfx finished\n"));
}
