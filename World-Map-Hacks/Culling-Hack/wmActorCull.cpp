#include <common.h>
#include <actors.h>

// Denotes entries that don't use the culling feature
// Default value if cull radius isn't redefined
#define NO_CULL 0.0f

static const float wmActorCullRadius[] = {
    0.0f,     // WM_IBARA        : World 5 vines
    NO_CULL,  // WM_ANTLION_MNG  : World 2 ambush manager
    250.0f,   // WM_CASTLE       : Castle
    100.0f,   // WM_TOWER        : Unused actor
    200.0f,   // WM_PEACH_CASTLE : Peach's Castle
    100.0f,   // WM_KILLER       : World 6 Bill Blasters
    60.0f,    // WM_KILLERBULLET : Bullet Bill
    100.0f,   // WM_SINKSHIP     : Unused actor
    80.0f,    // WM_SWITCH       : World 3 switches
    50.0f,    // WM_START        : Start node
    120.0f,   // WM_KINOKO_BASE  : Base actor for Toad Houses (not used directly)
    120.0f,   // WM_KINOKO_RED   : Red Toad House
    120.0f,   // WM_KINOKO_1UP   : Green Toad House
    120.0f,   // WM_KINOKO_STAR  : Star Toad House
    80.0f,    // WM_COURSE       : Course node
    10.0f,    // WM_STOP         : Unused actor
    170.0f,   // WM_TORIDE       : Tower
    180.0f,   // WM_GHOST        : Ghost House
    80.0f,    // WM_DOKAN        : Obsolete actor(?) Created but never sets up any model
    120.0f,   // WM_CANNON       : Warp Cannon
    200.0f,   // WM_KOOPASHIP    : Airship
    100.0f,   // WM_BOSS_BASE    : Base actor for bosses (not used directly)
    100.0f,   // WM_BOSS_LARRY   : Bosses
    100.0f,   // WM_BOSS_ROY     : ^
    100.0f,   // WM_BOSS_WENDY   : ^
    100.0f,   // WM_BOSS_IGGY    : ^
    100.0f,   // WM_BOSS_LEMMY   : ^
    100.0f,   // WM_BOSS_MORTON  : ^
    100.0f,   // WM_BOSS_LUDWIG  : ^
    100.0f,   // WM_BOSS_KAMECK  : ^
    100.0f,   // WM_ANTLION      : World 2 sinkhole ambushes
    60.0f,    // WM_KURIBO       : World 1 Goomba
    60.0f,    // WM_PUKU         : World 4 Porcupuffer
    60.0f,    // WM_PAKKUN       : World 5 Piranha
    80.0f,    // WM_BROS         : World 3 Ice Bro
    60.0f,    // WM_JUGEM        : World 7 Lakitu
    NO_CULL,  // WM_PLAYER       : World Map player
    NO_CULL,  // WM_SUBPLAYER    : World Map sub-players (P2-P4)
    50.0f,    // WM_NOTE         : Unused actor
    50.0f,    // WM_TREASURESHIP : Unused actor
    NO_CULL,  // WM_DIRECTOR     : Map script manager, does not draw models
    NO_CULL,  // WM_GRID         : Unused, dummied-out actor
    NO_CULL,  // WM_ISLAND       : World Select island, cannot be culled
    NO_CULL,  // WM_ITEM         : Items menu powerups, cannot be culled
    2000.0f,  // WM_CS_W3_PALM   : Palm tree manager for World 2 and World 4
    100.0f,   // WM_SURRENDER    : Tower/Castle clear flags
    800.0f,   // WM_KOOPA_CASTLE : Bowser's Castle
    100.0f,   // WM_ANCHOR       : Airship anchor
    250.0f,   // WM_PAKKUNHEAD   : World 7 climbable vines
    2500.0f,  // WM_CLOUD        : World 7 clouds
    400.0f,   // WM_SMALLCLOUD   : World 7 clouds, and the cloud in World 6
    250.0f,   // WM_KOOPAJR      : Bowser Jr
    10000.0f, // WM_PEACH        : Princess Peach
    150.0f,   // WM_BOARD        : World 9 Star Coin blockade
    100.0f,   // WM_BUBBLE       : World 8 Podoboo
    120.0f,   // WM_KINOBALLOON  : Toad Rescue balloons
    350.0f,   // WM_SANDPILLAR   : World 2 sand geysers
    250.0f,   // WM_YOGANPILLAR  : World 8 lava geysers
    100.0f,   // WM_KINOPIO      : World 1 Toad that introduces Toad Rescues
    250.0f,   // WM_DANCE_PAKKUN : World 6 decorative pipe Piranha Plants 
    250.0f,   // WM_DOKANROUTE   : Animated pipe routes for World 6
    250.0f,   // WM_HANACHAN     : Wiggler in the background of World 5
    250.0f,   // WM_TOGEZO       : Unused actor
    250.0f,   // WM_MANTA        : Unused actor
    80.0f,    // WM_TERESA       : Ghost House Boo
};

f32 getWmActorCullRadius(short profName) {
    // There are map actors before WM_IBARA, however they do not need to be culled
    if ((profName < WM_CS_SEQ_MNG) || (profName > WORLD_SELECT)) {
        return NO_CULL;
    }

    return wmActorCullRadius[profName - WM_IBARA];
}
