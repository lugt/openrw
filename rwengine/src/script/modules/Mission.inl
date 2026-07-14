/**
    @brief   car %1d% crushed_by_car_crusher

    opcode 0149
    @arg vehicle Car/vehicle
*/
bool opcode_0149(const ScriptArguments& args, const ScriptVehicle vehicle) {
    RW_UNIMPLEMENTED_OPCODE(0x0149);
    RW_UNUSED(vehicle);
    RW_UNUSED(args);
    return false;
}

/**
    @brief set_fade_color %1d% %2d% %3d%

    opcode 0169
    @arg colour Colour (0-255)
*/
void opcode_0169(const ScriptArguments& args, ScriptRGB colour) {
    args.getState()->setFadeColour(colour);
}

/**
    @brief fade %2b% for %1d% ms

    opcode 016a
    @arg time Time (ms)
    @arg fadeIn Boolean true/false
*/
void opcode_016a(const ScriptArguments& args, const ScriptInt time, const ScriptBoolean fadeIn) {
    args.getState()->fade(time / 1000.f, fadeIn);
}

/**
    @brief   fading

    opcode 016b
*/
bool opcode_016b(const ScriptArguments& args) {
    return args.getState()->isFading();
}

/**
    @brief override_next_restart at %1d% %2d% %3d% heading %4d%

    opcode 016e
    @arg coord Coordinates
    @arg angle Angle
*/
void opcode_016e(const ScriptArguments& args, ScriptVec3 coord, const ScriptFloat heading) {
    coord = script::getGround(args, coord);
    args.getState()->overrideRestart(glm::vec4(coord, heading));
}

/**
    @brief   player %1d% picked_up_object %2d%

    opcode 0178
    @arg player Player
    @arg object Object
*/
bool opcode_0178(const ScriptArguments& args, const ScriptPlayer player, const ScriptObject object) {
    RW_UNIMPLEMENTED_OPCODE(0x0178);
    RW_UNUSED(player);
    RW_UNUSED(object);
    RW_UNUSED(args);
    return false;
}

/**
    @brief   actor %1d% picked_up_object %2d%

    opcode 0179
    @arg character Character/ped
    @arg object Object
*/
bool opcode_0179(const ScriptArguments& args, const ScriptCharacter character, const ScriptObject object) {
    RW_UNIMPLEMENTED_OPCODE(0x0179);
    RW_UNUSED(character);
    RW_UNUSED(object);
    RW_UNUSED(args);
    return false;
}

/**
    @brief activate_crane %1d% %2d% %3d% %4d% %5d% %6d% %7d% %8d% %9d% %10d%

    opcode 01ee
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
*/
void opcode_01ee(const ScriptArguments& args, const ScriptFloat arg1, const ScriptFloat arg2, const ScriptFloat arg3, const ScriptFloat arg4, const ScriptFloat arg5, const ScriptFloat arg6, const ScriptFloat arg7, const ScriptFloat arg8, const ScriptFloat arg9, const ScriptFloat arg10) {
    RW_UNIMPLEMENTED_OPCODE(0x01ee);
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
    RW_UNUSED(args);
}

/**
    @brief deactivate_crane %1d% %2d%

    opcode 01ef
    @arg arg1 
    @arg arg2 
*/
void opcode_01ef(const ScriptArguments& args, const ScriptFloat arg1, const ScriptFloat arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x01ef);
    RW_UNUSED(arg1);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief set_max_wanted_level_to %1d%

    opcode 01f0
    @arg wantedLevel 
*/
void opcode_01f0(const ScriptArguments& args, const ScriptInt wantedLevel) {
    args.getState()->maxWantedLevel = wantedLevel;
}

/**
    @brief cancel_override_restart

    opcode 01f6
*/
void opcode_01f6(const ScriptArguments& args) {
    args.getState()->cancelRestartOverride();
}

