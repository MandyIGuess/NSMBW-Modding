#include <game.h>

// Fix Bramball detecting invisible blocks as valid terrain when stepping up
// Example setup to test this: ReggieClip|0:0:17:1:33:21:2:1|0:0:17:1:45:23:2:1|0:0:26:1:37:22:2:1|0:0:26:1:41:22:2:1|1:230:632:336:0:0:0:0:0:0:0|%

int daEnIbaramushi_c_chkStepUp(dEn_c *self, Vec *pos) {
    int ret = 0;
    float pY = pos->y + 8.0f;

    while (true) {
        bool bVar2 = false;
        bool bVar3 = false;
        float fVar1 = 0.0f;
        while (!bVar2) {
            if (fVar1 > 8.0f) {
                bVar2 = true;
                fVar1 = 8.0f;
            }
            u32 unitType = collisionMgr_c::getTileBehaviour1At((pos->x - 4.0f) + fVar1, pY, self->currentLayerID);
            // 0x2000 : Invisible block
            // 0x801D : Checks for solid, ? block, brick block, explodable, or solid-on-top tiles
            // Taken from chkStepDown (0x80A1D6A0)
            if (((unitType & 0x2000) == 0) && ((unitType & 0x801D) != 0)) {
                bVar3 = true;
                break;
            }
            fVar1 += 16.0f;
        }

        if (!bVar3) {
            return ret;
        }

        ret++;
        pY += 16.0;
        if (ret > 1) {
            return ret;
        }
    }
}
