/**
    @brief NOP

    opcode 0000
*/
void opcode_0000(const ScriptArguments& args) {
    // Does nothing.
    RW_UNUSED(args);
}

/**
    @brief abs_var_int %1d%

    opcode 0094
    @arg arg1G 
*/
void opcode_0094(const ScriptArguments& args, ScriptInt& arg1G) {
    arg1G = std::abs(arg1G);
    RW_UNUSED(args);
}

/**
    @brief abs_lvar_int %1d%

    opcode 0095
    @arg arg1L 
*/
void opcode_0095(const ScriptArguments& args, ScriptInt& arg1L) {
    arg1L = std::abs(arg1L);
    RW_UNUSED(args);
}

/**
    @brief abs_var_float %1d%

    opcode 0096
    @arg arg1G 
*/
void opcode_0096(const ScriptArguments& args, ScriptFloat& arg1G) {
    arg1G = std::abs(arg1G);
    RW_UNUSED(args);
}

/**
    @brief abs_lvar_float %1d%

    opcode 0097
    @arg arg1L 
*/
void opcode_0097(const ScriptArguments& args, ScriptFloat& arg1L) {
    arg1L = std::abs(arg1L);
    RW_UNUSED(args);
}

/**
    @brief   is_button_pressed %1d% button %2d%

    opcode 00e1
    @arg player Player
    @arg buttonID Button ID
*/
bool opcode_00e1(const ScriptArguments& args, const ScriptPad player,
                 const ScriptButton buttonID) {
    RW_UNIMPLEMENTED_OPCODE(0x00e1);
    // Hack: not implemented correctly.
    if (player == 0) {
        if (buttonID == 12) {  // not implemented correctly
            return args.getState()->input[0].pressed(
                GameInputState::Jump);
        }
        if (buttonID == 16) {  // not implemented correctly
            return args.getState()->input[0].pressed(
                GameInputState::Jump);
        }
        if (buttonID == 19) {  // Look behind / sub mission
            return args.getState()->input[0].pressed(
                GameInputState::Submission);
        }
    }
    return false;
}

/**
    @brief play_sound %4d% at %1d% %2d% %3d%

    opcode 018c
    @arg coord Coordinates
    @arg sound 
*/
void opcode_018c(const ScriptArguments& args, ScriptVec3 coord, const ScriptSoundType sound) {
    auto world = args.getWorld();
    auto metaData = getSoundInstanceData(sound);
    auto name = world->sound.createSfxInstance(metaData->sfx);
    world->sound.playSfx(name, coord, false, metaData->range);
}

/**
    @brief stop_sound %1d%

    opcode 018e
    @arg sound 
*/
void opcode_018e(const ScriptArguments& args, const ScriptSound sound) {
    RW_UNUSED(args);
    sound->stop();
}

/**
    @brief add_route_point %1d% at %2d% %3d% %4d%

    opcode 01e2
    @arg arg1 
    @arg arg2 
    @arg arg3 
    @arg arg4 
*/
void opcode_01e2(const ScriptArguments& args, const ScriptInt arg1, const ScriptFloat arg2, const ScriptFloat arg3, const ScriptFloat arg4) {
    RW_UNIMPLEMENTED_OPCODE(0x01e2);
    RW_UNUSED(arg1);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(args);
}

/**
    @brief set_gang %1h% models_to %2o% %3o%

    opcode 0235
    @arg gangID Gang ID
    @arg model0 Model ID
    @arg model1 Model ID
*/
void opcode_0235(const ScriptArguments& args, const ScriptGang gangID, const ScriptModelID model0, const ScriptModelID model1) {
    RW_UNIMPLEMENTED_OPCODE(0x0235);
    RW_UNUSED(gangID);
    RW_UNUSED(model0);
    RW_UNUSED(model1);
    RW_UNUSED(args);
}

/**
    @brief request_model %1o%

    opcode 0247
    @arg model Model ID
*/
void opcode_0247(const ScriptArguments& args, const ScriptModel model) {
    RW_UNIMPLEMENTED_OPCODE(0x0247);
    RW_UNUSED(model);
    RW_UNUSED(args);
}

