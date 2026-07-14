/**
    @brief   is_player_in_area_2d %1d% coords %2d% %3d% to %4d% %5d% sphere %6b%

    opcode 0056
    @arg player Player
    @arg coord0 Coordinates
    @arg coord1 Coordinates
    @arg arg6 Boolean true/false
*/
bool opcode_0056(const ScriptArguments& args, const ScriptPlayer player, ScriptVec2 coord0, ScriptVec2 coord1, const ScriptBoolean arg6) {
    return script::objectInArea(args, player->getCharacter(), coord0, coord1, arg6);
}

/**
    @brief   is_player_in_area_3d %1d% coords %2d% %3d% %4d% to %5d% %6d% %7d% sphere %8b%

    opcode 0057
    @arg player Player
    @arg coord0 Coordinates
    @arg coord1 Coordinates
    @arg arg8 Boolean true/false
*/
bool opcode_0057(const ScriptArguments& args, const ScriptPlayer player, ScriptVec3 coord0, ScriptVec3 coord1, const ScriptBoolean arg8) {
    return script::objectInArea(args, player->getCharacter(), coord0, coord1, arg8);
}

/**
    @brief   is_char_in_area_2d %1d% from %2d% %3d% to %4d% %5d% sphere %6d%

    opcode 00a3
    @arg character Character/ped
    @arg coord0 Coordinates
    @arg coord1 Coordinates
    @arg arg6 Boolean true/false
*/
bool opcode_00a3(const ScriptArguments& args, const ScriptCharacter character, const ScriptVec2 coord0, const ScriptVec2 coord1, const ScriptBoolean arg6) {
    return script::objectInArea(args, character, coord0, coord1, arg6);
}

/**
    @brief   is_char_in_area_3d %1d% from %2d% %3d% %4d% to %5d% %6d% %7d% sphere %8d%

    opcode 00a4
    @arg character Character/ped
    @arg coord0 Coordinates
    @arg coord1 Coordinates
    @arg arg8 Boolean true/false
*/
bool opcode_00a4(const ScriptArguments& args, const ScriptCharacter character, const ScriptVec3 coord0, const ScriptVec3 coord1, const ScriptBoolean arg8) {
    return script::objectInArea(args, character, coord0, coord1, arg8);
}

/**
    @brief   is_car_in_area_2d %1d% from %2d% %3d% to %4d% %5d% sphere %6d%

    opcode 00b0
    @arg vehicle Car/vehicle
    @arg coord0 Coordinates
    @arg coord1 Coordinates
    @arg arg6 Boolean true/false
*/
bool opcode_00b0(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptVec2 coord0, const ScriptVec2 coord1, const ScriptBoolean arg6) {
    return script::objectInArea(args, vehicle, coord0, coord1, arg6);
}

/**
    @brief   is_car_in_area_3d %1d% from %2d% %3d% %4d% to %5d% %6d% %7d% sphere %8d%

    opcode 00b1
    @arg vehicle Car/vehicle
    @arg coord0 Coordinates
    @arg coord1 Coordinates
    @arg arg8 Boolean true/false
*/
bool opcode_00b1(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptVec3 coord0, const ScriptVec3 coord1, const ScriptBoolean arg8) {
    return script::objectInArea(args, vehicle, coord0, coord1, arg8);
}

/**
    @brief   player %1d% %6bin-sphere/%near_point %2d% %3d% radius %4d% %5d%

    opcode 00e3
    @arg player Player
    @arg center Center of object
    @arg radius Radius of object 
    @arg showMarker Show marker (True/False)
*/
bool opcode_00e3(const ScriptArguments& args, const ScriptPlayer player, const ScriptVec2 center, const ScriptVec2 radius, const ScriptBoolean showMarker) {
    auto plyChar = player->getCharacter();
    return script::objectInRadius(args, plyChar, center, radius, showMarker);
}

/**
    @brief   player %1d% %6b:in-sphere/%near_point_on_foot %2d% %3d% radius %4d% %5d%

    opcode 00e4
    @arg player Player
    @arg center Center of object
    @arg radius Radius of object
    @arg showMarker Show marker (True/False)
*/
bool opcode_00e4(const ScriptArguments& args, const ScriptPlayer player, const ScriptVec2 center, const ScriptVec2 radius, const ScriptBoolean showMarker) {
    auto plyChar = player->getCharacter();
    auto condition = plyChar->getCurrentVehicle() == nullptr;
    return script::objectInRadius(args, plyChar, center, radius, showMarker, condition);
}

/**
    @brief   player %1d% %6bin-sphere/%near_point_in_car %2d% %3d% radius %4d% %5d%

    opcode 00e5
    @arg player Player
    @arg center Center of object
    @arg radius Radius of object
    @arg showMarker Show marker (True/False)
*/
bool opcode_00e5(const ScriptArguments& args, const ScriptPlayer player, ScriptVec2 center, ScriptVec2 radius, const ScriptBoolean showMarker) {
    auto plyChar = player->getCharacter();
    auto condition = plyChar->getCurrentVehicle() != nullptr;
    return script::objectInRadius(args, plyChar, center, radius, showMarker, condition);
}

/**
    @brief   player %1d% stopped %6bin-sphere/%near_point %2d% %3d% radius %4d% %5d%

    opcode 00e6
    @arg player Player
    @arg center Center of object
    @arg radius Radius of object
    @arg showMarker Show marker (True/False)
*/
bool opcode_00e6(const ScriptArguments& args, const ScriptPlayer player, ScriptVec2 center, ScriptVec2 radius, const ScriptBoolean showMarker) {
    auto plyChar = player->getCharacter();
    auto condition = plyChar->isStopped();
    return script::objectInRadius(args, plyChar, center, radius, showMarker, condition);
}

/**
    @brief   player %1d% stopped %6b:in-sphere/%near_point_on_foot %2d% %3d% radius %4d% %5d%

    opcode 00e7
    @arg player Player
    @arg center Center of object
    @arg radius Radius of object
    @arg showMarker Show marker (True/False)
*/
bool opcode_00e7(const ScriptArguments& args, const ScriptPlayer player, ScriptVec2 center, ScriptVec2 radius, const ScriptBoolean showMarker) {
    auto plyChar = player->getCharacter();
    auto condition = plyChar->isStopped() && plyChar->getCurrentVehicle() == nullptr;
    return script::objectInRadius(args, plyChar, center, radius, showMarker, condition);
}

/**
    @brief   player %1d% stopped %6b:in-sphere/%near_point_in_car %2d% %3d% radius %4d% %5d%

    opcode 00e8
    @arg player Player
    @arg center Center of object
    @arg radius Radius of object
    @arg showMarker Show marker (True/False)
*/
bool opcode_00e8(const ScriptArguments& args, const ScriptPlayer player, ScriptVec2 center, ScriptVec2 radius, const ScriptBoolean showMarker) {
    auto plyChar = player->getCharacter();
    auto condition = plyChar->isStopped() && plyChar->getCurrentVehicle() != nullptr;
    return script::objectInRadius(args, plyChar, center, radius, showMarker, condition);
}

/**
    @brief   player %1d% %5b:in-sphere/%near_actor %2d% radius %3d% %4d%

    opcode 00e9
    @arg player Player
    @arg character Character goal
    @arg radius Radius of goal
    @arg showMarker Show marker (True/False)
*/
bool opcode_00e9(const ScriptArguments& args, const ScriptPlayer player, const ScriptCharacter character, ScriptVec2 radius, const ScriptBoolean showMarker) {
    auto plyChar = player->getCharacter();
    /// @todo if character is in vehicle, game uses vehicle position instead of character one
    return script::objectInRadiusNear(args, plyChar, character, radius, showMarker);
}

/**
    @brief   player %1d% %5b:in-sphere/%near_actor_on_foot %2d% radius %3d% %4d%

    opcode 00ea
    @arg player Player
    @arg character Character goal
    @arg radius Radius of goal
    @arg showMarker Show marker (True/False)
*/
bool opcode_00ea(const ScriptArguments& args, const ScriptPlayer player, const ScriptCharacter character, ScriptVec2 radius, const ScriptBoolean showMarker) {
    auto plyChar = player->getCharacter();
    auto condition = plyChar->getCurrentVehicle() == nullptr;
    /// @todo if character is in vehicle, game uses vehicle position instead of character one
    return script::objectInRadiusNear(args, plyChar, character, radius, showMarker, condition);
}

/**
    @brief   player %1d% %5b:in-sphere/%near_actor_in_car %2d% radius %3d% %4d%

    opcode 00eb
    @arg player Player
    @arg character Character goal
    @arg radius Radius of goal
    @arg showMarker Show marker (True/False)
*/
bool opcode_00eb(const ScriptArguments& args, const ScriptPlayer player, const ScriptCharacter character, ScriptVec2 radius, const ScriptBoolean showMarker) {
    auto plyChar = player->getCharacter();
    auto condition = plyChar->getCurrentVehicle() != nullptr;
    /// @todo if character is in vehicle, game uses vehicle position instead of character one
    return script::objectInRadiusNear(args, plyChar, character, radius, showMarker, condition);
}

/**
    @brief   actor %1d% %6bin-sphere/%near_point %2d% %3d% radius %4d% %5d%

    opcode 00ec
    @arg character Character/ped
    @arg center Center of goal
    @arg radius Radius of goal
    @arg showMarker Show marker (True/False)
*/
bool opcode_00ec(const ScriptArguments& args, const ScriptCharacter character, ScriptVec2 center, ScriptVec2 radius, const ScriptBoolean showMarker) {
    return script::objectInRadius(args, character.get(), center, radius, showMarker);
}

