#include "script/ScriptMachine.hpp"

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <vector>

#include "ai/PlayerController.hpp"
#include "core/Logger.hpp"
#include "core/Profiler.hpp"
#include "engine/GameState.hpp"
#include "engine/GameWorld.hpp"
#include "script/SCMFile.hpp"
#include "script/ScriptModule.hpp"
#include "script/UnimplementedOpcodes.hpp"

void ScriptMachine::executeThread(SCMThread& t, int msPassed) {
    auto player = state->world->getPlayer();

    if (player) {
        if (t.isMission && t.deathOrArrestCheck &&
            (player->isWasted() || player->isBusted())) {
            t.wastedOrBusted = true;
            t.stackDepth = 0;
            t.programCounter = t.calls[t.stackDepth];
        }
    }
    // There is 02a1 opcode that is used only during "Kingdom Come", which
    // basically acts like a wait command, but waiting time can be skipped
    // by pressing 'X'? PS2 button
    if (t.allowWaitSkip && getState()->input[0].pressed(GameInputState::Jump)) {
        t.wakeCounter = 0;
        t.allowWaitSkip = false;
    }
    if (t.wakeCounter > 0) {
        t.wakeCounter = std::max(t.wakeCounter - msPassed, 0);
    }
    if (t.wakeCounter > 0) return;

    while (t.wakeCounter == 0) {
        auto pc = t.programCounter;
        auto opcode = file.read<SCMOpcode>(pc);

        bool isNegatedConditional = ((opcode & SCM_NEGATE_CONDITIONAL_MASK) ==
                                     SCM_NEGATE_CONDITIONAL_MASK);
        opcode = opcode & ~SCM_NEGATE_CONDITIONAL_MASK;

        ++opcodeCallCounts[opcode];

        ScriptFunctionMeta* foundcode;
        if (!module->findOpcode(opcode, &foundcode)) {
            throw IllegalInstruction(opcode, pc, t.name);
        }
        ScriptFunctionMeta& code = *foundcode;

        pc += sizeof(SCMOpcode);

        SCMParams parameters;

        bool hasExtraParameters = code.arguments < 0;
        auto requiredParams = std::abs(code.arguments);

        for (int p = 0; p < requiredParams || hasExtraParameters; ++p) {
            auto type_r = file.read<SCMByte>(pc);
            auto type = static_cast<SCMType>(type_r);

            if (type_r > 42) {
                // for implicit strings, we need the byte we just read.
                type = TString;
            } else {
                pc += sizeof(SCMByte);
            }

            parameters.push_back(SCMOpcodeParameter{type, {0}});
            switch (type) {
                case EndOfArgList:
                    hasExtraParameters = false;
                    break;
                case TInt8:
                    parameters.back().integer = file.read<std::int8_t>(pc);
                    pc += sizeof(SCMByte);
                    break;
                case TInt16:
                    parameters.back().integer = file.read<std::int16_t>(pc);
                    pc += sizeof(SCMByte) * 2;
                    break;
                case TGlobal: {
                    auto v = file.read<std::uint16_t>(pc);
                    parameters.back().globalPtr =
                        globalData.data() + v;  //* SCM_VARIABLE_SIZE;
                    if (v >= file.getGlobalsSize()) {
                        state->world->logger->error(
                            "SCM", "Global Out of bounds! " +
                                       std::to_string(v) + " " +
                                       std::to_string(file.getGlobalsSize()));
                    }
                    pc += sizeof(SCMByte) * 2;
                } break;
                case TLocal: {
                    auto v = file.read<std::uint16_t>(pc);
                    parameters.back().globalPtr =
                        t.locals.data() + v * SCM_VARIABLE_SIZE;
                    if (v >= SCM_THREAD_LOCAL_SIZE) {
                        state->world->logger->error("SCM",
                                                    "Local Out of bounds!");
                    }
                    pc += sizeof(SCMByte) * 2;
                } break;
                case TInt32:
                    parameters.back().integer = file.read<std::int32_t>(pc);
                    pc += sizeof(SCMByte) * 4;
                    break;
                case TString:
                    std::copy(file.data() + pc, file.data() + pc + 8,
                              parameters.back().string);
                    pc += sizeof(SCMByte) * 8;
                    break;
                case TFloat16:
                    parameters.back().real =
                        file.read<std::int16_t>(pc) / 16.f;
                    pc += sizeof(SCMByte) * 2;
                    break;
                default:
                    throw UnknownType(type, pc, t.name);
                    break;
            };
        }

        ScriptArguments sca(&parameters, &t, this);

#if RW_SCRIPT_DEBUG
        static auto sDebugThreadName = getenv("OPENRW_DEBUG_THREAD");
        if (!sDebugThreadName || strncmp(t.name, sDebugThreadName, 8) == 0) {
            printf("%8s %01x %06x %04x %s", t.name, t.conditionResult,
                   t.programCounter, opcode, code.signature.c_str());
            for (auto& a : sca.getParameters()) {
                if (a.type == SCMType::TString) {
                    printf(" %1x:'%s'", a.type, a.string);
                } else if (a.type == SCMType::TFloat16) {
                    printf(" %1x:%f", a.type, a.realValue());
                } else {
                    printf(" %1x:%d", a.type, a.integerValue());
                }
            }
            printf("\n");
        }
#endif

        // After debugging has been completed, update the program counter
        t.programCounter = pc;

        if (code.function) {
            code.function(sca);
        }

        if (isNegatedConditional) {
            t.conditionResult = !t.conditionResult;
        }

        // Handle conditional results for IF statements.
        if (t.conditionCount > 0 && opcode != 0x00D6)  /// @todo add conditional
                                                       /// flag to opcodes
                                                       /// instead of checking
                                                       /// for 0x00D6
        {
            --t.conditionCount;
            if (t.conditionAND) {
                if (t.conditionResult == false) {
                    t.conditionMask = 0;
                } else {
                    // t.conditionMask is already set to 0xFF by the if and
                    // opcode.
                }
            } else {
                t.conditionMask = t.conditionMask || t.conditionResult;
            }

            t.conditionResult = (t.conditionMask != 0);
        }
    }

    SCMOpcodeParameter p;
    p.globalPtr = (t.locals.data() + 16 * sizeof(SCMByte) * 4);
    *p.globalInteger += msPassed;
    p.globalPtr = (t.locals.data() + 17 * sizeof(SCMByte) * 4);
    *p.globalInteger += msPassed;

    if (t.wakeCounter == -1) {
        t.wakeCounter = 0;
    }
}

