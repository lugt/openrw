/**
    @brief print_big %1g% duration %2d% ms style %3d%

    opcode 00ba
    @arg gxtEntry GXT entry
    @arg time Time (ms)
    @arg style
*/
void opcode_00ba(const ScriptArguments& args, const ScriptString gxtEntry, const ScriptInt time, const ScriptInt style) {
    const auto& text = script::gxt(args, gxtEntry);
    args.getWorld()->state->text.addText<ScreenTextType::Big>(
    			ScreenTextEntry::makeBig(
    				gxtEntry, text, style, time
    				));
}

/**
    @brief print %1g% duration %2d% ms flag %3d%

    opcode 00bb
    @arg gxtEntry GXT entry
    @arg time Time (ms)
    @arg flags 
*/
void opcode_00bb(const ScriptArguments& args, const ScriptString gxtEntry, const ScriptInt time, const ScriptInt flags) {
    const auto& text = script::gxt(args, gxtEntry);
    RW_UNUSED(flags);
    args.getWorld()->state->text.addText<ScreenTextType::HighPriority>(
    			ScreenTextEntry::makeHighPriority(
    				gxtEntry, text, time
    				));
}

/**
    @brief print_now %1g% duration %2d% ms flag %3d%

    opcode 00bc
    @arg gxtEntry GXT entry
    @arg time Time (ms)
    @arg arg3 
*/
void opcode_00bc(const ScriptArguments& args, const ScriptString gxtEntry, const ScriptInt time, const ScriptInt arg3) {
    const auto& text = script::gxt(args, gxtEntry);
    RW_UNUSED(arg3);
    RW_UNIMPLEMENTED("Unclear what style should be used");
    args.getWorld()->state->text.clear<ScreenTextType::HighPriority>();
    args.getWorld()->state->text.addText<ScreenTextType::HighPriority>(
    			ScreenTextEntry::makeHighPriority(
    				gxtEntry, text, time
    				));
}

/**
    @brief print_soon %1g% duration %2d% ms flag %3d%

    opcode 00bd
    @arg gxtEntry
    @arg time
    @arg arg3 
*/
void opcode_00bd(const ScriptArguments& args, const ScriptString gxtEntry, const ScriptInt time, const ScriptInt arg3) {
    const auto& text = script::gxt(args, gxtEntry);
    RW_UNUSED(arg3);
    args.getWorld()->state->text.addText<ScreenTextType::BigLowPriority>(
        ScreenTextEntry::makeBig(gxtEntry, text, arg3, time));
}

/**
    @brief clear_prints

    opcode 00be
*/
void opcode_00be(const ScriptArguments& args) {
    args.getWorld()->state->text.clear<ScreenTextType::Big>();
}

/**
    @brief remove_status_text %1d%

    opcode 0151
    @arg arg1G 
*/
void opcode_0151(const ScriptArguments& args, ScriptInt& arg1G) {
    RW_UNIMPLEMENTED_OPCODE(0x0151);
    RW_UNUSED(arg1G);
    RW_UNUSED(args);
}

/**
    @brief text_1number_styled %1g% number %2d% duration %3d% ms style %4d%

    opcode 01e3
    @arg gxtEntry GXT entry
    @arg arg2 
    @arg time Time (ms)
    @arg style
*/
void opcode_01e3(const ScriptArguments& args, const ScriptString gxtEntry, const ScriptInt arg2, const ScriptInt time, const ScriptInt style) {
    auto str =
            ScreenText::format(
                script::gxt(args, gxtEntry),
                GameStringUtil::fromString(std::to_string(arg2), FONT_PRICEDOWN));
    args.getState()->text.addText<ScreenTextType::Big>(
                ScreenTextEntry::makeBig(
                    gxtEntry, str, style, time));
}