/**
    @brief   actor %1d% %6bin-sphere/%near_point_on_foot %2d% %3d% radius %4d% %5d%

    opcode 00ed
    @arg character Character/ped
    @arg center Center of goal
    @arg radius Radius of goal
    @arg showMarker Show marker (True/False)
*/
bool opcode_00ed(const ScriptArguments& args, const ScriptCharacter character, ScriptVec2 center, ScriptVec2 radius, const ScriptBoolean showMarker) {
    auto condition = character->getCurrentVehicle() == nullptr;
    return script::objectInRadius(args, character.get(), center, radius, showMarker, condition);
}

/**
    @brief   actor %1d% %6bin-sphere/%near_point_in_car %2d% %3d% radius %4d% %5d%

    opcode 00ee
    @arg character Character/ped
    @arg center Center of goal
    @arg radius Radius of goal
    @arg showMarker Show marker (True/False)
*/
bool opcode_00ee(const ScriptArguments& args, const ScriptCharacter character, ScriptVec2 center, ScriptVec2 radius, const ScriptBoolean showMarker) {
    auto condition = character->getCurrentVehicle() != nullptr;
    return script::objectInRadius(args, character.get(), center, radius, showMarker, condition);
}

/**
    @brief   actor %1d% sphere %6bin-sphere/%near_point %2d% %3d% radius %4d% %5d%

    opcode 00ef
    @arg character Character/ped
    @arg center Center of goal
    @arg radius Radius of goal
    @arg showMarker Show marker (True/False)
*/
bool opcode_00ef(const ScriptArguments& args, const ScriptCharacter character, ScriptVec2 center, ScriptVec2 radius, const ScriptBoolean showMarker) {
    auto condition = character->isStopped();
    return script::objectInRadius(args, character.get(), center, radius, showMarker, condition);
}

/**
    @brief   actor %1d% stopped %6bin-sphere/%near_point_on_foot %2d% %3d% radius %4d% %5d%

    opcode 00f0
    @arg character Character/ped
    @arg center Center of goal
    @arg radius Radius of goal
    @arg showMarker Show marker (True/False)
*/
bool opcode_00f0(const ScriptArguments& args, const ScriptCharacter character, ScriptVec2 center, ScriptVec2 radius, const ScriptBoolean showMarker) {
    auto condition = character->isStopped() && character->getCurrentVehicle() == nullptr;
    return script::objectInRadius(args, character.get(), center, radius, showMarker, condition);
}

/**
    @brief   actor %1d% stopped %6bin-sphere/%near_point_in_car %2d% %3d% radius %4d% %5d%

    opcode 00f1
    @arg character Character/ped
    @arg center Center of goal
    @arg radius Radius of goal
    @arg showMarker Show marker (True/False)
*/
bool opcode_00f1(const ScriptArguments& args, const ScriptCharacter character, ScriptVec2 center, ScriptVec2 radius, const ScriptBoolean showMarker) {
    auto condition = character->isStopped() && character->getCurrentVehicle() != nullptr;
    return script::objectInRadius(args, character.get(), center, radius, showMarker, condition);
}

/**
    @brief   locate_char_any_means_char_2d %1d% char %2d% radius %3d% %4d% sphere %5h%

    opcode 00f2
    @arg character0 Character/ped
    @arg character1 Character/ped
    @arg radius Radius of goal
    @arg showMarker Show marker (True/False)
*/
bool opcode_00f2(const ScriptArguments& args, const ScriptCharacter character0, const ScriptCharacter character1, ScriptVec2 radius, const ScriptBoolean showMarker) {
    /// @todo if characters are in vehicles, game uses vehicle positions instead of character ones
    return script::objectInRadiusNear(args, character0, character1, radius, showMarker);
}

/**
    @brief   actor %1d% near_actor_on_foot %2d% radius %3d% %4d% sphere %5h%

    opcode 00f3
    @arg character0 Character/ped
    @arg character1 Character/ped
    @arg radius Radius of goal
    @arg showMarker Show marker (True/False)
*/
bool opcode_00f3(const ScriptArguments& args, const ScriptCharacter character0, const ScriptCharacter character1, ScriptVec2 radius, const ScriptBoolean showMarker) {
    auto condition = character0->getCurrentVehicle() == nullptr;
    /// @todo if characters are in vehicles, game uses vehicle positions instead of character ones
    return script::objectInRadiusNear(args, character0, character1, radius, showMarker, condition);
}

/**
    @brief   player %1d% %8b:in-sphere/%near_point %2d% %3d% %4d% radius %5d% %6d% %7d%

    opcode 00f5
    @arg player Player
    @arg center Center of object
    @arg radius Radius of object
    @arg showMarker Show marker (True/False)
*/
bool opcode_00f5(const ScriptArguments& args, const ScriptPlayer player, ScriptVec3 center, ScriptVec3 radius, const ScriptBoolean showMarker) {
    auto plyChar = player->getCharacter();
    return script::objectInRadius(args, plyChar, center, radius, showMarker);
}

/**
    @brief   player %1d% %8b:in-sphere/%near_point_on_foot %2d% %3d% %4d% radius %5d% %6d% %7d%

    opcode 00f6
    @arg player Player
    @arg center Center of object
    @arg radius Radius of object
    @arg showMarker Show marker (True/False)
*/
bool opcode_00f6(const ScriptArguments& args, const ScriptPlayer player, ScriptVec3 center, ScriptVec3 radius, const ScriptBoolean showMarker) {
    auto plyChar = player->getCharacter();
    auto condition = plyChar->getCurrentVehicle() == nullptr;
    return script::objectInRadius(args, plyChar, center, radius, showMarker, condition);
}

/**
    @brief   player %1d% sphere %8b% near_point_in_car %2d% %3d% %4d% radius %5d% %6d% %7d%

    opcode 00f7
    @arg player Player
    @arg center Center of object
    @arg radius Radius of object
    @arg showMarker Show marker (True/False)
*/
bool opcode_00f7(const ScriptArguments& args, const ScriptPlayer player, ScriptVec3 center, ScriptVec3 radius, const ScriptBoolean showMarker) {
    auto plyChar = player->getCharacter();
    auto condition = plyChar->getCurrentVehicle() != nullptr;
    return script::objectInRadius(args, plyChar, center, radius, showMarker, condition);
}

/**
    @brief   player %1d% stopped %8b:in-sphere/%near_point %2d% %3d% %4d% radius %5d% %6d% %7d%

    opcode 00f8
    @arg player Player
    @arg center Center of object
    @arg radius Radius of object
    @arg showMarker Show marker (True/False)
*/
bool opcode_00f8(const ScriptArguments& args, const ScriptPlayer player, ScriptVec3 center, ScriptVec3 radius, const ScriptBoolean showMarker) {
    auto plyChar = player->getCharacter();
    auto condition = plyChar->isStopped();
    return script::objectInRadius(args, plyChar, center, radius, showMarker, condition);
}

/**
    @brief   player %1d% stopped %8b:in-sphere/%near_point_on_foot %2d% %3d% %4d% radius %5d% %6d% %7d%

    opcode 00f9
    @arg player Player
    @arg center Center of object
    @arg radius Radius of object
    @arg showMarker Show marker (True/False)
*/
bool opcode_00f9(const ScriptArguments& args, const ScriptPlayer player, ScriptVec3 center, ScriptVec3 radius, const ScriptBoolean showMarker) {
    auto plyChar = player->getCharacter();
    auto condition = plyChar->isStopped() && plyChar->getCurrentVehicle() == nullptr;
    return script::objectInRadius(args, plyChar, center, radius, showMarker, condition);
}

/**
    @brief   player %1d% stopped %8b:in-sphere/%near_point_in_car %2d% %3d% %4d% radius %5d% %6d% %7d%

    opcode 00fa
    @arg player Player
    @arg center Center of object
    @arg radius Radius of object
    @arg showMarker Show marker (True/False)
*/
bool opcode_00fa(const ScriptArguments& args, const ScriptPlayer player, ScriptVec3 center, ScriptVec3 radius, const ScriptBoolean showMarker) {
    auto plyChar = player->getCharacter();
    auto condition = plyChar->isStopped() && plyChar->getCurrentVehicle() != nullptr;
    return script::objectInRadius(args, plyChar, center, radius, showMarker, condition);
}

/**
    @brief   player %1d% %6b:in-sphere/%near_actor %2d% radius %3d% %4d% %5d%

    opcode 00fb
    @arg player Player
    @arg character Character goal
    @arg radius Radius of goal
    @arg showMarker Show marker (True/False)
*/
bool opcode_00fb(const ScriptArguments& args, const ScriptPlayer player, const ScriptCharacter character, ScriptVec3 radius, const ScriptBoolean showMarker) {
    auto plyChar = player->getCharacter();
    /// @todo if character is in vehicle, game uses vehicle position instead of character one
    return script::objectInRadiusNear(args, plyChar, character, radius, showMarker);
}

/**
    @brief   player %1d% %6b:in-sphere/%near_actor %2d% on_foot radius %3d% %4d% %5d%

    opcode 00fc
    @arg player Player
    @arg character Character goal
    @arg radius Radius of goal
    @arg showMarker Show marker (True/False)
*/
bool opcode_00fc(const ScriptArguments& args, const ScriptPlayer player, const ScriptCharacter character, ScriptVec3 radius, const ScriptBoolean showMarker) {
    auto plyChar = player->getCharacter();
    auto condition = plyChar->getCurrentVehicle() == nullptr;
    /// @todo if character is in vehicle, game uses vehicle position instead of character one
    return script::objectInRadiusNear(args, plyChar, character, radius, showMarker, condition);
}

/**
    @brief   player %1d% %6b:in-sphere/%near_actor %2d% in_car radius %3d% %4d% %5d%

    opcode 00fd
    @arg player Player
    @arg character Character goal
    @arg radius Radius of goal
    @arg showMarker Show marker (True/False)
*/
bool opcode_00fd(const ScriptArguments& args, const ScriptPlayer player, const ScriptCharacter character, ScriptVec3 radius, const ScriptBoolean showMarker) {
    auto plyChar = player->getCharacter();
    auto condition = plyChar->getCurrentVehicle() != nullptr;
    /// @todo if character is in vehicle, game uses vehicle position instead of character one
    return script::objectInRadiusNear(args, plyChar, character, radius, showMarker, condition);
}

