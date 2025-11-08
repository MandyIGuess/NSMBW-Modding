#include <game.h>

class daEnCoinAngle_c : public dEn_c {
public:
	u8 crap[0x5C0];
	u32 rotControllerUniqueID;

	void handleRotation(); // 0x809E5660
	void addNewSettings();
};

// 5.4 : always upright
// 5.3 : tilted coin
// 6 : forced rotation
void daEnCoinAngle_c::addNewSettings() {
	this->handleRotation();

	int forcedAngleIdx = (settings >> 24) & 0xF;
	if (forcedAngleIdx != 0) { // 0 serves as "disabled" value
		rot.z = -0x1000 * forcedAngleIdx;
		return;
	}

	if ((settings >> 28) & 1) { // always upright
		rot.z = 0;
	}

	if ((settings >> 28) & 2) { // tilted coins
		dStageActor_c *rotController = (dStageActor_c*)fBase_c::searchById(this->rotControllerUniqueID);
		if (rotController != 0x0) {
			Vec2 deltaPos;
			deltaPos.x = this->pos.x - rotController->pos.x;
			deltaPos.y = this->pos.y - rotController->pos.y;

			this->rot.z = -atan2(deltaPos.x, deltaPos.y) * 0x8000 / M_PI;
		}
	}
}
