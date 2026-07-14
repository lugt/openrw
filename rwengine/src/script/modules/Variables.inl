/**
    @brief %1d% = %2d%

    opcode 0004
    @arg arg1G 
    @arg arg2 
*/
void opcode_0004(const ScriptArguments& args, ScriptInt& arg1G, const ScriptInt arg2) {
    RW_UNUSED(args);
    arg1G = arg2;
}

/**
    @brief %1d% = %2d%

    opcode 0005
    @arg arg1G 
    @arg arg2 
*/
void opcode_0005(const ScriptArguments& args, ScriptFloat& arg1G, const ScriptFloat arg2) {
    RW_UNUSED(args);
    arg1G = arg2;
}

/**
    @brief %1d% = %2d%

    opcode 0006
    @arg arg1L 
    @arg arg2 
*/
void opcode_0006(const ScriptArguments& args, ScriptInt& arg1L, const ScriptInt arg2) {
    RW_UNUSED(args);
    arg1L = arg2;
}

/**
    @brief %1d% = %2d%

    opcode 0007
    @arg arg1L 
    @arg arg2 
*/
void opcode_0007(const ScriptArguments& args, ScriptFloat& arg1L, const ScriptFloat arg2) {
    RW_UNUSED(args);
    arg1L = arg2;
}

/**
    @brief %1d% += %2d%

    opcode 0008
    @arg arg1G 
    @arg arg2 
*/
void opcode_0008(const ScriptArguments& args, ScriptInt& arg1G, const ScriptInt arg2) {
    RW_UNUSED(args);
    arg1G += arg2;
}

/**
    @brief %1d% += %2d%

    opcode 0009
    @arg arg1G 
    @arg arg2 
*/
void opcode_0009(const ScriptArguments& args, ScriptFloat& arg1G, const ScriptFloat arg2) {
    RW_UNUSED(args);
    arg1G += arg2;
}

/**
    @brief %1d% += %2h%

    opcode 000a
    @arg arg1L 
    @arg arg2 
*/
void opcode_000a(const ScriptArguments& args, ScriptInt& arg1L, const ScriptInt arg2) {
    RW_UNUSED(args);
    arg1L += arg2;
}

/**
    @brief %1d% += %2d%

    opcode 000b
    @arg arg1L 
    @arg arg2 
*/
void opcode_000b(const ScriptArguments& args, ScriptFloat& arg1L, const ScriptFloat arg2) {
    RW_UNUSED(args);
    arg1L += arg2;
}

/**
    @brief %1d% -= %2d%

    opcode 000c
    @arg arg1G 
    @arg arg2 
*/
void opcode_000c(const ScriptArguments& args, ScriptInt& arg1G, const ScriptInt arg2) {
    RW_UNUSED(args);
    arg1G -= arg2;
}

/**
    @brief %1d% -= %2d%

    opcode 000d
    @arg arg1G 
    @arg arg2 
*/
void opcode_000d(const ScriptArguments& args, ScriptFloat& arg1G, const ScriptFloat arg2) {
    RW_UNUSED(args);
    arg1G -= arg2;
}

/**
    @brief %1d% -= %2h%

    opcode 000e
    @arg arg1L 
    @arg arg2 
*/
void opcode_000e(const ScriptArguments& args, ScriptInt& arg1L, const ScriptInt arg2) {
    RW_UNUSED(args);
    arg1L -= arg2;
}

/**
    @brief %1d% -= %2d%

    opcode 000f
    @arg arg1L 
    @arg arg2 
*/
void opcode_000f(const ScriptArguments& args, ScriptFloat& arg1L, const ScriptFloat arg2) {
    RW_UNUSED(args);
    arg1L -= arg2;
}

/**
    @brief %1d% *= %2d%

    opcode 0010
    @arg arg1G 
    @arg arg2 
*/
void opcode_0010(const ScriptArguments& args, ScriptInt& arg1G, const ScriptInt arg2) {
    RW_UNUSED(args);
    arg1G *= arg2;
}

/**
    @brief %1d% *= %2d%

    opcode 0011
    @arg arg1G 
    @arg arg2 
*/
void opcode_0011(const ScriptArguments& args, ScriptFloat& arg1G, const ScriptFloat arg2) {
    RW_UNUSED(args);
    arg1G *= arg2;
}

/**
    @brief %1d% *= %2d%

    opcode 0012
    @arg arg1L 
    @arg arg2 
*/
void opcode_0012(const ScriptArguments& args, ScriptInt& arg1L, const ScriptInt arg2) {
    RW_UNUSED(args);
    arg1L *= arg2;
}

/**
    @brief %1d% *= %2d%

    opcode 0013
    @arg arg1L 
    @arg arg2 
*/
void opcode_0013(const ScriptArguments& args, ScriptFloat& arg1L, const ScriptFloat arg2) {
    RW_UNUSED(args);
    arg1L *= arg2;
}

/**
    @brief %1d% /= %2d%

    opcode 0014
    @arg arg1G 
    @arg arg2 
*/
void opcode_0014(const ScriptArguments& args, ScriptInt& arg1G, const ScriptInt arg2) {
    RW_UNUSED(args);
    arg1G /= arg2;
}

/**
    @brief %1d% /= %2d%

    opcode 0015
    @arg arg1G 
    @arg arg2 
*/
void opcode_0015(const ScriptArguments& args, ScriptFloat& arg1G, const ScriptFloat arg2) {
    RW_UNUSED(args);
    arg1G /= arg2;
}

/**
    @brief %1d% /= %2d%

    opcode 0016
    @arg arg1L 
    @arg arg2 
*/
void opcode_0016(const ScriptArguments& args, ScriptInt& arg1L, const ScriptInt arg2) {
    RW_UNUSED(args);
    arg1L /= arg2;
}

/**
    @brief %1d% /= %2d%

    opcode 0017
    @arg arg1L 
    @arg arg2 
*/
void opcode_0017(const ScriptArguments& args, ScriptFloat& arg1L, const ScriptFloat arg2) {
    RW_UNUSED(args);
    arg1L /= arg2;
}

/**
    @brief   %1d% > %2d%

    opcode 0018
    @arg arg1G 
    @arg arg2 
*/
bool opcode_0018(const ScriptArguments& args, ScriptInt& arg1G, const ScriptInt arg2) {
    RW_UNUSED(args);
    return arg1G > arg2;
}

/**
    @brief   %1d% > %2d%

    opcode 0019
    @arg arg1L 
    @arg arg2 
*/
bool opcode_0019(const ScriptArguments& args, ScriptInt& arg1L, const ScriptInt arg2) {
    RW_UNUSED(args);
    return arg1L > arg2;
}

/**
    @brief   %1d% > %2d%

    opcode 001a
    @arg arg1 
    @arg arg2G 
*/
bool opcode_001a(const ScriptArguments& args, const ScriptInt arg1, ScriptInt& arg2G) {
    RW_UNUSED(args);
    return arg1 > arg2G;
}

/**
    @brief   %1d% > %2d%

    opcode 001b
    @arg arg1 
    @arg arg2L 
*/
bool opcode_001b(const ScriptArguments& args, const ScriptInt arg1, ScriptInt& arg2L) {
    RW_UNUSED(args);
    return arg1 > arg2L;
}

/**
    @brief   %1d% > %2d%

    opcode 001c
    @arg arg1G 
    @arg arg2G 
*/
bool opcode_001c(const ScriptArguments& args, ScriptInt& arg1G, ScriptInt& arg2G) {
    RW_UNUSED(args);
    return arg1G > arg2G;
}

/**
    @brief   %1d% > %2d%

    opcode 001d
    @arg arg1L 
    @arg arg2L 
*/
bool opcode_001d(const ScriptArguments& args, ScriptInt& arg1L, ScriptInt& arg2L) {
    RW_UNUSED(args);
    return arg1L > arg2L;
}

/**
    @brief   %1d% > %2d%

    opcode 001e
    @arg arg1G 
    @arg arg2L 
*/
bool opcode_001e(const ScriptArguments& args, ScriptInt& arg1G, ScriptInt& arg2L) {
    RW_UNUSED(args);
    return arg1G > arg2L;
}

/**
    @brief   %1d% > %2d%

    opcode 001f
    @arg arg1L 
    @arg arg2G 
*/
bool opcode_001f(const ScriptArguments& args, ScriptInt& arg1L, ScriptInt& arg2G) {
    RW_UNUSED(args);
    return arg1L > arg2G;
}

/**
    @brief   %1d% > %2d%

    opcode 0020
    @arg arg1G 
    @arg arg2 
*/
bool opcode_0020(const ScriptArguments& args, ScriptFloat& arg1G, const ScriptFloat arg2) {
    RW_UNUSED(args);
    return arg1G > arg2;
}

/**
    @brief   %1d% > %2d%

    opcode 0021
    @arg arg1L 
    @arg arg2 
*/
bool opcode_0021(const ScriptArguments& args, ScriptFloat& arg1L, const ScriptFloat arg2) {
    RW_UNUSED(args);
    return arg1L > arg2;
}

/**
    @brief   %1d% > %2d%

    opcode 0022
    @arg arg1 
    @arg arg2G 
*/
bool opcode_0022(const ScriptArguments& args, const ScriptFloat arg1, ScriptFloat& arg2G) {
    RW_UNUSED(args);
    return arg1 > arg2G;
}

/**
    @brief   %1d% > %2d%

    opcode 0023
    @arg arg1 
    @arg arg2L 
*/
bool opcode_0023(const ScriptArguments& args, const ScriptFloat arg1, ScriptFloat& arg2L) {
    RW_UNUSED(args);
    return arg1 > arg2L;
}