/**
    @brief   actor %1d% %8bin-sphere/%near_point %2d% %3d% %4d% radius %5d% %6d% %7d%

    opcode 00fe
    @arg player Player
    @arg center Center of object
    @arg radius Radius of object
    @arg showMarker Show marker (True/False)
*/
bool opcode_00fe(const ScriptArguments& args, const ScriptCharacter character, ScriptVec3 center, ScriptVec3 radius, const ScriptBoolean showMarker) {
    /// @todo if character is in vehicle, game uses vehicle position instead of character one
    return script::objectInRadius(args, character.get(), center, radius, showMarker);
}

/**
    @brief   actor %1d% %8bin-sphere/%near_point_on_foot %2d% %3d% %4d% radius %5d% %6d% %7d%

    opcode 00ff
    @arg player Player
    @arg center Center of object
    @arg radius Radius of object
    @arg showMarker Show marker (True/False)
*/
bool opcode_00ff(const ScriptArguments& args, const ScriptCharacter character, ScriptVec3 center, ScriptVec3 radius, const ScriptBoolean showMarker) {
    auto condition = character->getCurrentVehicle() == nullptr;
    /// @todo if character is in vehicle, game uses vehicle position instead of character one
    return script::objectInRadius(args, character.get(), center, radius, showMarker, condition);
}

/**
    @brief   actor %1d% near_point_in_car %2d% %3d% %4d% radius %5d% %6d% %7d% sphere %8h%

    opcode 0100
    @arg character Character/ped
    @arg center Center of object
    @arg radius Radius of object
    @arg showMarker Show marker (True/False)
*/
bool opcode_0100(const ScriptArguments& args, const ScriptCharacter character, ScriptVec3 center, ScriptVec3 radius, const ScriptBoolean showMarker) {
    auto condition = character->getCurrentVehicle() != nullptr;
    /// @todo if character is in vehicle, game uses vehicle position instead of character one
    return script::objectInRadius(args, character.get(), center, radius, showMarker, condition);
}

/**
    @brief   actor %1d% stopped_near_point %2d% %3d% %4d% radius %5d% %6d% %7d% sphere %8h%

    opcode 0101
    @arg character Character/ped
    @arg center Center of object
    @arg radius Radius of object
    @arg showMarker Show marker (True/False)
*/
bool opcode_0101(const ScriptArguments& args, const ScriptCharacter character, ScriptVec3 center, ScriptVec3 radius, const ScriptBoolean showMarker) {
    auto condition = character->isStopped();
    /// @todo if character is in vehicle, game uses vehicle position instead of character one
    return script::objectInRadius(args, character.get(), center, radius, showMarker, condition);
}

/**
    @brief   actor %1d% stopped_near_point_on_foot %2d% %3d% %4d% radius %5d% %6d% %7d% sphere %8h%

    opcode 0102
    @arg character Character/ped
    @arg center Center of object
    @arg radius Radius of object
    @arg showMarker Show marker (True/False)
*/
bool opcode_0102(const ScriptArguments& args, const ScriptCharacter character, ScriptVec3 center, ScriptVec3 radius, const ScriptBoolean showMarker) {
    auto condition = character->isStopped() && character->getCurrentVehicle() == nullptr;
    /// @todo if character is in vehicle, game uses vehicle position instead of character one
    return script::objectInRadius(args, character.get(), center, radius, showMarker, condition);
}

/**
    @brief   actor %1d% stopped_near_point_in_car %2d% %3d% %4d% radius %5d% %6d% %7d% sphere %8d%

    opcode 0103
    @arg character Character/ped
    @arg center Center of object
    @arg radius Radius of object
    @arg showMarker Show marker (True/False)
*/
bool opcode_0103(const ScriptArguments& args, const ScriptCharacter character, ScriptVec3 center, ScriptVec3 radius, const ScriptBoolean showMarker) {
    auto condition = character->isStopped() && character->getCurrentVehicle() != nullptr;
    /// @todo if character is in vehicle, game uses vehicle position instead of character one
    return script::objectInRadius(args, character.get(), center, radius, showMarker, condition);
}

/**
    @brief   actor %1d% near_actor %2d% radius %3d% %4d% %5d% sphere %6h%

    opcode 0104
    @arg character0 Character/ped
    @arg character1 Character/ped
    @arg radius Radius of goal
    @arg showMarker Show marker (True/False)
*/
bool opcode_0104(const ScriptArguments& args, const ScriptCharacter character0, const ScriptCharacter character1, ScriptVec3 radius, const ScriptBoolean showMarker) {
    /// @todo if characters are in vehicles, game uses vehicle positions instead of character ones
    return script::objectInRadiusNear(args, character0, character1, radius, showMarker);
}

/**
    @brief   actor %1d% near_actor_on_foot %2d% radius %3d% %4d% %5d% sphere %6h%

    opcode 0105
    @arg character0 Character/ped
    @arg character1 Character/ped
    @arg radius Radius of goal
    @arg showMarker Show marker (True/False)
*/
bool opcode_0105(const ScriptArguments& args, const ScriptCharacter character0, const ScriptCharacter character1, ScriptVec3 radius, const ScriptBoolean showMarker) {
    auto condition = character0->getCurrentVehicle() == nullptr;
    /// @todo if characters are in vehicles, game uses vehicle positions instead of character ones
    return script::objectInRadiusNear(args, character0, character1, radius, showMarker, condition);
}

/**
    @brief %5d% = create_object %1o% at %2d% %3d% %4d%

    opcode 0107
    @arg model Model ID
    @arg coord Coordinates
    @arg object Object
*/
void opcode_0107(const ScriptArguments& args, const ScriptModel model, ScriptVec3 coord, ScriptObject& object) {
    // @todo calculate distance from centre of mass to base of model and apply it as spawnOffset
    coord = script::getGround(args, coord);
    object = args.getWorld()->createInstance(script::getModel(args, model), coord);
    object->setStatic(true);
}

/**
    @brief destroy_object %1d%

    opcode 0108
    @arg object Object
*/
void opcode_0108(const ScriptArguments& args, const ScriptObject object) {
    args.getWorld()->destroyObjectQueued(object);
}

/**
    @brief %4d% = create_marker_above_object %1d% color %2d% visibility %3d%

    opcode 0163

    Creates and attaches blip for an object
    Note: not used in the game

    @arg instance Object
    @arg colour Blip colour
    @arg display Blip display mode
    @arg blip Created blip
*/
void opcode_0163(const ScriptArguments& args, const ScriptObject instance, const ScriptBlipColour colour, const ScriptBlipDisplay display, ScriptBlip& blip) {
    auto& data = script::createObjectBlip(args, instance);
    data.colour = colour;
    /// @todo change ScriptBlipDisplay to BlipData::DisplayMode
    data.display = static_cast <BlipData::DisplayMode> (display);
    blip = &data;
}

/**
    @brief create_particle %1a% %5d% %6d% %7d% %8d% %9d% %10d% at %2d% %3d% %4d%

    opcode 016f
    @arg arg1 
    @arg coord Coordinates
    @arg angle Angle
    @arg arg6 
    @arg arg7 
    @arg colour Colour (0-255)
*/
void opcode_016f(const ScriptArguments& args, const ScriptShadow arg1, ScriptVec3 coord, const ScriptFloat angle, const ScriptFloat arg6, const ScriptInt arg7, ScriptRGB colour) {
    RW_UNIMPLEMENTED_OPCODE(0x016f);
    RW_UNUSED(arg1);
    RW_UNUSED(coord);
    RW_UNUSED(angle);
    RW_UNUSED(arg6);
    RW_UNUSED(arg7);
    RW_UNUSED(colour);
    RW_UNUSED(args);
}

/**
    @brief %2d% = object %1d% z_angle

    opcode 0176
    @arg object Object
    @arg angle Angle
*/
void opcode_0176(const ScriptArguments& args, const ScriptObject object, ScriptFloat& angle) {
    RW_UNUSED(args);
    angle = object->getHeading();
}

/**
    @brief set_object %1d% z_angle_to %2d%

    opcode 0177
    @arg object Object
    @arg angle Angle
*/
void opcode_0177(const ScriptArguments& args, const ScriptObject object, const ScriptFloat angle) {
    RW_UNUSED(args);
    object->setHeading(angle);
}

/**
    @brief %2d% = create_marker_above_object %1d%

    opcode 0188
    @arg object Character/ped
    @arg blip Blip
*/
void opcode_0188(const ScriptArguments& args, const ScriptObject object, ScriptBlip& blip) {
    auto& data = script::createObjectBlip(args, object);
    blip = &data;
}

/**
    @brief   player %1d% %6b:in-sphere/%in_rectangle_on_foot %2d% %3d% %4d% %5d%

    opcode 0197
    @arg player Player
    @arg coord0 Coordinates
    @arg coord1 Coordinates
    @arg arg6 Boolean true/false
*/
bool opcode_0197(const ScriptArguments& args, const ScriptPlayer player, const ScriptVec2 coord0, const ScriptVec2 coord1, const ScriptBoolean arg6) {
    auto condition = player->getCharacter()->getCurrentVehicle() == nullptr;
    return script::objectInArea(args, player->getCharacter(), coord0, coord1, arg6, condition);
}

/**
    @brief   player %1d% %6b:in-sphere/%in_rectangle_in_car %2d% %3d% %4d% %5d%

    opcode 0198
    @arg player Player
    @arg coord0 Coordinates
    @arg coord1 Coordinates
    @arg arg6 Boolean true/false
*/
bool opcode_0198(const ScriptArguments& args, const ScriptPlayer player, const ScriptVec2 coord0, const ScriptVec2 coord1, const ScriptBoolean arg6) {
    auto condition = player->getCharacter()->getCurrentVehicle() != nullptr;
    return script::objectInArea(args, player->getCharacter(), coord0, coord1, arg6, condition);
}

