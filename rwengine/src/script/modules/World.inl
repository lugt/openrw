/**
    @brief get_time_of_day %1d% %2d%

    opcode 00bf
    @arg hour
    @arg minute
*/
void opcode_00bf(const ScriptArguments& args, ScriptInt& hour, ScriptInt& minute) {
    hour = args.getWorld()->getHour();
    minute = args.getWorld()->getMinute();
}

/**
    @brief set_current_time %1d% %2d%

    opcode 00c0
    @arg hour
    @arg minute
*/
void opcode_00c0(const ScriptArguments& args, const ScriptInt hour, const ScriptInt minute) {
    /// @todo game set time
    args.getWorld()->state->basic.gameHour = hour;
    args.getWorld()->state->basic.gameMinute = minute;
}

/**
    @brief   is_point_on_screen %1d% %2d% %3d% %4d%

    opcode 00c2
    @arg coord Coordinates
    @arg radius Radius
*/
bool opcode_00c2(const ScriptArguments& args, ScriptVec3 coord, const ScriptFloat radius) {
    RW_UNIMPLEMENTED_OPCODE(0x00c2);
    RW_UNUSED(coord);
    RW_UNUSED(radius);
    RW_UNUSED(args);
    return false;
}

/**
    @brief set_zone_gang_info %1s% %2bday/night% %3h% %4h% %5h% %6h% %7h% %8h% %9h% %10h% %11h%

    opcode 015c
    @arg areaName Area name
    @arg arg2 Boolean true/false
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
    @arg arg7 
    @arg arg8 
    @arg arg9 
    @arg arg10 
    @arg arg11 
*/
void opcode_015c(const ScriptArguments& args, const ScriptString areaName, const ScriptBoolean arg2, const ScriptInt arg3, const ScriptInt arg4, const ScriptInt arg5, const ScriptInt arg6, const ScriptInt arg7, const ScriptInt arg8, const ScriptInt arg9, const ScriptInt arg10, const ScriptInt arg11) {
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(arg6);
    RW_UNUSED(arg7);
    RW_UNUSED(arg8);
    RW_UNUSED(arg9);
    RW_UNUSED(arg10);
    RW_UNUSED(arg11);
    auto zone = args.getWorld()->data->findZone(areaName);
    if (zone) {
    	auto density = (zone->gangCarDensityNight);
    	if (arg2) {
    		density = zone->gangCarDensityDay;
    	}
    	auto count = args.getParameters().size();
    	for (auto g = 0u; g < count - 2; ++g) {
    		*density++ = args[g+2].integerValue();
    	}
    }
}

/**
    @brief disable_marker %1d%

    opcode 0164
    @arg blip Blip
*/
void opcode_0164(const ScriptArguments& args, const ScriptBlip blip) {
    RW_CHECK(blip.get(), "Blip is null");
    if (blip) {
    	args.getWorld()->state->removeBlip(blip->id);
    }
}

/**
    @brief set_marker %1d% color_to %2d%

    opcode 0165
    @arg blip Blip
    @arg colour Blip colour
*/
void opcode_0165(const ScriptArguments& args, const ScriptBlip blip, const ScriptBlipColour colour) {
    RW_UNUSED(args);
    blip->colour = colour;
}

/**
    @brief set_marker %1d% brightness_to %2d%

    opcode 0166
    @arg blip Blip
    @arg brightness Blip brightness
*/
void opcode_0166(const ScriptArguments& args, const ScriptBlip blip, const ScriptInt brightness) {
    RW_UNUSED(args);
    blip->brightness = brightness;
}

/**
    @brief show_on_radar %1d% %2d%

    opcode 0168
    @arg blip Blip
    @arg size Blip size
*/
void opcode_0168(const ScriptArguments& args, const ScriptBlip blip, const ScriptInt size) {
    RW_UNUSED(args);
    blip->size = size;
}

/**
    @brief show_on_radar %1d% %2d%

    opcode 018b
    @arg blip Blip
    @arg display Blip display mode
*/
void opcode_018b(const ScriptArguments& args, const ScriptBlip blip, const ScriptBlipDisplay display) {
    RW_UNUSED(args);
    switch (display) {
    default:
    	blip->display = BlipData::Hide;
    	break;
    case 1:
    	blip->display = BlipData::MarkerOnly;
    	break;
    case 2:
    	blip->display = BlipData::RadarOnly;
    	break;
    case 3:
    	blip->display = BlipData::ShowBoth;
    	break;
    }
}

/**
    @brief force_weather %1d%

    opcode 01B5
    @arg weatherID Weather ID
*/
void opcode_01b5(const ScriptArguments& args, const ScriptWeather weatherID) {
    args.getState()->basic.forcedWeather = weatherID;
}