/**
    @brief init_rampage %1g% weapon %2d% time %3d% %4d% targets %5o% %6o% %7o% %8o% flag %9d%

    opcode 01f9
    @arg gxtEntry GXT entry
    @arg weaponID Weapon ID
    @arg time Time (ms)
    @arg arg4 
    @arg model0 Model ID
    @arg model1 Model ID
    @arg model2 Model ID
    @arg model3 Model ID
    @arg arg9 Boolean true/false
*/
void opcode_01f9(const ScriptArguments& args, const ScriptString gxtEntry, const ScriptWeaponType weaponID, const ScriptInt time, const ScriptInt arg4, const ScriptModelID model0, const ScriptModelID model1, const ScriptModelID model2, const ScriptModelID model3, const ScriptBoolean arg9) {
    RW_UNIMPLEMENTED_OPCODE(0x01f9);
    RW_UNUSED(gxtEntry);
    RW_UNUSED(weaponID);
    RW_UNUSED(time);
    RW_UNUSED(arg4);
    RW_UNUSED(model0);
    RW_UNUSED(model1);
    RW_UNUSED(model2);
    RW_UNUSED(model3);
    RW_UNUSED(arg9);
    RW_UNUSED(args);
}

/**
    @brief %1d% = rampage_status

    opcode 01fa
    @arg arg1 
*/
void opcode_01fa(const ScriptArguments& args, ScriptInt& arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x01fa);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief   pickup %1d% picked_up

    opcode 0214
    @arg pickup Pickup
*/
bool opcode_0214(const ScriptArguments& args, const ScriptPickup pickup) {
    RW_UNUSED(args);
    RW_CHECK(pickup != nullptr, "Pickup is null");
    if (!pickup) {
        return false;
    }
    bool collected = pickup->isCollected();
    pickup->setCollected(false);
    return collected;
}

/**
    @brief destroy_pickup %1d%

    opcode 0215
    @arg pickup Pickup
*/
void opcode_0215(const ScriptArguments& args, const ScriptPickup pickup) {
    args.getWorld()->destroyObjectQueued(pickup);
}

/**
    @brief set_free_bomb_shop_to %1btrue/false%

    opcode 021d
    @arg arg1 
*/
void opcode_021d(const ScriptArguments& args, const ScriptInt arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x021d);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief set_gang %1d% primary_weapon_to %2c% secondary_weapon_to %3c%

    opcode 0237
    @arg gangID Gang ID
    @arg weaponID0 Weapon ID
    @arg weaponID1 Weapon ID
*/
void opcode_0237(const ScriptArguments& args, const ScriptGang gangID, const ScriptWeaponType weaponID0, const ScriptWeaponType weaponID1) {
    RW_UNIMPLEMENTED_OPCODE(0x0237);
    RW_UNUSED(gangID);
    RW_UNUSED(weaponID0);
    RW_UNUSED(weaponID1);
    RW_UNUSED(args);
}

/**
    @brief %3d% = create_payphone_at %1d% %2d%

    opcode 024a
    @arg coord Coordinates
    @arg payphone Handle
*/
void opcode_024a(const ScriptArguments& args, const ScriptVec2 coord, ScriptPayphone& payphone) {
    payphone = args.getWorld()->createPayphone(coord);
}

/**
    @brief text_payphone_repeatedly %1d% %2g%

    opcode 024b
    @arg payphone 
    @arg arg2 
*/
void opcode_024b(const ScriptArguments& args, const ScriptPayphone payphone, const ScriptString arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x024b);
    RW_UNUSED(payphone);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief text_payphone %1d% %2g%

    opcode 024c
    @arg payphone 
    @arg text 
*/
void opcode_024c(const ScriptArguments& args, const ScriptPayphone payphone, const ScriptString text) {
    RW_UNUSED(args);
    payphone->setMessageAndStartRinging(text);
}

/**
    @brief   payphone_text_been_displayed %1d%

    opcode 024d
    @arg payphone 
*/
bool opcode_024d(const ScriptArguments& args, const ScriptPayphone payphone) {
    RW_UNIMPLEMENTED_OPCODE(0x024d);
    RW_UNUSED(payphone);
    RW_UNUSED(args);
    return false;
}

/**
    @brief disable_payphone %1d%

    opcode 024e
    @arg payphone 
*/
void opcode_024e(const ScriptArguments& args, const ScriptPayphone payphone) {
    RW_UNUSED(args);
    payphone->disable();
}

/**
    @brief clear_rampage_kills

    opcode 0297
*/
void opcode_0297(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x0297);
    RW_UNUSED(args);
}

