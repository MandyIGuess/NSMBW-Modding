#include <game.h>
#include <sfx.h>
#include <stage.h>

class SndSceneMgr {
public:
    u8 unk[0x14];
    int mSndSceneID;

    void startMiss();
    void moveMissFin();

    static SndSceneMgr *sInstance;
};

class SndAudioMgr {
public:
    void startFanfare(ulong);
};

static bool doMissFin = false;

void SndSceneMgr::startMiss() {
    if (mSndSceneID == 0x11) {
        // moveMissFin() needs to run every frame, which does not happen here,
        // so we'll call it in dAcPy_c's execute, but only if this static var is on
        doMissFin = true;
    }
}

int daPlBase_c__executePatch(int ret) {
    if (doMissFin) {
        SndSceneMgr::sInstance->moveMissFin();
    }
    return ret;
}

// Reset it to avoid issues in the next stage we enter
int dAcPy_c__doDeletePatch(int ret) {
    doMissFin = false;
    return ret;
}
