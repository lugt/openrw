/**
    @brief shake_cam %1d%

    opcode 0003
    @arg time Time (ms)
*/
void opcode_0003(const ScriptArguments& args, const ScriptInt time) {
    RW_UNIMPLEMENTED_OPCODE(0x0003);
    RW_UNUSED(time);
    RW_UNUSED(args);
}

/**
    @brief  shake_cam_with_point %1d% xyz %2% %3% %4%

    opcode 0136
    @arg arg1 
    @arg arg2 
    @arg arg3 
    @arg arg4 
*/
void opcode_0136(const ScriptArguments& args, const ScriptInt arg1, const ScriptFloat arg2, const ScriptFloat arg3, const ScriptFloat arg4) {
    RW_UNIMPLEMENTED_OPCODE(0x0136);
    RW_UNUSED(arg1);
    RW_UNUSED(arg2);
    RW_UNUSED(arg3);
    RW_UNUSED(arg4);
    RW_UNUSED(args);
}

/**
    @brief camera_on_player %1d% mode %2d% switchstyle %3d%

    opcode 0157
    @arg player Player
    @arg cameraModeID Camera mode ID
    @arg cameraChangeModeID
*/
void opcode_0157(const ScriptArguments& args, const ScriptPlayer player,
                 const ScriptCamMode cameraModeID,
                 const ScriptChangeCamMode cameraChangeModeID) {
    args.getWorld()->state->cameraTarget =
        player->getCharacter()->getGameObjectID();

    RW_UNUSED(cameraModeID);
    RW_UNUSED(cameraChangeModeID);
}

/**
    @brief camera_on_vehicle %1d% mode %2d% switchstyle %3d%

    opcode 0158
    @arg vehicle Car/vehicle
    @arg cameraModeID Camera mode ID
    @arg cameraChangeModeID
*/
void opcode_0158(const ScriptArguments& args, const ScriptVehicle vehicle,
                 const ScriptCamMode cameraModeID,
                 const ScriptChangeCamMode cameraChangeModeID) {
    if (vehicle) {
        args.getWorld()->state->cameraTarget = vehicle->getGameObjectID();
    }
    RW_UNUSED(cameraModeID);
    RW_UNUSED(cameraChangeModeID);
}

/**
    @brief camera_on_ped %1d% mode %2d% switchstyle %3d%

    opcode 0159
    @arg character Character/ped
    @arg cameraModeID Camera mode ID
    @arg cameraChangeModeID
*/
void opcode_0159(const ScriptArguments& args, const ScriptCharacter character,
                 const ScriptCamMode cameraModeID,
                 const ScriptChangeCamMode cameraChangeModeID) {
    if (character) {
        args.getWorld()->state->cameraTarget = character->getGameObjectID();
    }
    RW_UNUSED(cameraModeID);
    RW_UNUSED(cameraChangeModeID);
}

/**
    @brief restore_camera

    opcode 015a
*/
void opcode_015a(const ScriptArguments& args) {
    args.getWorld()->state->cameraTarget = 0;
    args.getWorld()->state->cameraFixed = false;
}

/**
    @brief set_camera_position %1d% %2d% %3d% rotation %4d% %5d% %6d%

    opcode 015f
    @arg coord Coordinates
    @arg rotation Rotation
*/
void opcode_015f(const ScriptArguments& args, ScriptVec3 coord, ScriptVec3 rotation) {
    args.getWorld()->state->cameraFixed = true;
    args.getWorld()->state->cameraPosition = coord;
    args.getWorld()->state->cameraRotation = glm::quat(rotation);
}

/**
    @brief point_camera %1d% %2d% %3d% switchstyle %4d%

    opcode 0160
    @arg coord Coordinates
    @arg arg4 
*/
void opcode_0160(const ScriptArguments& args, ScriptVec3 coord, const ScriptChangeCamMode arg4) {
    RW_UNUSED(arg4);
    RW_UNIMPLEMENTED("camera switch mode");

    auto direction = glm::normalize(coord - args.getWorld()->state->cameraPosition);
    auto right = glm::normalize(glm::cross(glm::vec3(0.f, 0.f, 1.f), direction));
    auto up = glm::normalize(glm::cross(direction, right));
    
    glm::mat3 v;
    v[0][0] = direction.x;
    v[0][1] = right.x;
    v[0][2] = up.x;
    
    v[1][0] = direction.y;
    v[1][1] = right.y;
    v[1][2] = up.y;
    
    v[2][0] = direction.z;
    v[2][1] = right.z;
    v[2][2] = up.z;
    
    args.getWorld()->state->cameraRotation = glm::inverse(glm::quat_cast(v));
}