/**
    @brief %2d% = rampage_kills %1o%

    opcode 0298
    @arg model0 Player
    @arg model1 Model ID
*/
void opcode_0298(const ScriptArguments& args, const ScriptModelID model0, ScriptInt& model1) {
    RW_UNIMPLEMENTED_OPCODE(0x0298);
    RW_UNUSED(model0);
    RW_UNUSED(model1);
    RW_UNUSED(args);
}

/**
    @brief remove_pickup_items_from_ground

    opcode 02c6
*/
void opcode_02c6(const ScriptArguments& args) {
    for (auto& p : args.getWorld()->pickupPool.objects) {
        auto pickup = static_cast<BigNVeinyPickup*>(p.second.get());
        if (pickup->isBigNVeinyPickup()) {
            script::destroyObject(args, pickup);
        }
    }
}

/**
    @brief put_hidden_package_at %1d% %2d% %3d%

    opcode 02ec
    @arg coord Coordinates
*/
void opcode_02ec(const ScriptArguments& args, ScriptVec3 coord) {
    coord = script::getGround(args, coord);
    args.getWorld()->createPickup(coord, args.getWorld()->data->findModelObject("package1"), PickupObject::PickupType::Collectable);
}

/**
    @brief set_total_hidden_packages_to %1d%

    opcode 02ed
    @arg arg1 
*/
void opcode_02ed(const ScriptArguments& args, const ScriptInt arg1) {
    args.getState()->playerInfo.hiddenPackageCount = arg1;
}

/**
    @brief create_crusher_crane %1d% %2d% %3d% %4d% %5d% %6d% %7d% %8d% %9d% %10d%

    opcode 02fb
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
*/
void opcode_02fb(const ScriptArguments& args, const ScriptFloat arg1, const ScriptFloat arg2, const ScriptFloat arg3, const ScriptFloat arg4, const ScriptFloat arg5, const ScriptFloat arg6, const ScriptFloat arg7, const ScriptFloat arg8, const ScriptFloat arg9, const ScriptFloat arg10) {
    RW_UNIMPLEMENTED_OPCODE(0x02fb);
    RW_UNUSED(args);
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
}

/**
    @brief set_free_paynspray_to %1b:true/false%

    opcode 0335
    @arg arg1 Boolean true/false
*/
void opcode_0335(const ScriptArguments& args, const ScriptBoolean arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x0335);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief create_incoming_cessna

    opcode 033a
*/
void opcode_033a(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x033a);
    RW_UNUSED(args);
}

/**
    @brief   incoming_cessna_landed

    opcode 033b
*/
bool opcode_033b(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x033b);
    RW_UNUSED(args);
    return false;
}

/**
    @brief   incoming_cessna_destroyed

    opcode 033c
*/
bool opcode_033c(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x033c);
    RW_UNUSED(args);
    return false;
}

/**
    @brief portland_complete

    opcode 034a
*/
void opcode_034a(const ScriptArguments& args) {
    args.getState()->gameStats.portlandPassed = 1;
}

/**
    @brief staunton_complete

    opcode 034b
*/
void opcode_034b(const ScriptArguments& args) {
    args.getState()->gameStats.stauntonPassed = 1;
}

/**
    @brief shoreside_complete

    opcode 034c
*/
void opcode_034c(const ScriptArguments& args) {
    args.getState()->gameStats.shoresidePassed = 1;
}

/**
    @brief destroy_actor_with_fade %1d%

    opcode 034f
    @arg character Character/ped
*/
void opcode_034f(const ScriptArguments& args, const ScriptCharacter character) {
    RW_UNIMPLEMENTED_OPCODE(0x034f);
    RW_UNUSED(character);
    RW_UNUSED(args);
    /// @todo implement fading
    args.getWorld()->destroyObjectQueued(character);
}

