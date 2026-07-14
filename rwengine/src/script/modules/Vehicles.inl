/**
    @brief delete_car %1d%

    opcode 00a6
    @arg vehicle Car/vehicle
*/
void opcode_00a6(const ScriptArguments& args, const ScriptVehicle vehicle) {
    script::destroyObject(args, vehicle);
}

/**
    @brief get_car_coordinates %1d% store_to %2d% %3d% %4d%

    opcode 00aa
    @arg vehicle Car/vehicle
    @arg xCoord X Coord
    @arg yCoord Y Coord
    @arg zCoord Z Coord
*/
void opcode_00aa(const ScriptArguments& args, const ScriptVehicle vehicle, ScriptFloat& xCoord, ScriptFloat& yCoord, ScriptFloat& zCoord) {
    script::getObjectPosition(vehicle, xCoord, yCoord, zCoord);
    RW_UNUSED(args);
}

/**
    @brief set_car_coordinates %1d% to %2d% %3d% %4d%

    opcode 00ab
    @arg vehicle Car/vehicle
    @arg coord Coordinates
*/
void opcode_00ab(const ScriptArguments& args, const ScriptVehicle vehicle, ScriptVec3 coord) {
    script::setObjectPosition(vehicle, coord);
    script::clearSpaceForObject(args, vehicle);
}

/**
    @brief   is_car_still_alive %1d%

    opcode 00ac
    @arg vehicle 
*/
bool opcode_00ac(const ScriptArguments& args, const ScriptVehicle vehicle) {
    RW_UNUSED(args);
    if (vehicle) {
    	return !vehicle->isWrecked();
    }
    return false;
}

/**
    @brief set_car_cruise_speed %1d% to %2d%

    opcode 00ad
    @arg vehicle Car/vehicle
    @arg arg2 
*/
void opcode_00ad(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptFloat arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x00ad);
    RW_UNUSED(vehicle);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief set_car_driving_style %1d% to %2d%

    opcode 00ae
    @arg vehicle Car/vehicle
    @arg arg2 
*/
void opcode_00ae(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptDrivingMode arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x00ae);
    RW_UNUSED(arg2);
    RW_UNUSED(args);

    // Check whether we have a driver
    if (vehicle->getDriver() != nullptr)
    {
        // @todo set the right driving style and lane
        vehicle->getDriver()->controller->setGoal(ai::CharacterController::TrafficDriver);
        vehicle->getDriver()->controller->setLane(1);
    }
}

/**
    @brief   car %1d% wrecked

    opcode 0119
    @arg vehicle Car/vehicle
*/
bool opcode_0119(const ScriptArguments& args, const ScriptVehicle vehicle) {
    RW_UNUSED(args);
    if (vehicle) {
        return vehicle->isWrecked();
    }
    return true;
}

/**
    @brief set_car %1d% door_lock %2d%

    opcode 0135
    @arg vehicle Car/vehicle
    @arg arg2 
*/
void opcode_0135(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptCarLock arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x0135);
    RW_UNUSED(vehicle);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief set_parked_car_generator %1d% cars_to_generate_to %2d%

    opcode 014c
    @arg carGen Car generator
    @arg arg2 
*/
void opcode_014c(const ScriptArguments& args, const ScriptVehicleGenerator carGen, const ScriptInt arg2) {
    carGen->remainingSpawns = arg2;
    RW_UNUSED(args);
}

