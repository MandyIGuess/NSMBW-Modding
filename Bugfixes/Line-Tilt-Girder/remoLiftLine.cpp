#include <game.h>

class dLineMng_c {
public:
    u8 unk[0x40];
    Vec2 pos;
    u8 unk2[0xA4];
};

class daLiftRemoconXline_c : public dActorState_c {
public:
    u8 unk[0x28C];
    dLineMng_c lineMng;
};

extern "C" void LineMng_SetPos(void *, Vec2 *);

float fixRemoLineLiftPos(daLiftRemoconXline_c *self, float x) {
    Vec2 pos;
    pos.x = self->lineMng.pos.x;
    pos.y = self->lineMng.pos.y;

    // Prevent dragging along the screen edge
    if ((self->settings >> 0x1F) != 0) {
        self->pos.x = x;
        pos.x = x;
    }

    // Note: When dragging against left edge, dLineMng_c::CalcAdjustPosY() was used instead,
    // which caused massive lag spikes if the lift was dragged off of its line guides
    LineMng_SetPos(&self->lineMng, &pos);
    return pos.y;
}