/**
    @brief   model %1o% available

    opcode 0248
    @arg model Model ID
*/
bool opcode_0248(const ScriptArguments& args, const ScriptModel model) {
    RW_UNIMPLEMENTED_OPCODE(0x0248);
    RW_UNUSED(model);
    RW_UNUSED(args);
    return true;
}

/**
    @brief release_model %1o%

    opcode 0249
    @arg model Model ID
*/
void opcode_0249(const ScriptArguments& args, const ScriptModel model) {
    RW_UNIMPLEMENTED_OPCODE(0x0249);
    RW_UNUSED(model);
    RW_UNUSED(args);
}

/**
    @brief create_corona %4d% %5d% %6d% with_color %7d% %8d% %9d% at_point %1d% %2d% %3d%

    opcode 024f
    @arg coord Coordinates
    @arg radius Radius
    @arg arg5 
    @arg arg6 Boolean true/false
    @arg colour Colour (0-255)
*/
void opcode_024f(const ScriptArguments& args, ScriptVec3 coord, const ScriptFloat radius, const ScriptCoronaType arg5, const ScriptBoolean arg6, ScriptRGB colour) {
    RW_UNIMPLEMENTED_OPCODE(0x024f);
    RW_UNUSED(coord);
    RW_UNUSED(radius);
    RW_UNUSED(arg5);
    RW_UNUSED(arg6);
    RW_UNUSED(colour);
    RW_UNUSED(args);
}

/**
    @brief create_donkey_mags %1d%

    opcode 02c3
    @arg unused
*/
void opcode_02c3(const ScriptArguments& args, const ScriptInt unused) {
    RW_UNUSED(unused);
    args.getState()->bigNVeinyPickupsCollected = 0;

    for (auto& pos : BigNVeinyPickup::getBigNVeinyPickupsLocations()) {
        args.getWorld()->createPickup(
            pos, args.getWorld()->data->findModelObject("donkeymag"),
            PickupObject::PickupType::OnStreet);
    }
}

/**
    @brief   is_object_on_screen %1d% 

    opcode 02cc
    @arg object Object
*/
bool opcode_02cc(const ScriptArguments& args, const ScriptObject object) {
    RW_UNIMPLEMENTED_OPCODE(0x02cc);
    RW_UNUSED(object);
    RW_UNUSED(args);
    return false;
}

/**
    @brief    had_object_been_damaged %1d%

    opcode 0366
    @arg object Object
*/
bool opcode_0366(const ScriptArguments& args, const ScriptObject object) {
    RW_UNIMPLEMENTED_OPCODE(0x0366);
    RW_UNUSED(object);
    RW_UNUSED(args);
    return false;
}

/**
    @brief load_all_models_now

    opcode 038b
*/
void opcode_038b(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x038b);
    RW_UNUSED(args);
}

/**
    @brief load_txd_dictionary %1h% 

    opcode 0390
    @arg arg1 
*/
void opcode_0390(const ScriptArguments& args, const ScriptString arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x0390);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief unknown_clear_point %1d% %2d% %3d% radius %4d%

    opcode 03a1
    @arg coord Coordinates
    @arg radius Radius
*/
void opcode_03a1(const ScriptArguments& args, ScriptVec3 coord, const ScriptFloat radius) {
    RW_UNIMPLEMENTED_OPCODE(0x03a1);
    RW_UNUSED(coord);
    RW_UNUSED(radius);
    RW_UNUSED(args);
}

/**
    @brief replace_model_at %1d% %2d% %3d% radius %4d% from %5o% to %6o%

    opcode 03b6
    @arg coord Coordinates
    @arg radius Radius
    @arg model0 Model ID
    @arg model1 Model ID
*/
void opcode_03b6(const ScriptArguments& args, ScriptVec3 coord, const ScriptFloat radius, const ScriptModel model0, const ScriptModel model1) {
    if( std::abs(model0) > 178 || std::abs(model1) > 178 ) {
    	/// @todo implement this path, move model code into ScriptArguments
    	return;
    }

    int name0 = std::abs(model0);
    int name1 = std::abs(model1);

    auto oldmodel = args.getVM()->getFile().getModels()[name0];
    auto newmodel = args.getVM()->getFile().getModels()[name1];
    std::transform(newmodel.begin(), newmodel.end(), newmodel.begin(), ::tolower);
    std::transform(oldmodel.begin(), oldmodel.end(), oldmodel.begin(), ::tolower);

    auto newobjectid = args.getWorld()->data->findModelObject(newmodel);
    auto nobj = args.getWorld()->data->findModelInfo<SimpleModelInfo>(newobjectid);

    for(auto& p : args.getWorld()->instancePool.objects) {
        auto o = p.second.get();
    	if( !o->getClump() ) continue;
    	if( o->getModelInfo<BaseModelInfo>()->name != oldmodel ) continue;
    	float d = glm::distance(coord, o->getPosition());
    	if( d < radius ) {
    		InstanceObject* inst = static_cast<InstanceObject*>(o);
    		inst->changeModel(nobj);
    	}
    }
}