/**
    @brief   %1d% > %2d%

    opcode 0024
    @arg arg1G 
    @arg arg2G 
*/
bool opcode_0024(const ScriptArguments& args, ScriptFloat& arg1G, ScriptFloat& arg2G) {
    RW_UNUSED(args);
    return arg1G > arg2G;
}

/**
    @brief   %1d% > %2d%

    opcode 0025
    @arg arg1L 
    @arg arg2L 
*/
bool opcode_0025(const ScriptArguments& args, ScriptFloat& arg1L, ScriptFloat& arg2L) {
    RW_UNUSED(args);
    return arg1L > arg2L;
}

/**
    @brief   %1d% > %2d%

    opcode 0026
    @arg arg1G 
    @arg arg2L 
*/
bool opcode_0026(const ScriptArguments& args, ScriptFloat& arg1G, ScriptFloat& arg2L) {
    RW_UNUSED(args);
    return arg1G > arg2L;
}

/**
    @brief   %1d% > %2d%

    opcode 0027
    @arg arg1L 
    @arg arg2G 
*/
bool opcode_0027(const ScriptArguments& args, ScriptFloat& arg1L, ScriptFloat& arg2G) {
    RW_UNUSED(args);
    return arg1L > arg2G;
}

/**
    @brief   %1d% >= %2d%

    opcode 0028
    @arg arg1G 
    @arg arg2 
*/
bool opcode_0028(const ScriptArguments& args, ScriptInt& arg1G, const ScriptInt arg2) {
    RW_UNUSED(args);
    return arg1G >= arg2;
}

/**
    @brief   %1d% >= %2d%

    opcode 0029
    @arg arg1L 
    @arg arg2 
*/
bool opcode_0029(const ScriptArguments& args, ScriptInt& arg1L, const ScriptInt arg2) {
    RW_UNUSED(args);
    return arg1L >= arg2;
}

/**
    @brief   %1d% >= %2d%

    opcode 002a
    @arg arg1 
    @arg arg2G 
*/
bool opcode_002a(const ScriptArguments& args, const ScriptInt arg1, ScriptInt& arg2G) {
    RW_UNUSED(args);
    return arg1 >= arg2G;
}

/**
    @brief   %1d% >= %2d%

    opcode 002b
    @arg arg1 
    @arg arg2L 
*/
bool opcode_002b(const ScriptArguments& args, const ScriptInt arg1, ScriptInt& arg2L) {
    RW_UNUSED(args);
    return arg1 >= arg2L;
}

/**
    @brief   %1d% >= %2d%

    opcode 002c
    @arg arg1G 
    @arg arg2G 
*/
bool opcode_002c(const ScriptArguments& args, ScriptInt& arg1G, ScriptInt& arg2G) {
    RW_UNUSED(args);
    return arg1G >= arg2G;
}

/**
    @brief   %1d% >= %2d%

    opcode 002d
    @arg arg1L 
    @arg arg2L 
*/
bool opcode_002d(const ScriptArguments& args, ScriptInt& arg1L, ScriptInt& arg2L) {
    RW_UNUSED(args);
    return arg1L >= arg2L;
}

/**
    @brief   %1d% >= %2d%

    opcode 002e
    @arg arg1G 
    @arg arg2L 
*/
bool opcode_002e(const ScriptArguments& args, ScriptInt& arg1G, ScriptInt& arg2L) {
    RW_UNUSED(args);
    return arg1G >= arg2L;
}

/**
    @brief   %1d% >= %2d%

    opcode 002f
    @arg arg1L 
    @arg arg2G 
*/
bool opcode_002f(const ScriptArguments& args, ScriptInt& arg1L, ScriptInt& arg2G) {
    RW_UNUSED(args);
    return arg1L >= arg2G;
}

/**
    @brief   %1d% >= %2d%

    opcode 0030
    @arg arg1G 
    @arg arg2 
*/
bool opcode_0030(const ScriptArguments& args, ScriptFloat& arg1G, const ScriptFloat arg2) {
    RW_UNUSED(args);
    return arg1G >= arg2;
}

/**
    @brief   %1d% >= %2d%

    opcode 0031
    @arg arg1L 
    @arg arg2 
*/
bool opcode_0031(const ScriptArguments& args, ScriptFloat& arg1L, const ScriptFloat arg2) {
    RW_UNUSED(args);
    return arg1L >= arg2;
}

/**
    @brief   %1d% >= %2d%

    opcode 0032
    @arg arg1 
    @arg arg2G 
*/
bool opcode_0032(const ScriptArguments& args, const ScriptFloat arg1, ScriptFloat& arg2G) {
    RW_UNUSED(args);
    return arg1 >= arg2G;
}

/**
    @brief   %1d% >= %2d%

    opcode 0033
    @arg arg1 
    @arg arg2L 
*/
bool opcode_0033(const ScriptArguments& args, const ScriptFloat arg1, ScriptFloat& arg2L) {
    RW_UNUSED(args);
    return arg1 >= arg2L;
}

/**
    @brief   %1d% >= %2d%

    opcode 0034
    @arg arg1G 
    @arg arg2G 
*/
bool opcode_0034(const ScriptArguments& args, ScriptFloat& arg1G, ScriptFloat& arg2G) {
    RW_UNUSED(args);
    return arg1G >= arg2G;
}

/**
    @brief   %1d% >= %2d%

    opcode 0035
    @arg arg1L 
    @arg arg2L 
*/
bool opcode_0035(const ScriptArguments& args, ScriptFloat& arg1L, ScriptFloat& arg2L) {
    RW_UNUSED(args);
    return arg1L >= arg2L;
}

/**
    @brief   %1d% >= %2d%

    opcode 0036
    @arg arg1G 
    @arg arg2L 
*/
bool opcode_0036(const ScriptArguments& args, ScriptFloat& arg1G, ScriptFloat& arg2L) {
    RW_UNUSED(args);
    return arg1G >= arg2L;
}

/**
    @brief   %1d% >= %2d%

    opcode 0037
    @arg arg1L 
    @arg arg2G 
*/
bool opcode_0037(const ScriptArguments& args, ScriptFloat& arg1L, ScriptFloat& arg2G) {
    RW_UNUSED(args);
    return arg1L >= arg2G;
}

/**
    @brief   %1d% == %2d%

    opcode 0038
    @arg arg1G 
    @arg arg2 
*/
bool opcode_0038(const ScriptArguments& args, ScriptInt& arg1G, const ScriptInt arg2) {
    RW_UNUSED(args);
    return arg1G == arg2;
}

/**
    @brief   %1d% == %2d%

    opcode 0039
    @arg arg1L 
    @arg arg2 
*/
bool opcode_0039(const ScriptArguments& args, ScriptInt& arg1L, const ScriptInt arg2) {
    RW_UNUSED(args);
    return arg1L == arg2;
}

/**
    @brief   %1d% == %2d%

    opcode 003a
    @arg arg1G 
    @arg arg2G 
*/
bool opcode_003a(const ScriptArguments& args, ScriptInt& arg1G, ScriptInt& arg2G) {
    RW_UNUSED(args);
    return arg1G == arg2G;
}

/**
    @brief   %1d% == %2d%

    opcode 003b
    @arg arg1L 
    @arg arg2L 
*/
bool opcode_003b(const ScriptArguments& args, ScriptInt& arg1L, ScriptInt& arg2L) {
    RW_UNUSED(args);
    return arg1L == arg2L;
}

/**
    @brief   %1d% == %2d%

    opcode 003c
    @arg arg1G 
    @arg arg2L 
*/
bool opcode_003c(const ScriptArguments& args, ScriptInt& arg1G, ScriptInt& arg2L) {
    RW_UNUSED(args);
    return arg1G == arg2L;
}

/**
    @brief   %1d% == %2d%

    opcode 0042
    @arg arg1G 
    @arg arg2 
*/
bool opcode_0042(const ScriptArguments& args, ScriptFloat& arg1G, const ScriptFloat arg2) {
    RW_UNUSED(args);
    return arg1G == arg2;
}

/**
    @brief   %1d% == %2d%

    opcode 0043
    @arg arg1L 
    @arg arg2 
*/
bool opcode_0043(const ScriptArguments& args, ScriptFloat& arg1L, const ScriptFloat arg2) {
    RW_UNUSED(args);
    return arg1L == arg2;
}

/**
    @brief   %1d% == %2d%

    opcode 0044
    @arg arg1G 
    @arg arg2G 
*/
bool opcode_0044(const ScriptArguments& args, ScriptFloat& arg1G, ScriptFloat& arg2G) {
    RW_UNUSED(args);
    return arg1G == arg2G;
}

/**
    @brief   %1d% == %2d%

    opcode 0045
    @arg arg1L 
    @arg arg2L 
*/
bool opcode_0045(const ScriptArguments& args, ScriptFloat& arg1L, ScriptFloat& arg2L) {
    RW_UNUSED(args);
    return arg1L == arg2L;
}

/**
    @brief   %1d% == %2d%

    opcode 0046
    @arg arg1G 
    @arg arg2L 
*/
bool opcode_0046(const ScriptArguments& args, ScriptFloat& arg1G, ScriptFloat& arg2L) {
    RW_UNUSED(args);
    return arg1G == arg2L;
}

