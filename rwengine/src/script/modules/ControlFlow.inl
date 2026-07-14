/**
    @brief wait %1d% ms

    opcode 0001
    @arg time Time (ms)
*/
void opcode_0001(const ScriptArguments& args, const ScriptInt time) {
    RW_CHECK(time >= 0, "negative wait time is not supported");
    auto thread = args.getThread();
    // Scripts use wait 0 to yield
    thread->wakeCounter = time > 0 ? time : -1;
}

/**
    @brief goto %1p%

    opcode 0002
    @arg arg1 
*/
void opcode_0002(const ScriptArguments& args, const ScriptLabel arg1) {
    auto thread = args.getThread();
    thread->programCounter = arg1 < 0 ? thread->baseAddress - arg1 : arg1;
}

/**
    @brief goto_if_true %1p%

    opcode 004c
    @arg arg1 
*/
void opcode_004c(const ScriptArguments& args, const ScriptLabel arg1) {
    auto thread = args.getThread();
    if (thread->conditionResult) {
    	thread->programCounter = arg1 < 0 ? thread->baseAddress - arg1 : arg1;
    }
}

/**
    @brief goto_if_false %1p%

    opcode 004d
    @arg arg1 
*/
void opcode_004d(const ScriptArguments& args, const ScriptLabel arg1) {
    auto thread = args.getThread();
    if (! thread->conditionResult) {
    	thread->programCounter = arg1 < 0 ? thread->baseAddress - arg1 : arg1;
    }
}

/**
    @brief end_thread

    opcode 004e
*/
void opcode_004e(const ScriptArguments& args) {
    auto thread = args.getThread();
    thread->wakeCounter = -1;
    thread->finished = true;
}

/**
    @brief create_thread %1p%

    opcode 004f
    @arg arg1 
    @arg arg2 
*/
void opcode_004f(const ScriptArguments& args, const ScriptLabel arg1) {
    args.getVM()->startThread(arg1, false);
    auto& threads = args.getVM()->getThreads();
    SCMThread& thread = threads.back();
    // Copy arguments to locals
    /// @todo prevent overflow
    /// @todo don't do pointer casting
    for (auto i = 1u; i < args.getParameters().size(); ++i) {
    	if (args[i].type == EndOfArgList)
    		break;
    	*reinterpret_cast<ScriptInt*>(thread.locals.data() +
    	                        sizeof(ScriptInt) * (i - 1)) =
    	    args[i].integerValue();
    }
}

/**
    @brief gosub %1p%

    opcode 0050
    @arg arg1 
*/
void opcode_0050(const ScriptArguments& args, const ScriptLabel arg1) {
    auto thread = args.getThread();
    thread->calls[thread->stackDepth++] = thread->programCounter;
    thread->programCounter = arg1 < 0 ? thread->baseAddress - arg1 : arg1;
}

/**
    @brief return

    opcode 0051
*/
void opcode_0051(const ScriptArguments& args) {
    auto thread = args.getThread();
    thread->programCounter = thread->calls[--thread->stackDepth];
}

/**
    @brief car_goto_coordinates %1d% coords %2d% %3d% %4d%

    opcode 00a7
    @arg vehicle Car/vehicle
    @arg coord Coordinates
*/
void opcode_00a7(const ScriptArguments& args, const ScriptVehicle vehicle, ScriptVec3 coord) {
    RW_UNIMPLEMENTED_OPCODE(0x00a7);
    RW_UNUSED(vehicle);
    RW_UNUSED(coord);
    RW_UNUSED(args);
}

/**
    @brief set_car_mission %1d% to %2d%

    opcode 00af
    @arg vehicle Character/ped
    @arg arg2 
*/
void opcode_00af(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptMission arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x00af);
    RW_UNUSED(vehicle);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief debug_on

    opcode 00c3
*/
void opcode_00c3(const ScriptArguments& args) {
    args.getVM()->setDebugFlag(true);

}

/**
    @brief debug_off

    opcode 00c4
*/
void opcode_00c4(const ScriptArguments& args) {
    args.getVM()->setDebugFlag(false);
}

/**
    @brief return_true

    opcode 00c5
*/
bool opcode_00c5(const ScriptArguments& args) {
    RW_UNUSED(args);
    return true;
}