/**
    @brief set_up_chase_scene %1d%

    opcode 0354
    @arg arg1 
*/
void opcode_0354(const ScriptArguments& args, const ScriptFloat arg1) {
    RW_UNUSED(arg1);
    // Hardcoded list of vehicles, put this somewhere else.
    auto chaseVehicle = [](auto& args, const auto& data) {
        args.getWorld()->chase.reserve(data.size());

        for (auto& [model, x, y, z, hdg, c1, c2, path] : data) {
            auto vehicle0 = args.getWorld()->createVehicle(
                model, glm::vec3(x, y, z),
                glm::angleAxis(glm::radians(hdg), glm::vec3(0.f, 0.f, 1.f)));
            vehicle0->setPrimaryColour(c1);
            vehicle0->setSecondaryColour(c2);
            args.getWorld()->chase.addChaseVehicle(
                vehicle0, path,
                args.getWorld()->data->getDataPath().string() +
                    "/data/paths/CHASE" + std::to_string(path) + ".DAT");
        }
    };

    chaseVehicle(
        args, std::initializer_list<
                  std::tuple<int, float, float, float, float, float, int, int>>{
                  {116, 273.5422f, -1167.1907f, 24.9906f, 64.f, 2, 1, 0},
                  {117, 231.1783f, -1388.832f, 25.9782f, 90.0f, 2, 1, 1},
                  {130, -28.9762f, -1031.3367f, 25.9781f, 242.0f, 1, 75, 2},
                  {96, 114.1564f, -796.6938f, 24.9782f, 180.0f, 0, 0, 3},
                  {110, 184.3156f, -1473.251f, 25.9782f, 0.0f, 6, 6, 4},
                  {105, 173.8868f, -1377.6514f, 25.9782f, 0.0f, 4, 5, 6},
                  {92, 102.5946f, -943.9363f, 25.9781f, 270.0f, 53, 53, 7},
                  {105, 177.7157f, -862.1865f, 25.9782f, 155.0f, 41, 1, 10},
                  {92, 170.5698f, -889.0236f, 25.9782f, 154.0f, 10, 10, 11},
                  {111, 402.6081f, -917.4963f, 37.381f, 90.0f, 34, 1, 14},
                  {110, -33.4962f, -938.4563f, 25.9781f, 266.0f, 6, 6, 16},
                  {111, 49.3631f, -987.605f, 25.9781f, 0.0f, 51, 1, 18},
                  {110, 179.0049f, -1154.6686f, 25.9781f, 0.0f, 6, 76, 19}});

    args.getWorld()->chase.start();
}

/**
    @brief clean_up_chase_scene

    opcode 0355
*/
void opcode_0355(const ScriptArguments& args) {
    args.getWorld()->chase.cleanup();
}

/**
    @brief start_drug_drop_off

    opcode 0358
*/
void opcode_0358(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x0358);
    RW_UNUSED(args);
}

/**
    @brief   drop_off_cessna_shot_down

    opcode 0359
*/
bool opcode_0359(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x0359);
    RW_UNUSED(args);
    return false;
}

/**
    @brief find_drop_off_plane_coords %1d% %2d% %3d%

    opcode 035a
    @arg arg1 
    @arg arg2 
    @arg arg3 
*/
void opcode_035a(const ScriptArguments& args, ScriptFloat& arg1, ScriptFloat& arg2, ScriptFloat& arg3) {
    RW_UNIMPLEMENTED_OPCODE(0x035a);
    RW_UNUSED(arg1);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(args);
}

/**
    @brief %4d% = create_drop_off_package %1d% %2d% %3d%

    opcode 035b
    @arg arg1 
    @arg arg2 
    @arg arg3 
    @arg pickup 
*/
void opcode_035b(const ScriptArguments& args, ScriptVec3 coord, ScriptPickup& pickup) {
    coord = script::getGround(args, coord);
    pickup = args.getWorld()->createPickup(coord, args.getWorld()->data->findModelObject("floatpackge1"), PickupObject::PickupType::FloatingPackage);
}

/**
    @brief init_headshot_rampage %1g% weapon %2d% time %3d% %4d% targets %5o% %6o% %7o% %8o% flag %9d%

    opcode 0367
    @arg gxtEntry GXT entry
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg model0 Model ID
    @arg model1 Model ID
    @arg model2 Model ID
    @arg model3 Model ID
    @arg arg9 Boolean true/false
*/
void opcode_0367(const ScriptArguments& args, const ScriptString gxtEntry, const ScriptWeaponType arg2, const ScriptInt arg3, const ScriptInt arg4, const ScriptModelID model0, const ScriptModelID model1, const ScriptModelID model2, const ScriptModelID model3, const ScriptBoolean arg9) {
    RW_UNIMPLEMENTED_OPCODE(0x0367);
    RW_UNUSED(gxtEntry);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(model0);
    RW_UNUSED(model1);
    RW_UNUSED(model2);
    RW_UNUSED(model3);
    RW_UNUSED(arg9);
    RW_UNUSED(args);
}