/**
    @brief  %5d% = create_player %1o% at %2d% %3d% %4d%

    opcode 0053

    Creates a player

    @arg index Player index
    @arg x X coordinate
    @arg y Y coordinate
    @arg z Z coordinate
    @arg outPlayerHandle Created player
*/
void opcode_0053(const ScriptArguments& args, const ScriptInt index, ScriptVec3 coord, ScriptPlayer& player) {
    // index used for PlayerInfo
    RW_UNUSED(index);

    coord = script::getGround(args, coord);
    /// @todo fix the API interfaces that are now totally incoherent
    auto character = args.getWorld()->createPlayer(coord);
    character->applyOffset();
    player = static_cast<ai::PlayerController*>(character->controller);
    args.getState()->playerObject = character->getGameObjectID();
    script::clearSpaceForObject(args, character);
}

/**
    @brief %1d% += %2d%

    opcode 0058
    @arg arg1G 
    @arg arg2G 
*/
void opcode_0058(const ScriptArguments& args, ScriptInt& arg1G, ScriptInt& arg2G) {
    arg1G += arg2G;
    RW_UNUSED(args);
}

/**
    @brief %1d% += %2d%

    opcode 0059
    @arg arg1G 
    @arg arg2G 
*/
void opcode_0059(const ScriptArguments& args, ScriptFloat& arg1G, ScriptFloat& arg2G) {
    arg1G += arg2G;
    RW_UNUSED(args);
}

/**
    @brief %1d% += %2d% 

    opcode 005a
    @arg arg1L 
    @arg arg2L 
*/
void opcode_005a(const ScriptArguments& args, ScriptInt& arg1L, ScriptInt& arg2L) {
    arg1L += arg2L;
    RW_UNUSED(args);
}

/**
    @brief %1d% += %2d% 

    opcode 005b
    @arg arg1L 
    @arg arg2L 
*/
void opcode_005b(const ScriptArguments& args, ScriptFloat& arg1L, ScriptFloat& arg2L) {
    arg1L += arg2L;
    RW_UNUSED(args);
}

/**
    @brief %1d% += %2d%

    opcode 005c
    @arg arg1L 
    @arg arg2G 
*/
void opcode_005c(const ScriptArguments& args, ScriptInt& arg1L, ScriptInt& arg2G) {
    arg1L += arg2G;
    RW_UNUSED(args);
}

/**
    @brief %1d% += %2d% 

    opcode 005d
    @arg arg1L 
    @arg arg2G 
*/
void opcode_005d(const ScriptArguments& args, ScriptFloat& arg1L, ScriptFloat& arg2G) {
    arg1L += arg2G;
    RW_UNUSED(args);
}

/**
    @brief %1d% += %2d%  

    opcode 005e
    @arg arg1G 
    @arg arg2L 
*/
void opcode_005e(const ScriptArguments& args, ScriptInt& arg1G, ScriptInt& arg2L) {
    arg1G += arg2L;
    RW_UNUSED(args);
}

/**
    @brief %1d% += %2d% 

    opcode 005f
    @arg arg1G 
    @arg arg2L 
*/
void opcode_005f(const ScriptArguments& args, ScriptFloat& arg1G, ScriptFloat& arg2L) {
    arg1G += arg2L;
    RW_UNUSED(args);
}

/**
    @brief %1d% -= %2d% 

    opcode 0060
    @arg arg1G 
    @arg arg2G 
*/
void opcode_0060(const ScriptArguments& args, ScriptInt& arg1G, ScriptInt& arg2G) {
    arg1G -= arg2G;
    RW_UNUSED(args);
}

/**
    @brief %1d% -= %2d% 

    opcode 0061
    @arg arg1G 
    @arg arg2G 
*/
void opcode_0061(const ScriptArguments& args, ScriptFloat& arg1G, ScriptFloat& arg2G) {
    arg1G -= arg2G;
    RW_UNUSED(args);
}

/**
    @brief %1d% -= %2d%

    opcode 0062
    @arg arg1L 
    @arg arg2L 
*/
void opcode_0062(const ScriptArguments& args, ScriptInt& arg1L, ScriptInt& arg2L) {
    arg1L -= arg2L;
    RW_UNUSED(args);
}

/**
    @brief %1d% -= %2d% 

    opcode 0063
    @arg arg1L 
    @arg arg2L 
*/
void opcode_0063(const ScriptArguments& args, ScriptFloat& arg1L, ScriptFloat& arg2L) {
    arg1L -= arg2L;
    RW_UNUSED(args);
}

/**
    @brief %1d% -= %2d%  

    opcode 0064
    @arg arg1L 
    @arg arg2G 
*/
void opcode_0064(const ScriptArguments& args, ScriptInt& arg1L, ScriptInt& arg2G) {
    arg1L -= arg2G;
    RW_UNUSED(args);
}

/**
    @brief %1d% -= %2d% 

    opcode 0065
    @arg arg1L 
    @arg arg2G 
*/
void opcode_0065(const ScriptArguments& args, ScriptFloat& arg1L, ScriptFloat& arg2G) {
    arg1L -= arg2G;
    RW_UNUSED(args);
}

/**
    @brief %1d% -= %2d%

    opcode 0066
    @arg arg1G 
    @arg arg2L 
*/
void opcode_0066(const ScriptArguments& args, ScriptInt& arg1G, ScriptInt& arg2L) {
    arg1G -= arg2L;
    RW_UNUSED(args);
}

/**
    @brief %1d% -= %2d% 

    opcode 0067
    @arg arg1G 
    @arg arg2L 
*/
void opcode_0067(const ScriptArguments& args, ScriptFloat& arg1G, ScriptFloat& arg2L) {
    arg1G -= arg2L;
    RW_UNUSED(args);
}

/**
    @brief %1d% *= %2d%  

    opcode 0068
    @arg arg1G 
    @arg arg2G 
*/
void opcode_0068(const ScriptArguments& args, ScriptInt& arg1G, ScriptInt& arg2G) {
    arg1G *= arg2G;
    RW_UNUSED(args);
}

/**
    @brief %1d% *= %2d%

    opcode 0069
    @arg arg1G 
    @arg arg2G 
*/
void opcode_0069(const ScriptArguments& args, ScriptFloat& arg1G, ScriptFloat& arg2G) {
    arg1G *= arg2G;
    RW_UNUSED(args);
}

/**
    @brief %1d% *= %2d% 

    opcode 006a
    @arg arg1L 
    @arg arg2L 
*/
void opcode_006a(const ScriptArguments& args, ScriptInt& arg1L, ScriptInt& arg2L) {
    arg1L *= arg2L;
    RW_UNUSED(args);
}

/**
    @brief %1d% *= %2d% 

    opcode 006b
    @arg arg1L 
    @arg arg2L 
*/
void opcode_006b(const ScriptArguments& args, ScriptFloat& arg1L, ScriptFloat& arg2L) {
    arg1L *= arg2L;
    RW_UNUSED(args);
}

/**
    @brief %1d% *= %2d%  

    opcode 006c
    @arg arg1G 
    @arg arg2L 
*/
void opcode_006c(const ScriptArguments& args, ScriptInt& arg1G, ScriptInt& arg2L) {
    arg1G *= arg2L;
    RW_UNUSED(args);
}

/**
    @brief %1d% *= %2d%  

    opcode 006d
    @arg arg1G 
    @arg arg2L 
*/
void opcode_006d(const ScriptArguments& args, ScriptFloat& arg1G, ScriptFloat& arg2L) {
    arg1G *= arg2L;
    RW_UNUSED(args);
}

/**
    @brief %1d% *= %2d%  

    opcode 006e
    @arg arg1L 
    @arg arg2G 
*/
void opcode_006e(const ScriptArguments& args, ScriptInt& arg1L, ScriptInt& arg2G) {
    arg1L *= arg2G;
    RW_UNUSED(args);
}

/**
    @brief %1d% *= %2d%  

    opcode 006f
    @arg arg1L 
    @arg arg2G 
*/
void opcode_006f(const ScriptArguments& args, ScriptFloat& arg1L, ScriptFloat& arg2G) {
    arg1L *= arg2G;
    RW_UNUSED(args);
}

/**
    @brief %1d% /= %2d%  

    opcode 0070
    @arg arg1G 
    @arg arg2G 
*/
void opcode_0070(const ScriptArguments& args, ScriptInt& arg1G, ScriptInt& arg2G) {
    arg1G /= arg2G;
    RW_UNUSED(args);
}

/**
    @brief %1d% /= %2d% 

    opcode 0071
    @arg arg1G 
    @arg arg2G 
*/
void opcode_0071(const ScriptArguments& args, ScriptFloat& arg1G, ScriptFloat& arg2G) {
    arg1G /= arg2G;
    RW_UNUSED(args);
}

/**
    @brief %1d% /= %2d%  

    opcode 0072
    @arg arg1L 
    @arg arg2L 
*/
void opcode_0072(const ScriptArguments& args, ScriptInt& arg1L, ScriptInt& arg2L) {
    arg1L /= arg2L;
    RW_UNUSED(args);
}

/**
    @brief %1d% /= %2d% 

    opcode 0073
    @arg arg1L 
    @arg arg2L 
*/
void opcode_0073(const ScriptArguments& args, ScriptFloat& arg1L, ScriptFloat& arg2L) {
    arg1L /= arg2L;
    RW_UNUSED(args);
}

/**
    @brief %1d% /= %2d% 

    opcode 0074
    @arg arg1G 
    @arg arg2L 
*/
void opcode_0074(const ScriptArguments& args, ScriptInt& arg1G, ScriptInt& arg2L) {
    arg1G /= arg2L;
    RW_UNUSED(args);
}

/**
    @brief %1d% /= %2d% 

    opcode 0075
    @arg arg1G 
    @arg arg2L 
*/
void opcode_0075(const ScriptArguments& args, ScriptFloat& arg1G, ScriptFloat& arg2L) {
    arg1G /= arg2L;
    RW_UNUSED(args);
}