/**
    @brief   player %1d% %6b:in-sphere/%in_rectangle %2d% %3d% %4d% %5d%

    opcode 0199
    @arg player Player
    @arg coord0 Coordinates
    @arg coord1 Coordinates
    @arg arg6 Boolean true/false
*/
bool opcode_0199(const ScriptArguments& args, const ScriptPlayer player, const ScriptVec2 coord0, const ScriptVec2 coord1, const ScriptBoolean arg6) {
    return script::objectInArea(args, player->getCharacter(), coord0, coord1, arg6);
}

/**
    @brief   player %1d% stopped %6b:in-sphere/%in_rectangle_on_foot %2d% %3d% %4d% %5d%

    opcode 019a
    @arg player 
    @arg coord0 
    @arg coord1 
    @arg arg6 
*/
bool opcode_019a(const ScriptArguments& args, const ScriptPlayer player, const ScriptVec2 coord0, const ScriptVec2 coord1, const ScriptInt arg6) {
    auto condition = player->getCharacter()->getCurrentVehicle() == nullptr && player->getCharacter()->isStopped(); 
    return script::objectInArea(args, player->getCharacter(), coord0, coord1, arg6, condition);
}

/**
    @brief   player %1d% stopped %6b:in-sphere/%in_rectangle_in_car %2d% %3d% %4d% %5d%

    opcode 019b
    @arg player 
    @arg coord0 
    @arg coord1 
    @arg arg6 
*/
bool opcode_019b(const ScriptArguments& args, const ScriptPlayer player, const ScriptVec2 coord0, const ScriptVec2 coord1, const ScriptInt arg6) {
    auto condition = player->getCharacter()->getCurrentVehicle() != nullptr && player->getCharacter()->isStopped(); 
    return script::objectInArea(args, player->getCharacter(), coord0, coord1, arg6, condition);
}

/**
    @brief   player %1d% %8b:in-sphere/%in_cube_on_foot %2d% %3d% %4d% %5d% %6d% %7d%

    opcode 019c
    @arg player 
    @arg coord0 
    @arg coord1 
    @arg arg8 
*/
bool opcode_019c(const ScriptArguments& args, const ScriptPlayer player, const ScriptVec3 coord0, const ScriptVec3 coord1, const ScriptInt arg8) {
    auto condition = player->getCharacter()->getCurrentVehicle() == nullptr;
    return script::objectInArea(args, player->getCharacter(), coord0, coord1, arg8, condition);
}

/**
    @brief   player %1d% %8b:in-sphere/%in_cube_in_car %2d% %3d% %4d% %5d% %6d% %7d%

    opcode 019d
    @arg player 
    @arg coord0 
    @arg coord1 
    @arg arg8 
*/
bool opcode_019d(const ScriptArguments& args, const ScriptPlayer player, const ScriptVec3 coord0, const ScriptVec3 coord1, const ScriptInt arg8) {
    auto condition = player->getCharacter()->getCurrentVehicle() != nullptr;
    return script::objectInArea(args, player->getCharacter(), coord0, coord1, arg8, condition);
}

/**
    @brief   player %1d% stopped %8b:in-sphere/%in_cube %2d% %3d% %4d% %5d% %6d% %7d%

    opcode 019e
    @arg player 
    @arg coord0
    @arg coord1
    @arg arg8 
*/
bool opcode_019e(const ScriptArguments& args, const ScriptPlayer player, const ScriptVec3 coord0, const ScriptVec3 coord1, const ScriptInt arg8) {
    auto condition = player->getCharacter()->isStopped();
    return script::objectInArea(args, player->getCharacter(), coord0, coord1, arg8, condition);
}

/**
    @brief   player %1d% stopped %8b:in-sphere/%in_cube_on_foot %2d% %3d% %4d% %5d% %6d% %7d%

    opcode 019f
    @arg player 
    @arg coord0
    @arg coord1
    @arg arg8 
*/
bool opcode_019f(const ScriptArguments& args, const ScriptPlayer player, const ScriptVec3 coord0, const ScriptVec3 coord1, const ScriptInt arg8) {
    auto condition = player->getCharacter()->getCurrentVehicle() == nullptr && player->getCharacter()->isStopped();
    return script::objectInArea(args, player->getCharacter(), coord0, coord1, arg8, condition);
}

/**
    @brief   player %1d% stopped %8b:in-sphere/%in_cube_in_car %2d% %3d% %4d% %5d% %6d% %7d%

    opcode 01a0
    @arg player 
    @arg coord0
    @arg coord1
    @arg arg8 
*/
bool opcode_01a0(const ScriptArguments& args, const ScriptPlayer player, const ScriptVec3 coord0, const ScriptVec3 coord1, const ScriptInt arg8) {
    auto condition = player->getCharacter()->getCurrentVehicle() != nullptr && player->getCharacter()->isStopped();
    return script::objectInArea(args, player->getCharacter(), coord0, coord1, arg8, condition);
}

/**
    @brief   actor %1d% %6b:in-sphere/%in_rectangle_on_foot %2d% %3d% %4d% %5d%

    opcode 01a1
    @arg character Character/ped
    @arg coord0 Coordinates
    @arg coord1 Coordinates
    @arg arg6 Boolean true/false
*/
bool opcode_01a1(const ScriptArguments& args, const ScriptCharacter character, const ScriptVec2 coord0, const ScriptVec2 coord1, const ScriptBoolean arg6) {
    auto condition = character->getCurrentVehicle() == nullptr;
    return script::objectInArea(args, character, coord0, coord1, arg6, condition);
}

/**
    @brief   actor %1d% %6b:in-sphere/%in_rectangle_in_car %2d% %3d% %4d% %5d%

    opcode 01a2
    @arg character Character/ped
    @arg coord0 Coordinates
    @arg coord1 Coordinates
    @arg arg6 Boolean true/false
*/
bool opcode_01a2(const ScriptArguments& args, const ScriptCharacter character, const ScriptVec2 coord0, const ScriptVec2 coord1, const ScriptBoolean arg6) {
    auto condition = character->getCurrentVehicle() != nullptr;
    return script::objectInArea(args, character, coord0, coord1, arg6, condition);
}

/**
    @brief   actor %1d% stopped %6bin-sphere/%in_rectangle %2d% %3d% %4d% %5d%

    opcode 01a3
    @arg character Character/ped
    @arg coord0 Coordinates
    @arg coord1 Coordinates
    @arg arg6 Boolean true/false
*/
bool opcode_01a3(const ScriptArguments& args, const ScriptCharacter character, const ScriptVec2 coord0, const ScriptVec2 coord1, const ScriptBoolean arg6) {
    auto condition = character->isStopped();
    return script::objectInArea(args, character, coord0, coord1, arg6, condition);
}

/**
    @brief   actor %1d% stopped %6bin-sphere/%in_rectangle_on_foot %2d% %3d% %4d% %5d%

    opcode 01a4
    @arg character Character/ped
    @arg coord0 Coordinates
    @arg coord1 Coordinates
    @arg arg6 Boolean true/false
*/
bool opcode_01a4(const ScriptArguments& args, const ScriptCharacter character, const ScriptVec2 coord0, const ScriptVec2 coord1, const ScriptBoolean arg6) {
    auto condition = character->getCurrentVehicle() == nullptr && character->isStopped();
    return script::objectInArea(args, character, coord0, coord1, arg6, condition);
}

/**
    @brief   actor %1d% stopped %6b:in-sphere/%in_rectangle_in_car %2d% %3d% %4d% %5d%

    opcode 01a5
    @arg character Character/ped
    @arg coord0 Coordinates
    @arg coord1 Coordinates
    @arg arg6 Boolean true/false
*/
bool opcode_01a5(const ScriptArguments& args, const ScriptCharacter character, const ScriptVec2 coord0, const ScriptVec2 coord1, const ScriptBoolean arg6) {
    auto condition = character->getCurrentVehicle() != nullptr && character->isStopped();
    return script::objectInArea(args, character, coord0, coord1, arg6, condition);
}

/**
    @brief   actor %1d% %8b:in-sphere/%in_cube_on_foot %2d% %3d% %4d% %5d% %6d% %7d%

    opcode 01a6
    @arg character Character/ped
    @arg coord0 Coordinates
    @arg coord1 Coordinates
    @arg arg8 Boolean true/false
*/
bool opcode_01a6(const ScriptArguments& args, const ScriptCharacter character, const ScriptVec3 coord0, const ScriptVec3 coord1, const ScriptBoolean arg8) {
    auto condition = character->getCurrentVehicle() == nullptr;
    return script::objectInArea(args, character, coord0, coord1, arg8, condition);
}

/**
    @brief   actor %1d% %8b:in-sphere/%in_cube_in_car %2d% %3d% %4d% %5d% %6d% %7d%

    opcode 01a7
    @arg character Character/ped
    @arg coord0 Coordinates
    @arg coord1 Coordinates
    @arg arg8 Boolean true/false
*/
bool opcode_01a7(const ScriptArguments& args, const ScriptCharacter character, const ScriptVec3 coord0, const ScriptVec3 coord1, const ScriptBoolean arg8) {
    auto condition = character->getCurrentVehicle() != nullptr;
    return script::objectInArea(args, character, coord0, coord1, arg8, condition);
}

/**
    @brief   actor %1d% stopped %8bin-sphere/%in_cube %2d% %3d% %4d% %5d% %6d% %7d%

    opcode 01a8
    @arg character Character/ped
    @arg coord0 Coordinates
    @arg coord1 Coordinates
    @arg arg8 Boolean true/false
*/
bool opcode_01a8(const ScriptArguments& args, const ScriptCharacter character, const ScriptVec3 coord0, const ScriptVec3 coord1, const ScriptBoolean arg8) {
    auto condition = character->isStopped();
    return script::objectInArea(args, character, coord0, coord1, arg8, condition);
}