/**
    @brief set_zone_car_info %1s% %2bday/night% %3h% %4h% %5h% %6h% %7h% %8h% %9h% %10h% %11h% %12h% %13h% %14h% %15h% %16h% %17h%

    opcode 0152
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
    @arg arg13 
    @arg arg14 
    @arg arg15 
    @arg arg16 
    @arg arg17 
*/
void opcode_0152(const ScriptArguments& args, const ScriptString arg1, const ScriptInt arg2, const ScriptInt arg3, const ScriptInt arg4, const ScriptInt arg5, const ScriptInt arg6, const ScriptInt arg7, const ScriptInt arg8, const ScriptInt arg9, const ScriptInt arg10, const ScriptInt arg11, const ScriptInt arg12, const ScriptInt arg13, const ScriptInt arg14, const ScriptInt arg15, const ScriptInt arg16, const ScriptInt arg17) {
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
    RW_UNUSED(arg13);
    RW_UNUSED(arg14);
    RW_UNUSED(arg15);
    RW_UNUSED(arg16);
    RW_UNUSED(arg17);
    auto zone = args.getWorld()->data->findZone(arg1);
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
    @brief   car %1d% wheels_on_ground

    opcode 015e
    @arg vehicle 
*/
bool opcode_015e(const ScriptArguments& args, const ScriptVehicle vehicle) {
    RW_UNIMPLEMENTED_OPCODE(0x015e);
    RW_UNUSED(vehicle);
    RW_UNUSED(args);
    return false;
}

/**
    @brief set_car %1d% z_angle_to %2d%

    opcode 0175
    @arg vehicle Car/vehicle
    @arg angle Angle
*/
void opcode_0175(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptFloat angle) {
    RW_UNUSED(args);
    vehicle->setHeading(angle);
}

/**
    @brief remove_references_to_car %1d%

    opcode 01c3
    @arg vehicle Car/vehicle
*/
void opcode_01c3(const ScriptArguments& args, const ScriptVehicle vehicle) {
    /// @todo: there's more logic than only changing life time, or maybe it should be done in cleanUpTraffic
    if (vehicle) {
        vehicle->setLifetime(GameObject::TrafficLifetime);

        if (args.getThread()->isMission) {
            script::removeObjectFromMissionCleanup(args, vehicle);
        }
    }
}

/**
    @brief set_car_density_to %1d%

    opcode 01eb
    @arg arg1 
*/
void opcode_01eb(const ScriptArguments& args, const ScriptFloat arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x01eb);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief make_car %1d% very_heavy %2h%

    opcode 01ec
    @arg vehicle Car/vehicle
    @arg arg2 Boolean true/false
*/
void opcode_01ec(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptBoolean arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x01ec);
    RW_UNUSED(vehicle);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief   car %1d% airborne

    opcode 01f3
    @arg vehicle Car/vehicle
*/
bool opcode_01f3(const ScriptArguments& args, const ScriptVehicle vehicle) {
    RW_UNIMPLEMENTED_OPCODE(0x01f3);
    RW_UNUSED(vehicle);
    RW_UNUSED(args);
    return false;
}

/**
    @brief set_car %1d% door_status_to %2d%

    opcode 020a
    @arg vehicle Car/vehicle
    @arg arg2 
*/
void opcode_020a(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptCarLock arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x020a);
    RW_UNUSED(vehicle);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief explode_car %1d%

    opcode 020b
    @arg vehicle Car/vehicle
*/
void opcode_020b(const ScriptArguments& args, const ScriptVehicle vehicle) {
    RW_UNUSED(args);
    const auto pos = vehicle->getPosition();
    vehicle->setHealth(0.f);

    // Spawn explosion VFX and apply area damage to nearby objects.
    // Mirrors ProjectileObject::explode(); the vehicle itself is excluded
    // because VehicleObject::takeDamage asserts hitpoints == 0.
    auto world = args.getWorld();
    const float damageSize = 5.f;
    const float damage = 100.f;
    auto self = vehicle.get();
    for (auto& o : world->allObjects) {
        if (o == self) continue;
        switch (o->type()) {
            case GameObject::Instance:
            case GameObject::Vehicle:
            case GameObject::Character:
                break;
            default:
                continue;
        }
        float d = glm::distance(pos, o->getPosition());
        if (d > damageSize) continue;
        o->takeDamage({GameObject::DamageInfo::DamageType::Explosion,
                       pos, pos, damage / glm::max(d, 1.f), 0.f});
    }

    auto& explosion = world->createParticleEffect();
    explosion.texture = world->data->findSlotTexture("particle", "explo02");
    explosion.size = glm::vec2(10.f);
    explosion.starttime = world->getGameTime();
    explosion.lifetime = 0.5f;
    explosion.orientation = ParticleFX::Camera;
    explosion.colour = glm::vec4(1.0f);
    explosion.position = pos;
    explosion.direction = glm::vec3(0.f, 0.f, 1.f);
}

/**
    @brief   car %1d% is_upright

    opcode 020d
    @arg vehicle Car/vehicle
*/
bool opcode_020d(const ScriptArguments& args, const ScriptVehicle vehicle) {
    RW_UNUSED(args);
    return vehicle->isUpright();
}

/**
    @brief set_car %1d% taxi_available_light_to %2b:on/off%

    opcode 0216
    @arg vehicle Car/vehicle
    @arg arg2 Boolean true/false
*/
void opcode_0216(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptBoolean arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x0216);
    RW_UNUSED(vehicle);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief set_garage %1d% to_accept_car %2d%

    opcode 021b
    @arg garage 
    @arg vehicle Car/vehicle
*/
void opcode_021b(const ScriptArguments& args, const ScriptGarage garage, const ScriptVehicle vehicle) {
    RW_UNUSED(args);
    garage->target = vehicle.get();
}

/**
    @brief   car_inside_garage %1d%

    opcode 021c
    @arg garage 
*/
bool opcode_021c(const ScriptArguments& args, const ScriptGarage garage) {
    RW_UNUSED(args);
    return garage->isTargetInsideGarage();
}

/**
    @brief   car %d has_car_bomb

    opcode 0220
    @arg vehicle Car/vehicle
*/
bool opcode_0220(const ScriptArguments& args, const ScriptVehicle vehicle) {
    RW_UNIMPLEMENTED_OPCODE(0x0220);
    RW_UNUSED(vehicle);
    RW_UNUSED(args);
    return false;
}

/**
    @brief set_car %1d% color_to %2d% %3d%

    opcode 0229
    @arg vehicle Car/vehicle
    @arg carColour0 Car colour ID
    @arg carColour1 Car colour ID
*/
void opcode_0229(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptCarColour carColour0, const ScriptCarColour carColour1) {
    auto& colours = args.getWorld()->data->vehicleColours;
    vehicle->colourPrimary = colours[carColour0];
    vehicle->colourSecondary = colours[carColour1];
}

/**
    @brief script_heli %1bon/off%

    opcode 0231
    @arg arg1 Boolean true/false
*/
void opcode_0231(const ScriptArguments& args, const ScriptBoolean arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x0231);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief set_gang %1d% car_to %2o%

    opcode 0236
    @arg gangID Gang ID
    @arg model Model ID
*/
void opcode_0236(const ScriptArguments& args, const ScriptGang gangID, const ScriptModelID model) {
    RW_UNIMPLEMENTED_OPCODE(0x0236);
    RW_UNUSED(gangID);
    RW_UNUSED(model);
    RW_UNUSED(args);
}

/**
    @brief set_car %1d% bomb_status_to %2d%

    opcode 0242
    @arg vehicle Car/vehicle
    @arg arg2 
*/
void opcode_0242(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptCarBomb arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x0242);
    RW_UNUSED(vehicle);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief set_car %1d% resprayable_to %2benabled/disabled%

    opcode 0294
    @arg vehicle Car/vehicle
    @arg arg2 Boolean true/false
*/
void opcode_0294(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptBoolean arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x0294);
    RW_UNUSED(vehicle);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief   is_boat %1d%

    opcode 029c
    @arg vehicle 
*/
bool opcode_029c(const ScriptArguments& args, const ScriptVehicle vehicle) {
    RW_UNUSED(args);
    return vehicle->getVehicle()->vehicletype_ == VehicleModelInfo::BOAT;
}

/**
    @brief set_car %1d% immunities %2d% %3d% %4d% %5d% %6d%

    opcode 02ac
    @arg vehicle Car/vehicle
    @arg arg2 Boolean true/false
    @arg arg3 Boolean true/false
    @arg arg4 Boolean true/false
    @arg arg5 Boolean true/false
    @arg arg6 Boolean true/false
*/
void opcode_02ac(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptBoolean arg2, const ScriptBoolean arg3, const ScriptBoolean arg4, const ScriptBoolean arg5, const ScriptBoolean arg6) {
    RW_UNIMPLEMENTED_OPCODE(0x02ac);
    RW_UNUSED(vehicle);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(arg5);
    RW_UNUSED(arg6);
    RW_UNUSED(args);
}

/**
    @brief   car %1d% sunk

    opcode 02bf
    @arg vehicle Car/vehicle
*/
bool opcode_02bf(const ScriptArguments& args, const ScriptVehicle vehicle) {
    RW_UNUSED(args);
    return vehicle->isInWater();
}

/**
    @brief set %4d% %5d% %6d% to_car_path_coords_closest_to %1d% %2d% %3d%

    opcode 02c1
    @arg coord Coordinates
    @arg xCoord X Coord
    @arg yCoord Y Coord
    @arg zCoord Z Coord
*/
void opcode_02c1(const ScriptArguments& args, ScriptVec3 coord, ScriptFloat& xCoord, ScriptFloat& yCoord, ScriptFloat& zCoord) {
    script::getClosestNode(args, coord, ai::NodeType::Vehicle, xCoord, yCoord, zCoord);
}

/**
    @brief car %1d% drive_to_point %2d% %3d% %4d%

    opcode 02c2
    @arg vehicle Car/vehicle
    @arg coord Coordinates
*/
void opcode_02c2(const ScriptArguments& args, const ScriptVehicle vehicle, ScriptVec3 coord) {
    RW_UNIMPLEMENTED_OPCODE(0x02c2);
    RW_UNUSED(vehicle);
    RW_UNUSED(coord);
    RW_UNUSED(args);
}

/**
    @brief remove_platinum_from_car

    opcode 02c9
*/
void opcode_02c9(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x02c9);
    RW_UNUSED(args);
}

