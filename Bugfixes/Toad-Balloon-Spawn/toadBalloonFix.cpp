#include <game.h>

class daEnGreenCoin_c : public dEn_c {
public:
    USING_STATES(daEnGreenCoin_c);
    REF_NINTENDO_STATE(Move);
};

class daBattleGame_c : public dActorState_c {
public:
    u32 pad;
    int gameBeginDelay;
    int balloonActivateDelay;
    u32 pad2;

    int execute();

    USING_STATES(daBattleGame_c);
    REF_NINTENDO_STATE(DemoStart_SoundStartWait);
};

int daBattleGame_c::execute() {
    acState.execute();

    // Check if the ambush itself is running, to avoid affecting the initial spawn
    if ((balloonActivateDelay == 0) && (gameBeginDelay == 0) && acState.getCurrentState()->isEqual(&StateID_DemoStart_SoundStartWait)) {
        daEnGreenCoin_c *from = 0x0;
        while (from = (daEnGreenCoin_c*)fBase_c::searchByProfileId(EN_GREENCOIN, from), from != 0x0) {
            // We do this manually to prevent it from playing the appear sound
            from->visible = true;
            from->acState.setState(&daEnGreenCoin_c::StateID_Move);
        }
    }
    return true;
}
