#include <game.h>

class dScGameSetup_c : public dScene_c {
public:
	dStateWrapper_c<dScGameSetup_c> state;
	FunctionChain funcChain;

	void *numPeopleChange;	// dNumberOfPeopleChange_c
	void *selectCursor;		// dSelectCursor_c
	void *player2d[4];		// da2DPlayer_c
	void *selectPlayer;		// dSelectPlayer_c
	void *easyPairing;		// dEasyPairing_c
	void *sequenceBG;		// dSequenceBG_c
	void *dateFiles[3];
	void *fileSelect;		// dFileSelect_c
	void *infoWindow;		// dInfoWindow_c

	u32 _F0, _F4;
	int playerCount;
	u32 _FC, _100, lastUsedSaveFile;

	bool isInPlayerSelect;
	u8 pad[3];

	u8 ortho[0x60]; // EGG_OrthoData
	EGG::LookAtCamera lookAtCamera;
	u8 viewport[0x1C]; // EGG__SimpleViewport

	void executeState_FadeIn();

	USING_STATES(dScGameSetup_c);
	REF_NINTENDO_STATE(LowBatteryCheck);
};

void dScGameSetup_c::executeState_FadeIn() {
	state.setState(&StateID_LowBatteryCheck);
}