/**
    @brief   is_car_on_screen %1d% 

    opcode 02ca
    @arg vehicle Car/vehicle
*/
bool opcode_02ca(const ScriptArguments& args, const ScriptVehicle vehicle) {
    RW_UNIMPLEMENTED_OPCODE(0x02ca);
    RW_UNUSED(vehicle);
    RW_UNUSED(args);
    return false;
}

/**
    @brief boat %1d% drive_to %2d% %3d% %4d%

    opcode 02d3
    @arg vehicle Car/vehicle
    @arg coord Coordinates
*/
void opcode_02d3(const ScriptArguments& args, const ScriptVehicle vehicle, ScriptVec3 coord) {
    RW_UNIMPLEMENTED_OPCODE(0x02d3);
    RW_UNUSED(vehicle);
    RW_UNUSED(coord);
    RW_UNUSED(args);
}

/**
    @brief boat_stop %1d%

    opcode 02d4
    @arg vehicle Car/vehicle
*/
void opcode_02d4(const ScriptArguments& args, const ScriptVehicle vehicle) {
    RW_UNIMPLEMENTED_OPCODE(0x02d4);
    RW_UNUSED(vehicle);
    RW_UNUSED(args);
}

/**
    @brief set_boat %1d% speed_to %2d%

    opcode 02db
    @arg vehicle 
    @arg arg2 
*/
void opcode_02db(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptFloat arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x02db);
    RW_UNUSED(vehicle);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief get_car %1d% Z_angle_sine_to %2d%

    opcode 02f8
    @arg vehicle Car/vehicle
    @arg arg2 
