#include "moreFonts.h"

// EDIT THESE WHEN ADDING NEW FONTS:
#define FONT_COUNT 4

// Changing the order of these will change what font is used by BMG-printed text
static const char *FONT_NAME_TBL[FONT_COUNT] = {
	"mj2d01_marioFont_64_IA4.brfnt",
	"mj2d00_PictureFont_32_RGBA8.brfnt",
	"mj2d00_MessageFont_32_I4.brfnt",
	"mj2d00_numberFont_I4A.brfnt",
	// START OF NEW ENTRIES...
};


void AreaLanguageFolder(const char *name, const char *out); // 0x800B4670
bool ResFontSetResource(ResFontBase *self, BinaryFileHeader *brfnt); // 0x8022C4E0
void *s_FontManagerHeap; // 0x8042A378

class dNewFontMng_c {
public:
	ResFontBase		  mFont[FONT_COUNT];
	dDvdLoader_c	  mFontLoader[FONT_COUNT];
	BinaryFileHeader *mFontData[FONT_COUNT];

	dNewFontMng_c();

	static int create(void *heap);

	static u32 getResFontIndex(char *name);
	static BinaryFileHeader *getResFontData(char *name);
	static ResFontBase *getFont(int index);

	static dNewFontMng_c *instance;
};

dNewFontMng_c *dNewFontMng_c::instance = 0x0;

bool CreateNewFontMng() {
	// make a new fontmng
	if (dNewFontMng_c::instance == 0x0) {
		void *buffer = AllocFromGameHeap1(sizeof(dNewFontMng_c));
		dNewFontMng_c *obj = new(buffer) dNewFontMng_c;
		dNewFontMng_c::instance = obj;
	}

	// now load our fonts
	if (dNewFontMng_c::instance != 0x0) {
		return dNewFontMng_c::create(s_FontManagerHeap);
	}
	return false;
}

dNewFontMng_c::dNewFontMng_c() {
	for (int i = 0; i < FONT_COUNT; i++) {
		this->mFont[i] = ResFontBase();
		this->mFontData[i] = 0x0;
	}
}

int dNewFontMng_c::create(void *heap) {
	BinaryFileHeader *brfnt = 0x0;
	char resPath[48];
	char filename[100];
	dNewFontMng_c *fontMng = dNewFontMng_c::instance;

	for (int i = 0; i < FONT_COUNT; i++) {
		memset(resPath, 0x0, sizeof(resPath));
		strcat(resPath, "Font/");
		strcat(resPath, FONT_NAME_TBL[i]);

		if (fontMng->mFontData[i] == 0x0) {
			AreaLanguageFolder(resPath, filename);
			brfnt = (BinaryFileHeader*)fontMng->mFontLoader[i].load(filename, 0, heap);
			if (brfnt == 0x0) {
				return false;
			}

			fontMng->mFontData[i] = brfnt;
			ResFontSetResource(&fontMng->mFont[i], brfnt);
		}
	}
	return true;
}

u32 dNewFontMng_c::getResFontIndex(char *name) {
	u32 index = 0;
	while (FONT_NAME_TBL[index & 0xFF] == 0 || strcmp(name, FONT_NAME_TBL[index & 0xFF])) {
		index++;
		if (index == FONT_COUNT) {
			return -1;
		}
	}
	return index;
}

BinaryFileHeader *dNewFontMng_c::getResFontData(char *name) {
	u32 idx = getResFontIndex(name);
	if (idx < 0)
		idx = 0;
	return dNewFontMng_c::instance->mFontData[idx & 0xFF];
}

ResFontBase *dNewFontMng_c::getFont(int index) {
	if (index < 0)
		index = 0;
	return dNewFontMng_c::instance->mFont + index;
}

// Archive Fonts
void *InternalAccessor_GetFont(void *self, char *name) {
	int idx = dNewFontMng_c::getResFontIndex(name);
	if (idx < 0) {
		return 0x0;
	} else {
		return dNewFontMng_c::getFont(idx);
	}
}