.text
.align 4

#include <asm_setup.S>

.extern wmNodeCullTable

.global newCullInfo
newCullInfo:
    lis     r29, wmNodeCullTable@h
    ori     r29, r29, wmNodeCullTable@l
    blr

.global newCullInfo2
newCullInfo2:
    lis     r31, wmNodeCullTable@h
    ori     r31, r31, wmNodeCullTable@l
    blr