*/
void opcode_02f8(const ScriptArguments& args, const ScriptVehicle vehicle, ScriptFloat& arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x02f8);
    RW_UNUSED(vehicle);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief get_car %1d% Z_angle_cosine_to %2d%

    opcode 02f9
    @arg vehicle Car/vehicle
    @arg arg2 
*/
void opcode_02f9(const ScriptArguments& args, const ScriptVehicle vehicle, ScriptFloat& arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x02f9);
    RW_UNUSED(vehicle);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief increment_taxi_dropoffs

    opcode 0315
*/
void opcode_0315(const ScriptArguments& args) {
    args.getState()->gameStats.passengersDroppedOff++;
}

/**
    @brief save_taxi_earnings_from %1d%

    opcode 0316
    @arg money 
*/
void opcode_0316(const ScriptArguments& args, const ScriptInt money) {
    args.getState()->gameStats.taxiRevenue += money;
}

/**
    @brief   vehicle %1d% hit_by_weapon %2h%

    opcode 031e
    @arg vehicle Car/vehicle
    @arg weaponID Weapon ID
*/
bool opcode_031e(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptWeaponType weaponID) {
    RW_UNIMPLEMENTED_OPCODE(0x031e);
    RW_UNUSED(vehicle);
    RW_UNUSED(weaponID);
    RW_UNUSED(args);
    return false;
}

/**
    @brief enable_boat %1d% anchor %2d%

    opcode 0323
    @arg vehicle 
    @arg arg2 Boolean true/false
*/
void opcode_0323(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptBoolean arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x0323);
    RW_UNUSED(vehicle);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief set_car_on_fire %1d% store_to %2d%

    opcode 0325
    @arg vehicle Car/vehicle
    @arg fire Fire
*/
void opcode_0325(const ScriptArguments& args, const ScriptVehicle vehicle, ScriptFire& fire) {
    RW_UNIMPLEMENTED_OPCODE(0x0325);
    RW_UNUSED(vehicle);
    RW_UNUSED(fire);
    RW_UNUSED(args);
}

