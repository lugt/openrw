/**
    @brief get_player_coordinates %1d% store_to %2d% %3d% %4d%

    opcode 0054
    @arg player Player
    @arg xCoord X Coord
    @arg yCoord Y Coord
    @arg zCoord Z Coord
*/
void opcode_0054(const ScriptArguments& args, const ScriptPlayer player, ScriptFloat& xCoord, ScriptFloat& yCoord, ScriptFloat& zCoord) {
    RW_UNUSED(args);
    script::getObjectPosition(player->getCharacter(), xCoord, yCoord, zCoord);
}

/**
    @brief set_player_coordinates %1d% to %2d% %3d% %4d%

    opcode 0055
    @arg player Player
    @arg coord Coordinates
*/
void opcode_0055(const ScriptArguments& args, const ScriptPlayer player, ScriptVec3 coord) {
    player->getCharacter()->setPosition(coord);
    player->getCharacter()->applyOffset();
    script::clearSpaceForObject(args, player->getCharacter());
}

/**
    @brief delete_char %1d%

    opcode 009b
    @arg character Character/ped
*/
void opcode_009b(const ScriptArguments& args, const ScriptCharacter character) {
    script::destroyObject(args, character);
}

/**
    @brief char_wander_dir %1d% to %2d%

    opcode 009c
    @arg character 
    @arg arg2 
*/
void opcode_009c(const ScriptArguments& args, const ScriptCharacter character, const ScriptInt arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x009c);
    RW_UNUSED(character);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief char_wander_range

    opcode 009d
    @arg character 
*/
void opcode_009d(const ScriptArguments& args, const ScriptCharacter character) {
    RW_UNIMPLEMENTED_OPCODE(0x009d);
    RW_UNUSED(character);
    RW_UNUSED(args);
}

/**
    @brief char_follow_path %1d% path %2d% %3d% %4d%

    opcode 009e
    @arg character 
    @arg coord Coordinates
*/
void opcode_009e(const ScriptArguments& args, const ScriptCharacter character, ScriptVec3 coord) {
    RW_UNIMPLEMENTED_OPCODE(0x009e);
    RW_UNUSED(character);
    RW_UNUSED(coord);
    RW_UNUSED(args);
}

/**
    @brief char_set_idle %1d%

    opcode 009f
    @arg character 
*/
void opcode_009f(const ScriptArguments& args, const ScriptCharacter character) {
    RW_UNIMPLEMENTED_OPCODE(0x009f);
    RW_UNUSED(character);
    RW_UNUSED(args);
}

/**
    @brief get_char_coordinates %1d% store_to %2d% %3d% %4d%

    opcode 00a0
    @arg character Character/ped
    @arg xCoord X Coord
    @arg yCoord Y Coord
    @arg zCoord Z Coord
*/
void opcode_00a0(const ScriptArguments& args, const ScriptCharacter character, ScriptFloat& xCoord, ScriptFloat& yCoord, ScriptFloat& zCoord) {
    script::getObjectPosition(character, xCoord, yCoord, zCoord);
    RW_UNUSED(args);
}

/**
    @brief set_char_coordinates %1d% to %2d% %3d% %4d%

    opcode 00a1
    @arg character Character/ped
    @arg coord Coordinates
*/
void opcode_00a1(const ScriptArguments& args, const ScriptCharacter character, ScriptVec3 coord) {
    script::setObjectPosition(character, coord);
    script::clearSpaceForObject(args, character);
}

/**
    @brief   is_char_still_alive %1d%

    opcode 00a2
    @arg character 
*/
bool opcode_00a2(const ScriptArguments& args, const ScriptCharacter character) {
    RW_UNUSED(args);
    if (character) {
    	return character->isAlive();
    }
    return false;
}

/**
    @brief car_set_idle %1d%

    opcode 00a9
    @arg vehicle Car/vehicle
*/
void opcode_00a9(const ScriptArguments& args, const ScriptVehicle vehicle) {
    RW_UNIMPLEMENTED_OPCODE(0x00a9);
    RW_UNUSED(vehicle);
    RW_UNUSED(args);
}

/**
    @brief   is_char_in_car %1d% car %2d%

    opcode 00db
    @arg character Character/ped
    @arg vehicle Car/vehicle
*/
bool opcode_00db(const ScriptArguments& args, const ScriptCharacter character, const ScriptVehicle vehicle) {
    RW_UNUSED(args);
    return (script::getCharacterVehicle(character) == vehicle);
}

/**
    @brief   is_player_in_car %1d% car %2d%

    opcode 00dc
    @arg player 
    @arg vehicle 
*/
bool opcode_00dc(const ScriptArguments& args, const ScriptPlayer player, const ScriptVehicle vehicle) {
    RW_UNUSED(args);
    return (script::getCharacterVehicle(player->getCharacter()) == vehicle);
}

/**
    @brief   is_char_in_model %1d% model %2o%

    opcode 00dd
    @arg character Character/ped
    @arg model Model ID
*/
bool opcode_00dd(const ScriptArguments& args, const ScriptCharacter character, const ScriptModelID model) {
    RW_UNUSED(args);
    return script::isInModel(args, character, model);
}

/**
    @brief   is_player_in_model %1d% model %2t%

    opcode 00de
    @arg player 
    @arg model 
*/
bool opcode_00de(const ScriptArguments& args, const ScriptPlayer player, const ScriptModelID model) {
    return script::isInModel(args, player->getCharacter(), model);
}

/**
    @brief   is_char_in_any_car %1d%

    opcode 00df
    @arg character Character/ped
*/
bool opcode_00df(const ScriptArguments& args, const ScriptCharacter character) {
    RW_UNUSED(args);
    return script::getCharacterVehicle(character) != nullptr;
}

/**
    @brief   is_player_in_any_car %1d%

    opcode 00e0
    @arg player 
*/
bool opcode_00e0(const ScriptArguments& args, const ScriptPlayer player) {
    RW_UNUSED(args);
    return script::getCharacterVehicle(player->getCharacter()) != nullptr;
}

/**
    @brief   actor %1d% near_actor_in_car %2d% radius %3d% %4d% %5h%

    opcode 00f4
    @arg character0 Character/ped
    @arg character1 Character/ped
    @arg radius Radius of goal
    @arg showMarker Show marker (True/False)
*/
bool opcode_00f4(const ScriptArguments& args, const ScriptCharacter character0, const ScriptCharacter character1, ScriptVec2 radius, const ScriptBoolean showMarker) {
    auto condition = character0->getCurrentVehicle() != nullptr;
    /// @todo if characters are in vehicles, game uses vehicle positions instead of character ones
    return script::objectInRadiusNear(args, character0, character1, radius, showMarker, condition);
}

/**
    @brief   actor %1d% near_actor_in_car %2d% radius %3d% %4d% %5d% %6h%

    opcode 0106
    @arg character0 Character/ped
    @arg character1 Character/ped
    @arg radius Radius of goal
    @arg showMarker Show marker (True/False)
*/
bool opcode_0106(const ScriptArguments& args, const ScriptCharacter character0, const ScriptCharacter character1, ScriptVec3 radius, const ScriptBoolean showMarker) {
    auto condition = character0->getCurrentVehicle() != nullptr;
    /// @todo if characters are in vehicles, game uses vehicle positions instead of character ones
    return script::objectInRadiusNear(args, character0, character1, radius, showMarker, condition);
}

/**
    @brief change_player_into_rc_buggy %1d% at %2d% %3d% %4d% %5d%

    opcode 010c
    @arg player Player
    @arg coord Coordinates
    @arg arg5 
*/
void opcode_010c(const ScriptArguments& args, const ScriptPlayer player, ScriptVec3 coord, const ScriptFloat arg5) {
    RW_UNIMPLEMENTED_OPCODE(0x010c);
    RW_UNUSED(player);
    RW_UNUSED(coord);
    RW_UNUSED(arg5);
    RW_UNUSED(args);
}

/**
    @brief set_player %1d% wanted_level_to %2d%

    opcode 010d
    @arg player Player
    @arg arg2 
*/
void opcode_010d(const ScriptArguments& args, const ScriptPlayer player, const ScriptInt arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x010d);
    RW_UNUSED(player);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief set_player %1d% minimum_wanted_level_to %2d%

    opcode 010e
    @arg player Player
    @arg arg2 
*/
void opcode_010e(const ScriptArguments& args, const ScriptPlayer player, const ScriptInt arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x010e);
    RW_UNUSED(player);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief clear_player %1d% wanted_level

    opcode 0110
    @arg player Player
*/
void opcode_0110(const ScriptArguments& args, const ScriptPlayer player) {
    RW_UNIMPLEMENTED_OPCODE(0x0110);
    RW_UNUSED(player);
    RW_UNUSED(args);
}

/**
    @brief set_wasted_busted_check_to %1benabled/disabled%

    opcode 0111
    @arg arg1 Boolean true/false
*/
void opcode_0111(const ScriptArguments& args, const ScriptBoolean arg1) {
    args.getThread()->deathOrArrestCheck = arg1;
}