/**
    @brief return_false

    opcode 00c6
*/
bool opcode_00c6(const ScriptArguments& args) {
    RW_UNUSED(args);
    return false;
}

/**
    @brief if %1d%

    opcode 00d6
    @arg arg1 
*/
void opcode_00d6(const ScriptArguments& args, const ScriptInt arg1) {
    if (arg1 <= 7) {
    	args.getThread()->conditionCount = arg1+1;
    	args.getThread()->conditionMask = 0xFF;
    	args.getThread()->conditionAND = true;
    }
    else {
    	args.getThread()->conditionCount = arg1-19;
    	args.getThread()->conditionMask = 0x00;
    	args.getThread()->conditionAND = false;
    }
}

/**
    @brief create_thread_without_extra_params %1p%

    opcode 00d7
    @arg arg1 
*/
void opcode_00d7(const ScriptArguments& args, const ScriptLabel arg1) {
    args.getVM()->startThread(arg1, true);
}

/**
    @brief mission_has_finished

    opcode 00d8
*/
void opcode_00d8(const ScriptArguments& args) {
    if (args.getThread()->isMission) {
        auto& missionObjects = args.getState()->missionObjects;
        for (auto object : missionObjects) {
            /// @todo: there's more logic than only changing life time, or maybe it should be done in cleanUpTraffic
            object->setLifetime(GameObject::TrafficLifetime);
        }
        missionObjects.clear();
    }

    auto player = args.getWorld()->getPlayer();
    player->freeFromCutscene();
}

/**
    @brief   has_deatharrest_been_executed

    opcode 0112
*/
bool opcode_0112(const ScriptArguments& args) {
    return args.getThread()->wastedOrBusted;
}

/**
    @brief declare_mission_flag %1d%

    opcode 0180
    @arg arg1G 
*/
void opcode_0180(const ScriptArguments& args, ScriptInt& arg1G) {
    args.getState()->scriptOnMissionFlag = &arg1G;
}

/**
    @brief declare_mission_flag_for_contact %1d% as %2d%

    opcode 0181
    @arg arg1 
    @arg arg2G 
*/
void opcode_0181(const ScriptArguments& args, const ScriptContact arg1, ScriptInt& arg2G) {
    auto& c = args.getState()->scriptContacts.at(arg1);
    c.onMissionOffset = args.getVM()->getGlobalOffset(arg2G);
}

/**
    @brief remove_actor_from_mission_cleanup_list %1d%

    opcode 01c5
    @arg character Character/ped
*/
void opcode_01c5(const ScriptArguments& args, const ScriptCharacter character) {
    script::removeObjectFromMissionCleanup(args, character);
}

/**
    @brief remove_car_from_mission_cleanup_list %1d%

    opcode 01c6
    @arg vehicle Car/vehicle
*/
void opcode_01c6(const ScriptArguments& args, const ScriptVehicle vehicle) {
    script::removeObjectFromMissionCleanup(args, vehicle);
}

/**
    @brief remove_object_from_mission_cleanup_list %1d%

    opcode 01c7
    @arg object Object
*/
void opcode_01c7(const ScriptArguments& args, const ScriptObject object) {
    script::removeObjectFromMissionCleanup(args, object);
}

/**
    @brief set_critical_mission_restart_at %1d% %2d% %3d% angle %4d%

    opcode 0255
    @arg coord Coordinates
    @arg angle Angle
*/
void opcode_0255(const ScriptArguments& args, ScriptVec3 coord, const ScriptFloat heading) {
    coord = script::getGround(args, coord);
    args.getState()->overrideRestart(glm::vec4(coord, heading));
    auto player = args.getWorld()->getPlayer();
    player->requestMissionRestart();
}

/**
    @brief skippable_wait

    opcode 02a1
    @arg time 
    @arg waitSkip 
*/
void opcode_02a1(const ScriptArguments& args, const ScriptInt time, const ScriptBoolean waitSkip) {
    RW_CHECK(time >= 0, "negative wait time is not supported");
    auto thread = args.getThread();
    // Scripts use wait 0 to yield
    thread->wakeCounter = time > 0 ? time : -1;
    thread->allowWaitSkip = waitSkip;
}