/**
    @brief text_1number_lowpriority %1g% number %2d% duration %3d% ms flag %4d%

    opcode 01e4
    @arg gxtEntry GXT entry
    @arg arg2 
    @arg time Time (ms)
    @arg arg4 
*/
void opcode_01e4(const ScriptArguments& args, const ScriptString gxtEntry, const ScriptInt arg2, const ScriptInt time, const ScriptInt arg4) {
    RW_UNIMPLEMENTED_OPCODE(0x01e4);
    RW_UNUSED(gxtEntry);
    RW_UNUSED(arg2);
    RW_UNUSED(time);
    RW_UNUSED(arg4);
    RW_UNUSED(args);
}

/**
    @brief text_1number_highpriority %1g% number %2d% duration %3d% ms flag %4d%

    opcode 01e5
    @arg gxtEntry GXT entry
    @arg arg2 
    @arg time Time (ms)
    @arg arg4 
*/
void opcode_01e5(const ScriptArguments& args, const ScriptString gxtEntry, const ScriptInt arg2, const ScriptInt time, const ScriptInt arg4) {
    RW_UNIMPLEMENTED_OPCODE(0x01e5);
    RW_UNUSED(gxtEntry);
    RW_UNUSED(arg2);
    RW_UNUSED(time);
    RW_UNUSED(arg4);
    RW_UNUSED(args);
}

/**
    @brief text_big_styled %1g% duration %2d% ms style %3d%

    opcode 0217
    @arg gxtEntry GXT entry
    @arg time Time (ms)
    @arg arg3 
*/
void opcode_0217(const ScriptArguments& args, const ScriptString gxtEntry, const ScriptInt time, const ScriptInt arg3) {
    RW_UNIMPLEMENTED_OPCODE(0x0217);
    RW_UNUSED(gxtEntry);
    RW_UNUSED(time);
    RW_UNUSED(arg3);
    RW_UNUSED(args);
}

/**
    @brief text_big_1number_styled %1g% number %2d% duration %3d% ms style %4d%

    opcode 0218
    @arg gxtEntry GXT entry
    @arg arg2 
    @arg time Time (ms)
    @arg arg4 
*/
void opcode_0218(const ScriptArguments& args, const ScriptString gxtEntry, const ScriptInt arg2, const ScriptInt time, const ScriptInt arg4) {
    RW_UNIMPLEMENTED_OPCODE(0x0218);
    RW_UNUSED(gxtEntry);
    RW_UNUSED(arg2);
    RW_UNUSED(time);
    RW_UNUSED(arg4);
    RW_UNUSED(args);
}

/**
    @brief toggle_widescreen %1bon/off%

    opcode 02a3
    @arg flag Boolean true/false
*/
void opcode_02a3(const ScriptArguments& args, const ScriptBoolean flag) {
    args.getState()->isCinematic = flag;
}

/**
    @brief text_2numbers %1g% numbers %2d% %3d% duration %4d% ms flag %5d%

    opcode 02fc
    @arg arg1 
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
*/
void opcode_02fc(const ScriptArguments& args, const ScriptString arg1, const ScriptInt arg2, const ScriptInt arg3, const ScriptInt arg4, const ScriptInt arg5) {
    RW_UNIMPLEMENTED_OPCODE(0x02fc);
    RW_UNUSED(arg1);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(args);
}

/**
    @brief text_2numbers_lowpriority %1g% numbers %2d% %3d% duration %4d% ms flag %5d%

    opcode 02fd
    @arg gxtEntry GXT entry
    @arg arg2 
    @arg arg3 
    @arg time Time (ms)
    @arg arg5 
*/
void opcode_02fd(const ScriptArguments& args, const ScriptString gxtEntry, const ScriptInt arg2, const ScriptInt arg3, const ScriptInt time, const ScriptInt arg5) {
    RW_UNIMPLEMENTED_OPCODE(0x02fd);
    RW_UNUSED(gxtEntry);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(time);
    RW_UNUSED(arg5);
    RW_UNUSED(args);
}