/**
    @brief   actor %1d% stopped %8b:in-sphere/%in_cube_on_foot %2d% %3d% %4d% %5d% %6d% %7d%

    opcode 01a9
    @arg character Character/ped
    @arg coord0 Coordinates
    @arg coord1 Coordinates
    @arg arg8 Boolean true/false
*/
bool opcode_01a9(const ScriptArguments& args, const ScriptCharacter character, const ScriptVec3 coord0, const ScriptVec3 coord1, const ScriptBoolean arg8) {
    auto condition = character->getCurrentVehicle() == nullptr && character->isStopped();
    return script::objectInArea(args, character, coord0, coord1, arg8, condition);
}

/**
    @brief   actor %1d% stopped %8b:in-sphere/%in_cube_in_car %2d% %3d% %4d% %5d% %6d% %7d%

    opcode 01aa
    @arg character Character/ped
    @arg coord0 Coordinates
    @arg coord1 Coordinates
    @arg arg8 Boolean true/false
*/
bool opcode_01aa(const ScriptArguments& args, const ScriptCharacter character, const ScriptVec3 coord0, const ScriptVec3 coord1, const ScriptBoolean arg8) {
    auto condition = character->getCurrentVehicle() != nullptr && character->isStopped();
    return script::objectInArea(args, character, coord0, coord1, arg8, condition);
}

/**
    @brief   car %1d% stopped %6b:in-sphere/%in_rectangle %2d% %3d% %4d% %5d%

    opcode 01ab
    @arg vehicle Character/ped
    @arg coord0 Coordinates
    @arg coord1 Coordinates
    @arg arg6 Boolean true/false
*/
bool opcode_01ab(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptVec2 coord0, const ScriptVec2 coord1, const ScriptBoolean arg6) {
    auto condition = vehicle->isStopped();
    return script::objectInArea(args, vehicle, coord0, coord1, arg6, condition);
}

/**
    @brief   car %1d% stopped %8b:in-sphere/%in_cube %2d% %3d% %4d% %5d% %6d% %7d%

    opcode 01ac
    @arg vehicle Car/vehicle
    @arg coord0 Coordinates
    @arg coord1 Coordinates
    @arg arg8 Boolean true/false
*/
bool opcode_01ac(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptVec3 coord0, const ScriptVec3 coord1, const ScriptBoolean arg8) {
    auto condition = vehicle->isStopped();
    return script::objectInArea(args, vehicle, coord0, coord1, arg8, condition);
}

/**
    @brief   car %1d% sphere %6b% near_point %2d% %3d% radius %4d% %5d%

    opcode 01ad
    @arg vehicle Car/vehicle
    @arg coord Coordinates
    @arg radius Radius
    @arg arg6 Boolean true/false
*/
bool opcode_01ad(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptVec2 coord, const ScriptVec2 radius, const ScriptBoolean arg6) {
    return script::objectInRadius(args, vehicle, coord, radius, arg6);
}

/**
    @brief   car %1d% stopped %6b:in-sphere/%near_point %2d% %3d% %4d% %5d%

    opcode 01ae
    @arg vehicle Car/vehicle
    @arg coord Coordinates
    @arg radius Radius
    @arg arg6 Boolean true/false
*/
bool opcode_01ae(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptVec2 coord, const ScriptVec2 radius, const ScriptBoolean arg6) {
    auto condition = vehicle->isStopped();
    return script::objectInRadius(args, vehicle, coord, radius, arg6, condition);
}

/**
    @brief   car %1d% %8bin-sphere/%near_point %2d% %3d% %4d% radius %5d% %6d% %7d%

    opcode 01af
    @arg vehicle Car/vehicle
    @arg coord Coordinates
    @arg radius Radius
    @arg arg8 Boolean true/false
*/
bool opcode_01af(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptVec3 coord, const ScriptVec3 radius, const ScriptBoolean arg8) {
    return script::objectInRadius(args, vehicle, coord, radius, arg8);
}

/**
    @brief   car %1d% stopped %8b:in-sphere/%near_point %2d% %3d% %4d% radius %5d% %6d% %7d%

    opcode 01b0
    @arg vehicle Character/ped
    @arg coord Coordinates
    @arg radius Radius
    @arg arg8 Boolean true/false
*/
bool opcode_01b0(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptVec3 coord, const ScriptVec3 radius, const ScriptBoolean arg8) {
    auto condition = vehicle->isStopped();
    return script::objectInRadius(args, vehicle, coord, radius, arg8, condition);
}

/**
    @brief store_object %1d% position_to %2d% %3d% %4d%

    opcode 01bb
    @arg object Object
    @arg xCoord X Coord
    @arg yCoord Y Coord
    @arg zCoord Z Coord
*/
void opcode_01bb(const ScriptArguments& args, const ScriptObject object, ScriptFloat& xCoord, ScriptFloat& yCoord, ScriptFloat& zCoord) {
    RW_UNUSED(args);
    script::getObjectPosition(object, xCoord, yCoord, zCoord);
}

/**
    @brief set_object_coordinates %1d% at %2d% %3d% %4d%

    opcode 01bc
    @arg object Object
    @arg coord Coordinates
*/
void opcode_01bc(const ScriptArguments& args, const ScriptObject object, ScriptVec3 coord) {
    script::setObjectPosition(object, coord);
    script::clearSpaceForObject(args, object);
}

/**
    @brief remove_references_to_object %1d%

    opcode 01c4
    @arg object Object
*/
void opcode_01c4(const ScriptArguments& args, const ScriptObject object) {
    /// @todo: there's more logic than only changing life time, or maybe it should be done in cleanUpTraffic
    if (object) {
        object->setLifetime(GameObject::TrafficLifetime);
        
        if (args.getThread()->isMission) {
            script::removeObjectFromMissionCleanup(args, object);
        }
    }
}

/**
    @brief actor %1d% destroy_object %2d%

    opcode 01d8
    @arg character 
    @arg object 
*/
void opcode_01d8(const ScriptArguments& args, const ScriptCharacter character, const ScriptObject object) {
    RW_UNIMPLEMENTED_OPCODE(0x01d8);
    RW_UNUSED(character);
    RW_UNUSED(object);
    RW_UNUSED(args);
}

/**
    @brief clear_leader %1d%

    opcode 01e0
    @arg character 
*/
void opcode_01e0(const ScriptArguments& args, const ScriptCharacter character) {
    RW_UNUSED(args);
    character->controller->setTargetCharacter(nullptr);
}

/**
    @brief switch_roads_on %1d% %2d% %3d% to %4d% %5d% %6d%

    opcode 01e7
    @arg coord0 Coordinates
    @arg coord1 Coordinates
*/
void opcode_01e7(const ScriptArguments& args, ScriptVec3 coord0, ScriptVec3 coord1) {
    args.getWorld()->enableAIPaths(ai::NodeType::Vehicle, coord0, coord1);
}

/**
    @brief switch_roads_off %1d% %2d% %3d% to %4d% %5d% %6d%

    opcode 01e8
    @arg coord0 Coordinates
    @arg coord1 Coordinates
*/
void opcode_01e8(const ScriptArguments& args, ScriptVec3 coord0, ScriptVec3 coord1) {
    args.getWorld()->disableAIPaths(ai::NodeType::Vehicle, coord0, coord1);
}

/**
    @brief   actor %1d% near_car %2d% radius %3d% %4d% sphere %5d%

    opcode 0202
    @arg character Character/ped
    @arg vehicle Car/vehicle
    @arg radius Radius
    @arg arg5 Boolean true/false
*/
bool opcode_0202(const ScriptArguments& args, const ScriptCharacter character, const ScriptVehicle vehicle, ScriptVec2 radius, const ScriptBoolean showMarker) {
    return script::objectInRadiusNear(args, character, vehicle, radius, showMarker);
}

/**
    @brief create_explosion %4d% at %1d% %2d% %3d%

    opcode 020c
    @arg coord Coordinates
    @arg explosionID Explosion ID
*/
void opcode_020c(const ScriptArguments& args, ScriptVec3 coord, const ScriptExplosion explosionID) {
    RW_UNIMPLEMENTED_OPCODE(0x020c);
    RW_UNUSED(coord);
    RW_UNUSED(explosionID);
    RW_UNUSED(args);
}

/**
    @brief has_player_collided_with_object %1d% %2d%

    opcode 023a
    @arg player 
    @arg object 
*/
void opcode_023a(const ScriptArguments& args, const ScriptPlayer player, const ScriptObject object) {
    RW_UNIMPLEMENTED_OPCODE(0x023a);
    RW_UNUSED(player);
    RW_UNUSED(object);
    RW_UNUSED(args);
}

/**
    @brief has_actor_collided_with_object %1d% %2d%

    opcode 023b
    @arg character Character/ped
    @arg object Object
*/
void opcode_023b(const ScriptArguments& args, const ScriptCharacter character, const ScriptObject object) {
    RW_UNIMPLEMENTED_OPCODE(0x023b);
    RW_UNUSED(character);
    RW_UNUSED(object);
    RW_UNUSED(args);
}

/**
    @brief flash_object %1d% %2d%

    opcode 0240
    @arg object Object
    @arg arg2 Boolean true/false
*/
void opcode_0240(const ScriptArguments& args, const ScriptObject object, const ScriptBoolean arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x0240);
    RW_UNUSED(object);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief create_light_at %1d% %2d% %3d% RGB_values %4d% %5d% %6d%

    opcode 0250
    @arg coord Coordinates
    @arg colour Colour (0-255)
*/
void opcode_0250(const ScriptArguments& args, ScriptVec3 coord, ScriptRGB colour) {
    RW_UNIMPLEMENTED_OPCODE(0x0250);
    RW_UNUSED(coord);
    RW_UNUSED(colour);
    RW_UNUSED(args);
}