/**
    @brief create_ev_crane %1d% %2d% %3d% %4d% %5d% %6d% %7d% %8d% %9d% %10d%

    opcode 0368
    @arg coord0 Coordinates
    @arg coord1 Coordinates
    @arg coord2 Coordinates
    @arg coord3 Coordinates
    @arg arg9 
    @arg arg10 
*/
void opcode_0368(const ScriptArguments& args, ScriptVec2 coord0, ScriptVec2 coord1, ScriptVec2 coord2, ScriptVec2 coord3, const ScriptFloat arg9, const ScriptFloat arg10) {
    RW_UNIMPLEMENTED_OPCODE(0x0368);
    RW_UNUSED(coord0);
    RW_UNUSED(coord1);
    RW_UNUSED(coord2);
    RW_UNUSED(coord3);
    RW_UNUSED(arg9);
    RW_UNUSED(arg10);
    RW_UNUSED(args);
}

/**
    @brief text_payphone_1string_repeatedly %1d% %2g% %3g%  

    opcode 0378
    @arg payphone 
    @arg arg2 
    @arg arg3 
*/
void opcode_0378(const ScriptArguments& args, const ScriptPayphone payphone, const ScriptString arg2, const ScriptString arg3) {
    RW_UNIMPLEMENTED_OPCODE(0x0378);
    RW_UNUSED(payphone);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(args);
}

/**
    @brief text_payphone_1string %1d% %2g% %3g%  

    opcode 0379
    @arg payphone 
    @arg arg2 
    @arg arg3 
*/
void opcode_0379(const ScriptArguments& args, const ScriptPayphone payphone, const ScriptString arg2, const ScriptString arg3) {
    RW_UNIMPLEMENTED_OPCODE(0x0379);
    RW_UNUSED(payphone);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(args);
}

/**
    @brief text_payphone_2strings_repeatedly %1d% %2g% %3g% %4g%  

    opcode 037a
    @arg payphone 
    @arg arg2 
    @arg arg3 
    @arg arg4 
*/
void opcode_037a(const ScriptArguments& args, const ScriptPayphone payphone, const ScriptString arg2, const ScriptString arg3, const ScriptString arg4) {
    RW_UNIMPLEMENTED_OPCODE(0x037a);
    RW_UNUSED(payphone);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(args);
}

/**
    @brief text_payphone_2strings %1d% %2g% %3g% %4g%  

    opcode 037b
    @arg payphone 
    @arg arg2 
    @arg arg3 
    @arg arg4 
*/
void opcode_037b(const ScriptArguments& args, const ScriptPayphone payphone, const ScriptString arg2, const ScriptString arg3, const ScriptString arg4) {
    RW_UNIMPLEMENTED_OPCODE(0x037b);
    RW_UNUSED(payphone);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(args);
}

/**
    @brief text_payphone_3strings_repeatedly %1d% %2g% %3g% %4g% %5g%  

    opcode 037c
    @arg payphone 
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
*/
void opcode_037c(const ScriptArguments& args, const ScriptPayphone payphone, const ScriptString arg2, const ScriptString arg3, const ScriptString arg4, const ScriptString arg5) {
    RW_UNIMPLEMENTED_OPCODE(0x037c);
    RW_UNUSED(payphone);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(args);
}

/**
    @brief text_payphone_3strings %1d% %2g% %3g% %4g% %5g%  

    opcode 037d
    @arg payphone 
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
*/
void opcode_037d(const ScriptArguments& args, const ScriptPayphone payphone, const ScriptString arg2, const ScriptString arg3, const ScriptString arg4, const ScriptString arg5) {
    RW_UNIMPLEMENTED_OPCODE(0x037d);
    RW_UNUSED(payphone);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(args);
}