ScriptMachine::ScriptMachine(GameState* _state, SCMFile& file,
                             ScriptModule* ops)
    : file(file)
    , module(ops)
    , state(_state)
    , debugFlag(false) {
    // Copy globals
    auto size = file.getGlobalsSize();
    globalData.resize(size);
    auto offset = file.getGlobalSection();
    std::copy(file.data() + offset, file.data() + offset + size,
              globalData.begin());
}

void ScriptMachine::startThread(SCMThread::pc_t start, bool mission) {
    SCMThread t;
    for (int i = 0; i < SCM_THREAD_LOCAL_SIZE * SCM_VARIABLE_SIZE; ++i) {
        t.locals[i] = 0;
    }
    strncpy(t.name, "THREAD", 16);
    t.conditionResult = false;
    t.conditionCount = 0;
    t.conditionAND = false;
    t.programCounter = start;
    t.baseAddress = start; /* Indicates where negative jumps should jump from */
    t.wakeCounter = 0;
    t.isMission = mission;
    t.finished = false;
    t.stackDepth = 0;
    t.deathOrArrestCheck = true;
    t.wastedOrBusted = false;
    t.allowWaitSkip = false;
    _activeThreads.push_back(t);
}

SCMByte* ScriptMachine::getGlobals() {
    return globalData.data();
}

void ScriptMachine::execute(float dt) {
    RW_PROFILE_SCOPEC(__func__, MP_ORANGERED);
    int ms = static_cast<int>(dt * 1000.f);
    for (auto t = _activeThreads.begin(); t != _activeThreads.end(); ++t) {
        auto& thread = *t;
        executeThread(thread, ms);

        if (thread.finished) {
            t = _activeThreads.erase(t);
        }
    }

    // Periodic opcode-usage flush: writing to opcode_usage.txt every
    // kProfileDumpIntervalSec means a SIGKILL only loses the last interval.
    profileAccumulator += dt;
    if (profileAccumulator >= kProfileDumpIntervalSec) {
        profileAccumulator = 0.f;
        dumpOpcodeUsage(false);
    }
}

ScriptMachine::~ScriptMachine() {
    // Final complete dump on clean exit. Overwrites the last periodic snapshot.
    dumpOpcodeUsage(true);
}

void ScriptMachine::dumpOpcodeUsage(bool finalDump) const {
    // Written to the game's working directory (cwd at launch).
    // Periodic dumps overwrite this file; a SIGKILL leaves the last snapshot.
    const char* path = "opcode_usage.txt";
    std::ofstream out(path);
    if (!out.is_open()) {
        return;
    }

    const auto& unimpl = script::unimplementedOpcodes();

    // Sort by call count, descending.
    std::vector<std::pair<uint16_t, uint64_t>> sorted(
        opcodeCallCounts.begin(), opcodeCallCounts.end());
    std::sort(sorted.begin(), sorted.end(),
              [](const auto& a, const auto& b) { return a.second > b.second; });

    uint64_t totalCalls = 0;
    uint64_t unimplCalls = 0;
    for (const auto& kv : sorted) {
        totalCalls += kv.second;
        if (unimpl.count(kv.first)) unimplCalls += kv.second;
    }

    out << "# Opcode usage profile"
        << (finalDump ? " (final, on exit)" : " (periodic snapshot)")
        << "\n";
    out << "# distinct opcodes executed: " << sorted.size() << " / 904\n";
    out << "# total opcode dispatches:  " << totalCalls << "\n";
    out << "# unimplemented dispatches:  " << unimplCalls << " ("
        << (totalCalls ? 100 * unimplCalls / totalCalls : 0) << "% of total)\n";
    out << "# file overwritten on each dump; safe to read mid-run.\n\n";
    out << "rank  opcode   status    calls         %total\n";
    out << "----  ------   -------   ------------  -------\n";

    int rank = 1;
    for (const auto& kv : sorted) {
        bool isUnimpl = unimpl.count(kv.first) != 0;
        out << std::setw(4) << rank++ << "  0x" << std::hex
            << std::setw(4) << std::setfill('0') << kv.first << std::dec
            << std::setfill(' ') << "  "
            << (isUnimpl ? "UNIMPL" : "impl  ") << "  " << std::setw(12)
            << kv.second << "  " << std::setw(6) << std::fixed
            << std::setprecision(2)
            << (totalCalls ? 100.0 * kv.second / totalCalls : 0.0) << "%\n";
    }
}