/**
    @brief text_2numbers_highpriority %1g% numbers %2d% %3d% duration %4d% ms flag %5d%

    opcode 02fe
    @arg arg1 
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
*/
void opcode_02fe(const ScriptArguments& args, const ScriptString arg1, const ScriptInt arg2, const ScriptInt arg3, const ScriptInt arg4, const ScriptInt arg5) {
    RW_UNIMPLEMENTED_OPCODE(0x02fe);
    RW_UNUSED(arg1);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(args);
}

/**
    @brief text_3numbers %1g% numbers %2d% %3d% %4d% duration %5d% ms flag %6h%

    opcode 02ff
    @arg gxtEntry GXT entry
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg time Time (ms)
    @arg arg6 
*/
void opcode_02ff(const ScriptArguments& args, const ScriptString gxtEntry, const ScriptInt arg2, const ScriptInt arg3, const ScriptInt arg4, const ScriptInt time, const ScriptInt arg6) {
    RW_UNIMPLEMENTED_OPCODE(0x02ff);
    RW_UNUSED(gxtEntry);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(time);
    RW_UNUSED(arg6);
    RW_UNUSED(args);
}

/**
    @brief text_3numbers_highpriority %1g% numbers %2d% %3d% %4d% duration %5d% ms flag %6h%

    opcode 0300
    @arg gxtEntry GXT entry
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg time Time (ms)
    @arg arg6 
*/
void opcode_0300(const ScriptArguments& args, const ScriptString gxtEntry, const ScriptInt arg2, const ScriptInt arg3, const ScriptInt arg4, const ScriptInt time, const ScriptInt arg6) {
    RW_UNIMPLEMENTED_OPCODE(0x0300);
    RW_UNUSED(gxtEntry);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(time);
    RW_UNUSED(arg6);
    RW_UNUSED(args);
}

/**
    @brief text_3numbers_lowpriority %1g% numbers %2d% %3d% %4d% duration %5d% ms flag %6h%

    opcode 0301
    @arg gxtEntry GXT entry
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg time Time (ms)
    @arg arg6 
*/
void opcode_0301(const ScriptArguments& args, const ScriptString gxtEntry, const ScriptInt arg2, const ScriptInt arg3, const ScriptInt arg4, const ScriptInt time, const ScriptInt arg6) {
    RW_UNIMPLEMENTED_OPCODE(0x0301);
    RW_UNUSED(gxtEntry);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(time);
    RW_UNUSED(arg6);
    RW_UNUSED(args);
}

/**
    @brief text_4numbers %1g% numbers %2d% %3d% %4d% %5d% duration %6d% ms flag %7d%

    opcode 0302
    @arg gxtEntry GXT entry
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg time Time (ms)
    @arg arg7 
*/
void opcode_0302(const ScriptArguments& args, const ScriptString gxtEntry, const ScriptInt arg2, const ScriptInt arg3, const ScriptInt arg4, const ScriptInt arg5, const ScriptInt time, const ScriptInt arg7) {
    RW_UNIMPLEMENTED_OPCODE(0x0302);
    RW_UNUSED(gxtEntry);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(time);
    RW_UNUSED(arg7);
    RW_UNUSED(args);
}

/**
    @brief text_4numbers_highpriority %1g% numbers %2d% %3d% %4d% %5d% duration %6d% ms flag %7d%

    opcode 0303
    @arg gxtEntry GXT entry
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg time Time (ms)
    @arg arg7 
*/
void opcode_0303(const ScriptArguments& args, const ScriptString gxtEntry, const ScriptInt arg2, const ScriptInt arg3, const ScriptInt arg4, const ScriptInt arg5, const ScriptInt time, const ScriptInt arg7) {
    RW_UNIMPLEMENTED_OPCODE(0x0303);
    RW_UNUSED(gxtEntry);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(time);
    RW_UNUSED(arg7);
    RW_UNUSED(args);
}