/**
    @brief %5d% = create_object %1o% at %2d% %3d% %4d%

    opcode 029b
    @arg model Model ID
    @arg coord Coordinates
    @arg object Object
*/
void opcode_029b(const ScriptArguments& args, const ScriptModel model, ScriptVec3 coord, ScriptObject& object) {
    coord = script::getGround(args, coord);
    object = args.getWorld()->createInstance(script::getModel(args, model), coord);
    object->setStatic(true);
}

/**
    @brief create_particle %1a% %5d% at %2d% %3d% %4d%

    opcode 02a2
    @arg arg1 
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
*/
void opcode_02a2(const ScriptArguments& args, const ScriptPObject arg1, const ScriptFloat arg2, const ScriptFloat arg3, const ScriptFloat arg4, const ScriptInt arg5) {
    RW_UNIMPLEMENTED_OPCODE(0x02a2);
    RW_UNUSED(arg1);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(args);
}

/**
    @brief %5d% = create_icon_marker_and_sphere %4d% at %1d% %2d% %3d%

    opcode 02a7
    @arg coord Coordinates
    @arg blipSprite Blip sprite ID
    @arg blip Blip
*/
void opcode_02a7(const ScriptArguments& args, ScriptVec3 coord, const ScriptRadarSprite blipSprite, ScriptBlip& blip) {
    auto& data = script::createBlipSprite(args, coord, BlipData::Contact, blipSprite);
    blip = &data;
    RW_UNIMPLEMENTED("Radar Blip Indicator Sphere");
}

/**
    @brief   player %1d% in_area %2d% %3d% %4d% %5d% radius %6d% sphere %7h%

    opcode 02ad
    @arg player Player
    @arg coord0 Coordinates
    @arg coord1 Coordinates
    @arg radius Radius
    @arg arg7 Boolean true/false
*/
bool opcode_02ad(const ScriptArguments& args, const ScriptPlayer player, ScriptVec2 coord0, ScriptVec2 coord1, const ScriptFloat radius, const ScriptBoolean arg7) {
    RW_UNIMPLEMENTED_OPCODE(0x02ad);
    RW_UNUSED(player);
    RW_UNUSED(coord0);
    RW_UNUSED(coord1);
    RW_UNUSED(radius);
    RW_UNUSED(arg7);
    RW_UNUSED(args);
    return false;
}

/**
    @brief   player %1d% in_area_on_foot %2d% %3d% %4d% %5d% radius %6d% sphere %7h%

    opcode 02ae
    @arg player Player
    @arg coord0 Coordinates
    @arg coord1 Coordinates
    @arg radius Radius
    @arg arg7 Boolean true/false
*/
bool opcode_02ae(const ScriptArguments& args, const ScriptPlayer player, ScriptVec2 coord0, ScriptVec2 coord1, const ScriptFloat radius, const ScriptBoolean arg7) {
    RW_UNIMPLEMENTED_OPCODE(0x02ae);
    RW_UNUSED(player);
    RW_UNUSED(coord0);
    RW_UNUSED(coord1);
    RW_UNUSED(radius);
    RW_UNUSED(arg7);
    RW_UNUSED(args);
    return false;
}

/**
    @brief   player %1d% in_area_in_car %2d% %3d% %4d% %5d% radius %6d% sphere %7h%

    opcode 02af
    @arg player Player
    @arg coord0 Coordinates
    @arg coord1 Coordinates
    @arg radius Radius
    @arg arg7 Boolean true/false
*/
bool opcode_02af(const ScriptArguments& args, const ScriptPlayer player, ScriptVec2 coord0, ScriptVec2 coord1, const ScriptFloat radius, const ScriptBoolean arg7) {
    RW_UNIMPLEMENTED_OPCODE(0x02af);
    RW_UNUSED(player);
    RW_UNUSED(coord0);
    RW_UNUSED(coord1);
    RW_UNUSED(radius);
    RW_UNUSED(arg7);
    RW_UNUSED(args);
    return false;
}

/**
    @brief   player %1d% stopped_in_area %2d% %3d% %4d% %5d% radius %6d% sphere %7h%

    opcode 02b0
    @arg player 
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
    @arg arg7 
*/
bool opcode_02b0(const ScriptArguments& args, const ScriptPlayer player, const ScriptFloat arg2, const ScriptFloat arg3, const ScriptFloat arg4, const ScriptFloat arg5, const ScriptFloat arg6, const ScriptInt arg7) {
    RW_UNIMPLEMENTED_OPCODE(0x02b0);
    RW_UNUSED(player);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(arg6);
    RW_UNUSED(arg7);
    RW_UNUSED(args);
    return false;
}

/**
    @brief   player %1d% stopped_in_area_on_foot %2d% %3d% %4d% %5d% radius %6d% sphere %7h%

    opcode 02b1
    @arg player 
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
    @arg arg7 
*/
bool opcode_02b1(const ScriptArguments& args, const ScriptPlayer player, const ScriptFloat arg2, const ScriptFloat arg3, const ScriptFloat arg4, const ScriptFloat arg5, const ScriptFloat arg6, const ScriptInt arg7) {
    RW_UNIMPLEMENTED_OPCODE(0x02b1);
    RW_UNUSED(player);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(arg6);
    RW_UNUSED(arg7);
    RW_UNUSED(args);
    return false;
}

/**
    @brief   player %1d% stopped_in_area_in_car %2d% %3d% %4d% %5d% radius %6d% sphere %7h%

    opcode 02b2
    @arg player 
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
    @arg arg7 
*/
bool opcode_02b2(const ScriptArguments& args, const ScriptPlayer player, const ScriptFloat arg2, const ScriptFloat arg3, const ScriptFloat arg4, const ScriptFloat arg5, const ScriptFloat arg6, const ScriptInt arg7) {
    RW_UNIMPLEMENTED_OPCODE(0x02b2);
    RW_UNUSED(player);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(arg6);
    RW_UNUSED(arg7);
    RW_UNUSED(args);
    return false;
}

/**
    @brief   player %1d% in_cube %2d% %3d% %4d% %5d% %6d% %7d% radius %8d% sphere %9h%

    opcode 02b3
    @arg player 
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
    @arg arg7 
    @arg arg8 
    @arg arg9 
*/
bool opcode_02b3(const ScriptArguments& args, const ScriptPlayer player, const ScriptFloat arg2, const ScriptFloat arg3, const ScriptFloat arg4, const ScriptFloat arg5, const ScriptFloat arg6, const ScriptFloat arg7, const ScriptFloat arg8, const ScriptInt arg9) {
    RW_UNUSED(args);
    bool inArea;

    if (arg9) {
        RW_UNIMPLEMENTED("02B3: in_cube sphere");
        inArea = false;
    } else {
        const glm::vec3& p = player.get()->getCharacter()->getPosition();

        float angle = std::atan2(arg3 - arg6, arg5 - arg2);
        float x = arg8 * std::cos(angle);
        float y = arg8 * std::sin(angle);

        glm::vec2 AB = glm::vec2(arg2 - (arg2 - x), arg3 - (arg3 - y));
        glm::vec2 AM = glm::vec2(arg2 - p.x, arg3 - p.y);
        glm::vec2 BC = glm::vec2((arg2 - x) - (arg5 - x), (arg3 - y) - (arg6 - y));
        glm::vec2 BM = glm::vec2(arg2 - p.x, arg3 - p.y);
        float dotABAM = glm::dot(AB, AM);
        float dotBCBM = glm::dot(BC, BM);

        inArea = (p.z >= arg4 && p.z <= arg7 &&
                  0 < dotABAM && dotABAM < glm::dot(AB, AB) &&
                  0 < dotBCBM && dotBCBM < glm::dot(BC, BC));
    }

    return inArea;
}

/**
    @brief   player %1d% in_cube_on_foot %2d% %3d% %4d% %5d% %6d% %7d% radius %8d% sphere %9h%

    opcode 02b4
    @arg player 
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
    @arg arg7 
    @arg arg8 
    @arg arg9 
*/
bool opcode_02b4(const ScriptArguments& args, const ScriptPlayer player, const ScriptFloat arg2, const ScriptFloat arg3, const ScriptFloat arg4, const ScriptFloat arg5, const ScriptFloat arg6, const ScriptFloat arg7, const ScriptFloat arg8, const ScriptInt arg9) {
    RW_UNIMPLEMENTED_OPCODE(0x02b4);
    RW_UNUSED(player);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(arg6);
    RW_UNUSED(arg7);
    RW_UNUSED(arg8);
    RW_UNUSED(arg9);
    RW_UNUSED(args);
    return false;
}

/**
    @brief   player %1d% in_cube_in_car %2d% %3d% %4d% %5d% %6d% %7d% radius %8d% sphere %9h%

    opcode 02b5
    @arg player Player
    @arg coord0 Coordinates
    @arg coord1 Coordinates
    @arg radius Radius
    @arg arg9 Boolean true/false
*/
bool opcode_02b5(const ScriptArguments& args, const ScriptPlayer player, ScriptVec3 coord0, ScriptVec3 coord1, const ScriptFloat radius, const ScriptBoolean arg9) {
    RW_UNIMPLEMENTED_OPCODE(0x02b5);
    RW_UNUSED(player);
    RW_UNUSED(coord0);
    RW_UNUSED(coord1);
    RW_UNUSED(radius);
    RW_UNUSED(arg9);
    RW_UNUSED(args);
    return false;
}