/**
    @brief add_ammo_to_player %1d% weapon %2h% to %3d%

    opcode 0113
    @arg player Player
    @arg weaponID Weapon ID
    @arg arg3 
*/
void opcode_0113(const ScriptArguments& args, const ScriptPlayer player, const ScriptWeaponType weaponID, const ScriptInt arg3) {
    RW_UNIMPLEMENTED_OPCODE(0x0113);
    RW_UNUSED(player);
    RW_UNUSED(weaponID);
    RW_UNUSED(arg3);
    RW_UNUSED(args);
}

/**
    @brief set_actor %1d% car_weapon %2h% ammo_to %3d%

    opcode 0114
    @arg character Character/ped
    @arg weaponID Weapon ID
    @arg arg3 
*/
void opcode_0114(const ScriptArguments& args, const ScriptCharacter character, const ScriptWeaponType weaponID, const ScriptInt arg3) {
    RW_UNIMPLEMENTED_OPCODE(0x0114);
    RW_UNUSED(character);
    RW_UNUSED(weaponID);
    RW_UNUSED(arg3);
    RW_UNUSED(args);
}

/**
    @brief   player %1d% wasted

    opcode 0117
    @arg player Player
*/
bool opcode_0117(const ScriptArguments& args, const ScriptPlayer player) {
    RW_UNUSED(args);
    return player->isWasted();
}

/**
    @brief   actor %1d% dead

    opcode 0118
    @arg character Character/ped
*/
bool opcode_0118(const ScriptArguments& args, const ScriptCharacter character) {
    RW_UNUSED(args);
    if (character) {
    	return !character->isAlive();
    }
    return true;
}

/**
    @brief set_actor %1d% search_threat %2i%

    opcode 011a
    @arg character 
    @arg arg2 
*/
void opcode_011a(const ScriptArguments& args, const ScriptCharacter character, const ScriptThreat arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x011a);
    RW_UNUSED(character);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief actor %1d% clear_objective

    opcode 011c
    @arg character 
*/
void opcode_011c(const ScriptArguments& args, const ScriptCharacter character) {
    RW_UNIMPLEMENTED_OPCODE(0x011c);
    RW_UNUSED(character);
    RW_UNUSED(args);
}

/**
    @brief   player %1d% in_zone %2z%

    opcode 0121
    @arg player Player
    @arg areaName Area name
*/
bool opcode_0121(const ScriptArguments& args, const ScriptPlayer player, const ScriptString areaName) {
    return script::objectInZone(args, player->getCharacter(), areaName);
}

/**
    @brief   player %1d% pressing_horn

    opcode 0122
    @arg player Player
*/
bool opcode_0122(const ScriptArguments& args, const ScriptPlayer player) {
    RW_UNIMPLEMENTED_OPCODE(0x0122);
    RW_UNUSED(player);
    RW_UNUSED(args);
    return true;
}

/**
    @brief   actor %1d% spotted_player %2d%

    opcode 0123
    @arg character Character/ped
    @arg player Player
*/
bool opcode_0123(const ScriptArguments& args, const ScriptCharacter character, const ScriptPlayer player) {
    RW_UNIMPLEMENTED_OPCODE(0x0123);
    RW_UNUSED(character);
    RW_UNUSED(player);
    RW_UNUSED(args);
    return false;
}

/**
    @brief   actor %1d% walking

    opcode 0126
    @arg character Character/ped
*/
bool opcode_0126(const ScriptArguments& args, const ScriptCharacter character) {
    RW_UNUSED(args);
    /// @todo activity tracking will likely be changed.
    return character->controller->getCurrentActivity() == nullptr;
}

/**
    @brief put_player %1d% at %2d% %3d% %4d% and_remove_from_car

    opcode 012a
    @arg player 
    @arg coord
*/
void opcode_012a(const ScriptArguments& args, const ScriptPlayer player, const ScriptVec3 coord) {
    RW_UNUSED(args);
    auto plyChar = player->getCharacter();
    plyChar->setCurrentVehicle(nullptr, 0);
    plyChar->setPosition(coord);
}

/**
    @brief   player %1d% busted

    opcode 0130
    @arg player Player
*/
bool opcode_0130(const ScriptArguments& args, const ScriptPlayer player) {
    RW_UNIMPLEMENTED_OPCODE(0x0130);
    RW_UNUSED(player);
    RW_UNUSED(args);
    return false;
}

/**
    @brief text_pager %1g% time_per_char %2d% ms unknown_flags %3d% %4d%

    opcode 014d
    @arg arg1 
    @arg arg2 
    @arg arg3 
    @arg arg4 
*/
void opcode_014d(const ScriptArguments& args, const ScriptString arg1, const ScriptInt arg2, const ScriptInt arg3, const ScriptInt arg4) {
    RW_UNIMPLEMENTED_OPCODE(0x014d);
    RW_UNUSED(arg1);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(args);
}

/**
    @brief   actor %1d% in_zone %2z%

    opcode 0154
    @arg character Character/ped
    @arg areaName Area name
*/
bool opcode_0154(const ScriptArguments& args, const ScriptCharacter character, const ScriptString areaName) {
    return script::objectInZone(args, character.get(), areaName);
}

/**
    @brief set_zone_ped_density %1z% %2b:day/night% %3d%

    opcode 0156
    @arg arg1 
    @arg arg2 
    @arg arg3 
*/
void opcode_0156(const ScriptArguments& args, const ScriptString arg1, const ScriptInt arg2, const ScriptInt arg3) {
    RW_UNIMPLEMENTED_OPCODE(0x0156);
    RW_UNUSED(arg1);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(args);
}

/**
    @brief restart_if_wasted at %1d% %2d% %3d% heading %4d%

    opcode 016c
    @arg coord Coordinates
    @arg angle Angle
*/
void opcode_016c(const ScriptArguments& args, ScriptVec3 coord, const ScriptFloat heading) {
    coord = script::getGround(args, coord);
    args.getState()->addHospitalRestart(glm::vec4(coord, heading));
}

/**
    @brief restart_if_busted at %1d% %2d% %3d% heading %4d%

    opcode 016d
    @arg coord Coordinates
    @arg angle Angle
*/
void opcode_016d(const ScriptArguments& args, ScriptVec3 coord, const ScriptFloat heading) {
    coord = script::getGround(args, coord);
    args.getState()->addPoliceRestart(glm::vec4(coord, heading));
}

/**
    @brief set_player %1d% z_angle_to %2d%

    opcode 0171
    @arg player Player
    @arg angle Angle
*/
void opcode_0171(const ScriptArguments& args, const ScriptPlayer player, const ScriptFloat angle) {
    RW_UNUSED(args);
    player->getCharacter()->setHeading(angle);
}

/**
    @brief set_actor %1d% z_angle_to %2d%

    opcode 0173
    @arg character Character/ped
    @arg angle Angle
*/
void opcode_0173(const ScriptArguments& args, const ScriptCharacter character, const ScriptFloat angle) {
    RW_UNUSED(args);
    character->setHeading(angle);
}

/**
    @brief set_player %1d% weapon %2d% ammo_to %3d%

    opcode 017a
    @arg player
    @arg weaponID Weapon ID
    @arg arg3
*/
void opcode_017a(const ScriptArguments& args, const ScriptPlayer player,
                 const ScriptWeaponType weaponID, const ScriptInt ammo) {
    RW_UNUSED(args);
    player->getCharacter()->getCurrentState().weapons[weaponID].bulletsTotal =
        ammo;
}

/**
    @brief set_actor %1d% weapon %2d% ammo_to %3d%

    opcode 017b
    @arg character Character/ped
    @arg weaponID Weapon ID
    @arg arg3 
*/
void opcode_017b(const ScriptArguments& args, const ScriptCharacter character, const ScriptWeaponType weaponID, const ScriptInt arg3) {
    RW_UNIMPLEMENTED_OPCODE(0x017b);
    RW_UNUSED(character);
    RW_UNUSED(weaponID);
    RW_UNUSED(arg3);
    RW_UNUSED(args);
}

/**
    @brief   car %1d% flipped_for_2_seconds

    opcode 018f
    @arg vehicle Car/vehicle
*/
bool opcode_018f(const ScriptArguments& args, const ScriptVehicle vehicle) {
    RW_UNIMPLEMENTED_OPCODE(0x018f);
    RW_UNUSED(vehicle);
    RW_UNUSED(args);
    return false;
}

/**
    @brief add_car %1d% to_flipped_check

    opcode 0190
    @arg vehicle Car/vehicle
*/
void opcode_0190(const ScriptArguments& args, const ScriptVehicle vehicle) {
    RW_UNIMPLEMENTED_OPCODE(0x0190);
    RW_UNUSED(vehicle);
    RW_UNUSED(args);
}

/**
    @brief remove_car %1d% from_flipped_check

    opcode 0191
    @arg vehicle Car/vehicle
*/
void opcode_0191(const ScriptArguments& args, const ScriptVehicle vehicle) {
    RW_UNIMPLEMENTED_OPCODE(0x0191);
    RW_UNUSED(vehicle);
    RW_UNUSED(args);
}