/**
    @brief car %1d% ram %2d%

    opcode 032c
    @arg vehicle0 Car/vehicle
    @arg vehicle1 Car/vehicle
*/
void opcode_032c(const ScriptArguments& args, const ScriptVehicle vehicle0, const ScriptVehicle vehicle1) {
    RW_UNIMPLEMENTED_OPCODE(0x032c);
    RW_UNUSED(vehicle0);
    RW_UNUSED(vehicle1);
    RW_UNUSED(args);
}

/**
    @brief car %1d% block %2d%

    opcode 032d
    @arg vehicle0 
    @arg vehicle1 
*/
void opcode_032d(const ScriptArguments& args, const ScriptVehicle vehicle0, const ScriptVehicle vehicle1) {
    RW_UNIMPLEMENTED_OPCODE(0x032d);
    RW_UNUSED(vehicle0);
    RW_UNUSED(vehicle1);
    RW_UNUSED(args);
}

/**
    @brief   car_in_cube %1d% %2d% %3d% to %4d% %5d% %6d%

    opcode 038a
    @arg coord Coordinates
    @arg radius Radius
*/
bool opcode_038a(const ScriptArguments& args, ScriptVec3 coord, ScriptVec3 radius) {
    RW_UNIMPLEMENTED_OPCODE(0x038a);
    RW_UNUSED(coord);
    RW_UNUSED(radius);
    RW_UNUSED(args);
    return false;
}