/**
    @brief text_payphone_4strings_repeatedly %1d% %2g% %3g% %4g% %5g% %6g%  

    opcode 0386
    @arg payphone 
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
*/
void opcode_0386(const ScriptArguments& args, const ScriptPayphone payphone, const ScriptString arg2, const ScriptString arg3, const ScriptString arg4, const ScriptString arg5, const ScriptString arg6) {
    RW_UNIMPLEMENTED_OPCODE(0x0386);
    RW_UNUSED(payphone);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(arg6);
    RW_UNUSED(args);
}

/**
    @brief text_payphone_4strings %1d% %2g% %3g% %4g% %5g% %6g%  

    opcode 0387
    @arg payphone 
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
*/
void opcode_0387(const ScriptArguments& args, const ScriptPayphone payphone, const ScriptString arg2, const ScriptString arg3, const ScriptString arg4, const ScriptString arg5, const ScriptString arg6) {
    RW_UNIMPLEMENTED_OPCODE(0x0387);
    RW_UNUSED(payphone);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(arg6);
    RW_UNUSED(args);
}

/**
    @brief text_payphone_5strings_repeatedly %1d% %2g% %3g% %4g% %5g% %6g% %7g%  

    opcode 0388
    @arg payphone 
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
    @arg arg7 
*/
void opcode_0388(const ScriptArguments& args, const ScriptPayphone payphone, const ScriptString arg2, const ScriptString arg3, const ScriptString arg4, const ScriptString arg5, const ScriptString arg6, const ScriptString arg7) {
    RW_UNIMPLEMENTED_OPCODE(0x0388);
    RW_UNUSED(payphone);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(arg6);
    RW_UNUSED(arg7);
    RW_UNUSED(args);
}

/**
    @brief text_payphone_5strings %1d% %2g% %3g% %4g% %5g% %6g% %7g%  

    opcode 0389
    @arg payphone 
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
    @arg arg7 
*/
void opcode_0389(const ScriptArguments& args, const ScriptPayphone payphone, const ScriptString arg2, const ScriptString arg3, const ScriptString arg4, const ScriptString arg5, const ScriptString arg6, const ScriptString arg7) {
    RW_UNIMPLEMENTED_OPCODE(0x0389);
    RW_UNUSED(payphone);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(arg6);
    RW_UNUSED(arg7);
    RW_UNUSED(args);
}

/**
    @brief   car %3d% picked_up_by_crane %1d% %2d%

    opcode 03a0
    @arg arg1 
    @arg arg2 
    @arg vehicle 
*/
bool opcode_03a0(const ScriptArguments& args, const ScriptFloat arg1, const ScriptFloat arg2, const ScriptVehicle vehicle) {
    RW_UNIMPLEMENTED_OPCODE(0x03a0);
    RW_UNUSED(arg1);
    RW_UNUSED(arg2);
    RW_UNUSED(vehicle);
    RW_UNUSED(args);
    return false;
}

/**
    @brief play_suspect_last_seen_at %1d% %2d% %3d%

    opcode 03aa
    @arg coord Coordinates
*/
void opcode_03aa(const ScriptArguments& args, ScriptVec3 coord) {
    RW_UNIMPLEMENTED_OPCODE(0x03aa);
    RW_UNUSED(coord);
    RW_UNUSED(args);
}

/**
    @brief clear_route %1d%

    opcode 03ac
    @arg arg1 
*/
void opcode_03ac(const ScriptArguments& args, const ScriptInt arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x03ac);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief start_catalina_flyby

    opcode 03b2
*/
void opcode_03b2(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x03b2);
    RW_UNUSED(args);
}

/**
    @brief catalina_take_off

    opcode 03b3
*/
void opcode_03b3(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x03b3);
    RW_UNUSED(args);
}

/**
    @brief remove_catalina_heli

    opcode 03b4
*/
void opcode_03b4(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x03b4);
    RW_UNUSED(args);
}

/**
    @brief   catalina_shot_down

    opcode 03b5
*/
bool opcode_03b5(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x03b5);
    RW_UNUSED(args);
    return false;
}

/**
    @brief create_catalinas_chopper %1d%

    opcode 03b9
    @arg vehicle 
*/
void opcode_03b9(const ScriptArguments& args, ScriptVehicle& vehicle) {
    RW_UNIMPLEMENTED_OPCODE(0x03b9);
    RW_UNUSED(vehicle);
    RW_UNUSED(args);
}