/**
    @brief call %1p% %2p%

    opcode 02cd

    Branches to a subroutine

    @arg pc Position in the script it will jump to
    @arg unused Not used 
*/
void opcode_02cd(const ScriptArguments& args, const ScriptLabel pc, const ScriptLabel unused) {
    RW_UNUSED(unused);
    auto thread = args.getThread();
    thread->calls[thread->stackDepth++] = thread->programCounter;
    thread->programCounter = pc;
}

/**
    @brief restore_camera_jumpcut

    opcode 02eb
*/
void opcode_02eb(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x02eb);
    args.getWorld()->state->cameraTarget = 0;
    args.getWorld()->state->cameraFixed = false;
}

/**
    @brief set_mission_points += %1d%

    opcode 030c
    @arg progress 
*/
void opcode_030c(const ScriptArguments& args, const ScriptInt progress) {
    args.getState()->currentProgress += progress;
}

/**
    @brief set_total_mission_points_to %1d%

    opcode 030d
    @arg progress 
*/
void opcode_030d(const ScriptArguments& args, const ScriptInt progress) {
    args.getState()->maxProgress = progress;
}

/**
    @brief save_jump_distance %1d%

    opcode 030e
    @arg distance 
*/
void opcode_030e(const ScriptArguments& args, const ScriptFloat distance) {
    if (args.getWorld()->state->gameStats.insaneJumpMaxDistance < distance) {
        args.getWorld()->state->gameStats.insaneJumpMaxDistance = distance;
    }
}

/**
    @brief save_jump_height %1d%

    opcode 030f
    @arg height 
*/
void opcode_030f(const ScriptArguments& args, const ScriptFloat height) {
    if (args.getWorld()->state->gameStats.insaneJumpMaxHeight < height) {
        args.getWorld()->state->gameStats.insaneJumpMaxHeight = height;
    }
}

/**
    @brief save_jump_flips %1d%

    opcode 0310
    @arg flips 
*/
void opcode_0310(const ScriptArguments& args, const ScriptInt flips) {
    if (args.getWorld()->state->gameStats.insaneJumpMaxFlips < flips) {
        args.getWorld()->state->gameStats.insaneJumpMaxFlips = flips;
    }
}

/**
    @brief save_jump_rotation %1d%

    opcode 0311
    @arg rotation 
*/
void opcode_0311(const ScriptArguments& args, const ScriptInt rotation) {
    if (args.getWorld()->state->gameStats.insaneJumpMaxRotation < rotation) {
        args.getWorld()->state->gameStats.insaneJumpMaxRotation = rotation;
    }
}

/**
    @brief save_jump_type %1d%

    opcode 0312
    @arg best 
*/
void opcode_0312(const ScriptArguments& args, const ScriptInt best) {
    if (args.getWorld()->state->gameStats.bestStunt < best) {
        args.getWorld()->state->gameStats.bestStunt = best;
    }
}

/**
    @brief increment_unique_jumps_found

    opcode 0313
*/
void opcode_0313(const ScriptArguments& args) {
    args.getState()->gameStats.uniqueStuntsFound++;
}

/**
    @brief set_total_unique_jumps_to %1d%

    opcode 0314
    @arg stunts 
*/
void opcode_0314(const ScriptArguments& args, const ScriptInt stunts) {
    args.getState()->gameStats.uniqueStuntsTotal = stunts;
}

/**
    @brief increment_mission_attempts

    opcode 0317
*/
void opcode_0317(const ScriptArguments& args) {
    args.getState()->gameStats.missionAttempts++;
}

/**
    @brief set_latest_mission_passed %1g%

    opcode 0318
    @arg gxtEntry GXT entry
*/
void opcode_0318(const ScriptArguments& args, const ScriptString gxtEntry) {
    args.getState()->lastMissionName = gxtEntry;
}

/**
    @brief   gore_enabled

    opcode 0351
*/
bool opcode_0351(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x0351);
    RW_UNUSED(args);
    return false;
}

/**
    @brief set_actor %1d% anim %2d% wait_state_time %3d% ms

    opcode 0372
    @arg character Character/ped
    @arg arg2 
    @arg time Time (ms)
*/
void opcode_0372(const ScriptArguments& args, const ScriptCharacter character, const ScriptWaitState arg2, const ScriptInt time) {
    RW_UNIMPLEMENTED_OPCODE(0x0372);
    RW_UNUSED(character);
    RW_UNUSED(arg2);
    RW_UNUSED(time);
    RW_UNUSED(args);
}