/**
    @brief remove_forbidden_for_cars_angled_cube %1d% %2d% %3d% to %4d% %5d% %6d% angle %7d%

    opcode 039a
    @arg arg1 
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
    @arg arg7 
*/
void opcode_039a(const ScriptArguments& args, const ScriptFloat arg1, const ScriptFloat arg2, const ScriptFloat arg3, const ScriptFloat arg4, const ScriptFloat arg5, const ScriptFloat arg6, const ScriptFloat arg7) {
    RW_UNIMPLEMENTED_OPCODE(0x039a);
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
    @brief create_forbidden_for_cars_angled_cube %1d% %2d% %3d% to %4d% %5d% %6d% angle %7d%

    opcode 039b
    @arg arg1 
    @arg arg2 
    @arg arg3 
    @arg arg4 
    @arg arg5 
    @arg arg6 
    @arg arg7 
*/
void opcode_039b(const ScriptArguments& args, const ScriptFloat arg1, const ScriptFloat arg2, const ScriptFloat arg3, const ScriptFloat arg4, const ScriptFloat arg5, const ScriptFloat arg6, const ScriptFloat arg7) {
    RW_UNIMPLEMENTED_OPCODE(0x039b);
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
    @brief set_car %1d% watertight %2h%

    opcode 039c
    @arg vehicle Car/vehicle
    @arg arg2 Boolean true/false
*/
void opcode_039c(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptBoolean arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x039c);
    RW_UNUSED(vehicle);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief turn_car %1d% to_face %2d% %3d%

    opcode 039f
    @arg vehicle Car/vehicle
    @arg coord Coordinates
*/
void opcode_039f(const ScriptArguments& args, const ScriptVehicle vehicle,
                 ScriptVec2 coord) {
    RW_UNUSED(args);
    vehicle->setHeading(
        glm::degrees(glm::atan(coord.x, coord.y) + glm::half_pi<float>()));
}

/**
    @brief set_car_status %1d% to %2h%

    opcode 03a2
    @arg vehicle Car/vehicle
    @arg arg2 
*/
void opcode_03a2(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptStatus arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x03a2);
    RW_UNUSED(vehicle);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief get_drug_plane_coords %1d% %2d% %3d%

    opcode 03a6
    @arg arg1 
    @arg arg2 
    @arg arg3 
*/
void opcode_03a6(const ScriptArguments& args, ScriptFloat& arg1, ScriptFloat& arg2, ScriptFloat& arg3) {
    RW_UNIMPLEMENTED_OPCODE(0x03a6);
    RW_UNUSED(arg1);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(args);
}

/**
    @brief set_car %1d% strong %2d%

    opcode 03ab
    @arg vehicle Car/vehicle
    @arg arg2 Boolean true/false
*/
void opcode_03ab(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptBoolean arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x03ab);
    RW_UNUSED(vehicle);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief   garage %1d% door_open

    opcode 03b0
    @arg garage 
*/
bool opcode_03b0(const ScriptArguments& args, const ScriptGarage garage) {
    RW_UNIMPLEMENTED_OPCODE(0x03b0);
    RW_UNUSED(garage);
    RW_UNUSED(args);
    return false;
}

/**
    @brief   garage %1d% door_closed

    opcode 03b1
    @arg garage 
*/
bool opcode_03b1(const ScriptArguments& args, const ScriptGarage garage) {
    RW_UNUSED(args);
    return garage->state == GarageState::Closed;
}

/**
    @brief clear_cars_from_cube %1d% %2d% %3d% to %4d% %5d% %6d%

    opcode 03ba
    @arg coord0 Coordinates
    @arg coord1 Coordinates
*/
void opcode_03ba(const ScriptArguments& args, ScriptVec3 coord0, ScriptVec3 coord1) {
    RW_UNIMPLEMENTED_OPCODE(0x03ba);
    RW_UNUSED(coord0);
    RW_UNUSED(coord1);
    RW_UNUSED(args);
}

/**
    @brief set_garage %1d% door_type_to_swing_open

    opcode 03bb
    @arg garage
*/
void opcode_03bb(const ScriptArguments& args, const ScriptGarage garage) {
    RW_UNUSED(args);
    garage->makeDoorSwing();
}

/**
    @brief   car %1d% damaged

    opcode 03c9
    @arg vehicle Car/vehicle
*/
bool opcode_03c9(const ScriptArguments& args, const ScriptVehicle vehicle) {
    RW_UNIMPLEMENTED_OPCODE(0x03c9);
    RW_UNUSED(vehicle);
    RW_UNUSED(args);
    return false;
}

/**
    @brief car %1d% remove_from_stuck_car_check

    opcode 03cd
    @arg vehicle Car/vehicle
*/
void opcode_03cd(const ScriptArguments& args, const ScriptVehicle vehicle) {
    RW_UNIMPLEMENTED_OPCODE(0x03cd);
    RW_UNUSED(vehicle);
    RW_UNUSED(args);
}

/**
    @brief   car %1d% stuck

    opcode 03ce
    @arg vehicle Car/vehicle
*/
bool opcode_03ce(const ScriptArguments& args, const ScriptVehicle vehicle) {
    RW_UNIMPLEMENTED_OPCODE(0x03ce);
    RW_UNUSED(vehicle);
    RW_UNUSED(args);
    return false;
}

/**
    @brief get_closest_car_node_at %1d% %2d% %3d% store_to %4d% %5d% %6d% heading %7d%

    opcode 03d3
    @arg coord Coordinates
    @arg xCoord X Coord
    @arg yCoord Y Coord
    @arg zCoord Z Coord
    @arg angle Angle
*/
void opcode_03d3(const ScriptArguments& args, ScriptVec3 coord, ScriptFloat& xCoord, ScriptFloat& yCoord, ScriptFloat& zCoord, ScriptFloat& angle) {
    RW_UNIMPLEMENTED_OPCODE(0x03d3);
    script::getClosestNode(args, coord, ai::NodeType::Vehicle, xCoord, yCoord, zCoord);
    // @todo calculate angle based on node connections
    angle = 0.f;
}

/**
    @brief   garage %1d% contains_neededcar %2d%

    opcode 03d4
    @arg garage Handle
    @arg arg2 
*/
bool opcode_03d4(const ScriptArguments& args, const ScriptGarage garage, const ScriptInt index) {
    int entryIndex = index;
    RW_CHECK(entryIndex >= 0, "Entry index too low");
    RW_CHECK(entryIndex < 32, "Entry index too high");

    // @todo reimplement
    if (garage->type == GarageType::CollectCars1) {
        return args.getState()->importExportPortland[entryIndex];
    }
    if (garage->type == GarageType::CollectCars2) {
        return args.getState()->importExportShoreside[entryIndex];
    }

    return false;
}

/**
    @brief set_car %1d% not_damaged_when_upside_down %2h%

    opcode 03ed
    @arg vehicle Car/vehicle
    @arg arg2 Boolean true/false
*/
void opcode_03ed(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptBoolean arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x03ed);
    RW_UNUSED(vehicle);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief get_car %1d% color %2d% %3d%

    opcode 03f3
    @arg vehicle Car/vehicle
    @arg carColour0 Car colour ID
    @arg carColour1 Car colour ID
*/
void opcode_03f3(const ScriptArguments& args, const ScriptVehicle vehicle, ScriptInt& carColour0, ScriptInt& carColour1) {
    RW_UNIMPLEMENTED_OPCODE(0x03f3);
    RW_UNUSED(vehicle);
    RW_UNUSED(carColour0);
    RW_UNUSED(carColour1);
    RW_UNUSED(args);
    /// @todo get the right colours
    carColour0 = 0;
    carColour1 = 0;
}

/**
    @brief set_all_cars_can_be_damaged %1b:true/false%

    opcode 03f4
    @arg arg1 Boolean true/false
*/
void opcode_03f4(const ScriptArguments& args, const ScriptBoolean arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x03f4);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief set_car %1d% can_be_damaged %1b:true/false%

    opcode 03f5
    @arg vehicle Car/vehicle
    @arg arg2 Boolean true/false
*/
void opcode_03f5(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptBoolean arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x03f5);
    RW_UNUSED(vehicle);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief set_car %1d% stays_on_current_island %2d%

    opcode 03fb
    @arg vehicle 
    @arg arg2 
*/
void opcode_03fb(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptInt arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x03fb);
    RW_UNUSED(vehicle);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief blow_up_rc_buggy

    opcode 0409
*/
void opcode_0409(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x0409);
    RW_UNUSED(args);
}

/**
    @brief remove_car_from_chase %1d%

    opcode 040a
    @arg arg1 
*/
void opcode_040a(const ScriptArguments& args, const ScriptInt arg1) {
    GameObject* car = args.getWorld()->chase.getChaseVehicle(arg1);
    RW_CHECK(car != nullptr, "Tried to remove null car from chase");
    if (car == nullptr) return;
    args.getWorld()->chase.removeChaseVehicle(arg1);
    args.getWorld()->destroyObject(car);
}

/**
    @brief   garage_contain_car %1d% %2d%

    opcode 0422
    @arg garage Handle
    @arg vehicle Car/vehicle
*/
bool opcode_0422(const ScriptArguments& args, const ScriptGarage garage, const ScriptVehicle vehicle) {
    RW_UNUSED(args);
    return garage->isObjectInsideGarage(vehicle.get());
}

/**
    @brief car %1d% improve_handling %2d%

    opcode 0423
    @arg vehicle Car/vehicle
    @arg arg2 
*/
void opcode_0423(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptFloat arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x0423);
    RW_UNUSED(vehicle);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief create_save_cars_between_levels_cube %1d% %2d% %3d% to %4d% %5d% %6d%

    opcode 0426
    @arg coord0 Coordinates
    @arg coord1 Coordinates
*/
void opcode_0426(const ScriptArguments& args, ScriptVec3 coord0, ScriptVec3 coord1) {
    RW_UNIMPLEMENTED_OPCODE(0x0426);
    RW_UNUSED(coord0);
    RW_UNUSED(coord1);
    RW_UNUSED(args);
}

/**
    @brief   car %1d% passenger_seat_free %2d%

    opcode 0431
    @arg vehicle Car/vehicle
    @arg arg2 
*/
bool opcode_0431(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptInt arg2) {
    RW_UNUSED(args);
    return !vehicle->getOccupant(arg2);
}

/**
    @brief   are_any_car_cheats_activated

    opcode 0445
*/
bool opcode_0445(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x0445);
    RW_UNUSED(args);
    return false;
}

/**
    @brief car %1d% level %2b:set_from_position/clear%

    opcode 044e
    @arg vehicle 
    @arg arg2 
*/
void opcode_044e(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptInt arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x044e);
    RW_UNUSED(vehicle);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief make_craigs_car_a_bit_stronger %1d% %2d%

    opcode 044f
    @arg vehicle 
    @arg arg2 
*/
void opcode_044f(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptInt arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x044f);
    RW_UNUSED(vehicle);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief set_car_temp_action %1d% to %2h% time %3d%

    opcode 0477
    @arg vehicle Car/vehicle
    @arg vehicleActionID Vehicle action ID
    @arg time Time (ms)
*/
void opcode_0477(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptTempact vehicleActionID, const ScriptInt time) {
    RW_UNIMPLEMENTED_OPCODE(0x0477);
    RW_UNUSED(vehicle);
    RW_UNUSED(vehicleActionID);
    RW_UNUSED(time);
    RW_UNUSED(args);
}