/**
    @brief %1d% /= %2d% 

    opcode 0076
    @arg arg1L 
    @arg arg2G 
*/
void opcode_0076(const ScriptArguments& args, ScriptInt& arg1L, ScriptInt& arg2G) {
    arg1L /= arg2G;
    RW_UNUSED(args);
}

/**
    @brief %1d% /= %2d%

    opcode 0077
    @arg arg1L 
    @arg arg2G 
*/
void opcode_0077(const ScriptArguments& args, ScriptFloat& arg1L, ScriptFloat& arg2G) {
    arg1L /= arg2G;
    RW_UNUSED(args);
}

/**
    @brief %1d% += frame_delta_time * %2d%

    opcode 0078
    @arg arg1G 
    @arg arg2 
*/
void opcode_0078(const ScriptArguments& args, ScriptFloat& arg1G, const ScriptFloat arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x0078);
    RW_UNUSED(arg1G);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief %1d% += frame_delta_time * %2d%

    opcode 0079
    @arg arg1L 
    @arg arg2 
*/
void opcode_0079(const ScriptArguments& args, ScriptFloat& arg1L, const ScriptFloat arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x0079);
    RW_UNUSED(arg1L);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief %1d% += frame_delta_time * %2d%

    opcode 007a
    @arg arg1G 
    @arg arg2G 
*/
void opcode_007a(const ScriptArguments& args, ScriptFloat& arg1G, ScriptFloat& arg2G) {
    RW_UNIMPLEMENTED_OPCODE(0x007a);
    RW_UNUSED(arg1G);
    RW_UNUSED(arg2G);
    RW_UNUSED(args);
}

/**
    @brief %1d% += frame_delta_time * %2d%

    opcode 007b
    @arg arg1L 
    @arg arg2L 
*/
void opcode_007b(const ScriptArguments& args, ScriptFloat& arg1L, ScriptFloat& arg2L) {
    RW_UNIMPLEMENTED_OPCODE(0x007b);
    RW_UNUSED(arg1L);
    RW_UNUSED(arg2L);
    RW_UNUSED(args);
}

/**
    @brief %1d% += frame_delta_time * %2d%

    opcode 007c
    @arg arg1G 
    @arg arg2L 
*/
void opcode_007c(const ScriptArguments& args, ScriptFloat& arg1G, ScriptFloat& arg2L) {
    RW_UNIMPLEMENTED_OPCODE(0x007c);
    RW_UNUSED(arg1G);
    RW_UNUSED(arg2L);
    RW_UNUSED(args);
}

/**
    @brief %1d% += frame_delta_time * %2d%

    opcode 007d
    @arg arg1L 
    @arg arg2G 
*/
void opcode_007d(const ScriptArguments& args, ScriptFloat& arg1L, ScriptFloat& arg2G) {
    RW_UNIMPLEMENTED_OPCODE(0x007d);
    RW_UNUSED(arg1L);
    RW_UNUSED(arg2G);
    RW_UNUSED(args);
}

/**
    @brief %1d% -= frame_delta_time * %2d%

    opcode 007e
    @arg arg1G 
    @arg arg2 
*/
void opcode_007e(const ScriptArguments& args, ScriptFloat& arg1G, const ScriptFloat arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x007e);
    RW_UNUSED(arg1G);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief %1d% -= frame_delta_time * %2d%

    opcode 007f
    @arg arg1L 
    @arg arg2 
*/
void opcode_007f(const ScriptArguments& args, ScriptFloat& arg1L, const ScriptFloat arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x007f);
    RW_UNUSED(arg1L);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief %1d% -= frame_delta_time * %2d%

    opcode 0080
    @arg arg1G 
    @arg arg2G 
*/
void opcode_0080(const ScriptArguments& args, ScriptFloat& arg1G, ScriptFloat& arg2G) {
    RW_UNIMPLEMENTED_OPCODE(0x0080);
    RW_UNUSED(arg1G);
    RW_UNUSED(arg2G);
    RW_UNUSED(args);
}

/**
    @brief %1d% -= frame_delta_time * %2d%

    opcode 0081
    @arg arg1L 
    @arg arg2L 
*/
void opcode_0081(const ScriptArguments& args, ScriptFloat& arg1L, ScriptFloat& arg2L) {
    RW_UNIMPLEMENTED_OPCODE(0x0081);
    RW_UNUSED(arg1L);
    RW_UNUSED(arg2L);
    RW_UNUSED(args);
}

/**
    @brief %1d% -= frame_delta_time * %2d% 

    opcode 0082
    @arg arg1G 
    @arg arg2L 
*/
void opcode_0082(const ScriptArguments& args, ScriptFloat& arg1G, ScriptFloat& arg2L) {
    RW_UNIMPLEMENTED_OPCODE(0x0082);
    RW_UNUSED(arg1G);
    RW_UNUSED(arg2L);
    RW_UNUSED(args);
}

/**
    @brief %1d% -= frame_delta_time * %2d%

    opcode 0083
    @arg arg1L 
    @arg arg2G 
*/
void opcode_0083(const ScriptArguments& args, ScriptFloat& arg1L, ScriptFloat& arg2G) {
    RW_UNIMPLEMENTED_OPCODE(0x0083);
    RW_UNUSED(arg1L);
    RW_UNUSED(arg2G);
    RW_UNUSED(args);
}

/**
    @brief %1d% = %2d% 

    opcode 0084
    @arg arg1G 
    @arg arg2G 
*/
void opcode_0084(const ScriptArguments& args, ScriptInt& arg1G, ScriptInt& arg2G) {
    arg1G = arg2G;
    RW_UNUSED(args);
}

/**
    @brief %1d% = %2d% 

    opcode 0085
    @arg arg1L 
    @arg arg2L 
*/
void opcode_0085(const ScriptArguments& args, ScriptInt& arg1L, ScriptInt& arg2L) {
    arg1L = arg2L;
    RW_UNUSED(args);
}

/**
    @brief %1d% = %2d%

    opcode 0086
    @arg arg1G 
    @arg arg2G 
*/
void opcode_0086(const ScriptArguments& args, ScriptFloat& arg1G, ScriptFloat& arg2G) {
    arg1G = arg2G;
    RW_UNUSED(args);
}

/**
    @brief %1d% = %2d% 

    opcode 0087
    @arg arg1L 
    @arg arg2L 
*/
void opcode_0087(const ScriptArguments& args, ScriptFloat& arg1L, ScriptFloat& arg2L) {
    arg1L = arg2L;
    RW_UNUSED(args);
}

/**
    @brief %1d% = %2d% 

    opcode 0088
    @arg arg1G 
    @arg arg2L 
*/
void opcode_0088(const ScriptArguments& args, ScriptFloat& arg1G, ScriptFloat& arg2L) {
    arg1G = arg2L;
    RW_UNUSED(args);
}

/**
    @brief %1d% = %2d%  

    opcode 0089
    @arg arg1L 
    @arg arg2G 
*/
void opcode_0089(const ScriptArguments& args, ScriptFloat& arg1L, ScriptFloat& arg2G) {
    arg1L = arg2G;
    RW_UNUSED(args);
}

/**
    @brief %1d% = %2d% 

    opcode 008a
    @arg arg1G 
    @arg arg2L 
*/
void opcode_008a(const ScriptArguments& args, ScriptInt& arg1G, ScriptInt& arg2L) {
    arg1G = arg2L;
    RW_UNUSED(args);
}

/**
    @brief %1d% = %2d%  

    opcode 008b
    @arg arg1L 
    @arg arg2G 
*/
void opcode_008b(const ScriptArguments& args, ScriptInt& arg1L, ScriptInt& arg2G) {
    arg1L = arg2G;
    RW_UNUSED(args);
}

/**
    @brief %1d% = float_to_integer %2d%

    opcode 008c
    @arg arg1G 
    @arg arg2G 
*/
void opcode_008c(const ScriptArguments& args, ScriptInt& arg1G, ScriptFloat& arg2G) {
    arg1G = static_cast<ScriptInt>(arg2G);
    RW_UNUSED(args);
}

/**
    @brief %1d% = integer_to_float %2d%

    opcode 008d
    @arg arg1G 
    @arg arg2G 
*/
void opcode_008d(const ScriptArguments& args, ScriptFloat& arg1G, ScriptInt& arg2G) {
    arg1G = static_cast<ScriptFloat>(arg2G);
    RW_UNUSED(args);
}

/**
    @brief %1d% = float_to_integer %2d%

    opcode 008e
    @arg arg1L 
    @arg arg2G 
*/
void opcode_008e(const ScriptArguments& args, ScriptInt& arg1L, ScriptFloat& arg2G) {
    arg1L = static_cast<ScriptInt>(arg2G);
    RW_UNUSED(args);
}

/**
    @brief %1d% = integer_to_float %2d%

    opcode 008f
    @arg arg1L 
    @arg arg2G 
*/
void opcode_008f(const ScriptArguments& args, ScriptFloat& arg1L, ScriptInt& arg2G) {
    arg1L = static_cast<ScriptFloat>(arg2G);
    RW_UNUSED(args);
}

/**
    @brief %1d% = float_to_int %2d%

    opcode 0090
    @arg arg1G 
    @arg arg2L 
*/
void opcode_0090(const ScriptArguments& args, ScriptInt& arg1G, ScriptFloat& arg2L) {
    arg1G = static_cast<ScriptInt>(arg2L);
    RW_UNUSED(args);
}

/**
    @brief %1d% = int_to_float %2d%

    opcode 0091
    @arg arg1G 
    @arg arg2L 
*/
void opcode_0091(const ScriptArguments& args, ScriptFloat& arg1G, ScriptInt& arg2L) {
    arg1G = static_cast<ScriptFloat>(arg2L);
    RW_UNUSED(args);
}