/**
    @brief   player %1d% stopped_in_cube %2d% %3d% %4d% %5d% %6d% %7d% radius %8d% sphere %9h%

    opcode 02b6
    @arg player 
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
    @arg arg7 
    @arg arg8 
    @arg arg9 
*/
bool opcode_02b6(const ScriptArguments& args, const ScriptPlayer player, const ScriptFloat arg2, const ScriptFloat arg3, const ScriptFloat arg4, const ScriptFloat arg5, const ScriptFloat arg6, const ScriptFloat arg7, const ScriptFloat arg8, const ScriptInt arg9) {
    RW_UNIMPLEMENTED_OPCODE(0x02b6);
    RW_UNUSED(player);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(arg6);
    RW_UNUSED(arg7);
    RW_UNUSED(arg8);
    RW_UNUSED(arg9);
    RW_UNUSED(args);
    return false;
}

/**
    @brief   player %1d% stopped_in_cube_on_foot %2d% %3d% %4d% %5d% %6d% %7d% radius %8d% sphere %9h%

    opcode 02b7
    @arg player 
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
    @arg arg7 
    @arg arg8 
    @arg arg9 
*/
bool opcode_02b7(const ScriptArguments& args, const ScriptPlayer player, const ScriptFloat arg2, const ScriptFloat arg3, const ScriptFloat arg4, const ScriptFloat arg5, const ScriptFloat arg6, const ScriptFloat arg7, const ScriptFloat arg8, const ScriptInt arg9) {
    RW_UNIMPLEMENTED_OPCODE(0x02b7);
    RW_UNUSED(player);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(arg6);
    RW_UNUSED(arg7);
    RW_UNUSED(arg8);
    RW_UNUSED(arg9);
    RW_UNUSED(args);
    return false;
}

/**
    @brief   player %1d% stopped_in_cube_in_car %2d% %3d% %4d% %5d% %6d% %7d% radius %8d% sphere %9h%

    opcode 02b8
    @arg player Player
    @arg coord0 Coordinates
    @arg coord1 Coordinates
    @arg radius Radius
    @arg arg9 Boolean true/false
*/
bool opcode_02b8(const ScriptArguments& args, const ScriptPlayer player, ScriptVec3 coord0, ScriptVec3 coord1, const ScriptFloat radius, const ScriptBoolean arg9) {
    RW_UNIMPLEMENTED_OPCODE(0x02b8);
    RW_UNUSED(player);
    RW_UNUSED(coord0);
    RW_UNUSED(coord1);
    RW_UNUSED(radius);
    RW_UNUSED(arg9);
    RW_UNUSED(args);
    return false;
}

/**
    @brief scatter_platinum %5d% at %1d% %2d% %3d% %4d%

    opcode 02c7
    @arg arg1 
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
*/
void opcode_02c7(const ScriptArguments& args, const ScriptFloat arg1, const ScriptFloat arg2, const ScriptFloat arg3, const ScriptFloat arg4, const ScriptInt arg5) {
    RW_UNIMPLEMENTED_OPCODE(0x02c7);
    RW_UNUSED(arg1);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(args);
}

/**
    @brief get_ground_z_for_3d_coord %1d% %2d% %3d% store_to %4d%

    opcode 02CE

    Gets the height in the z-axis of the ground below the specified coordinates point

    @arg x X coordinate
    @arg y Y coordinate
    @arg z Z coordinate
    @arg groundZ Z ground coordinate
*/
void opcode_02ce(const ScriptArguments& args, ScriptVec3 coord, ScriptFloat& groundZ) {
    auto groundPoint = script::getGround(args, coord);
    groundZ = groundPoint.z;
}

/**
    @brief   fire %1d% extinguished

    opcode 02d0
    @arg fire Fire
*/
bool opcode_02d0(const ScriptArguments& args, const ScriptFire fire) {
    RW_UNIMPLEMENTED_OPCODE(0x02d0);
    RW_UNUSED(fire);
    RW_UNUSED(args);
    return false;
}

/**
    @brief remove_fire %1d%

    opcode 02d1
    @arg fire Fire
*/
void opcode_02d1(const ScriptArguments& args, const ScriptFire fire) {
    RW_UNIMPLEMENTED_OPCODE(0x02d1);
    RW_UNUSED(fire);
    RW_UNUSED(args);
}

/**
    @brief %2d% = create_cutscene_object %1o%

    opcode 02e5
    @arg model Model ID
    @arg object Object
*/
void opcode_02e5(const ScriptArguments& args, const ScriptModelID model, ScriptObject& object) {
    RW_UNUSED(object);
    auto cutsceneObject = args.getWorld()->createCutsceneObject(
        model, args.getState()->currentCutscene->meta.sceneOffset);
    RW_CHECK(cutsceneObject != nullptr, "Failed to create cutscene Object");
    /// @todo use correct interface
    *args[1].globalInteger = cutsceneObject->getGameObjectID();
}

/**
    @brief   is_projectile_in_cube %1d% %2d% %3d% to %4d% %5d% %6d%

    opcode 02ee
    @arg coord0 Coordinates
    @arg coord1 Coordinates
*/
bool opcode_02ee(const ScriptArguments& args, ScriptVec3 coord0, ScriptVec3 coord1) {
    RW_UNIMPLEMENTED_OPCODE(0x02ee);
    RW_UNUSED(coord0);
    RW_UNUSED(coord1);
    RW_UNUSED(args);
    return false;
}

/**
    @brief destroy_projectiles_in_cube %1d% %2d% %3d% to %4d% %5d% %6d%

    opcode 02ef
    @arg arg1 
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
*/
void opcode_02ef(const ScriptArguments& args, const ScriptFloat arg1, const ScriptFloat arg2, const ScriptFloat arg3, const ScriptFloat arg4, const ScriptFloat arg5, const ScriptFloat arg6) {
    RW_UNIMPLEMENTED_OPCODE(0x02ef);
    RW_UNUSED(arg1);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(arg6);
    RW_UNUSED(args);
}

/**
    @brief drop_nautical_mine_at %1d% %2d% %3d%

    opcode 02f1
    @arg coord Coordinates
*/
void opcode_02f1(const ScriptArguments& args, ScriptVec3 coord) {
    RW_UNIMPLEMENTED_OPCODE(0x02f1);
    RW_UNUSED(coord);
    RW_UNUSED(args);
}

/**
    @brief load_object %1o% %2f%

    opcode 02f3
    @arg model Model ID
    @arg arg2 
*/
void opcode_02f3(const ScriptArguments& args, const ScriptModelID model, const ScriptString arg2) {
    args.getWorld()->loadSpecialModel(model, arg2);
}

/**
    @brief remove_all_fires

    opcode 031a
*/
void opcode_031a(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x031a);
    RW_UNUSED(args);
}

/**
    @brief   objects_in_cube %1d% %2d% %3d% to %4d% %5d% %6d% flags %7d% %8d% %9d% %10d% %11d%

    opcode 0339
    @arg coord0 Coordinates
    @arg coord1 Coordinates
    @arg arg7 Boolean true/false
    @arg arg8 Boolean true/false
    @arg arg9 Boolean true/false
    @arg arg10 Boolean true/false
    @arg arg11 Boolean true/false
*/
bool opcode_0339(const ScriptArguments& args, ScriptVec3 coord0, ScriptVec3 coord1, const ScriptBoolean solids, const ScriptBoolean cars, const ScriptBoolean actors, const ScriptBoolean objects, const ScriptBoolean particles) {
    RW_UNUSED(particles);
    if (solids) {
    	RW_UNIMPLEMENTED("0x339: solid flag");
    }
    if (actors) {
    	auto& actors = args.getWorld()->pedestrianPool.objects;
    	for (const auto& o : actors) {
                if (script::objectInBounds(o.second.get(), coord0, coord1)) {
    			return true;
    		}
    	}
    }
    if (cars) {
    	auto& cars = args.getWorld()->vehiclePool.objects;
    	for (const auto& o : cars) {
                if (script::objectInBounds(o.second.get(), coord0, coord1)) {
    			return true;
    		}
    	}
    }
    if (objects) {
    	auto& objects = args.getWorld()->instancePool.objects;
    	for (const auto& o : objects) {
                if (script::objectInBounds(o.second.get(), coord0, coord1)) {
    			return true;
    		}
    	}
    }
    return false;
}

/**
    @brief rotate_object %1d% from_angle %2d% to %3d% collision_check %4d%

    opcode 034d
    @arg object Object
    @arg angle0 Angle
    @arg angle1 Angle
    @arg arg4 Boolean true/false
*/
bool opcode_034d(const ScriptArguments& args, const ScriptObject object, const ScriptFloat angle0, const ScriptFloat angle1, const ScriptBoolean arg4) {
    RW_UNUSED(angle0);
    RW_UNUSED(arg4);
    if( object )
    {
    	/// @todo INTERPOLATE instead of just setting the heading.
    	object->setHeading(angle1);
    }
    RW_UNUSED(args);
    return true;
}

/**
    @brief move_object %1d% to %2d% %3d% %4d% speed %5d% %6d% %7d% collision_check %8d%

    opcode 034e
    @arg object Object
    @arg coord Coordinates
    @arg arg5 
    @arg arg6 
    @arg arg7 
    @arg arg8 Boolean true/false
*/
bool opcode_034e(const ScriptArguments& args, const ScriptObject object, ScriptVec3 coord, const ScriptFloat arg5, const ScriptFloat arg6, const ScriptFloat arg7, const ScriptBoolean arg8) {
    RW_UNUSED(args);
    const glm::vec3& curPos = object.m_object->getPosition();
    glm::vec3 newPos;

    if (curPos == coord) {
        return true;
    }

    newPos.x = (curPos.x < coord.x ? curPos.x + arg5 : curPos.x - arg5);
    newPos.y = (curPos.y < coord.y ? curPos.y + arg6 : curPos.y - arg6);
    newPos.z = (curPos.z < coord.z ? curPos.z + arg7 : curPos.z - arg7);

    if (arg8) {
        for (const auto& obj : args.getWorld()->pedestrianPool.objects) {
            if (glm::distance(newPos, obj.second->getPosition()) <= 2.1f) {
                return true;
            }
        }

        for (const auto& obj : args.getWorld()->vehiclePool.objects) {
            if (glm::distance(newPos, obj.second->getPosition()) <= 3.61f) {
                return true;
            }
        }
    }

    object.m_object->setPosition(newPos);

    return (newPos == coord);
}