/**
    @brief set_actor %1d% objective_to_stand_still

    opcode 0192
    @arg character Character/ped
*/
void opcode_0192(const ScriptArguments& args, const ScriptCharacter character) {
    RW_UNIMPLEMENTED_OPCODE(0x0192);
    RW_UNUSED(character);
    RW_UNUSED(args);
}

/**
    @brief set_actor %1d% objective_to_act_like_ped

    opcode 0193
    @arg character Character/ped
*/
void opcode_0193(const ScriptArguments& args, const ScriptCharacter character) {
    RW_UNIMPLEMENTED_OPCODE(0x0193);
    RW_UNUSED(character);
    RW_UNUSED(args);
}

/**
    @brief set_actor %1d% objective_to_guard_point %2d% %3d% %4d%

    opcode 0194
    @arg character Character/ped
    @arg coord Coordinates
*/
void opcode_0194(const ScriptArguments& args, const ScriptCharacter character, ScriptVec3 coord) {
    RW_UNIMPLEMENTED_OPCODE(0x0194);
    RW_UNUSED(character);
    RW_UNUSED(coord);
    RW_UNUSED(args);
}

/**
    @brief set_actor %1d% objective3 %2d% %3d% %4d% %5d%

    opcode 0195
    @arg character 
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
*/
void opcode_0195(const ScriptArguments& args, const ScriptCharacter character, const ScriptFloat arg2, const ScriptFloat arg3, const ScriptFloat arg4, const ScriptFloat arg5) {
    RW_UNIMPLEMENTED_OPCODE(0x0195);
    RW_UNUSED(character);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(args);
}

/**
    @brief actor %1d% objective5

    opcode 0196
    @arg character 
*/
void opcode_0196(const ScriptArguments& args, const ScriptCharacter character) {
    RW_UNIMPLEMENTED_OPCODE(0x0196);
    RW_UNUSED(character);
    RW_UNUSED(args);
}

/**
    @brief give_player %1d% weapon %2c% ammo %3d%

    opcode 01b1
    @arg player 
    @arg weaponID 
    @arg bullets 
*/
void opcode_01b1(const ScriptArguments& args, const ScriptPlayer player, const ScriptWeaponType weaponID, const ScriptInt bullets) {
    RW_UNUSED(args);
    RW_CHECK(weaponID >= 0, "Weapon-ID too low");
    RW_CHECK(weaponID < static_cast<int>(player->getCharacter()->getCurrentState().weapons.size()), "Weapon-ID too high");

    auto plyChar = player->getCharacter();
    plyChar->addToInventory(weaponID, bullets);
    plyChar->setActiveItem(weaponID);
}

/**
    @brief give_actor %1d% weapon %2c% ammo %3d%

    opcode 01b2
    @arg character Character/ped
    @arg weaponID Weapon ID
    @arg bullets 
*/
void opcode_01b2(const ScriptArguments& args, const ScriptCharacter character, const ScriptWeaponType weaponID, const ScriptInt bullets) {
    RW_UNUSED(args);
    RW_CHECK(weaponID >= 0, "Weapon-ID too low");
    RW_CHECK(weaponID < static_cast<int>(character->getCurrentState().weapons.size()), "Weapon-ID too high");

    character->addToInventory(weaponID, bullets);
    character->setActiveItem(weaponID);
}

/**
    @brief set_player %1d% controllable %2btrue/false%

    opcode 01b4
    @arg player Player
    @arg control Boolean true/false
*/
void opcode_01b4(const ScriptArguments& args, const ScriptPlayer player,
                 const ScriptBoolean control) {
    RW_UNUSED(args);
    if (control) {
        player->freeFromCutscene();
    } else {
        player->prepareForCutscene();
    }
}

/**
    @brief set_player %1d% armed_weapon_to %2c%

    opcode 01b8
    @arg player 
    @arg weaponId 
*/
void opcode_01b8(const ScriptArguments& args, const ScriptPlayer player, const ScriptWeaponType weaponId) {
    RW_UNUSED(args);
    player->getCharacter()->setActiveItem(weaponId);
}

/**
    @brief set_actor %1d% armed_weapon_to %2c%

    opcode 01b9
    @arg character Character/ped
    @arg weaponID Weapon ID
*/
void opcode_01b9(const ScriptArguments& args, const ScriptCharacter character, const ScriptWeaponType weaponID) {
    RW_UNUSED(args);
    character->setActiveItem(weaponID);
}

/**
    @brief   car %1d% stopped

    opcode 01c1
    @arg vehicle Car/vehicle
*/
bool opcode_01c1(const ScriptArguments& args, const ScriptVehicle vehicle) {
    return vehicle->isStopped();
    RW_UNUSED(args);
}

/**
    @brief remove_references_to_actor %1d%

    opcode 01c2
    @arg character Character/ped
*/
void opcode_01c2(const ScriptArguments& args, const ScriptCharacter character) {
    /// @todo: there's more logic than only changing life time, or maybe it should be done in cleanUpTraffic
    if (character) {
        character->setLifetime(GameObject::TrafficLifetime);

        if (args.getThread()->isMission) {
            script::removeObjectFromMissionCleanup(args, character);
        }
    }
}

/**
    @brief actor %1d% kill_actor %2d%

    opcode 01c9
    @arg character0 
    @arg character1 
*/
void opcode_01c9(const ScriptArguments& args, const ScriptCharacter character0, const ScriptCharacter character1) {
    RW_UNIMPLEMENTED_OPCODE(0x01c9);
    RW_UNUSED(character0);
    RW_UNUSED(character1);
    RW_UNUSED(args);
}

/**
    @brief actor %1d% kill_player %2d%

    opcode 01ca
    @arg character 
    @arg player 
*/
void opcode_01ca(const ScriptArguments& args, const ScriptCharacter character, const ScriptPlayer player) {
    RW_UNIMPLEMENTED_OPCODE(0x01ca);
    RW_UNUSED(character);
    RW_UNUSED(player);
    RW_UNUSED(args);
}

/**
    @brief actor %1d% kill_actor %2d%

    opcode 01cb
    @arg character0 
    @arg character1 
*/
void opcode_01cb(const ScriptArguments& args, const ScriptCharacter character0, const ScriptCharacter character1) {
    RW_UNIMPLEMENTED_OPCODE(0x01cb);
    RW_UNUSED(character0);
    RW_UNUSED(character1);
    RW_UNUSED(args);
}

/**
    @brief actor %1d% kill_player %2d%

    opcode 01cc
    @arg character 
    @arg player 
*/
void opcode_01cc(const ScriptArguments& args, const ScriptCharacter character, const ScriptPlayer player) {
    RW_UNIMPLEMENTED_OPCODE(0x01cc);
    RW_UNUSED(character);
    RW_UNUSED(player);
    RW_UNUSED(args);
}

/**
    @brief actor %1d% avoid_player %2d%

    opcode 01ce
    @arg character 
    @arg player 
*/
void opcode_01ce(const ScriptArguments& args, const ScriptCharacter character, const ScriptPlayer player) {
    RW_UNIMPLEMENTED_OPCODE(0x01ce);
    RW_UNUSED(character);
    RW_UNUSED(player);
    RW_UNUSED(args);
}

/**
    @brief actor %1d% avoid_char %2d%

    opcode 01cf
    @arg character0 
    @arg character1 
*/
void opcode_01cf(const ScriptArguments& args, const ScriptCharacter character0, const ScriptCharacter character1) {
    RW_UNIMPLEMENTED_OPCODE(0x01cf);
    RW_UNUSED(character0);
    RW_UNUSED(character1);
    RW_UNUSED(args);
}

/**
    @brief actor %1d% avoid_player %2d%

    opcode 01d0
    @arg character 
    @arg player 
*/
void opcode_01d0(const ScriptArguments& args, const ScriptCharacter character, const ScriptPlayer player) {
    RW_UNIMPLEMENTED_OPCODE(0x01d0);
    RW_UNUSED(character);
    RW_UNUSED(player);
    RW_UNUSED(args);
}

/**
    @brief actor %1d% follow_actor %2d%

    opcode 01d1
    @arg character0 
    @arg character1 
*/
void opcode_01d1(const ScriptArguments& args, const ScriptCharacter character0, const ScriptCharacter character1) {
    RW_UNIMPLEMENTED_OPCODE(0x01d1);
    RW_UNUSED(character0);
    RW_UNUSED(character1);
    RW_UNUSED(args);
}

/**
    @brief actor %1d% follow_player %2d%

    opcode 01d2
    @arg character 
    @arg player 
*/
void opcode_01d2(const ScriptArguments& args, const ScriptCharacter character, const ScriptPlayer player) {
    RW_UNIMPLEMENTED_OPCODE(0x01d2);
    RW_UNUSED(character);
    RW_UNUSED(player);
    RW_UNUSED(args);
}

/**
    @brief actor %1d% leave_car %2d%

    opcode 01d3
    @arg character 
    @arg vehicle 
*/
void opcode_01d3(const ScriptArguments& args, const ScriptCharacter character, const ScriptVehicle vehicle) {
    RW_UNUSED(vehicle);
    RW_UNUSED(args);
    character->controller->skipActivity();
    character->controller->setNextActivity(
            std::make_unique<ai::Activities::ExitVehicle>());
}