/**
    @brief text_4numbers_lowpriority %1g% numbers %2d% %3d% %4d% %5d% duration %6d% ms flag %7d%

    opcode 0304
    @arg gxtEntry GXT entry
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg time Time (ms)
    @arg arg7 
*/
void opcode_0304(const ScriptArguments& args, const ScriptString gxtEntry, const ScriptInt arg2, const ScriptInt arg3, const ScriptInt arg4, const ScriptInt arg5, const ScriptInt time, const ScriptInt arg7) {
    RW_UNIMPLEMENTED_OPCODE(0x0304);
    RW_UNUSED(gxtEntry);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(time);
    RW_UNUSED(arg7);
    RW_UNUSED(args);
}

/**
    @brief text_5numbers %1g% numbers %2d% %3d% %4d% %5d% %6d% duration %7d% ms flag %8d%

    opcode 0305
    @arg gxtEntry GXT entry
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
    @arg time Time (ms)
    @arg arg8 
*/
void opcode_0305(const ScriptArguments& args, const ScriptString gxtEntry, const ScriptInt arg2, const ScriptInt arg3, const ScriptInt arg4, const ScriptInt arg5, const ScriptInt arg6, const ScriptInt time, const ScriptInt arg8) {
    RW_UNIMPLEMENTED_OPCODE(0x0305);
    RW_UNUSED(gxtEntry);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(arg6);
    RW_UNUSED(time);
    RW_UNUSED(arg8);
    RW_UNUSED(args);
}

/**
    @brief text_5numbers_highpriority %1g% numbers %2d% %3d% %4d% %5d% %6d% duration %7d% ms flag %8d%

    opcode 0306
    @arg gxtEntry GXT entry
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
    @arg time Time (ms)
    @arg arg8 
*/
void opcode_0306(const ScriptArguments& args, const ScriptString gxtEntry, const ScriptInt arg2, const ScriptInt arg3, const ScriptInt arg4, const ScriptInt arg5, const ScriptInt arg6, const ScriptInt time, const ScriptInt arg8) {
    RW_UNIMPLEMENTED_OPCODE(0x0306);
    RW_UNUSED(gxtEntry);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(arg6);
    RW_UNUSED(time);
    RW_UNUSED(arg8);
    RW_UNUSED(args);
}

/**
    @brief text_5numbers_lowpriority %1g% numbers %2d% %3d% %4d% %5d% %6d% duration %7d% ms flag %8d%

    opcode 0307
    @arg gxtEntry GXT entry
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
    @arg time Time (ms)
    @arg arg8 
*/
void opcode_0307(const ScriptArguments& args, const ScriptString gxtEntry, const ScriptInt arg2, const ScriptInt arg3, const ScriptInt arg4, const ScriptInt arg5, const ScriptInt arg6, const ScriptInt time, const ScriptInt arg8) {
    RW_UNIMPLEMENTED_OPCODE(0x0307);
    RW_UNUSED(gxtEntry);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(arg6);
    RW_UNUSED(time);
    RW_UNUSED(arg8);
    RW_UNUSED(args);
}

/**
    @brief text_6numbers %1g% numbers %2d% %3d% %4d% %5d% %6d% %7d% duration %8d% ms flag %9d%

    opcode 0308
    @arg gxtEntry GXT entry
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
    @arg arg7 
    @arg time Time (ms)
    @arg arg9 
*/
void opcode_0308(const ScriptArguments& args, const ScriptString gxtEntry, const ScriptInt arg2, const ScriptInt arg3, const ScriptInt arg4, const ScriptInt arg5, const ScriptInt arg6, const ScriptInt arg7, const ScriptInt time, const ScriptInt arg9) {
    RW_UNIMPLEMENTED_OPCODE(0x0308);
    RW_UNUSED(gxtEntry);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(arg6);
    RW_UNUSED(arg7);
    RW_UNUSED(time);
    RW_UNUSED(arg9);
    RW_UNUSED(args);
}

