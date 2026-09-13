#include <game.h>

class daNiceCoin_c : public dActorState_c {
public:
    void finalizeState_Search();

    int mCollectionID;
    int mMode; // 0 = yellow only, 1 = blue only, 2 = blue and yellow
    int mActorType; // Set to 1 if this is AC_NICE_COIN_REGULAR

    int mCoinNum;
    int mBlueCoinNum;

    int mCoinCollectNum;
    int mBlueCollectNum;
};

void daNiceCoin_c::finalizeState_Search() {
    u8 eventNum = (spriteFlagNum & 0xFF) - 1;
    dFlagMgr_c::instance->set(eventNum, 0, true, false, false);
}