/**
    @brief actor %1d% go_to_car %2d% and_enter_it_as_a_passenger

    opcode 01d4
    @arg character 
    @arg vehicle 
*/
void opcode_01d4(const ScriptArguments& args, const ScriptCharacter character, const ScriptVehicle vehicle) {
    RW_UNUSED(args);
    character->controller->skipActivity();
    character->controller->setNextActivity(
        std::make_unique<ai::Activities::EnterVehicle>(
            vehicle, ai::Activities::EnterVehicle::ANY_SEAT));
}

/**
    @brief actor %1d% go_to_and_drive_car %2d%

    opcode 01d5
    @arg character 
    @arg vehicle 
*/
void opcode_01d5(const ScriptArguments& args, const ScriptCharacter character, const ScriptVehicle vehicle) {
    RW_UNUSED(args);
    character->controller->setNextActivity(
            std::make_unique<ai::Activities::EnterVehicle>(vehicle));
}

/**
    @brief actor %1d% destroy_car %2d%

    opcode 01d9
    @arg character 
    @arg vehicle 
*/
void opcode_01d9(const ScriptArguments& args, const ScriptCharacter character, const ScriptVehicle vehicle) {
    RW_UNIMPLEMENTED_OPCODE(0x01d9);
    RW_UNUSED(character);
    RW_UNUSED(vehicle);
    RW_UNUSED(args);
}

/**
    @brief tie_actor %1d% to_actor %2d%

    opcode 01de
    @arg character0 
    @arg character1 
*/
void opcode_01de(const ScriptArguments& args, const ScriptCharacter character0, const ScriptCharacter character1) {
    RW_UNIMPLEMENTED_OPCODE(0x01de);
    RW_UNUSED(character0);
    RW_UNUSED(character1);
    RW_UNUSED(args);
}

/**
    @brief tie_actor %1d% to_player %2d%

    opcode 01df
    @arg character 
    @arg player 
*/
void opcode_01df(const ScriptArguments& args, const ScriptCharacter character, const ScriptPlayer player) {
    character->controller->setGoal(ai::CharacterController::FollowLeader);
    character->controller->setTargetCharacter(player->getCharacter());
    RW_UNUSED(args);
}

/**
    @brief set_actor %1d% follow_route %2d% behaviour %3d%

    opcode 01e1
    @arg character 
    @arg arg2 
    @arg arg3 
*/
void opcode_01e1(const ScriptArguments& args, const ScriptCharacter character, const ScriptInt arg2, const ScriptFollowRoute arg3) {
    RW_UNIMPLEMENTED_OPCODE(0x01e1);
    RW_UNUSED(character);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(args);
}

/**
    @brief clear_actor %1d% threat_search

    opcode 01ed
    @arg character 
*/
void opcode_01ed(const ScriptArguments& args, const ScriptCharacter character) {
    RW_UNIMPLEMENTED_OPCODE(0x01ed);
    RW_UNUSED(character);
    RW_UNUSED(args);
}

/**
    @brief   car %1d% flipped

    opcode 01f4
    @arg vehicle Car/vehicle
*/
bool opcode_01f4(const ScriptArguments& args, const ScriptVehicle vehicle) {
    RW_UNUSED(args);
    return vehicle->isFlipped();
}

/**
    @brief set_player %1d% ignored_by_cops_state_to %2b:true/false%

    opcode 01f7
    @arg player Player
    @arg arg2 Boolean true/false
*/
void opcode_01f7(const ScriptArguments& args, const ScriptPlayer player, const ScriptBoolean arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x01f7);
    RW_UNUSED(player);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief   player %1d% near_car %2d% radius %3d% %4d% unknown %5d%

    opcode 01fc
    @arg player 
    @arg vehicle 
    @arg arg3 
    @arg arg4 
    @arg showMarker 
*/
bool opcode_01fc(const ScriptArguments& args, const ScriptPlayer player, const ScriptVehicle vehicle, const ScriptVec2 radius, const ScriptBoolean showMarker) {
    auto plyChar = player->getCharacter();
    return script::objectInRadiusNear(args, plyChar, vehicle, radius, showMarker);
}

/**
    @brief   player %1d% near_car_on_foot %2d% radius %3d% %4d% unknown %5d%

    opcode 01fd
    @arg player 
    @arg vehicle 
    @arg arg3 
    @arg arg4 
    @arg arg5 
*/
bool opcode_01fd(const ScriptArguments& args, const ScriptPlayer player, const ScriptVehicle vehicle, const ScriptVec2 radius, const ScriptBoolean showMarker) {
    auto plyChar = player->getCharacter();
    auto condition = plyChar->getCurrentVehicle() == nullptr;
    return script::objectInRadiusNear(args, plyChar, vehicle, radius, showMarker, condition);
}

/**
    @brief   player %1d% near_car_in_car %2d% radius %3d% %4d% unknown %5d%

    opcode 01fe
    @arg player 
    @arg vehicle 
    @arg arg3 
    @arg arg4 
    @arg arg5 
*/
bool opcode_01fe(const ScriptArguments& args, const ScriptPlayer player, const ScriptVehicle vehicle, const ScriptVec2 radius, const ScriptBoolean showMarker) {
    auto plyChar = player->getCharacter();
    auto condition = plyChar->getCurrentVehicle() != nullptr;
    return script::objectInRadiusNear(args, plyChar, vehicle, radius, showMarker, condition);
}

/**
    @brief   player %1d% near_car %2d% radius %3d% %4d% %5d% unknown %6h%

    opcode 01ff
    @arg player Player
    @arg vehicle Car/vehicle
    @arg radius Radius
    @arg arg6 Boolean true/false
*/
bool opcode_01ff(const ScriptArguments& args, const ScriptPlayer player, const ScriptVehicle vehicle, ScriptVec3 radius, const ScriptBoolean arg6) {
    RW_UNIMPLEMENTED_OPCODE(0x01ff);
    RW_UNUSED(player);
    RW_UNUSED(vehicle);
    RW_UNUSED(radius);
    RW_UNUSED(arg6);
    RW_UNUSED(args);
    return false;
}

/**
    @brief   player %1d% near_car_on_foot %2d% radius %3d% %4d% %5d% unknown %6h%

    opcode 0200
    @arg player Player
    @arg vehicle Car/vehicle
    @arg radius Radius
    @arg arg6 Boolean true/false
*/
bool opcode_0200(const ScriptArguments& args, const ScriptPlayer player, const ScriptVehicle vehicle, ScriptVec3 radius, const ScriptBoolean arg6) {
    RW_UNIMPLEMENTED_OPCODE(0x0200);
    RW_UNUSED(player);
    RW_UNUSED(vehicle);
    RW_UNUSED(radius);
    RW_UNUSED(arg6);
    RW_UNUSED(args);
    return false;
}

/**
    @brief   player %1d% near_car_in_car %2d% radius %3d% %4d% %5d% unknown %6h%

    opcode 0201
    @arg player Player
    @arg vehicle Character/ped
    @arg radius Radius
    @arg arg6 Boolean true/false
*/
bool opcode_0201(const ScriptArguments& args, const ScriptPlayer player, const ScriptVehicle vehicle, ScriptVec3 radius, const ScriptBoolean arg6) {
    RW_UNIMPLEMENTED_OPCODE(0x0201);
    RW_UNUSED(player);
    RW_UNUSED(vehicle);
    RW_UNUSED(radius);
    RW_UNUSED(arg6);
    RW_UNUSED(args);
    return false;
}

/**
    @brief   actor %1d% near_car_on_foot %2d% radius %3d% %4d% unknown %5d%

    opcode 0203
    @arg character Character/ped
    @arg vehicle Car/vehicle
    @arg radius Radius
    @arg arg5 Boolean true/false
*/
bool opcode_0203(const ScriptArguments& args, const ScriptCharacter character, const ScriptVehicle vehicle, ScriptVec2 radius, const ScriptBoolean showMarker) {
    auto condition = character->getCurrentVehicle() == nullptr;
    return script::objectInRadiusNear(args, character, vehicle, radius, showMarker, condition);
}

/**
    @brief   actor %1d% near_car_in_car %2d% radius %3d% %4d% unknown %5d%

    opcode 0204
    @arg character Character/ped
    @arg vehicle Car/vehicle
    @arg radius Radius
    @arg arg5 Boolean true/false
*/
bool opcode_0204(const ScriptArguments& args, const ScriptCharacter character, const ScriptVehicle vehicle, ScriptVec2 radius, const ScriptBoolean showMarker) {
    auto condition = character->getCurrentVehicle() != nullptr;
    return script::objectInRadiusNear(args, character, vehicle, radius, showMarker, condition);
}