/**
    @brief %1d% = float_to_int %2d%

    opcode 0092
    @arg arg1L 
    @arg arg2L 
*/
void opcode_0092(const ScriptArguments& args, ScriptInt& arg1L, ScriptFloat& arg2L) {
    arg1L = static_cast<ScriptInt>(arg2L);
    RW_UNUSED(args);
}

/**
    @brief %1d% = int_to_float %2d%

    opcode 0093
    @arg arg1L 
    @arg arg2L 
*/
void opcode_0093(const ScriptArguments& args, ScriptFloat& arg1L, ScriptInt& arg2L) {
    arg1L = static_cast<ScriptFloat>(arg2L);
    RW_UNUSED(args);
}

/**
    @brief generate_random_float %1d%

    opcode 0098
    @arg arg1G 
*/
void opcode_0098(const ScriptArguments& args, ScriptFloat& arg1G) {
    arg1G = args.getWorld()->getRandomNumber(0.f, 1.f);
}

/**
    @brief generate_random_int %1d%

    opcode 0099
    @arg arg1G 
*/
void opcode_0099(const ScriptArguments& args, ScriptInt& arg1G) {
    // TODO: For GTA III and VC, the range is 0-65535, for GTA: SA it is 0-32767
    arg1G = args.getWorld()->getRandomNumber(0, 65535);
}

/**
    @brief %6d% = create_char %1d% model %2o% at %3d% %4d% %5d%

    opcode 009a
    @arg pedType Ped type
    @arg model Model ID
    @arg coord Coordinates
    @arg character Character/ped
*/
void opcode_009a(const ScriptArguments& args, const ScriptPedType pedType, const ScriptModelID model, ScriptVec3 coord, ScriptCharacter& character) {
    RW_UNUSED(pedType);

    coord = script::getGround(args, coord);
    character = args.getWorld()->createPedestrian(model, coord);
    character->applyOffset();
    character->setLifetime(GameObject::MissionLifetime);

    script::clearSpaceForObject(args, character);

    if (args.getThread()->isMission) {
        script::addObjectToMissionCleanup(args, character);
    }
}

/**
    @brief %5d% = create_car %1o% at %2d% %3d% %4d%

    opcode 00a5
    @arg model Model ID
    @arg coord Coordinates
    @arg vehicle Car/vehicle
*/
void opcode_00a5(const ScriptArguments& args, const ScriptModelID model, ScriptVec3 coord, ScriptVehicle& vehicle) {
    // @todo calculate distance from centre of mass to base of model and apply it as spawnOffset
    coord = script::getGround(args, coord);
    vehicle = args.getWorld()->createVehicle(model, coord);
    vehicle->applyOffset();
    vehicle->setLifetime(GameObject::MissionLifetime);

    script::clearSpaceForObject(args, vehicle);

    if (args.getThread()->isMission) {
        script::addObjectToMissionCleanup(args, vehicle);
    }
}

/**
    @brief car_wander_randomly %1d%

    opcode 00a8
    @arg vehicle Car/vehicle
*/
void opcode_00a8(const ScriptArguments& args, const ScriptVehicle vehicle) {
    RW_UNIMPLEMENTED_OPCODE(0x00a8);
    RW_UNUSED(vehicle);
    RW_UNUSED(args);
}

/**
    @brief %3d% = get_minutes_until_time_of_day %1d% %2d%

    opcode 00C1
    @arg hour 
    @arg minute 
    @arg minutesUntil 
*/
void opcode_00c1(const ScriptArguments& args, const ScriptInt hour, const ScriptInt minute, ScriptInt& minutesUntil) {
    int targetTime = hour * 60 + minute;
    int currentTime = args.getWorld()->getHour() * 60 + args.getWorld()->getMinute();

    if (targetTime < currentTime) {
        targetTime += 1440;
    }

    minutesUntil = targetTime - currentTime;
}

/**
    @brief %2d% = store_car_char_is_in %1d%

    opcode 00d9
    @arg character Character/ped
    @arg vehicle Car/vehicle
*/
void opcode_00d9(const ScriptArguments& args, const ScriptCharacter character, ScriptVehicle& vehicle) {
    vehicle = script::getCharacterVehicle(character);
    RW_UNUSED(args);
}

/**
    @brief %2d% = store_car_player_is_in %1d%

    opcode 00da
    @arg player 
    @arg vehicle 
*/
void opcode_00da(const ScriptArguments& args, const ScriptPlayer player, ScriptVehicle& vehicle) {
    vehicle = script::getCharacterVehicle(player->getCharacter());
    RW_UNUSED(args);
}

/**
    @brief %3d% = get_pad_state %1d% button %2d%

    opcode 00e2
    @arg padID Pad ID
    @arg buttonID Button ID
    @arg arg3 
*/
void opcode_00e2(const ScriptArguments& args, const ScriptPad padID, const ScriptButton buttonID, ScriptInt& arg3) {
    RW_UNIMPLEMENTED_OPCODE(0x00e2);
    RW_UNUSED(padID);
    RW_UNUSED(buttonID);
    RW_UNUSED(arg3);
    RW_UNUSED(args);
}

/**
    @brief player %1d% money += %2d%

    opcode 0109
    @arg player Player
    @arg money 
*/
void opcode_0109(const ScriptArguments& args, const ScriptPlayer player, const ScriptInt money) {
    RW_UNUSED(player);
    args.getState()->playerInfo.money += money;
}

/**
    @brief   player %1d% money > %2d%

    opcode 010a
    @arg player Player
    @arg money 
*/
bool opcode_010a(const ScriptArguments& args, const ScriptPlayer player, const ScriptInt money) {
    RW_UNUSED(player);
    return args.getState()->playerInfo.money > money;
}

/**
    @brief %2d% = player %1d% money

    opcode 010b
    @arg player Player
    @arg money 
*/
void opcode_010b(const ScriptArguments& args, const ScriptPlayer player, ScriptInt& money) {
    RW_UNUSED(player);
    money = args.getState()->playerInfo.money;
}

/**
    @brief   player %1d% wanted_level > %2d%

    opcode 010f
    @arg player Player
    @arg arg2 
*/
bool opcode_010f(const ScriptArguments& args, const ScriptPlayer player, const ScriptInt arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x010f);
    RW_UNUSED(player);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
    return false;
}

/**
    @brief %4d% = create_actor %2d% %3o% in_car %1d% driverseat

    opcode 0129
    @arg vehicle Ped type
    @arg pedType Model ID
    @arg model Car/vehicle
    @arg character Character/ped
*/
void opcode_0129(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptPedType pedType, const ScriptModelID model, ScriptCharacter& character) {
    RW_UNIMPLEMENTED_OPCODE(0x0129);
    RW_UNUSED(pedType);
    RW_UNIMPLEMENTED("character type");

    character =
        args.getWorld()->createPedestrian(model, vehicle->getPosition());
    character->setLifetime(GameObject::MissionLifetime);

    if (args.getThread()->isMission) {
        script::addObjectToMissionCleanup(args, character);
    }

    character->setCurrentVehicle(vehicle, 0);
    vehicle->setOccupant(0, character);
}

/**
    @brief   car %1d% id == %2o%

    opcode 0137
    @arg vehicle Car/vehicle
    @arg model Model ID
*/
bool opcode_0137(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptModelID model) {
    RW_UNUSED(args);
    return vehicle->getVehicle()->id() == model;
}

/**
    @brief %13d% = init_car_generator %5o% %6d% %7d% force_spawn %8d% alarm %9d% door_lock %10d% min_delay %11d% max_delay %12d% at %1d% %2d% %3d% angle %4d%

    opcode 014b
    @arg coord Coordinates
    @arg angle Angle
    @arg model Model ID
    @arg carColour0 Car colour ID
    @arg carColour1 Car colour ID
    @arg force Boolean true/false
    @arg alarmChance
    @arg lockChance
    @arg time0 Time (ms)
    @arg time1 Time (ms)
    @arg carGen Car generator
*/
void opcode_014b(const ScriptArguments& args, ScriptVec3 coord, const ScriptFloat angle, const ScriptModelID model, const ScriptCarColour carColour0, const ScriptCarColour carColour1, const ScriptBoolean force, const ScriptInt alarmChance, const ScriptInt lockChance, const ScriptInt time0, const ScriptInt time1, ScriptVehicleGenerator& carGen) {
    auto& vehicleGenerators = args.getWorld()->state->vehicleGenerators;
    vehicleGenerators.emplace_back(
        vehicleGenerators.size(),
        coord, angle, model, carColour0, carColour1, force, alarmChance,
        lockChance, time0, time1, 0, 0);
    /// @todo fix assignment here
    carGen = &(args.getWorld()->state->vehicleGenerators.back());
}

/**
    @brief start_timer_at %1d%

    opcode 014e
    @arg timer
*/
void opcode_014e(const ScriptArguments& args, ScriptInt& timer) {
    args.getState()->scriptTimerVariable = &timer;
}

/**
    @brief stop_timer %1d%

    opcode 014f
    @arg arg1G Global timer storage
*/
void opcode_014f(const ScriptArguments& args, ScriptInt& unused) {
    RW_UNUSED(unused);
    args.getState()->scriptTimerVariable = nullptr;
}

/**
    @brief set_time_scale %1d%

    opcode 015d
    @arg scale 
*/
void opcode_015d(const ScriptArguments& args, const ScriptFloat scale) {
    args.getState()->basic.timeScale = scale;
}