/**
    @brief set_actor %1d% to_look_at_spot %2d% %3d% %4d%

    opcode 01be
    @arg character
    @arg arg2
    @arg arg3
    @arg arg4
*/
void opcode_01be(const ScriptArguments& args, const ScriptCharacter character,
                 const ScriptVec3 coord) {
    RW_UNUSED(args);
    GameObject* object = character;
    if (character->getCurrentVehicle()) {
        object = character->getCurrentVehicle();
    }
    const auto& pos = object->getPosition() - coord;
    object->setHeading(
        glm::degrees(glm::atan(pos.x, pos.y) + glm::half_pi<float>()));
}

/**
    @brief actor %1d% look_at_actor %2d%

    opcode 020e
    @arg character0 
    @arg character1 
*/
void opcode_020e(const ScriptArguments& args, const ScriptCharacter character0, const ScriptCharacter character1) {
    RW_UNUSED(args);
    const auto& pos = character1->getPosition();
    character0->setHeading(
        glm::degrees(glm::atan(pos.x, pos.y) + glm::half_pi<float>()));
}

/**
    @brief actor %1d% look_at_player %2d%

    opcode 020f
    @arg character 
    @arg player 
*/
void opcode_020f(const ScriptArguments& args, const ScriptCharacter character, const ScriptPlayer player) {
    RW_UNUSED(args);
    const auto& pos = player->getCharacter()->getPosition();
    character->setHeading(
        glm::degrees(glm::atan(pos.x, pos.y) + glm::half_pi<float>()));
}

/**
    @brief player %1d% look_at_actor %2d%

    opcode 0210
    @arg player Player
    @arg character Character/ped
*/
void opcode_0210(const ScriptArguments& args, const ScriptPlayer player, const ScriptCharacter character) {
    RW_UNUSED(args);
    const auto& pos = character->getPosition();
    player->getCharacter()->setHeading(
        glm::degrees(glm::atan(pos.x, pos.y) + glm::half_pi<float>()));
}

/**
    @brief set_actor %1d% to_look_at_actor %2d%

    opcode 022c
    @arg character0 
    @arg character1 
*/
void opcode_022c(const ScriptArguments& args, const ScriptCharacter character0, const ScriptCharacter character1) {
    RW_UNIMPLEMENTED_OPCODE(0x022c);
    RW_UNUSED(character0);
    RW_UNUSED(character1);
    RW_UNUSED(args);
}

/**
    @brief set_actor %1d% to_look_at_player %2d%

    opcode 022d
    @arg character 
    @arg player 
*/
void opcode_022d(const ScriptArguments& args, const ScriptCharacter character, const ScriptPlayer player) {
    RW_UNIMPLEMENTED_OPCODE(0x022d);
    RW_UNUSED(character);
    RW_UNUSED(player);
    RW_UNUSED(args);
}

/**
    @brief set_player %1d% to_look_at_actor %2d%

    opcode 022e
    @arg player 
    @arg character 
*/
void opcode_022e(const ScriptArguments& args, const ScriptPlayer player, const ScriptCharacter character) {
    RW_UNIMPLEMENTED_OPCODE(0x022e);
    RW_UNUSED(player);
    RW_UNUSED(character);
    RW_UNUSED(args);
}

/**
    @brief set_cutscene_pos %1d% %2d% %3d%

    opcode 0244
    @arg coord Coordinates
*/
void opcode_0244(const ScriptArguments& args, ScriptVec3 coord) {
    if (args.getState()->currentCutscene) {
        args.getState()->currentCutscene->meta.sceneOffset = coord;
    }
}

/**
    @brief load_cutscene_data %1s%

    opcode 02e4
    @arg arg1 
*/
void opcode_02e4(const ScriptArguments& args, const ScriptString arg1) {
    args.getWorld()->loadCutscene(arg1);
    args.getState()->cutsceneStartTime = -1.f;

    auto player = args.getWorld()->getPlayer();
    player->prepareForCutscene();
}

/**
    @brief set_cutscene_anim %1d% %2s%

    opcode 02e6
    @arg object Player
    @arg arg2 
*/
void opcode_02e6(const ScriptArguments& args, const ScriptObject object,
                 const ScriptString arg2) {
    RW_UNUSED(object);
    RW_UNUSED(arg2);
    /// @todo make animation data-driven rather than oop
    auto cutscene = args.getObject<CutsceneObject>(0);
    std::string animName = arg2;
    std::transform(animName.begin(), animName.end(), animName.begin(),
                   ::tolower);
    auto anim = args.getWorld()->data->animationsCutscene.at(animName);
    if (anim) {
        cutscene->animator->playAnimation(AnimIndexMovement, anim, 1.f, false);
    } else {
        args.getWorld()->logger->error(
            "SCM", "Failed to load cutscene anim: " + animName);
    }
}

/**
    @brief start_cutscene

    opcode 02e7
*/
void opcode_02e7(const ScriptArguments& args) {
    args.getWorld()->startCutscene();
}

/**
    @brief cutscene_reached_end

    opcode 02e9
*/
bool opcode_02e9(const ScriptArguments& args) {
    if (args.getState()->currentCutscene) {
    	if (args.getState()->skipCutscene) {
    		return true;
    	}
    	auto time = (args.getWorld()->getGameTime() - args.getWorld()->state->cutsceneStartTime);
        return time >= args.getState()->currentCutscene->tracks.duration;
    }
    return true;
}