/**
    @brief   actor %1d% near_car %2d% radius %3d% %4d% %5d% unknown %6h%

    opcode 0205
    @arg character Character/ped
    @arg vehicle Car/vehicle
    @arg radius Radius
    @arg arg6 Boolean true/false
*/
bool opcode_0205(const ScriptArguments& args, const ScriptCharacter character, const ScriptVehicle vehicle, ScriptVec3 radius, const ScriptBoolean arg6) {
    RW_UNIMPLEMENTED_OPCODE(0x0205);
    RW_UNUSED(character);
    RW_UNUSED(vehicle);
    RW_UNUSED(radius);
    RW_UNUSED(arg6);
    RW_UNUSED(args);
    return false;
}

/**
    @brief   actor %1d% near_car_on_foot %2d% radius %3d% %4d% %5d% unknown %6h%

    opcode 0206
    @arg character Character/ped
    @arg vehicle Car/vehicle
    @arg radius Radius
    @arg arg6 Boolean true/false
*/
bool opcode_0206(const ScriptArguments& args, const ScriptCharacter character, const ScriptVehicle vehicle, ScriptVec3 radius, const ScriptBoolean arg6) {
    RW_UNIMPLEMENTED_OPCODE(0x0206);
    RW_UNUSED(character);
    RW_UNUSED(vehicle);
    RW_UNUSED(radius);
    RW_UNUSED(arg6);
    RW_UNUSED(args);
    return false;
}

/**
    @brief   actor %1d% near_car_in_car %2d% radius %3d% %4d% %5d% unknown %6h%

    opcode 0207
    @arg character Character/ped
    @arg vehicle Car/vehicle
    @arg radius Radius
    @arg arg6 Boolean true/false
*/
bool opcode_0207(const ScriptArguments& args, const ScriptCharacter character, const ScriptVehicle vehicle, ScriptVec3 radius, const ScriptBoolean arg6) {
    RW_UNIMPLEMENTED_OPCODE(0x0207);
    RW_UNUSED(character);
    RW_UNUSED(vehicle);
    RW_UNUSED(radius);
    RW_UNUSED(arg6);
    RW_UNUSED(args);
    return false;
}

/**
    @brief actor %1d% walk_to %2d% %3d%

    opcode 0211
    @arg character Character/ped
    @arg coord Coordinates
*/
void opcode_0211(const ScriptArguments& args, const ScriptCharacter character, ScriptVec2 coord) {
    /// @todo verify that this is how the game treats this
    auto target = script::getGround(args, glm::vec3(coord, -100.f));
    character->controller->skipActivity();
    if( character->getCurrentVehicle() )
    {
    	// Since we just cleared the Activities, this will become current immediatley.
    	character->controller->setNextActivity(
                    std::make_unique<ai::Activities::ExitVehicle>());
    }

    character->controller->setNextActivity(
            std::make_unique<ai::Activities::GoTo>(target));
}

/**
    @brief set_player %1d% apply_brakes_to_car %2d%

    opcode 0221
    @arg player Player
    @arg arg2 Boolean true/false
*/
void opcode_0221(const ScriptArguments& args, const ScriptPlayer player, const ScriptBoolean arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x0221);
    RW_UNUSED(player);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief set_player %1d% health_to %2d%

    opcode 0222
    @arg player Player
    @arg health 
*/
void opcode_0222(const ScriptArguments& args, const ScriptPlayer player, const ScriptInt health) {
    RW_UNUSED(args);
    player->getCharacter()->getCurrentState().health = health;
}

/**
    @brief set_actor %1d% health_to %2d%

    opcode 0223
    @arg character Character/ped
    @arg health 
*/
void opcode_0223(const ScriptArguments& args, const ScriptCharacter character, const ScriptInt health) {
    character->getCurrentState().health = health;
    RW_UNUSED(args);
}

/**
    @brief set_car %1d% health_to %2d%

    opcode 0224
    @arg vehicle Car/vehicle
    @arg arg2 
*/
void opcode_0224(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptInt arg2) {
    RW_UNUSED(args);
    vehicle->setHealth(static_cast<float> (arg2));
}

/**
    @brief switch_ped_roads_on %1d% %2d% %3d% to %4d% %5d% %6d%

    opcode 022a
    @arg coord0 Coordinates
    @arg coord1 Coordinates
*/
void opcode_022a(const ScriptArguments& args, ScriptVec3 coord0, ScriptVec3 coord1) {
    args.getWorld()->enableAIPaths(ai::NodeType::Pedestrian, coord0, coord1);
}

/**
    @brief switch_ped_roads_off %1d% %2d% %3d% to %4d% %5d% %6d%

    opcode 022b
    @arg coord0 Coordinates
    @arg coord1 Coordinates
*/
void opcode_022b(const ScriptArguments& args, ScriptVec3 coord0, ScriptVec3 coord1) {
    args.getWorld()->disableAIPaths(ai::NodeType::Pedestrian, coord0, coord1);
}

/**
    @brief set_actor %1d% stop_looking

    opcode 022f
    @arg character 
*/
void opcode_022f(const ScriptArguments& args, const ScriptCharacter character) {
    RW_UNIMPLEMENTED_OPCODE(0x022f);
    RW_UNUSED(character);
    RW_UNUSED(args);
}

/**
    @brief set_player %1d% stop_looking

    opcode 0230
    @arg player Player
*/
void opcode_0230(const ScriptArguments& args, const ScriptPlayer player) {
    RW_UNIMPLEMENTED_OPCODE(0x0230);
    RW_UNUSED(player);
    RW_UNUSED(args);
}

/**
    @brief actor %1d% run_to %2d% %3d%

    opcode 0239
    @arg character Character/ped
    @arg coord Coordinates
*/
void opcode_0239(const ScriptArguments& args, const ScriptCharacter character, ScriptVec2 coord) {
    auto target = script::getGround(args, glm::vec3(coord, -100.f));
    character->controller->setNextActivity(
            std::make_unique<ai::Activities::GoTo>(target, true));
}

/**
    @brief load_special_actor %2d% as %1d%

    opcode 023c
    @arg arg1 
    @arg arg2 
*/
void opcode_023c(const ScriptArguments& args, const ScriptInt arg1, const ScriptString arg2) {
    args.getWorld()->loadSpecialCharacter(arg1, arg2);
}

/**
    @brief   special_actor %1d% loaded

    opcode 023d
    @arg arg1 
*/
bool opcode_023d(const ScriptArguments& args, const ScriptInt arg1) {
    /// @todo re-implement this when streaming is added
    return true;
    RW_UNUSED(args);
    RW_UNUSED(arg1);
#if 0
    auto model = args.getState()->specialCharacters[arg1];
    auto modelfind = args.getWorld()->data->models.find(model);
    if( modelfind != args.getWorld()->data->models.end() && modelfind->second->resource != nullptr ) {
    	return true;
    }
    return false;
#endif
}

/**
    @brief   player %1d% in_remote_mode

    opcode 0241
    @arg player Player
*/
bool opcode_0241(const ScriptArguments& args, const ScriptPlayer player) {
    RW_UNIMPLEMENTED_OPCODE(0x0241);
    RW_UNUSED(player);
    RW_UNUSED(args);
    return false;
}

/**
    @brief set_actor %1d% ped_stats_to %2d%

    opcode 0243
    @arg character Character/ped
    @arg arg2 
*/
void opcode_0243(const ScriptArguments& args, const ScriptCharacter character, const ScriptPedStat arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x0243);
    RW_UNUSED(character);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief set_actor %1d% walk_style_to %2d%

    opcode 0245
    @arg character Character/ped
    @arg arg2 
*/
void opcode_0245(const ScriptArguments& args, const ScriptCharacter character, const ScriptAnim arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x0245);
    RW_UNUSED(character);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief   is_player %1d% defined

    opcode 0256
    @arg player Player
*/
bool opcode_0256(const ScriptArguments& args, const ScriptPlayer player) {
    RW_UNUSED(args);
    return !player->isWasted() && !player->isBusted();
}

/**
    @brief set_actor %1d% attack_when_provoked %2d%

    opcode 0291
    @arg character Character/ped
    @arg arg2 Boolean true/false
*/
void opcode_0291(const ScriptArguments& args, const ScriptCharacter character, const ScriptBoolean arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x0291);
    RW_UNUSED(character);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief unload_special_actor %1d%

    opcode 0296
    @arg arg1 
*/
void opcode_0296(const ScriptArguments& args, const ScriptInt arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x0296);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief   player %1d% stopped

    opcode 029f
    @arg player 
*/
bool opcode_029f(const ScriptArguments& args, const ScriptPlayer player) {
    RW_UNUSED(args);
    return player->getCharacter()->isStopped();
}

/**
    @brief   actor %1d% stopped

    opcode 02a0
    @arg character Character/ped
*/
bool opcode_02a0(const ScriptArguments& args, const ScriptCharacter character) {
    RW_UNUSED(args);
    return character->isStopped();
}

/**
    @brief set_char_only_damaged_by_player %1d% to %2d%

    opcode 02a9
    @arg character Character/ped
    @arg arg2 Boolean true/false
*/
void opcode_02a9(const ScriptArguments& args, const ScriptCharacter character, const ScriptBoolean arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x02a9);
    RW_UNUSED(character);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief set_car %1d% immune_to_nonplayer %2d%

    opcode 02aa
    @arg vehicle Car/vehicle
    @arg arg2 Boolean true/false