/**
    @brief %4d% = create_marker_above_car %1d% color %2d% visibility %3d%

    opcode 0161
    @arg vehicle Car/vehicle
    @arg color Blip color 
    @arg display Blip display mode
    @arg blip Blip
*/
void opcode_0161(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptBlipColour colour, const ScriptBlipDisplay display, ScriptBlip& blip) {
    auto& data = script::createObjectBlip(args, vehicle);
    data.colour = colour;
    /// @todo change ScriptBlipDisplay to BlipData::DisplayMode
    data.display = static_cast <BlipData::DisplayMode> (display);
    blip = &data;
}

/**
    @brief %4d% = create_marker_above_actor %1d% color %2d% visibility %3d%

    opcode 0162

    Creates and attaches blip for a ped

    @arg character Ped
    @arg colour Blip colour
    @arg display Blip display mode
    @arg blip Created blip
*/
void opcode_0162(const ScriptArguments& args, const ScriptCharacter character, const ScriptBlipColour colour, const ScriptBlipDisplay display, ScriptBlip& blip) {
    auto& data = script::createObjectBlip(args, character);
    data.colour = colour;
    /// @todo change ScriptBlipDisplay to BlipData::DisplayMode
    data.display = static_cast <BlipData::DisplayMode> (display);
    blip = &data;
}

/**
    @brief %6d% = create_marker_at %1d% %2d% %3d% color %4d% visibility %5d%

    opcode 0167
    @arg coord Coordinates
    @arg colour Blip color
    @arg display Blip display mode
    @arg blip Blip
*/
void opcode_0167(const ScriptArguments& args, ScriptVec3 coord, const ScriptBlipColour colour, const ScriptBlipDisplay display, ScriptBlip& blip) {
    auto& data = script::createBlip(args, script::getGround(args, coord), BlipData::Coord);
    data.colour = colour;
    /// @todo change ScriptBlipDisplay to BlipData::DisplayMode
    data.display = static_cast <BlipData::DisplayMode> (display);
    blip = &data;
}

/**
    @brief %2d% = player %1d% z_angle

    opcode 0170
    @arg player Player
    @arg angle Angle
*/
void opcode_0170(const ScriptArguments& args, const ScriptPlayer player, ScriptFloat& angle) {
    RW_UNUSED(args);
    angle = player->getCharacter()->getHeading();
}

/**
    @brief %2d% = actor %1d% z_angle

    opcode 0172
    @arg character Character/ped
    @arg angle Angle
*/
void opcode_0172(const ScriptArguments& args, const ScriptCharacter character, ScriptFloat& angle) {
    RW_UNUSED(args);
    angle = character->getHeading();
}

/**
    @brief %2d% = car %1d% z_angle

    opcode 0174
    @arg vehicle Car/vehicle
    @arg angle Angle
*/
void opcode_0174(const ScriptArguments& args, const ScriptVehicle vehicle, ScriptFloat& angle) {
    RW_UNUSED(args);
    angle = vehicle->getHeading();
}

/**
    @brief contact %1d% base_brief = %2d%

    opcode 0182
    @arg arg1 
    @arg arg2 
*/
void opcode_0182(const ScriptArguments& args, const ScriptContact arg1, const ScriptInt arg2) {
    auto& c = args.getState()->scriptContacts.at(arg1);
    c.baseBrief = arg2;
}

/**
    @brief   player %1d% health > %2h%

    opcode 0183
    @arg player Player
    @arg value 
*/
bool opcode_0183(const ScriptArguments& args, const ScriptPlayer player, const ScriptInt value) {
    RW_UNUSED(args);
    return player->getCharacter()->getCurrentState().health > value;
}

/**
    @brief   actor %1d% health >= %2d%

    opcode 0184
    @arg character Character/ped
    @arg value 
*/
bool opcode_0184(const ScriptArguments& args, const ScriptCharacter character, const ScriptInt value) {
    RW_UNUSED(args);
    return character->getCurrentState().health > value;
}

/**
    @brief   car %1d% health >= %2d%

    opcode 0185
    @arg vehicle Car/vehicle
    @arg arg2 
*/
bool opcode_0185(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptInt arg2) {
    RW_UNUSED(args);
    return vehicle->getHealth() > arg2;
}

/**
    @brief %2d% = create_marker_above_car %1d%

    opcode 0186
    @arg vehicle Car/vehicle
    @arg blip Blip
*/
void opcode_0186(const ScriptArguments& args, const ScriptVehicle vehicle, ScriptBlip& blip) {
    auto& data = script::createObjectBlip(args, vehicle);
    blip = &data;
}

/**
    @brief %2d% = create_marker_above_actor %1d%

    opcode 0187
    @arg character Character/ped
    @arg blip Blip
*/
void opcode_0187(const ScriptArguments& args, const ScriptCharacter character, ScriptBlip& blip) {
    auto& data = script::createObjectBlip(args, character);
    blip = &data;
}

/**
    @brief %4d% = unknown_create_checkpoint_at %1d% %2d% %3d%

    opcode 0189
    @arg coord Coordinates
    @arg blip Blip
*/
void opcode_0189(const ScriptArguments& args, const ScriptVec3 coord, ScriptBlip& blip) {
    auto& data = script::createBlip(args, script::getGround(args, coord), BlipData::Contact);
    blip = &data;
}

/**
    @brief %4d% = create_checkpoint_at %1d% %2d% %3d%

    opcode 018a
    @arg coord Coordinates
    @arg blip Blip
*/
void opcode_018a(const ScriptArguments& args, const ScriptVec3 coord, ScriptBlip& blip) {
    auto& data = script::createBlip(args, script::getGround(args, coord), BlipData::Coord);
    blip = &data;
}

/**
    @brief %5d% = create_sound %4d% at %1d% %2d% %3d%

    opcode 018d
    @arg coord Coordinates
    @arg sound0 
    @arg sound1 
*/
void opcode_018d(const ScriptArguments& args, ScriptVec3 coord, const ScriptSoundType sound0, ScriptSound& sound1) {
    auto world = args.getWorld();
    auto metaData = getSoundInstanceData(sound0);
    auto bufferName = world->sound.createSfxInstance(metaData->sfx);
    world->sound.playSfx(bufferName, coord, true, metaData->range);
    sound1 = &world->sound.getSfxBufferRef(bufferName);
}

/**
    @brief %1d% = current_time_in_ms

    opcode 01bd
    @arg time Time (ms)
*/
void opcode_01bd(const ScriptArguments& args, ScriptInt& time) {
    time = args.getWorld()->getGameTime() * 1000;
}

/**
    @brief %2d% = player %1d% wanted_level

    opcode 01c0
    @arg player Player
    @arg wantedLevel 
*/
void opcode_01c0(const ScriptArguments& args, const ScriptPlayer player, ScriptInt& wantedLevel) {
    RW_UNIMPLEMENTED_OPCODE(0x01c0);
    RW_UNUSED(player);
    RW_UNUSED(args);
    wantedLevel = 0;
}

/**
    @brief %5d% = create_actor %2d% model %3o% in_car %1d% passenger_seat %4d%

    opcode 01c8
    @arg vehicle Ped type
    @arg pedType Model ID
    @arg model Car/vehicle
    @arg arg4 
    @arg character Character/ped
*/
void opcode_01c8(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptPedType pedType, const ScriptModelID model, const ScriptInt arg4, ScriptCharacter& character) {
    RW_UNUSED(pedType);

    character = args.getWorld()->createPedestrian(model, vehicle->getPosition());
    character->setLifetime(GameObject::MissionLifetime);

    if (args.getThread()->isMission) {
        script::addObjectToMissionCleanup(args, character);
    }

    int pickedseat = arg4;
    if (pickedseat <= -1) {
    	for (pickedseat = 0; pickedseat < static_cast<int>(vehicle->info->seats.size()); pickedseat++) {
    		if (vehicle->getOccupant(pickedseat) == nullptr && !vehicle->isOccupantDriver(pickedseat)) {
    			break;
    		}
    	}
    } else {
    	/// @todo 0 - passenger pickedseat (or back pickedseat of bike); 1 - left rear pickedseat; 2 - right rear pickedseat
    	pickedseat++;
    }

    RW_CHECK(pickedseat < static_cast<int>(vehicle->info->seats.size()), "Seat index too high");
    RW_CHECK(vehicle->getOccupant(pickedseat) == nullptr, "Seat is not free");
    RW_CHECK(vehicle->isOccupantDriver(pickedseat) == false, "Seat is not a passenger seat");

    character->setCurrentVehicle(vehicle, pickedseat);
    vehicle->setOccupant(pickedseat, character);
}

/**
    @brief %2d% = car %1d% num_passengers

    opcode 01e9
    @arg vehicle Car/vehicle
    @arg numOfPassengers 
*/
void opcode_01e9(const ScriptArguments& args, const ScriptVehicle vehicle,
                 ScriptInt& numOfPassengers) {
    RW_UNUSED(args);
    numOfPassengers = static_cast<int>(vehicle->seatOccupants.size());
}

/**
    @brief %2d% = car %1d% max_passengers

    opcode 01ea
    @arg vehicle Car/vehicle
    @arg maxNumOfPassengers 
*/
void opcode_01ea(const ScriptArguments& args, const ScriptVehicle vehicle,
                 ScriptInt& maxNumOfPassengers) {
    RW_UNUSED(args);
    maxNumOfPassengers = static_cast<int>(vehicle->info->seats.size());
}

/**
    @brief %2d% = create_emulated_actor_from_player %1d%

    opcode 01f5
    @arg player Player
    @arg character Character/ped
*/
void opcode_01f5(const ScriptArguments& args, const ScriptPlayer player, ScriptCharacter& character) {
    RW_UNUSED(args);
    character = player->getCharacter();
}