/**
    @brief play_mission_passed_music %1d%

    opcode 0394
    @arg arg1 
*/
void opcode_0394(const ScriptArguments& args, const ScriptInt arg1) {
    RW_UNUSED(arg1);
    RW_UNIMPLEMENTED("should be play mission passed tune");
    GameWorld* gw = args.getWorld();
    std::string name = "Miscom";

    // TODO play anything other than Miscom.wav
    if (! gw->data->loadAudioClip( name, name + ".wav" ))
    {
    	args.getWorld()->logger->error("SCM", "Error loading audio " + name);
    	return;
    }
    else if (args.getWorld()->missionAudio.length() > 0)
    {
    	args.getWorld()->sound.playSound(args.getWorld()->missionAudio);
    }
}

/**
    @brief name_thread %1s%

    opcode 03a4
    @arg name Set script name
*/
void opcode_03a4(const ScriptArguments& args, const ScriptString name) {
    auto thread = args.getThread();
    strncpy(thread->name, name, 8);
}

/**
    @brief set_streaming %1b:enabled/disabled%

    opcode 03af
    @arg arg1 Boolean true/false
*/
void opcode_03af(const ScriptArguments& args, const ScriptBoolean arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x03af);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief set_timer_with_text_to %1d% type %2h% text %3g%

    opcode 03c3
    @arg arg1G Global timer storage
    @arg arg2 
    @arg gxtEntry GXT entry
*/
void opcode_03c3(const ScriptArguments& args, ScriptInt& arg1G, const ScriptTimer arg2, const ScriptString gxtEntry) {
    RW_UNIMPLEMENTED_OPCODE(0x03c3);
    RW_UNUSED(arg1G);
    RW_UNUSED(arg2);
    RW_UNUSED(gxtEntry);
    RW_UNUSED(args);
}

/**
    @brief set_sprites_draw_before_fade %1h%

    opcode 03e3
    @arg arg1 Boolean true/false
*/
void opcode_03e3(const ScriptArguments& args, const ScriptBoolean arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x03e3);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief time_taken_defuse_mission = %1d%

    opcode 0407
    @arg newTime
*/
void opcode_0407(const ScriptArguments& args, const ScriptInt newTime) {
    if (args.getState()->gameStats.bombDefusalTime > newTime) {
        args.getState()->gameStats.bombDefusalTime = newTime;
    }
}

/**
    @brief   is_french_game

    opcode 040b
*/
bool opcode_040b(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x040b);
    RW_UNUSED(args);
    return false;
}

/**
    @brief   is_german_game

    opcode 040c
*/
bool opcode_040c(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x040c);
    RW_UNUSED(args);
    return false;
}

/**
    @brief clear_mission_audio

    opcode 040d
*/
void opcode_040d(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x040d);
    RW_UNUSED(args);
}

/**
    @brief start_mission %1d%

    opcode 0417
    @arg arg1 
*/
void opcode_0417(const ScriptArguments& args, const ScriptInt arg1) {
    auto offset = args.getVM()->getFile().getMissionOffsets()[arg1];
    args.getVM()->startThread(offset, true);
}

/**
    @brief   metric

    opcode 0424
*/
bool opcode_0424(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x0424);
    RW_UNUSED(args);
    return false;
}

/**
    @brief set_total_missions_to %1d%

    opcode 042c
    @arg arg1 
*/
void opcode_042c(const ScriptArguments& args, const ScriptInt arg1) {
    auto state = args.getWorld()->state;
    state->gameStats.totalMissions = arg1;
}

/**
    @brief set_intro_is_playing %1d%

    opcode 043d
    @arg arg1 
*/
void opcode_043d(const ScriptArguments& args, const ScriptInt arg1) {
    args.getState()->isIntroPlaying = arg1;
}

/**
    @brief end_threads_named %1s%

    opcode 0459
    @arg arg1 
*/
void opcode_0459(const ScriptArguments& args, const ScriptString arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x0459);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