*/
void opcode_02aa(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptBoolean arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x02aa);
    RW_UNUSED(vehicle);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief set_actor %1d% immunities BP %2d% FP %3d% EP %4d% CP %5d% MP %6d%

    opcode 02ab
    @arg character Character/ped
    @arg arg2 Boolean true/false
    @arg arg3 Boolean true/false
    @arg arg4 Boolean true/false
    @arg arg5 Boolean true/false
    @arg arg6 Boolean true/false
*/
void opcode_02ab(const ScriptArguments& args, const ScriptCharacter character, const ScriptBoolean arg2, const ScriptBoolean arg3, const ScriptBoolean arg4, const ScriptBoolean arg5, const ScriptBoolean arg6) {
    RW_UNIMPLEMENTED_OPCODE(0x02ab);
    RW_UNUSED(character);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(arg6);
    RW_UNUSED(args);
}

/**
    @brief set_cop_behaviour %1b:kill/arrest%

    opcode 02bc
    @arg arg1 
*/
void opcode_02bc(const ScriptArguments& args, const ScriptInt arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x02bc);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief set %4d% %5d% %6d% to_ped_path_coords_closest_to %1d% %2d% %3d%

    opcode 02c0
    @arg coord Coordinates
    @arg xCoord X Coord
    @arg yCoord Y Coord
    @arg zCoord Z Coord
*/
void opcode_02c0(const ScriptArguments& args, ScriptVec3 coord, ScriptFloat& xCoord, ScriptFloat& yCoord, ScriptFloat& zCoord) {
    script::getClosestNode(args, coord, ai::NodeType::Pedestrian, xCoord, yCoord, zCoord);
}

/**
    @brief   is_actor_on_screen %1d% 

    opcode 02cb
    @arg character Character/ped
*/
bool opcode_02cb(const ScriptArguments& args, const ScriptCharacter character) {
    RW_UNIMPLEMENTED_OPCODE(0x02cb);
    RW_UNUSED(character);
    RW_UNUSED(args);
    return false;
}

/**
    @brief   player %1d% firing_weapons_in_rectangle %2d% %3d% %4d% %5d% %6d%

    opcode 02d5
    @arg player 
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
*/
bool opcode_02d5(const ScriptArguments& args, const ScriptPlayer player, const ScriptFloat arg2, const ScriptFloat arg3, const ScriptFloat arg4, const ScriptFloat arg5, const ScriptInt arg6) {
    RW_UNIMPLEMENTED_OPCODE(0x02d5);
    RW_UNUSED(player);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(arg6);
    RW_UNUSED(args);
    return false;
}

/**
    @brief   player %1d% driving_taxi_vehicle

    opcode 02de
    @arg player 
*/
bool opcode_02de(const ScriptArguments& args, const ScriptPlayer player) {
    RW_UNUSED(args);
    auto vehicle = player->getCharacter()->getCurrentVehicle();
    if (!vehicle) {
    	return false;
    }
    auto type = vehicle->getVehicle()->vehicleclass_;
    return (type & VehicleModelInfo::TAXI) == VehicleModelInfo::TAXI;
}

/**
    @brief player %1d% agressive

    opcode 02df
    @arg player 
*/
void opcode_02df(const ScriptArguments& args, const ScriptPlayer player) {
    RW_UNIMPLEMENTED_OPCODE(0x02df);
    RW_UNUSED(player);
    RW_UNUSED(args);
}

/**
    @brief   actor %1d% firing_weapon

    opcode 02e0
    @arg character Character/ped
*/
bool opcode_02e0(const ScriptArguments& args, const ScriptCharacter character) {
    RW_UNIMPLEMENTED_OPCODE(0x02e0);
    RW_UNUSED(character);
    RW_UNUSED(args);
    return false;
}

/**
    @brief set_actor %1d% weapon_accuracy_to %2d%

    opcode 02e2
    @arg character Character/ped
    @arg arg2 
*/
void opcode_02e2(const ScriptArguments& args, const ScriptCharacter character, const ScriptInt arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x02e2);
    RW_UNUSED(character);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief set_head_anim %1d% %2s%

    opcode 02f5
    @arg object 
    @arg arg2 
*/
void opcode_02f5(const ScriptArguments& args, const ScriptObject object, const ScriptString arg2) {
    RW_UNUSED(object);
    RW_UNUSED(arg2);
    GameObject* head = args.getObject<CutsceneObject>(0);
    std::string animName = args[1].string;
    std::transform(animName.begin(), animName.end(), animName.begin(), ::tolower);
    auto anim = args.getWorld()->data->animations[animName];
    if( anim ) {
    	head->animator->playAnimation(AnimIndexMovement, anim, 1.f, false);
    }
    else {
    	args.getWorld()->logger->error("SCM", "Failed to load cutscene anim: " + animName);
    }
}

/**
    @brief set_actor %1d% running %2b:true/false%

    opcode 0319
    @arg character Character/ped
    @arg arg2 Boolean true/false
*/
void opcode_0319(const ScriptArguments& args, const ScriptCharacter character, const ScriptBoolean arg2) {
    character->setRunning(arg2);
    RW_UNUSED(args);
}

/**
    @brief   actor %1d% hit_by_weapon %2d%

    opcode 031d
    @arg character Character/ped
    @arg weaponID Weapon ID
*/
bool opcode_031d(const ScriptArguments& args, const ScriptCharacter character, const ScriptWeaponType weaponID) {
    RW_UNIMPLEMENTED_OPCODE(0x031d);
    RW_UNUSED(character);
    RW_UNUSED(weaponID);
    RW_UNUSED(args);
    return false;
}

/**
    @brief   unknown_actor %1d% unknown_actor %2d%

    opcode 031f
    @arg character0 Character/ped
    @arg character1 Character/ped
*/
bool opcode_031f(const ScriptArguments& args, const ScriptCharacter character0, const ScriptCharacter character1) {
    RW_UNIMPLEMENTED_OPCODE(0x031f);
    RW_UNUSED(character0);
    RW_UNUSED(character1);
    RW_UNUSED(args);
    return false;
}

/**
    @brief   actor %1d% in_range_of_player %2d%

    opcode 0320
    @arg character Character/ped
    @arg player Player
*/
bool opcode_0320(const ScriptArguments& args, const ScriptCharacter character, const ScriptPlayer player) {
    RW_UNUSED(args);
    return character->controller->getTargetCharacter() == player->getCharacter();
}

/**
    @brief kill_actor %1d%

    opcode 0321
    @arg character Character/ped
*/
void opcode_0321(const ScriptArguments& args, const ScriptCharacter character) {
    RW_UNIMPLEMENTED_OPCODE(0x0321);
    RW_UNUSED(character);
    RW_UNUSED(args);
}

/**
    @brief kill_player %1d%

    opcode 0322
    @arg player Player
*/
void opcode_0322(const ScriptArguments& args, const ScriptPlayer player) {
    RW_UNIMPLEMENTED_OPCODE(0x0322);
    RW_UNUSED(player);
    RW_UNUSED(args);
}

/**
    @brief set_zone_pedgroup_info %1z% %2b:day/night% %3u%

    opcode 0324
    @arg arg1 
    @arg arg2 Boolean true/false
    @arg arg3 
*/
void opcode_0324(const ScriptArguments& args, const ScriptString arg1, const ScriptBoolean arg2, const ScriptPedGrp arg3) {
    RW_UNUSED(arg1);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    auto zone = args.getWorld()->data->findZone(arg1);
    if (zone)
    {
    	auto day = args[1].integer == 1;
    	if( day )
    	{
    		zone->pedGroupDay = args[2].integer;
    	}
    	else
    	{
    		zone->pedGroupNight = args[2].integer;
    	}
    }
}

/**
    @brief set_actor_on_fire %1d% fire store_to %2d%

    opcode 0326
    @arg character Character/ped
    @arg fire Fire
*/
void opcode_0326(const ScriptArguments& args, const ScriptCharacter character, ScriptFire& fire) {
    RW_UNIMPLEMENTED_OPCODE(0x0326);
    RW_UNUSED(character);
    RW_UNUSED(fire);
    RW_UNUSED(args);
}

/**
    @brief set_player %1d% infinite_run_to %2b:true/false%

    opcode 0330
    @arg player Player
    @arg arg2 Boolean true/false
*/
void opcode_0330(const ScriptArguments& args, const ScriptPlayer player, const ScriptBoolean arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x0330);
    RW_UNUSED(player);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief set_player %1d% fast_reload %2h%

    opcode 0331
    @arg player Player
    @arg arg2 Boolean true/false
*/
void opcode_0331(const ScriptArguments& args, const ScriptPlayer player, const ScriptBoolean arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x0331);
    RW_UNUSED(player);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief set_actor %1d% bleeding_to %2b:true/false%

    opcode 0332
    @arg character Character/ped
    @arg arg2 Boolean true/false