/**
    @brief %2d% = square_root %1d%

    opcode 01fb
    @arg arg1 
    @arg arg2 
*/
void opcode_01fb(const ScriptArguments& args, const ScriptFloat arg1, ScriptFloat& arg2) {
    RW_UNUSED(args);
    arg2 = std::sqrt(arg1);
}

/**
    @brief %3d% = random_float %1d% %2d%

    opcode 0208
    @arg min
    @arg max
    @arg result
*/
void opcode_0208(const ScriptArguments& args, const ScriptFloat min, const ScriptFloat max, ScriptFloat& result) {
    result = args.getWorld()->getRandomNumber(min, max);
}

/**
    @brief %3d% = random_int_in_ranges %1d% %2d%

    opcode 0209
    @arg min
    @arg max
    @arg result
*/
void opcode_0209(const ScriptArguments& args, const ScriptInt min, const ScriptInt max, ScriptInt& result) {
    result = args.getWorld()->getRandomNumber(min, max);
}

/**
    @brief %6d% = create_pickup %1o% type %2d% at %3d% %4d% %5d%

    opcode 0213
    @arg model Model ID
    @arg pickup0 
    @arg coord Coordinates
    @arg pickup1 Pickup
*/
void opcode_0213(const ScriptArguments& args, const ScriptModel model, const ScriptPickupType pickup0, ScriptVec3 coord, ScriptPickup& pickup1) {
    pickup1 = args.getWorld()->createPickup(coord, script::getModel(args, model), pickup0);
}

/**
    @brief %8h% = create_garage %7h% from %1d% %2d% %3d% to %4d% %5d% %6d%

    opcode 0219
    @arg coord0 Coordinates
    @arg coord1 Coordinates
    @arg arg7
    @arg garage 
*/
void opcode_0219(const ScriptArguments& args, const ScriptVec3 coord0,
                 const ScriptVec3 coord1, const ScriptGarageType type,
                 ScriptGarage& garage) {
    garage = args.getWorld()->createGarage(coord0, coord1, type);
}

/**
    @brief %2d% = player %1d% health

    opcode 0225
    @arg player Player
    @arg health 
*/
void opcode_0225(const ScriptArguments& args, const ScriptPlayer player, ScriptInt& health) {
    RW_UNUSED(args);
    health = player->getCharacter()->getCurrentState().health;
}

/**
    @brief %2d% = actor %1d% health

    opcode 0226
    @arg character Character/ped
    @arg health 
*/
void opcode_0226(const ScriptArguments& args, const ScriptCharacter character, ScriptInt& health) {
    RW_UNUSED(args);
    health = character->getCurrentState().health;
}

/**
    @brief %2d% = car %1d% health

    opcode 0227
    @arg vehicle Car/vehicle
    @arg arg2 
*/
void opcode_0227(const ScriptArguments& args, const ScriptVehicle vehicle, ScriptInt& arg2) {
    RW_UNUSED(args);
    arg2 = static_cast<int> (vehicle->getHealth());
}

/**
    @brief   car %1d% bomb_status == %2d%

    opcode 0228
    @arg vehicle Car/vehicle
    @arg arg2 
*/
bool opcode_0228(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptCarBomb arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x0228);
    RW_UNUSED(vehicle);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
    return false;
}

/**
    @brief %1d% = get_controller_mode

    opcode 0293
    @arg arg1 
*/
void opcode_0293(const ScriptArguments& args, ScriptInt& arg1) {
    RW_UNUSED(args);
    /// @todo determine if other controller modes should be supported via script
    /// or if we should re-map things ourselves.
    arg1 = 0;
}

/**
    @brief %5d% = create_marker %4d% at %1d% %2d% %3d%

    opcode 02a8
    @arg coord Coordinates
    @arg blipSprite Blip sprite ID
    @arg blip Blip
*/
void opcode_02a8(const ScriptArguments& args, ScriptVec3 coord, const ScriptRadarSprite blipSprite, ScriptBlip& blip) {
    auto& data = script::createBlipSprite(args, coord, BlipData::Coord, blipSprite);
    blip = &data;
}

/**
    @brief %1d% = donkey_mags_picked_up

    opcode 02c5
    @arg collected
*/
void opcode_02c5(const ScriptArguments& args, ScriptInt& collected) {
    collected = args.getState()->bigNVeinyPickupsCollected;
}

/**
    @brief %1d% = platinum_pieces_in_car

    opcode 02c8
    @arg arg1 
*/
void opcode_02c8(const ScriptArguments& args, ScriptInt& arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x02c8);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief %4d% = create_fire_at %1d% %2d% %3d%

    opcode 02cf
    @arg coord Coordinates
    @arg fire 
*/
void opcode_02cf(const ScriptArguments& args, ScriptVec3 coord, ScriptFire& fire) {
    RW_UNIMPLEMENTED_OPCODE(0x02cf);
    RW_UNUSED(coord);
    RW_UNUSED(fire);
    RW_UNUSED(args);
}

/**
    @brief   player %1d% currentweapon == %2c%

    opcode 02d7
    @arg player 
    @arg weaponId 
*/
bool opcode_02d7(const ScriptArguments& args, const ScriptPlayer player, const ScriptWeaponType weaponId) {
    RW_UNUSED(args);
    auto plyChar = player->getCharacter();
    return plyChar->getCurrentState().weapons[plyChar->getActiveItem()].weaponId == unsigned(weaponId);
}

/**
    @brief   actor %1d% current_weapon == %2c%

    opcode 02d8
    @arg character Character/ped
    @arg weaponID Weapon ID
*/
bool opcode_02d8(const ScriptArguments& args, const ScriptCharacter character, const ScriptWeaponType weaponID) {
    RW_UNUSED(args);
    return character->getCurrentState().weapons[character->getActiveItem()].weaponId == unsigned(weaponID);
}

/**
    @brief donkey_mags_picked_up = none

    opcode 02d9
*/
void opcode_02d9(const ScriptArguments& args) {
    args.getState()->bigNVeinyPickupsCollected = 0;
}

/**
    @brief get_random_actor %2d% in_zone %1s%

    opcode 02dd
    @arg areaName Area name
    @arg character Character/ped
*/
void opcode_02dd(const ScriptArguments& args, const ScriptString areaName, ScriptCharacter& character) {
    RW_UNIMPLEMENTED_OPCODE(0x02dd);
    RW_UNUSED(areaName);
    RW_UNUSED(character);

    std::string zname(args[0].string);

    // Only try to find a character if this is a known zone
    auto zone = args.getWorld()->data->findZone(areaName);
    if (zone) {
        // Create a list of candidate characters by iterating and checking if the char is in this zone
        std::vector<std::pair<GameObjectID, GameObject*>> candidates;
        for (auto& [id, pedestrianPtr] : args.getWorld()->pedestrianPool.objects) {
            auto character = static_cast<CharacterObject*>(pedestrianPtr.get());

            // We only consider characters walking around normally
            // @todo not sure if we are able to grab script objects or players too
            // husho: only grab traffic objects
            if (character->getLifetime() != GameObject::TrafficLifetime) {
                continue;
            }

            // Check if character is in this zone
            auto cp = character->getPosition();
            auto& min = zone->min;
            auto& max = zone->max;
            if (cp.x > min.x && cp.y > min.y && cp.z > min.z &&
                cp.x < max.x && cp.y < max.y && cp.z < max.z) {
                candidates.emplace_back(id, pedestrianPtr.get());
            }
        }

        // Only return a result if we found a character
        const auto candidateCount = candidates.size();
        if (candidateCount > 0) {
            // Return the handle for any random character in this zone and use lifetime for use by script
            // @todo verify if the lifetime is actually changed in the original game
            // husho: lifetime is changed to mission object lifetime
            auto randomIndex =
                args.getWorld()->getRandomNumber(0u, candidateCount);
            const auto [candidateId, candidatePtr] = candidates.at(randomIndex);
            auto character = static_cast<CharacterObject*>(candidatePtr);
            character->setLifetime(GameObject::MissionLifetime);
            if (args.getThread()->isMission) {
                script::addObjectToMissionCleanup(args, character);
            }
            *args[1].globalInteger = candidateId;
            return;
        }
    }

    // If we didn't find any character in the zone return 0
    *args[1].globalInteger = -1;
}

/**
    @brief %5d% = create_cash_pickup %4d% at %1d% %2d% %3d%

    opcode 02e1
    @arg arg1 
    @arg arg2 
    @arg arg3 
    @arg money 
    @arg pickup 
*/
void opcode_02e1(const ScriptArguments& args, ScriptVec3 coord, const ScriptInt money, ScriptPickup& pickup) {
    coord = script::getGround(args, coord);
    PickupObject* pickupObj = args.getWorld()->createPickup(coord, args.getWorld()->data->findModelObject("Money"), PickupObject::PickupType::Money);
    static_cast<MoneyPickup*>(pickupObj)->setMoney(money);
    pickup = pickupObj;
}

/**
    @brief %2d% = car %1d% speed

    opcode 02e3
    @arg vehicle Car/vehicle
    @arg arg2 
*/
void opcode_02e3(const ScriptArguments& args, const ScriptVehicle vehicle, ScriptFloat& arg2) {
    RW_UNUSED(args);
    // m/s -> km/h
    arg2 = (vehicle->getVelocity()/1000.f)*60.f*60;
}