/**
    @brief   explosion_type %1d% in_cube %2d% %3d% %4d% to %5d% %6d% %7d%

    opcode 0356
    @arg explosionID Explosion ID
    @arg coord0 Coordinates
    @arg coord1 Coordinates
*/
bool opcode_0356(const ScriptArguments& args, const ScriptExplosion explosionID, ScriptVec3 coord0, ScriptVec3 coord1) {
    RW_UNIMPLEMENTED_OPCODE(0x0356);
    RW_UNUSED(explosionID);
    RW_UNUSED(coord0);
    RW_UNUSED(coord1);
    RW_UNUSED(args);
    return false;
}

/**
    @brief place_object %1d% relative_to_car %2d% offset %3d% %4d% %5d%

    opcode 035c
    @arg object Object
    @arg vehicle Car/vehicle
    @arg offset Offset
*/
void opcode_035c(const ScriptArguments& args, const ScriptObject object, const ScriptVehicle vehicle, ScriptVec3 offset) {
    RW_UNIMPLEMENTED_OPCODE(0x035c);
    RW_UNUSED(object);
    RW_UNUSED(vehicle);
    RW_UNUSED(offset);
    RW_UNUSED(args);
}

/**
    @brief make_object %1d% targetable

    opcode 035d
    @arg object Object
*/
void opcode_035d(const ScriptArguments& args, const ScriptObject object) {
    RW_UNIMPLEMENTED_OPCODE(0x035d);
    RW_UNUSED(object);
    RW_UNUSED(args);
}

/**
    @brief toggle_model_render_at %1d% %2d% %3d% radius %4d% object %5o% %6d%

    opcode 0363
    @arg coord Coordinates
    @arg radius Radius
    @arg model Model ID
    @arg visible Boolean true/false
*/
void opcode_0363(const ScriptArguments& args, ScriptVec3 coord, const ScriptFloat radius, const ScriptModel model, const ScriptBoolean visible) {
    auto& models = args.getVM()->getFile().getModels();
    auto& modelName = models[-model];

    // Attempt to find the closest object
    InstanceObject* closestObject = nullptr;
    float closestDistance = radius;
    for(auto& i : args.getWorld()->instancePool.objects) {
        InstanceObject* object = static_cast<InstanceObject*>(i.second.get());

    	// Check if this instance has the correct model id, early out if it isn't
    	auto modelinfo = object->getModelInfo<BaseModelInfo>();
    	if (!boost::iequals(modelinfo->name, modelName)) {
    		continue;
    	}

    	// Calculate distance and check if this is the new closest object
    	// @todo will this somehow respect the objects centre of mass / bounding box or something?
    	float distance = glm::length(object->position - coord);
    	if (distance <= closestDistance) {
    		closestObject = object;
    		closestDistance = distance;
    	}
    }

    // If an object was found, set its visibility
    if (closestObject) {
    closestObject->setVisible(visible);
    }
}

/**
    @brief throw_object %1d% distance %2d% %3d% %4d%

    opcode 0381
    @arg object Object
    @arg offset Offset
*/
void opcode_0381(const ScriptArguments& args, const ScriptObject object, ScriptVec3 offset) {
    RW_UNIMPLEMENTED_OPCODE(0x0381);
    RW_UNUSED(object);
    RW_UNUSED(offset);
    RW_UNUSED(args);
}

/**
    @brief set_object %1d% collision_detection %2d%

    opcode 0382
    @arg object Object
    @arg arg2 Boolean true/false
*/
void opcode_0382(const ScriptArguments& args, const ScriptObject object, const ScriptBoolean arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x0382);
    RW_UNUSED(object);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief object %1d% scatter %2d% %3d% %4d%

    opcode 038c
    @arg object Object
    @arg offset Offset
*/
void opcode_038c(const ScriptArguments& args, const ScriptObject object, ScriptVec3 offset) {
    RW_UNIMPLEMENTED_OPCODE(0x038c);
    RW_UNUSED(object);
    RW_UNUSED(offset);
    RW_UNUSED(args);
}

/**
    @brief object %1d% toggle_in_moving_list %2d%

    opcode 0392
    @arg object Object
    @arg dynamic Boolean true/false
*/
void opcode_0392(const ScriptArguments& args, const ScriptObject object, const ScriptBoolean dynamic) {
    RW_UNUSED(args);
    object->setStatic(!dynamic);
}

/**
    @brief scatter_particles type %1a% %8d% %9d% %10d% %11d% %12d% from %2d% %3d% %4d% to %5d% %6d% %7d%

    opcode 039d
    @arg arg1 
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
    @arg arg7 
    @arg arg8 
    @arg arg9 
    @arg arg10 
    @arg arg11 
    @arg arg12 
*/
void opcode_039d(const ScriptArguments& args, const ScriptPObject arg1, const ScriptFloat arg2, const ScriptFloat arg3, const ScriptFloat arg4, const ScriptFloat arg5, const ScriptFloat arg6, const ScriptFloat arg7, const ScriptFloat arg8, const ScriptInt arg9, const ScriptInt arg10, const ScriptInt arg11, const ScriptInt arg12) {
    RW_UNIMPLEMENTED_OPCODE(0x039d);
    RW_UNUSED(arg1);
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
    RW_UNUSED(arg12);
    RW_UNUSED(args);
}

/**
    @brief set_rubbish %1b:visible/invisible%

    opcode 03ad
    @arg arg1 Boolean true/false
*/
void opcode_03ad(const ScriptArguments& args, const ScriptBoolean arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x03ad);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief remove_objects_from_cube %1d% %2d% %3d% to %4d% %5d% %6d%

    opcode 03ae
    @arg arg1 
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
*/
void opcode_03ae(const ScriptArguments& args, const ScriptFloat arg1, const ScriptFloat arg2, const ScriptFloat arg3, const ScriptFloat arg4, const ScriptFloat arg5, const ScriptFloat arg6) {
    RW_UNIMPLEMENTED_OPCODE(0x03ae);
    RW_UNUSED(arg1);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(arg6);
    RW_UNUSED(args);
}

/**
    @brief %5d% = create_sphere_at %1d% %2d% %3d% radius %4d%

    opcode 03bc
    @arg coord Coordinates
    @arg radius Radius
    @arg sphere Handle
*/
void opcode_03bc(const ScriptArguments& args, ScriptVec3 coord, const ScriptFloat radius, ScriptSphere& sphere) {
    RW_UNIMPLEMENTED_OPCODE(0x03bc);
    RW_UNUSED(coord);
    RW_UNUSED(radius);
    RW_UNUSED(sphere);
    RW_UNUSED(args);
}

/**
    @brief destroy_sphere %1d%

    opcode 03bd
    @arg sphere Handle
*/
void opcode_03bd(const ScriptArguments& args, const ScriptSphere sphere) {
    RW_UNIMPLEMENTED_OPCODE(0x03bd);
    RW_UNUSED(sphere);
    RW_UNUSED(args);
}

/**
    @brief   object %1d% exists

    opcode 03ca
    @arg object Object
*/
bool opcode_03ca(const ScriptArguments& args, const ScriptObject object) {
    RW_UNIMPLEMENTED_OPCODE(0x03ca);
    RW_UNUSED(object);
    RW_UNUSED(args);
    return false;
}

/**
    @brief increment_fires_extinguished

    opcode 0404
*/
void opcode_0404(const ScriptArguments& args) {
    args.getState()->gameStats.firesExtinguished++;
}

/**
    @brief save_dodo_flight_time %1d%

    opcode 0406
    @arg newTime 
*/
void opcode_0406(const ScriptArguments& args, const ScriptInt newTime) {
    if (args.getState()->gameStats.longestDodoFlight < newTime) {
        args.getState()->gameStats.longestDodoFlight = newTime;
    }
}

/**
    @brief set_object %1d% draw_last %2h%

    opcode 0418
    @arg object Object
    @arg arg2 Boolean true/false
*/
void opcode_0418(const ScriptArguments& args, const ScriptObject object, const ScriptBoolean arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x0418);
    RW_UNUSED(object);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief scatter_particle %1a% %8d% at %2d% %3d% %4d% to %5d% %6d% %7d%

    opcode 0437
    @arg arg1 
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
    @arg arg7 
    @arg arg8 
*/
void opcode_0437(const ScriptArguments& args, const ScriptParticle arg1, const ScriptFloat arg2, const ScriptFloat arg3, const ScriptFloat arg4, const ScriptFloat arg5, const ScriptFloat arg6, const ScriptFloat arg7, const ScriptFloat arg8) {
    RW_UNIMPLEMENTED_OPCODE(0x0437);
    RW_UNUSED(arg1);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(arg6);
    RW_UNUSED(arg7);
    RW_UNUSED(arg8);
    RW_UNUSED(args);
}

/**
    @brief object %1d% set_rotation %2d% %3d% %4d%

    opcode 0453
    @arg object Object
    @arg rotation Rotation
    @arg angle Angle
*/
void opcode_0453(const ScriptArguments& args, const ScriptObject object, ScriptVec2 rotation, const ScriptFloat angle) {
    RW_UNIMPLEMENTED_OPCODE(0x0453);
    RW_UNUSED(object);
    RW_UNUSED(rotation);
    RW_UNUSED(angle);
    RW_UNUSED(args);
}

/**
    @brief is_player_targeting_object %1d% %1d%

    opcode 0458
    @arg player Player index
    @arg object Object
*/
bool opcode_0458(const ScriptArguments& args, const ScriptPlayer player, const ScriptObject object) {
    RW_UNIMPLEMENTED_OPCODE(0x0458);
    RW_UNUSED(player);
    RW_UNUSED(object);
    RW_UNUSED(args);
    return false;
}