/**
    @brief text_6numbers_highpriority %1g% numbers %2d% %3d% %4d% %5d% %6d% %7d% duration %8d% ms flag %9d%

    opcode 0309
    @arg gxtEntry GXT entry
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
    @arg arg7 
    @arg time Time (ms)
    @arg arg9 
*/
void opcode_0309(const ScriptArguments& args, const ScriptString gxtEntry, const ScriptInt arg2, const ScriptInt arg3, const ScriptInt arg4, const ScriptInt arg5, const ScriptInt arg6, const ScriptInt arg7, const ScriptInt time, const ScriptInt arg9) {
    RW_UNIMPLEMENTED_OPCODE(0x0309);
    RW_UNUSED(gxtEntry);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(arg6);
    RW_UNUSED(arg7);
    RW_UNUSED(time);
    RW_UNUSED(arg9);
    RW_UNUSED(args);
}

/**
    @brief text_6numbers_lowpriority %1g% numbers %2d% %3d% %4d% %5d% %6d% %7d% duration %8d% ms flag %9d%

    opcode 030a
    @arg arg1 
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
    @arg arg7 
    @arg arg8 
    @arg arg9 
*/
void opcode_030a(const ScriptArguments& args, const ScriptString arg1, const ScriptInt arg2, const ScriptInt arg3, const ScriptInt arg4, const ScriptInt arg5, const ScriptInt arg6, const ScriptInt arg7, const ScriptInt arg8, const ScriptInt arg9) {
    RW_UNIMPLEMENTED_OPCODE(0x030a);
    RW_UNUSED(arg1);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(arg6);
    RW_UNUSED(arg7);
    RW_UNUSED(arg8);
    RW_UNUSED(arg9);
    RW_UNUSED(args);
}

/**
    @brief text_draw %1d% %2d% %3g%

    opcode 033e
    @arg pixelX 2D pixel X
    @arg pixelY 2D pixel Y
    @arg gxtEntry GXT entry
*/
void opcode_033e(const ScriptArguments& args, const ScriptFloat pixelX, const ScriptFloat pixelY, const ScriptString gxtEntry) {
    auto str = script::gxt(args, gxtEntry);
    args.getState()->nextText.text = str;
    args.getState()->nextText.position = glm::vec2(pixelX, pixelY);
    args.getState()->texts.push_back(args.getState()->nextText);
}

/**
    @brief set_text_draw_letter_width_height %1d% %2d%

    opcode 033f
    @arg arg1 
    @arg arg2 
*/
void opcode_033f(const ScriptArguments& args, const ScriptFloat arg1, const ScriptFloat arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x033f);
    RW_UNUSED(arg1);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief set_text_draw_color %1d% %2d% %3d% %4d%

    opcode 0340
    @arg colour Colour (0-255)
*/
void opcode_0340(const ScriptArguments& args, ScriptRGBA colour) {
    RW_UNUSED(colour);
    args.getState()->nextText.colourFG.r = args[0].integer / 255.f;
    args.getState()->nextText.colourFG.g = args[1].integer / 255.f;
    args.getState()->nextText.colourFG.b = args[2].integer / 255.f;
    args.getState()->nextText.colourFG.a = args[3].integer / 255.f;
}

/**
    @brief set_text_draw_align_justify %1d%

    opcode 0341
    @arg arg1 Boolean true/false
*/
void opcode_0341(const ScriptArguments& args, const ScriptBoolean arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x0341);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief set_text_linewidth %1d%

    opcode 0343
    @arg pixelX 2D pixel X
*/
void opcode_0343(const ScriptArguments& args, const ScriptFloat pixelX) {
    RW_UNIMPLEMENTED_OPCODE(0x0343);
    RW_UNUSED(pixelX);
    RW_UNUSED(args);
}