/**
    @brief catalina_heli_drop_explosives_on_player

    opcode 03be
*/
void opcode_03be(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x03be);
    RW_UNUSED(args);
}

/**
    @brief   payphone %1d% answered

    opcode 03c2
    @arg payphone 
*/
bool opcode_03c2(const ScriptArguments& args, const ScriptPayphone payphone) {
    RW_UNUSED(args);
    return payphone->isTalking();
}

/**
    @brief set_sensitivity_to_crime_to %1d%

    opcode 03c7
    @arg arg1 
*/
void opcode_03c7(const ScriptArguments& args, const ScriptFloat arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x03c7);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief pickup %1d% show_on_radar %2d% %3d%

    opcode 03dd
    @arg pickup Pickup blip
    @arg blipSprite Blip sprite
    @arg blip Blip
*/
void opcode_03dd(const ScriptArguments& args, const ScriptPickup pickup, const ScriptRadarSprite blipSprite, ScriptBlip& blip) {
    auto data = script::createObjectBlipSprite(args, pickup, blipSprite);
    blip = &data;
}

/**
    @brief set_text_draw_before_fade %1h%

    opcode 03e0
    @arg arg1 Boolean true/false
*/
void opcode_03e0(const ScriptArguments& args, const ScriptBoolean arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x03e0);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief   ev_crane_collected_all_cars

    opcode 03ec
*/
bool opcode_03ec(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x03ec);
    RW_UNUSED(args);
    return false;
}

/**
    @brief enable_payphone %1d%

    opcode 0405
    @arg payphone Handle
*/
void opcode_0405(const ScriptArguments& args, const ScriptPayphone payphone) {
    RW_UNUSED(args);
    payphone->enable();
}

/**
    @brief set_total_rampages_to %1d%

    opcode 0408
    @arg total 
*/
void opcode_0408(const ScriptArguments& args, const ScriptInt total) {
    args.getState()->gameStats.totalRampages = total;
}

/**
    @brief %1b:set/clear% FadeInAfterNextArrest

    opcode 040e
    @arg arg1 
*/
void opcode_040e(const ScriptArguments& args, const ScriptInt arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x040e);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief %1b:set/clear% FadeInAfterNextDeath

    opcode 040f
    @arg arg1 
*/
void opcode_040f(const ScriptArguments& args, const ScriptInt arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x040f);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief enable %1d% get_out_of_jail_free %2d%

    opcode 0413
    @arg player Player
    @arg arg2 Boolean true/false
*/
void opcode_0413(const ScriptArguments& args, const ScriptPlayer player, const ScriptBoolean arg2) {
    // @todo support multiple players?
    RW_UNUSED(player);
    args.getState()->playerInfo.thaneOfLibertyCity = arg2;
}

/**
    @brief override_hospital %1d%

    opcode 041f
    @arg arg1 
*/
void opcode_041f(const ScriptArguments& args, const ScriptLevel arg1) {
    args.getState()->hospitalIslandOverride = arg1;
}

/**
    @brief show_credits

    opcode 0434
*/
void opcode_0434(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x0434);
    RW_UNUSED(args);
}

/**
    @brief end_credits

    opcode 0435
*/
void opcode_0435(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x0435);
    RW_UNUSED(args);
}

/**
    @brief   reached_end_of_credits

    opcode 0436
*/
bool opcode_0436(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x0436);
    RW_UNUSED(args);
    return false;
}

/**
    @brief set_game_sounds_fade %1d%

    opcode 043c
    @arg arg1 Boolean true/false
*/
void opcode_043c(const ScriptArguments& args, const ScriptBoolean arg1) {
    args.getState()->fadeSound = arg1;
}

/**
    @brief    is_player_lifting_a_payphone %1d%

    opcode 0447
    @arg player Player
*/
bool opcode_0447(const ScriptArguments& args, const ScriptPlayer player) {
    RW_UNUSED(args);
    return player->isPickingUpPayphone() || player->isTalkingOnPayphone() ||
           player->isHangingUpPayphone();
}

/**
    @brief change_to_island %1d%

    opcode 044c
    @arg arg1 
*/
void opcode_044c(const ScriptArguments& args, const ScriptLevel arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x044c);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