/**
    @brief %1d% = cutscenetime

    opcode 02e8
    @arg arg1 
*/
void opcode_02e8(const ScriptArguments& args, ScriptInt& arg1) {
    auto& cutscene = args.getState()->currentCutscene;
    if (args.getState()->skipCutscene) {
        arg1 = cutscene ? cutscene->tracks.duration * 1000 : 0.f;
    }
    else {
    	arg1 = (args.getWorld()->getGameTime() - args.getState()->cutsceneStartTime) * 1000;
    }
}

/**
    @brief   actor %1d% model == %2h%

    opcode 02f2
    @arg character Character/ped
    @arg model Model ID
*/
bool opcode_02f2(const ScriptArguments& args, const ScriptCharacter character, const ScriptModelID model) {
    RW_UNIMPLEMENTED_OPCODE(0x02f2);
    RW_UNUSED(character);
    RW_UNUSED(model);
    RW_UNUSED(args);
    return false;
}

/**
    @brief %2d% = sine %1d%

    opcode 02f6
    @arg angle Angle
    @arg xOffset X offset
*/
void opcode_02f6(const ScriptArguments& args, const ScriptFloat angle, ScriptFloat& xOffset) {
    xOffset = glm::sin(glm::radians(angle));
    RW_UNUSED(args);
}

/**
    @brief %2d% = cosine %1d%

    opcode 02f7
    @arg angle Angle
    @arg yOffset Y offset
*/
void opcode_02f7(const ScriptArguments& args, const ScriptFloat angle, ScriptFloat& yOffset) {
    yOffset = glm::cos(glm::radians(angle));
    RW_UNUSED(args);
}

/**
    @brief %6d% = get_random_car_of_type %5d% in_area %1d% %2d% to %3d% %4d%

    opcode 0327
    @arg coord0 Coordinates
    @arg coord1 Coordinates
    @arg model Model ID
    @arg vehicle Car/vehicle
*/
void opcode_0327(const ScriptArguments& args, ScriptVec2 coord0, ScriptVec2 coord1, const ScriptModelID model, ScriptVehicle& vehicle) {
    RW_UNIMPLEMENTED_OPCODE(0x0327);
    RW_UNUSED(coord0);
    RW_UNUSED(coord1);
    RW_UNUSED(model);
    RW_UNUSED(vehicle);
    RW_UNUSED(args);
}

/**
    @brief %7d% = create_weapon_pickup %1o% type %2d% ammo %3d% at %4d% %5d% %6d%

    opcode 032b
    @arg model Model ID
    @arg pickup0 Weapon ID
    @arg arg3 
    @arg coord Coordinates
    @arg pickup1 Player
*/
void opcode_032b(const ScriptArguments& args, const ScriptModel model, const ScriptPickupType pickup0, const ScriptInt arg3, ScriptVec3 coord, ScriptPickup& pickup1) {
    RW_UNUSED(arg3);
    RW_UNIMPLEMENTED("ammo count");
    RW_CHECK(model >= 0, "Must look up model");

    pickup1 = args.getWorld()->createPickup(coord, model, pickup0);
}

/**
    @brief text_draw_style = %1d%

    opcode 0349
    @arg arg1 
*/
void opcode_0349(const ScriptArguments& args, const ScriptFont arg1) {
    RW_UNIMPLEMENTED_OPCODE(0x0349);
    RW_UNUSED(arg1);
    RW_UNUSED(args);
}

/**
    @brief %4d% = create_random_actor %1d% %2d% %3d%

    opcode 0376
    @arg coord Coordinates
    @arg character Character/ped
*/
void opcode_0376(const ScriptArguments& args, ScriptVec3 coord,
                 ScriptCharacter& character) {
    coord = script::getGround(args, coord);
    auto world = args.getWorld();
    auto state = args.getState();
    auto data = world->data;
    auto zone =
        data->findZoneAt(world->getPlayer()->getCharacter()->getPosition());
    const bool day =
        (state->basic.gameHour >= 8 && state->basic.gameHour <= 19);
    const int groupId =
        zone ? (day ? zone->pedGroupDay : zone->pedGroupNight) : 0;
    const auto& pedGroup = data->pedgroups.at(groupId);
    const auto model =
        pedGroup.at(args.getWorld()->getRandomNumber(0u, pedGroup.size() - 1));
    character = world->createPedestrian(model, coord);
    character->applyOffset();
    script::clearSpaceForObject(args, character);
}

/**
    @brief pause_timer %1d%

    opcode 0396
    @arg arg1 Boolean true/false
*/
void opcode_0396(const ScriptArguments& args, const ScriptBoolean paused) {
    args.getState()->scriptTimerPaused = paused;
}

/**
    @brief car %1d% siren = %2b:on/off%

    opcode 0397
    @arg vehicle Car/vehicle
    @arg arg2 Boolean true/false
*/
void opcode_0397(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptBoolean arg2) {
    RW_UNIMPLEMENTED_OPCODE(0x0397);
    RW_UNUSED(vehicle);
    RW_UNUSED(arg2);
    RW_UNUSED(args);
}

/**
    @brief %2d% = actor %1d% car

    opcode 03c0
    @arg character Character/ped
    @arg vehicle Car/vehicle
*/
void opcode_03c0(const ScriptArguments& args, const ScriptCharacter character, ScriptVehicle& vehicle) {
    RW_UNIMPLEMENTED_OPCODE(0x03c0);
    RW_UNUSED(character);
    RW_UNUSED(vehicle);
    RW_UNUSED(args);
}

/**
    @brief %2d% = player %1d% car_no_save

    opcode 03c1
    @arg player 
    @arg vehicle 
*/
void opcode_03c1(const ScriptArguments& args, const ScriptPlayer player, ScriptVehicle& vehicle) {
    vehicle = player->getCharacter()->getCurrentVehicle();
    RW_UNUSED(args);
}

/**
    @brief create_random_car_for_carpark %1d% %2d% %3d% %4d%

    opcode 03c5
    @arg coord Coordinates
    @arg angle Angle
*/
void opcode_03c5(const ScriptArguments& args, ScriptVec3 coord, const ScriptFloat angle) {
    RW_UNIMPLEMENTED_OPCODE(0x03c5);
    RW_UNUSED(coord);
    RW_UNUSED(angle);
    RW_UNUSED(args);
}

/**
    @brief   current_island == %1d%

    opcode 03c6
    @arg island
*/
bool opcode_03c6(const ScriptArguments& args, const ScriptLevel island) {
    // The parameter to this is actually the island number.
    // Not sure how that will fit into the scheme of full paging
    auto world = args.getWorld();
    auto zone = world->data->findZoneAt(
        world->getPlayer()->getCharacter()->getPosition());

    return island == zone->island;
}

/**
    @brief car %1d% add_to_stuck_car_check %2d% = %3d%

    opcode 03cc
    @arg vehicle Car/vehicle
    @arg radius Radius
    @arg time Time (ms)
*/
void opcode_03cc(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptFloat radius, const ScriptInt time) {
    RW_UNIMPLEMENTED_OPCODE(0x03cc);
    RW_UNUSED(vehicle);
    RW_UNUSED(radius);
    RW_UNUSED(time);
    RW_UNUSED(args);
}

/**
    @brief %2d% = create_marker_above_pickup %1d%

    opcode 03dc
    @arg pickup Player
    @arg blip Blip
*/
void opcode_03dc(const ScriptArguments& args, const ScriptPickup pickup, ScriptBlip& blip) {
    auto& data = script::createObjectBlip(args, pickup);
    blip = &data;
}

/**
    @brief all_random_peds %1o%

    opcode 03df
    @arg pedType Model ID
*/
void opcode_03df(const ScriptArguments& args, const ScriptPedType pedType) {
    RW_UNIMPLEMENTED_OPCODE(0x03df);
    RW_UNUSED(pedType);
    RW_UNUSED(args);
}

/**
    @brief %1d% = packages_found

    opcode 03e1
    @arg arg1 
*/
void opcode_03e1(const ScriptArguments& args, ScriptInt& arg1) {
    arg1 = args.getState()->playerInfo.hiddenPackagesCollected;
}

/**
    @brief %2d% = meters_to_feet %1d% 

    opcode 0425
    @arg arg1 
    @arg arg2 
*/
void opcode_0425(const ScriptArguments& args, const ScriptFloat arg1, ScriptFloat& arg2) {
    arg2 = arg1 * 3.333333f;
    RW_UNUSED(args);
}

/**
    @brief %2d% = round(meters_to_feet(%1d%)) 

    opcode 042d
    @arg arg1 
    @arg arg2 
*/
void opcode_042d(const ScriptArguments& args, const ScriptInt arg1, ScriptInt& arg2) {
    arg2 = static_cast<ScriptInt>(std::floor(static_cast<ScriptFloat>(arg1) * 3.3333334f));
    RW_UNUSED(args);
}

/**
    @brief %3d% = get_passenger_in_car %1d% seat %2h%

    opcode 0432
    @arg vehicle Car/vehicle
    @arg arg2 
    @arg character Character/ped
*/
void opcode_0432(const ScriptArguments& args, const ScriptVehicle vehicle, const ScriptInt arg2, ScriptCharacter& character) {
    RW_UNIMPLEMENTED_OPCODE(0x0432);
    RW_UNUSED(vehicle);
    RW_UNUSED(arg2);
    RW_UNUSED(character);
    RW_UNUSED(args);
}

/**
    @brief %2d% = car %1d% model

    opcode 0441
    @arg vehicle Car/vehicle
    @arg model Model ID
*/
void opcode_0441(const ScriptArguments& args, const ScriptVehicle vehicle, ScriptInt& model) {
    RW_UNIMPLEMENTED_OPCODE(0x0441);
    RW_UNUSED(vehicle);
    RW_UNUSED(model);
    RW_UNUSED(args);
}