/**
    @brief set_weather %1d%

    opcode 01B6
    @arg weatherID Weather ID
*/
void opcode_01b6(const ScriptArguments& args, const ScriptWeather weatherID) {
    args.getState()->basic.lastWeather = weatherID;
    args.getState()->basic.nextWeather = weatherID;
    args.getState()->basic.forcedWeather = weatherID;
}

/**
    @brief release_weather

    opcode 01b7
*/
void opcode_01b7(const ScriptArguments& args) {
    RW_UNUSED(args);
    args.getState()->basic.forcedWeather = -1;
}

/**
    @brief save_current_time

    opcode 0253
*/
void opcode_0253(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x0253);
    RW_UNUSED(args);
}

/**
    @brief restore_time_of_day

    opcode 0254
*/
void opcode_0254(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x0254);
    RW_UNUSED(args);
}

/**
    @brief activate_garage %1d%

    opcode 0299
    @arg garage 
*/
void opcode_0299(const ScriptArguments& args, const ScriptGarage garage) {
    RW_UNUSED(args);
    garage->activate();
}

/**
    @brief deactivate_garage %1d%

    opcode 02b9
    @arg garage 
*/
void opcode_02b9(const ScriptArguments& args, const ScriptGarage garage) {
    RW_UNUSED(args);
    garage->deactivate();
}

/**
    @brief garage %1d% change_to_type %2d%

    opcode 02fa
    @arg garage0 
    @arg garage1 
*/
void opcode_02fa(const ScriptArguments& args, const ScriptGarage garage, const ScriptGarageType garageType) {
    RW_UNUSED(args);
    garage->type = garageType;
}

/**
    @brief   garage %1d% respray_done

    opcode 0329
    @arg garage Handle
*/
bool opcode_0329(const ScriptArguments& args, const ScriptGarage garage) {
    RW_UNUSED(args);
    return garage->resprayDone;
}

/**
    @brief  explosion_type %1d% in_zone %2z%

    opcode 0357
    @arg explosionID Explosion ID
    @arg areaName Area name
*/
void opcode_0357(const ScriptArguments& args, const ScriptExplosion explosionID, const ScriptString areaName) {
    RW_UNIMPLEMENTED_OPCODE(0x0357);
    RW_UNUSED(explosionID);
    RW_UNUSED(areaName);
    RW_UNUSED(args);
}

/**
    @brief open_garage %1d%

    opcode 0360
    @arg garage 
*/
void opcode_0360(const ScriptArguments& args, const ScriptGarage garage) {
    RW_UNUSED(args);
    garage->open();
}

/**
    @brief close_garage %1d%

    opcode 0361
    @arg garage 
*/
void opcode_0361(const ScriptArguments& args, const ScriptGarage garage) {
    RW_UNUSED(args);
    garage->close();
}

/**
    @brief   is_sniper_bullet_in_area %1d% %2d% %3d% to %4d% %5d% %6d%

    opcode 037e
    @arg coord0 Coordinates
    @arg coord1 Coordinates
*/
bool opcode_037e(const ScriptArguments& args, ScriptVec3 coord0, ScriptVec3 coord1) {
    RW_UNIMPLEMENTED_OPCODE(0x037e);
    RW_UNUSED(coord0);
    RW_UNUSED(coord1);
    RW_UNUSED(args);
    return false;
}

/**
    @brief clear_area %5d% at %1d% %2d% range %3d% %4d%

    opcode 0395
    @arg coord Coordinates
    @arg radius Radius
    @arg clearParticles Boolean true/false
*/
void opcode_0395(const ScriptArguments& args, ScriptVec3 coord, const ScriptFloat radius, const ScriptBoolean clearParticles) {
    coord = script::getGround(args, coord);
    args.getWorld()->clearObjectsWithinArea(coord, radius, clearParticles);
}

/**
    @brief set_garage %1d% type_to %2d% %3d%

    opcode 03a5
    @arg garage0 
    @arg garage1 
    @arg model 
*/
void opcode_03a5(const ScriptArguments& args, const ScriptGarage garage, const ScriptGarageType garageType, const ScriptModelID model) {
    RW_UNUSED(args);
    garage->type = garageType;
    garage->targetModel = model;
    garage->state = GarageState::Closed;
}

/**
    @brief set_wav_location %1d% %2d% %3d%

    opcode 03d7
    @arg coord Coordinates
*/
void opcode_03d7(const ScriptArguments& args, ScriptVec3 coord) {
    auto world = args.getWorld();
    auto& wav = world->sound.getSoundRef(world->missionAudio);
    wav.setPosition(coord);
}

/**
    @brief force_rain %1d%

    opcode 0421
    @arg arg1 Boolean true/false
*/
void opcode_0421(const ScriptArguments& args, const ScriptBoolean arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x0421);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

