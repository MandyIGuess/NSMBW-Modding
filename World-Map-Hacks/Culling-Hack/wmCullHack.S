.text
.align 4

#include <asm_setup.S>

.extern wmNodeCullTable
.extern returnToCullCode  # 0x808E3188
.extern returnToCullCode2 # 0x808E3260

.global newCullInfo
newCullInfo:
    lis     r29, wmNodeCullTable@h
    ori     r29, r29, wmNodeCullTable@l
	b       returnToCullCode

.global newCullInfo2
newCullInfo2:
    lis     r31, wmNodeCullTable@h
    ori     r31, r31, wmNodeCullTable@l
	b       returnToCullCode2