*/
void opcode_0332(const ScriptArguments& args, const ScriptCharacter character, const ScriptBoolean arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x0332);
    RW_UNUSED(character);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief set_player %1d% visible %2d%

    opcode 0336
    @arg player Player
    @arg arg2 Boolean true/false
*/
void opcode_0336(const ScriptArguments& args, const ScriptPlayer player, const ScriptBoolean arg2) {
    RW_UNUSED(args);
    player->getCharacter()->visible = arg2;
}

/**
    @brief set_actor %1d% visible %2h%

    opcode 0337
    @arg character Character/ped
    @arg arg2 Boolean true/false
*/
void opcode_0337(const ScriptArguments& args, const ScriptCharacter character, const ScriptBoolean arg2) {
    RW_UNUSED(args);
    character->visible = arg2;
}

/**
    @brief set_text_draw_centered %1d%

    opcode 0342
    @arg arg1 Boolean true/false
*/
void opcode_0342(const ScriptArguments& args, const ScriptBoolean arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x0342);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief set_text_draw_linewidth %1d% for_centered_text

    opcode 0344
    @arg arg1 
*/
void opcode_0344(const ScriptArguments& args, const ScriptFloat arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x0344);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief set_actor %1d% maintain_position_when_attacked %2d%

    opcode 0350
    @arg character Character/ped
    @arg arg2 Boolean true/false
*/
void opcode_0350(const ScriptArguments& args, const ScriptCharacter character, const ScriptBoolean arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x0350);
    RW_UNUSED(character);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief set_actor %1d% skin_to %2s%

    opcode 0352
    @arg character Character/ped
    @arg arg2 
*/
void opcode_0352(const ScriptArguments& args, const ScriptCharacter character, const ScriptString arg2) {
    RW_UNUSED(args);
    character->changeCharacterModel(arg2);
}

/**
    @brief refresh_actor %1d%

    opcode 0353
    @arg character Character/ped
*/
void opcode_0353(const ScriptArguments& args, const ScriptCharacter character) {
    RW_UNIMPLEMENTED_OPCODE(0x0353);
    RW_UNUSED(character);
    RW_UNUSED(args);
}

/**
    @brief set_player %1d% armour_to %2d%

    opcode 035e
    @arg player Player
    @arg arg2 
*/
void opcode_035e(const ScriptArguments& args, const ScriptPlayer player, const ScriptInt arg2) {
    RW_UNUSED(args);
    player->getCharacter()->getCurrentState().armour = arg2;
}

/**
    @brief set_actor %1d% armour_to %2d%

    opcode 035f
    @arg character Character/ped
    @arg arg2 
*/
void opcode_035f(const ScriptArguments& args, const ScriptCharacter character, const ScriptInt arg2) {
    RW_UNUSED(args);
    character->getCurrentState().armour = arg2;
}

/**
    @brief remove_actor %1d% from_car_and_place_at %2d% %3d% %4d%

    opcode 0362
    @arg character Character/ped
    @arg coord Coordinates
*/
void opcode_0362(const ScriptArguments& args, const ScriptCharacter character,
                 ScriptVec3 coord) {
    character->setCurrentVehicle(nullptr, 0);
    character->setPosition(coord);
    script::clearSpaceForObject(args, character);
}

/**
    @brief set_actor %1d% objective_hail_taxi

    opcode 0365
    @arg character Character/ped
*/
void opcode_0365(const ScriptArguments& args, const ScriptCharacter character) {
    RW_UNIMPLEMENTED_OPCODE(0x0365);
    RW_UNUSED(character);
    RW_UNUSED(args);
}

/**
    @brief put_player %1d% in_car %2d%

    opcode 0369
    @arg player Player
    @arg vehicle Car/vehicle
*/
void opcode_0369(const ScriptArguments& args, const ScriptPlayer player, const ScriptVehicle vehicle) {
    RW_UNUSED(args);
    auto plyChar = player->getCharacter();
    vehicle->setOccupant(0, plyChar);
    plyChar->setCurrentVehicle(vehicle, 0);
}

/**
    @brief put_actor %1d% in_car %2d%

    opcode 036a
    @arg character Character/ped
    @arg vehicle Car/vehicle
*/
void opcode_036a(const ScriptArguments& args, const ScriptCharacter character, const ScriptVehicle vehicle) {
    RW_UNUSED(args);
    //@TODO check the seat is empty
    vehicle->setOccupant(0, character);
    character->setCurrentVehicle(vehicle, 0);
}

/**
    @brief set_actor %1d% steal_any_car

    opcode 0377
    @arg character Character/ped
*/
void opcode_0377(const ScriptArguments& args, const ScriptCharacter character) {
    RW_UNIMPLEMENTED_OPCODE(0x0377);
    RW_UNUSED(character);
    RW_UNUSED(args);
}

/**
    @brief give_player_detonator

    opcode 037f
*/
void opcode_037f(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x037f);
    RW_UNUSED(args);
}

/**
    @brief   player %1d% car_horn_activated

    opcode 0383
    @arg vehicle Car/vehicle
*/
bool opcode_0383(const ScriptArguments& args, const ScriptVehicle vehicle) {
    RW_UNIMPLEMENTED_OPCODE(0x0383);
    RW_UNUSED(vehicle);
    RW_UNUSED(args);
    return true;
}

