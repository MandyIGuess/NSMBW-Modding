.text
.align 4

#include <asm_setup.S>

.extern getWmActorCullRadius__Fs
.extern returnFromWmActorCull # 0x800F2A4C

.global CullAllWmActors
CullAllWmActors:
    lha r3, 0x8(r31) # Get profileID
    bl getWmActorCullRadius__Fs

    fmr f0, f1 # Our float is in f1, we need it in f0
    stfs f1, 0x134(r31) # Override mSphere radius
    b returnFromWmActorCull