/**
    @brief enable_text_draw_background %1d%

    opcode 0345
    @arg arg1 Boolean true/false
*/
void opcode_0345(const ScriptArguments& args, const ScriptBoolean arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x0345);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief set_text_draw_background_color %1d% %2d% %3d% %4d%

    opcode 0346
    @arg colour Colour (0-255)
*/
void opcode_0346(const ScriptArguments& args, ScriptRGBA colour) {
    RW_UNUSED(colour);
    args.getState()->nextText.colourBG.r = args[0].integer / 255.f;
    args.getState()->nextText.colourBG.g = args[1].integer / 255.f;
    args.getState()->nextText.colourBG.b = args[2].integer / 255.f;
    args.getState()->nextText.colourBG.a = args[3].integer / 255.f;
}

/**
    @brief enable_text_draw_proportional %1d%

    opcode 0348
    @arg arg1 Boolean true/false
*/
void opcode_0348(const ScriptArguments& args, const ScriptBoolean arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x0348);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief text_2numbers_styled %1g% numbers %2d% %3d% duration %4d% ms style %5d%

    opcode 036d
    @arg gxtEntry GXT entry
    @arg arg2 
    @arg arg3 
    @arg time Time (ms)
    @arg arg5 
*/
void opcode_036d(const ScriptArguments& args, const ScriptString gxtEntry, const ScriptInt arg2, const ScriptInt arg3, const ScriptInt time, const ScriptInt arg5) {
    RW_UNUSED(arg5);
    auto world = args.getWorld();

    unsigned short style = args[4].integerValue();

    auto str =
        ScreenText::format(script::gxt(args, gxtEntry),
                           GameStringUtil::fromString(std::to_string(arg2), FONT_PRICEDOWN),
                           GameStringUtil::fromString(std::to_string(arg3), FONT_PRICEDOWN));

    auto textEntry = ScreenTextEntry::makeBig(gxtEntry, str, style, time);
    world->state->text.addText<ScreenTextType::Big>(textEntry);
}

/**
    @brief text_3numbers_styled %1g% numbers %2d% %3d% %4d% duration %5d% ms style %6d%

    opcode 036e
    @arg arg1 
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
*/
void opcode_036e(const ScriptArguments& args, const ScriptString arg1, const ScriptInt arg2, const ScriptInt arg3, const ScriptInt arg4, const ScriptInt arg5, const ScriptInt arg6) {
    RW_UNIMPLEMENTED_OPCODE(0x036e);
    RW_UNUSED(arg1);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(arg6);
    RW_UNUSED(args);
}

/**
    @brief text_4numbers_styled %1g% numbers %2d% %3d% %4d% %5d% duration %6d% ms flag %7d%

    opcode 036f
    @arg arg1 
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
    @arg arg7 
*/
void opcode_036f(const ScriptArguments& args, const ScriptString arg1, const ScriptInt arg2, const ScriptInt arg3, const ScriptInt arg4, const ScriptInt arg5, const ScriptInt arg6, const ScriptInt arg7) {
    RW_UNIMPLEMENTED_OPCODE(0x036f);
    RW_UNUSED(arg1);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(arg6);
    RW_UNUSED(arg7);
    RW_UNUSED(args);
}

/**
    @brief text_5numbers_styled %1g% numbers %2d% %3d% %4d% %5d% %6d% duration %7d% ms flag %8d%

    opcode 0370
    @arg gxtEntry GXT entry
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
    @arg time Time (ms)
    @arg arg8 
*/
void opcode_0370(const ScriptArguments& args, const ScriptString gxtEntry, const ScriptInt arg2, const ScriptInt arg3, const ScriptInt arg4, const ScriptInt arg5, const ScriptInt arg6, const ScriptInt time, const ScriptInt arg8) {
    RW_UNIMPLEMENTED_OPCODE(0x0370);
    RW_UNUSED(gxtEntry);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(arg6);
    RW_UNUSED(time);
    RW_UNUSED(arg8);
    RW_UNUSED(args);
}