/**
    @brief load_scene %1d% %2d% %3d%

    opcode 03cb
    @arg coord Coordinates
*/
void opcode_03cb(const ScriptArguments& args, ScriptVec3 coord) {
    RW_UNIMPLEMENTED_OPCODE(0x03cb);
    RW_UNUSED(coord);
    RW_UNUSED(args);
}

/**
    @brief load_wav %1s%

    opcode 03cf
    @arg soundID Sound ID
*/
void opcode_03cf(const ScriptArguments& args, const ScriptString soundID) {
    auto name = std::string(soundID);
    std::transform(name.begin(), name.end(), name.begin(), ::tolower);
    if (! args.getWorld()->data->loadAudioClip(name, name + ".wav")) {
    	if (! args.getWorld()->data->loadAudioClip(name, name + ".mp3")) {
    		args.getWorld()->logger->error("SCM", "Failed to load audio: " + name);
    	}
    }
}

/**
    @brief   wav_loaded

    opcode 03d0
*/
bool opcode_03d0(const ScriptArguments& args) {
    auto world = args.getWorld();
    return world->sound.isLoaded(world->missionAudio);
}

/**
    @brief play_wav

    opcode 03d1
*/
void opcode_03d1(const ScriptArguments& args) {
    auto world = args.getWorld();
    if (world->missionAudio.length() > 0) {
    	world->sound.playSound(world->missionAudio);
    }
}

/**
    @brief   wav_ended

    opcode 03d2
*/
bool opcode_03d2(const ScriptArguments& args) {
    auto world = args.getWorld();
    bool isFinished = ! world->sound.isPlaying(world->missionAudio);

    if (isFinished) {
    	world->missionAudio = "";
    }

    return isFinished;
}

/**
    @brief show_save_screen

    opcode 03d8
*/
void opcode_03d8(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x03d8);
    RW_UNUSED(args);
}

/**
    @brief   save_done

    opcode 03d9
*/
bool opcode_03d9(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x03d9);
    RW_UNUSED(args);
    return true;
}

/**
    @brief save_turismo_time %1d%

    opcode 03e2
    @arg time 
*/
void opcode_03e2(const ScriptArguments& args, const ScriptInt time) {
    if (args.getState()->gameStats.bestTurismoTime > time) {
        args.getState()->gameStats.bestTurismoTime = time;
    }
}

/**
    @brief load_island_data %1d%

    opcode 03f7
    @arg arg1 
*/
void opcode_03f7(const ScriptArguments& args, const ScriptLevel arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x03f7);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief save_offroad_time %1d%

    opcode 03fd
    @arg newTime 
*/
void opcode_03fd(const ScriptArguments& args, const ScriptInt newTime) {
    if (args.getState()->gameStats.patriotPlaygroundTime > newTime) {
        args.getState()->gameStats.patriotPlaygroundTime = newTime;
    }
}

/**
    @brief save_offroadII_time %1d%

    opcode 03fe
    @arg newTime 
*/
void opcode_03fe(const ScriptArguments& args, const ScriptInt newTime) {
    if (args.getState()->gameStats.aRideInTheParkTime > newTime) {
        args.getState()->gameStats.aRideInTheParkTime = newTime;
    }
}

/**
    @brief save_offroadIII_time %1d%

    opcode 03ff
    @arg newTime 
*/
void opcode_03ff(const ScriptArguments& args, const ScriptInt newTime) {
    if (args.getState()->gameStats.grippedTime > newTime) {
        args.getState()->gameStats.grippedTime = newTime;
    }
}

