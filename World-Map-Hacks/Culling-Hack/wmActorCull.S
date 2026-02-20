.text
.align 4

#include <asm_setup.S>

.extern getWmActorCullRadius__Fs
.extern returnFromWmActorCull # 0x800F2A4C

.extern wmCloudCullNames
.extern wmCloudCullRadius
.extern returnFromWmCloudCull1 # 0x808CD9E8
.extern returnFromWmCloudCull2 # 0x808CDA80

.global CullAllWmActors
CullAllWmActors:
    lha r3, 0x8(r31) # Get profileID
    bl getWmActorCullRadius__Fs

    fmr f0, f1 # Our float is in f1, we need it in f0
    stfs f1, 0x134(r31) # Override mSphere radius
    b returnFromWmActorCull

.global LoadWmCloudCullNames
LoadWmCloudCullNames:
    lis     r30, wmCloudCullNames@h
    ori     r30, r30, wmCloudCullNames@l
    b       returnFromWmCloudCull1

.global LoadWmCloudCullRadius
LoadWmCloudCullRadius:
    lis     r29, wmCloudCullRadius@h
    ori     r29, r29, wmCloudCullRadius@l
    b       returnFromWmCloudCull2