/**
    @brief remove_forbidden_for_peds_angled_cube %1d% %2d% %3d% to %4d% %5d% %6d% angle %7d%

    opcode 0398
    @arg arg1 
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
    @arg arg7 
*/
void opcode_0398(const ScriptArguments& args, const ScriptFloat arg1, const ScriptFloat arg2, const ScriptFloat arg3, const ScriptFloat arg4, const ScriptFloat arg5, const ScriptFloat arg6, const ScriptFloat arg7) {
    RW_UNIMPLEMENTED_OPCODE(0x0398);
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
    @brief create_forbidden_for_peds_angled_cube %1d% %2d% %3d% to %4d% %5d% %6d% angle %7d%

    opcode 0399
    @arg arg1 
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
    @arg arg7 
*/
void opcode_0399(const ScriptArguments& args, const ScriptFloat arg1, const ScriptFloat arg2, const ScriptFloat arg3, const ScriptFloat arg4, const ScriptFloat arg5, const ScriptFloat arg6, const ScriptFloat arg7) {
    RW_UNIMPLEMENTED_OPCODE(0x0399);
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
    @brief set_char_cant_be_dragged_out %1d% to %2d%

    opcode 039e
    @arg character Character/ped
    @arg arg2 Boolean true/false
*/
void opcode_039e(const ScriptArguments& args, const ScriptCharacter character, const ScriptBoolean arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x039e);
    RW_UNUSED(character);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief    is_char_male %1d%

    opcode 03a3
    @arg character Character/ped
*/
bool opcode_03a3(const ScriptArguments& args, const ScriptCharacter character) {
    RW_UNIMPLEMENTED_OPCODE(0x03a3);
    RW_UNUSED(character);
    RW_UNUSED(args);
    return false;
}

/**
    @brief clear_weapons_from_player %1d%

    opcode 03b8
    @arg player 
*/
void opcode_03b8(const ScriptArguments& args, const ScriptPlayer player) {
    RW_UNUSED(args);
    player->getCharacter()->clearInventory();
}

/**
    @brief set_player %1d% ignored_by_everyone_to %2b:true/false%

    opcode 03bf
    @arg player Player
    @arg arg2 Boolean true/false
*/
void opcode_03bf(const ScriptArguments& args, const ScriptPlayer player, const ScriptBoolean arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x03bf);
    RW_UNUSED(player);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief set_ped_density_multiplier %1d%

    opcode 03de
    @arg arg1 
*/
void opcode_03de(const ScriptArguments& args, const ScriptFloat arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x03de);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief   player %1d% controllable

    opcode 03ee
    @arg player Player
*/
bool opcode_03ee(const ScriptArguments& args, const ScriptPlayer player) {
    RW_UNIMPLEMENTED_OPCODE(0x03ee);
    RW_UNUSED(player);
    RW_UNUSED(args);
    return true;
}

/**
    @brief player %1d% make_safe

    opcode 03ef
    @arg player Player
*/
void opcode_03ef(const ScriptArguments& args, const ScriptPlayer player) {
    RW_UNUSED(args);
    player->prepareForCutscene();
}

/**
    @brief pedtype %1e% add_threat %2e%

    opcode 03f1
    @arg pedType 
    @arg arg2 
*/
void opcode_03f1(const ScriptArguments& args, const ScriptPedType pedType, const ScriptThreat arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x03f1);
    RW_UNUSED(pedType);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief pedgroup %1e% remove_threat %2e%

    opcode 03f2
    @arg pedType 
    @arg arg2 
*/
void opcode_03f2(const ScriptArguments& args, const ScriptPedType pedType, const ScriptThreat arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x03f2);
    RW_UNUSED(pedType);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief get_body_cast_health %1d%

    opcode 03f8
    @arg arg1 
*/
void opcode_03f8(const ScriptArguments& args, ScriptInt& arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x03f8);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief make_actors %1d% %2d% converse_in %3d% ms

    opcode 03f9
    @arg character0 
    @arg character1 
    @arg arg3 
*/
void opcode_03f9(const ScriptArguments& args, const ScriptCharacter character0, const ScriptCharacter character1, const ScriptInt arg3) {
    RW_UNIMPLEMENTED_OPCODE(0x03f9);
    RW_UNUSED(character0);
    RW_UNUSED(character1);
    RW_UNUSED(arg3);
    RW_UNUSED(args);
}

/**
    @brief set_actor %1d% stays_on_current_island %2d%

    opcode 03fc
    @arg character 
    @arg arg2 
*/
void opcode_03fc(const ScriptArguments& args, const ScriptCharacter character, const ScriptInt arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x03fc);
    RW_UNUSED(character);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief increment_criminals_stopped

    opcode 0402
*/
void opcode_0402(const ScriptArguments& args) {
    args.getState()->gameStats.criminalsKilled++;
}

/**
    @brief set_actor %1d% use_pednode_seek %2d:true/false%

    opcode 0411
    @arg character Character/ped
    @arg arg2 Boolean true/false
*/
void opcode_0411(const ScriptArguments& args, const ScriptCharacter character, const ScriptBoolean arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x0411);
    RW_UNUSED(character);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief toggle_player %1d% free_treatment_once %2d%

    opcode 0414
    @arg player Player
    @arg arg2 Boolean true/false
*/
void opcode_0414(const ScriptArguments& args, const ScriptPlayer player, const ScriptBoolean arg2) {
    // @todo support multiple players?
    RW_UNUSED(player);
    args.getState()->playerInfo.singlePayerHealthcare = arg2;
}

/**
    @brief get_ammo_of_player %1d% weapon %2c% store_to %3d%

    opcode 0419
    @arg player0 Weapon ID
    @arg player1 Player
    @arg arg3 
*/
void opcode_0419(const ScriptArguments& args, const ScriptPlayer player0, const ScriptWeaponType player1, ScriptInt& arg3) {
    RW_UNIMPLEMENTED_OPCODE(0x0419);
    RW_UNUSED(player0);
    RW_UNUSED(player1);
    RW_UNUSED(arg3);
    RW_UNUSED(args);
}

/**
    @brief get_ammo_of_actor %1d% weapon %2c% store_to %3d%

    opcode 041a
    @arg character0 Weapon ID
    @arg character1 Character/ped
    @arg arg3 
*/
void opcode_041a(const ScriptArguments& args, const ScriptCharacter character0, const ScriptWeaponType character1, ScriptInt& arg3) {
    RW_UNIMPLEMENTED_OPCODE(0x041a);
    RW_UNUSED(character0);
    RW_UNUSED(character1);
    RW_UNUSED(arg3);
    RW_UNUSED(args);
}

/**
    @brief make_actor %1d% say %2d%

    opcode 041c
    @arg character 
    @arg sound 
*/
void opcode_041c(const ScriptArguments& args, const ScriptCharacter character, const ScriptSoundType sound) {
    RW_UNIMPLEMENTED_OPCODE(0x041c);
    RW_UNUSED(character);
    RW_UNUSED(sound);
    RW_UNUSED(args);
}

/**
    @brief create_save_peds_between_levels_cube %1d% %2d% %3d% to %4d% %5d% %6d%

    opcode 0427
    @arg coord0 Coordinates
    @arg coord1 Coordinates
*/
void opcode_0427(const ScriptArguments& args, ScriptVec3 coord0, ScriptVec3 coord1) {
    RW_UNIMPLEMENTED_OPCODE(0x0427);
    RW_UNUSED(coord0);
    RW_UNUSED(coord1);
    RW_UNUSED(args);
}

/**
    @brief set_car %1d% avoid_level_transitions %2d%

    opcode 0428
    @arg vehicle Car/vehicle
    @arg arg2 Boolean true/false
*/
void opcode_0428(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptBoolean arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x0428);
    RW_UNUSED(vehicle);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief   ped_threat_exists %1u% %2u%

    opcode 042a
    @arg pedType 
    @arg arg2 
*/
bool opcode_042a(const ScriptArguments& args, const ScriptPedType pedType, const ScriptThreat arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x042a);
    RW_UNUSED(pedType);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
    return false;
}

/**
    @brief clear_peds_from_cube %1d% %2d% %3d% %4d% %5d% %6d%

    opcode 042b
    @arg coord0 Coordinates
    @arg coord1 Coordinates
*/
void opcode_042b(const ScriptArguments& args, ScriptVec3 coord0, ScriptVec3 coord1) {
    RW_UNIMPLEMENTED_OPCODE(0x042b);
    RW_UNUSED(coord0);
    RW_UNUSED(coord1);
    RW_UNUSED(args);
}

/**
    @brief set_actor %1d% criminal_flag %2h%

    opcode 0433
    @arg character Character/ped
    @arg arg2 Boolean true/false
*/
void opcode_0433(const ScriptArguments& args, const ScriptCharacter character, const ScriptBoolean arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x0433);
    RW_UNUSED(character);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief set_actor %1d% ignore_level_transitions %2d%

    opcode 0438
    @arg character Character/ped
    @arg arg2 Boolean true/false
*/
void opcode_0438(const ScriptArguments& args, const ScriptCharacter character, const ScriptBoolean arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x0438);
    RW_UNUSED(character);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief start_boat_foam_animation

    opcode 043a
*/
void opcode_043a(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x043a);
    RW_UNUSED(args);
}

/**
    @brief update_boat %1d% foam_animation

    opcode 043b
    @arg object 
*/
void opcode_043b(const ScriptArguments& args, const ScriptObject object) {
    RW_UNIMPLEMENTED_OPCODE(0x043b);
    RW_UNUSED(object);
    RW_UNUSED(args);
}

/**
    @brief   player %1d% in_car %2d%

    opcode 0442
    @arg player Player
    @arg vehicle Car/vehicle
*/
bool opcode_0442(const ScriptArguments& args, const ScriptPlayer player, const ScriptVehicle vehicle) {
    RW_UNUSED(args);
    return player->getCharacter()->getCurrentVehicle() == vehicle;
}

/**
    @brief   player %1d% in_a_car

    opcode 0443
    @arg player Player
*/
bool opcode_0443(const ScriptArguments& args, const ScriptPlayer player) {
    RW_UNUSED(args);
    return player->getCharacter()->getCurrentVehicle();
}

/**
    @brief set_actor %1d% dismemberment_possible %2d%

    opcode 0446
    @arg character Character/ped
    @arg arg2 Boolean true/false
*/
void opcode_0446(const ScriptArguments& args, const ScriptCharacter character, const ScriptBoolean arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x0446);
    RW_UNUSED(character);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief   actor %1d% in_car %2d%

    opcode 0448
    @arg character Character/ped
    @arg vehicle Car/vehicle
*/
bool opcode_0448(const ScriptArguments& args, const ScriptCharacter character, const ScriptVehicle vehicle) {
    RW_UNUSED(args);
    return character->getCurrentVehicle() == vehicle;
}

/**
    @brief   actor %1d% in_a_car

    opcode 0449
    @arg character Character/ped
*/
bool opcode_0449(const ScriptArguments& args, const ScriptCharacter character) {
    RW_UNUSED(args);
    return !character->getCurrentVehicle();
}

/**
    @brief   player %1d% on_foot

    opcode 044a
    @arg player Player
*/
bool opcode_044a(const ScriptArguments& args, const ScriptPlayer player) {
    RW_UNUSED(args);
    return !player->getCharacter()->getCurrentVehicle();
}

/**
    @brief    is_char_on_foot %1d%

    opcode 044b
    @arg character Character/ped
*/
bool opcode_044b(const ScriptArguments& args, const ScriptCharacter character) {
    RW_UNUSED(args);
    return !character->getCurrentVehicle();
}

/**
    @brief car %1d% warp_to_player

    opcode 0450
    @arg vehicle Car/vehicle
*/
void opcode_0450(const ScriptArguments& args, const ScriptVehicle vehicle) {
    RW_UNIMPLEMENTED_OPCODE(0x0450);
    RW_UNUSED(vehicle);
    RW_UNUSED(args);
}

/**
    @brief is_player_targeting_any_char %1d%

    opcode 0456
    @arg player Player index
*/
bool opcode_0456(const ScriptArguments& args, const ScriptPlayer player) {
    RW_UNIMPLEMENTED_OPCODE(0x0456);
    RW_UNUSED(player);
    RW_UNUSED(args);
    return false;
}

/**
    @brief is_player_targeting_char %1d% %2d%

    opcode 0457
    @arg player Player index
    @arg ped Ped
*/
bool opcode_0457(const ScriptArguments& args, const ScriptPlayer player, const ScriptCharacter character) {
    RW_UNIMPLEMENTED_OPCODE(0x0457);
    RW_UNUSED(player);
    RW_UNUSED(character);
    RW_UNUSED(args);
    return false;
}