/**
    @brief save_mayhem_time %1d%

    opcode 0400
    @arg newTime
*/
void opcode_0400(const ScriptArguments& args, const ScriptInt newTime) {
    if (args.getState()->gameStats.multistoryMayhemTime > newTime) {
        args.getState()->gameStats.multistoryMayhemTime = newTime;
    }
}

/**
    @brief increment_people_saved_in_ambulance

    opcode 0401
*/
void opcode_0401(const ScriptArguments& args) {
    args.getState()->gameStats.peopleSaved++;
}

/**
    @brief save_highest_ambulance_level %1d%

    opcode 0403
    @arg level 
*/
void opcode_0403(const ScriptArguments& args, const ScriptInt level) {
    if (args.getState()->gameStats.highestParamedicLevel < level) {
        args.getState()->gameStats.highestParamedicLevel = level;
    }
}

/**
    @brief override_gang_model %1d% %2d%

    opcode 0410
    @arg arg1 
    @arg model Model ID
*/
void opcode_0410(const ScriptArguments& args, const ScriptGang arg1, const ScriptInt model) {
    RW_UNIMPLEMENTED_OPCODE(0x0410);
    RW_UNUSED(arg1);
    RW_UNUSED(model);
    RW_UNUSED(args);
}

/**
    @brief 

    opcode 0412
    @arg vehicle 
    @arg arg2 
*/
void opcode_0412(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptInt arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x0412);
    RW_UNUSED(vehicle);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief 

    opcode 0415
    @arg vehicle 
    @arg arg2 
*/
void opcode_0415(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptDoor arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x0415);
    RW_UNUSED(vehicle);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief set_radio_station %1d% %2d%

    opcode 041e
    @arg arg1 
    @arg arg2 
*/
void opcode_041e(const ScriptArguments& args, const ScriptRadio arg1, const ScriptInt arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x041e);
    RW_UNUSED(arg1);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief override_police_station %1d%

    opcode 0420
    @arg arg1 
*/
void opcode_0420(const ScriptArguments& args, const ScriptLevel arg1) {
    args.getState()->policeIslandOverride = arg1;
}

/**
    @brief register_lowest_int_stat %1h% to %2d%

    opcode 042e
    @arg statID Stat ID
    @arg arg2 
*/
void opcode_042e(const ScriptArguments& args, const ScriptInt statID, const ScriptInt arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x042e);
    RW_UNUSED(statID);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief save_record %1d% %2d%

    opcode 042f
    @arg statID Stat ID
    @arg value 
*/
void opcode_042f(const ScriptArguments& args, const ScriptInt statID, const ScriptInt value) {
    if (args.getState()->gameStats.highestScore[statID] < value) {
        args.getState()->gameStats.highestScore[statID] = value;
    }
}

/**
    @brief create_fire_audio %1d% %2d%

    opcode 0444
    @arg fire Handle
    @arg arg2 Boolean true/false
*/
void opcode_0444(const ScriptArguments& args, const ScriptFire fire, const ScriptBoolean arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x0444);
    RW_UNUSED(fire);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief load_splash %1x%

    opcode 044d
    @arg arg1 
*/
void opcode_044d(const ScriptArguments& args, const ScriptString arg1) {
    args.getWorld()->data->loadSplash(arg1);
}

/**
    @brief load_end_of_game_audio

    opcode 0451
*/
void opcode_0451(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x0451);
    RW_UNUSED(args);
}

/**
    @brief 

    opcode 0455
    @arg arg1 
    @arg arg2 
    @arg arg3 
*/
void opcode_0455(const ScriptArguments& args, ScriptFloat& arg1, ScriptFloat& arg2, ScriptFloat& arg3) {
    RW_UNIMPLEMENTED_OPCODE(0x0455);
    RW_UNUSED(arg1);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(args);
}

/**
    @brief get_joystick %1h% direction_offset_to %2d% %3d% %4d% %5d%

    opcode 0494
*/
void opcode_0494(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x0494);
    RW_UNUSED(args);
}