/**
    @brief text_6numbers_styled %1g% numbers %2d% %3d% %4d% %5d% %6d% %7d% duration %8d% ms flag %9d%

    opcode 0371
    @arg gxtEntry GXT entry
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
    @arg arg7 
    @arg time Time (ms)
    @arg arg9 
*/
void opcode_0371(const ScriptArguments& args, const ScriptString gxtEntry, const ScriptInt arg2, const ScriptInt arg3, const ScriptInt arg4, const ScriptInt arg5, const ScriptInt arg6, const ScriptInt arg7, const ScriptInt time, const ScriptInt arg9) {
    RW_UNIMPLEMENTED_OPCODE(0x0371);
    RW_UNUSED(gxtEntry);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(arg6);
    RW_UNUSED(arg7);
    RW_UNUSED(time);
    RW_UNUSED(arg9);
    RW_UNUSED(args);
}

/**
    @brief text_1string %1g% %2g% duration %3d% ms flag %4d%

    opcode 0375
    @arg gxtEntry0 GXT entry
    @arg gxtEntry1 GXT entry
    @arg time Time (ms)
    @arg arg4 
*/
void opcode_0375(const ScriptArguments& args, const ScriptString gxtEntry0, const ScriptString gxtEntry1, const ScriptInt time, const ScriptInt arg4) {
    RW_UNIMPLEMENTED_OPCODE(0x0375);
    RW_UNUSED(gxtEntry0);
    RW_UNUSED(gxtEntry1);
    RW_UNUSED(time);
    RW_UNUSED(arg4);
    RW_UNUSED(args);
}

/**
    @brief text_1string %1g% string %2g% duration %3d% ms flag %4d%

    opcode 0384
    @arg gxtEntry0 GXT entry
    @arg gxtEntry1 GXT entry
    @arg time Time (ms)
    @arg arg4 
*/
void opcode_0384(const ScriptArguments& args, const ScriptString gxtEntry0, const ScriptString gxtEntry1, const ScriptInt time, const ScriptInt arg4) {
    RW_UNIMPLEMENTED_OPCODE(0x0384);
    RW_UNUSED(gxtEntry0);
    RW_UNUSED(gxtEntry1);
    RW_UNUSED(time);
    RW_UNUSED(arg4);
    RW_UNUSED(args);
}

/**
    @brief text_1string_lowpriority %1g% string %2g% duration %3d% ms flag %4d%

    opcode 0385
    @arg gxtEntry0 GXT entry
    @arg gxtEntry1 GXT entry
    @arg time Time (ms)
    @arg arg4 
*/
void opcode_0385(const ScriptArguments& args, const ScriptString gxtEntry0, const ScriptString gxtEntry1, const ScriptInt time, const ScriptInt arg4) {
    RW_UNIMPLEMENTED_OPCODE(0x0385);
    RW_UNUSED(gxtEntry0);
    RW_UNUSED(gxtEntry1);
    RW_UNUSED(time);
    RW_UNUSED(arg4);
    RW_UNUSED(args);
}

/**
    @brief draw_texture %1h% position %2d% %3d% size %4d% %5d% RGBA %6d% %7d% %8d% %9d% 

    opcode 038d
    @arg arg1 
    @arg pixelX 2D pixel X
    @arg pixelY 2D pixel Y
    @arg arg4 
    @arg arg5 
    @arg colour Colour (0-255)
*/
void opcode_038d(const ScriptArguments& args, const ScriptInt arg1, const ScriptFloat pixelX, const ScriptFloat pixelY, const ScriptFloat arg4, const ScriptFloat arg5, ScriptRGBA colour) {
    RW_UNIMPLEMENTED_OPCODE(0x038d);
    RW_UNUSED(arg1);
    RW_UNUSED(pixelX);
    RW_UNUSED(pixelY);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(colour);
    RW_UNUSED(args);
}

