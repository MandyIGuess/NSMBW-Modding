.text
.align 4

#include <asm_setup.S>

.extern getWmActorCullRadius__Fs
.extern returnFromWmActorCull # 0x800F2A4C

.extern wmCloudCullNames
.extern wmCloudCullRadius

.extern wmIbaraCullRadius
.extern wmIbaraCullNames

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
    blr

.global LoadWmCloudCullRadius
LoadWmCloudCullRadius:
    lis     r29, wmCloudCullRadius@h
    ori     r29, r29, wmCloudCullRadius@l
    blr

.global LoadWmIbaraNames
LoadWmIbaraNames:
    lis     r29, wmIbaraCullNames@h
    ori     r29, r29, wmIbaraCullNames@l
    blr

.global LoadWmIbaraRadius
LoadWmIbaraRadius:
    lis     r4, wmIbaraCullRadius@h
    ori     r4, r4, wmIbaraCullRadius@l
    lfs     f31, 0x0(r4)
    blr
