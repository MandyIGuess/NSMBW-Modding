#include <asm_setup.S>

.text
.align 4

.extern fixRemoLineLiftPos__FP20daLiftRemoconXline_cf
.extern afterFixRemoLineLift1
.extern afterFixRemoLineLift2

.global FixRemoLineLift1
FixRemoLineLift1:
    or r3, r28, r28
    bl fixRemoLineLiftPos__FP20daLiftRemoconXline_cf

    lfs f2, 0x60(r31)
    lfs f0, 0x74(r31)
    b afterFixRemoLineLift1

.global FixRemoLineLift2
FixRemoLineLift2:
    or r3, r28, r28
    fmr f1, f2
    bl fixRemoLineLiftPos__FP20daLiftRemoconXline_cf

    li r29, 0x1
    b afterFixRemoLineLift2