/**
    @brief end_cutscene

    opcode 02ea
*/
void opcode_02ea(const ScriptArguments& args) {
    args.getWorld()->clearCutscene();

    auto player = args.getWorld()->getPlayer();
    player->freeFromCutscene();
}

/**
    @brief create_cutscene_actor %3d% from_head %2o% and_body %1d%

    opcode 02f4
    @arg object0 
    @arg model 
    @arg object1 
*/
void opcode_02f4(const ScriptArguments& args, const ScriptObject object0, const ScriptModelID model, ScriptObject& object1) {
    RW_UNUSED(object0);
    RW_UNUSED(model);
    RW_UNUSED(object1);
    auto id = args[1].integer;
    auto actor = static_cast<CutsceneObject*>(args.getObject<CutsceneObject>(0));
    CutsceneObject* object = args.getWorld()->createCutsceneObject(id, args.getWorld()->state->currentCutscene->meta.sceneOffset );

    auto headframe = actor->getClump()->findFrame("shead");
    for (const auto& atomic : actor->getClump()->getAtomics()) {
    	if (atomic->getFrame().get() == headframe) {
    	    atomic->setFlag(Atomic::ATOMIC_RENDER, false);
    	}
    }
    object->setParentActor(actor, headframe);

    *args[2].globalInteger = object->getGameObjectID();
}

/**
    @brief set_behind_camera_mode_to %1h%

    opcode 032a
    @arg arg1 
*/
void opcode_032a(const ScriptArguments& args, const ScriptCamZoom arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x032a);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief set_camera_directly_behind_player

    opcode 0373
*/
void opcode_0373(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x0373);
    args.getWorld()->state->cameraTarget = 0;
    args.getWorld()->state->cameraFixed = false;
}

/**
    @brief set_motion_blur %1d%

    opcode 0374
    @arg arg1 
*/
void opcode_0374(const ScriptArguments& args, const ScriptMotionBlur arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x0374);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief process_cut_scene_only %1b:false/true%

    opcode 03b7
    @arg arg1 Boolean true/false
*/
void opcode_03b7(const ScriptArguments& args, const ScriptBoolean arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x03b7);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief set_camera_directly_before_player

    opcode 03c8
*/
void opcode_03c8(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x03c8);
    RW_UNUSED(args);
}

/**
    @brief set_garage %1d% camera_follows_player

    opcode 03da
    @arg garage Handle
*/
void opcode_03da(const ScriptArguments& args, const ScriptGarage garage) {
    RW_UNIMPLEMENTED_OPCODE(0x03da);
    RW_UNUSED(garage);
    RW_UNUSED(args);
}

/**
    @brief generate_cars_around_camera %1d%

    opcode 03ea
    @arg arg1 Boolean true/false
*/
void opcode_03ea(const ScriptArguments& args, const ScriptBoolean arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x03ea);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief set_camera_near_clip %1d%

    opcode 041d
    @arg arg1 
*/
void opcode_041d(const ScriptArguments& args, const ScriptFloat arg1) {
    args.getState()->cameraNear = arg1;
}

/**
    @brief play_cutscene_music

    opcode 043f
*/
void opcode_043f(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x043f);
    RW_UNUSED(args);
}

/**
    @brief stop_cutscene_music

    opcode 0440
*/
void opcode_0440(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x0440);
    RW_UNUSED(args);
}

/**
    @brief enable_player_control_camera

    opcode 0452
*/
void opcode_0452(const ScriptArguments& args) {
    RW_UNIMPLEMENTED_OPCODE(0x0452);
    RW_UNUSED(args);
}

/**
    @brief store_debug_camera_position_to %1d% %2d% %3d%

    opcode 0454
    @arg xCoord X Coord
    @arg yCoord Y Coord
    @arg zCoord Z Coord
*/
void opcode_0454(const ScriptArguments& args, ScriptFloat& xCoord, ScriptFloat& yCoord, ScriptFloat& zCoord) {
    RW_UNIMPLEMENTED_OPCODE(0x0454);
    RW_UNUSED(xCoord);
    RW_UNUSED(yCoord);
    RW_UNUSED(zCoord);
    RW_UNUSED(args);
}

/**
    @brief get_debug_camera_point_at %1d% %2d% %3d%

    opcode 0463
    @arg xCoord X Coord
    @arg yCoord Y Coord
    @arg zCoord Z Coord
*/
void opcode_0463(const ScriptArguments& args, ScriptFloat& xCoord, ScriptFloat& yCoord, ScriptFloat& zCoord) {
    RW_UNIMPLEMENTED_OPCODE(0x0463);
    RW_UNUSED(xCoord);
    RW_UNUSED(yCoord);
    RW_UNUSED(zCoord);
    RW_UNUSED(args);
}