/**
    @brief load_texture %2h% as %1d%  

    opcode 038f
    @arg arg1 
    @arg arg2 
*/
void opcode_038f(const ScriptArguments& args, const ScriptInt arg1, const ScriptString arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x038f);
    RW_UNUSED(arg1);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief release_textures

    opcode 0391
*/
void opcode_0391(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x0391);
    RW_UNUSED(args);
}

/**
    @brief set_status_text_to %1d% %2b:bar/number% %3g%

    opcode 03c4
    @arg arg1G 
    @arg arg2 Boolean true/false
    @arg gxtEntry GXT entry
*/
void opcode_03c4(const ScriptArguments& args, ScriptInt& arg1G, const ScriptBoolean arg2, const ScriptString gxtEntry) {
    RW_UNIMPLEMENTED_OPCODE(0x03c4);
    RW_UNUSED(arg1G);
    RW_UNUSED(arg2);
    RW_UNUSED(gxtEntry);
    RW_UNUSED(args);
}

/**
    @brief remove_text %1g%

    opcode 03d5
    @arg gxtEntry GXT entry
*/
void opcode_03d5(const ScriptArguments& args, const ScriptString gxtEntry) {
    args.getWorld()->state->text.remove<ScreenTextType::HighPriority>(gxtEntry);
}

/**
    @brief remove_styled_text %1g%

    opcode 03d6
    @arg gxtEntry GXT entry
*/
void opcode_03d6(const ScriptArguments& args, const ScriptString gxtEntry) {
    RW_UNIMPLEMENTED_OPCODE(0x03d6);
    RW_UNUSED(gxtEntry);
    RW_UNUSED(args);
}

/**
    @brief set_text_draw_align_right %1h%

    opcode 03e4
    @arg arg1 Boolean true/false
*/
void opcode_03e4(const ScriptArguments& args, const ScriptBoolean arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x03e4);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief text_box %1g%

    opcode 03e5
    @arg gxtEntry GXT entry
*/
void opcode_03e5(const ScriptArguments& args, const ScriptString gxtEntry) {
    args.getState()->text.clear<ScreenTextType::Big>();
    args.getState()->text.addText<ScreenTextType::Big>(
        ScreenTextEntry::makeHelp(gxtEntry, script::gxt(args, gxtEntry)));
}

/**
    @brief remove_text_box

    opcode 03e6
*/
void opcode_03e6(const ScriptArguments& args) {
    args.getState()->text.clear<ScreenTextType::Help>();
}

/**
    @brief flash_hud %1d%

    opcode 03e7
    @arg arg1 
*/
void opcode_03e7(const ScriptArguments& args, const ScriptHudFlash arg1) {
    args.getState()->hudFlash = static_cast<HudFlash>(arg1);
}

/**
    @brief clear_small_messages_only

    opcode 03eb
*/
void opcode_03eb(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x03eb);
    RW_UNUSED(args);
}

/**
    @brief enable_text_draw %1d%

    opcode 03f0
    @arg arg1 
*/
void opcode_03f0(const ScriptArguments& args, const ScriptInt arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x03f0);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief text_draw_2numbers %3g% numbers %4d% %5d% at %1d% %2d% 

    opcode 045b
    @arg pixelX 2D pixel X
    @arg pixelY 2D pixel Y
    @arg gxtEntry GXT entry
    @arg arg4 
    @arg arg5 
*/
void opcode_045b(const ScriptArguments& args, const ScriptFloat pixelX, const ScriptFloat pixelY, const ScriptString gxtEntry, const ScriptInt arg4, const ScriptInt arg5) {
    RW_UNIMPLEMENTED_OPCODE(0x045b);
    RW_UNUSED(pixelX);
    RW_UNUSED(pixelY);
    RW_UNUSED(gxtEntry);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(args);
}

