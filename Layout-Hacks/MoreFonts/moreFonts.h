#include <game.h>

class Font {
public:
	u8 mReaderFunc[0xC]; // actually a PTMF

	virtual ~Font();
};

class ResFontBase : public Font {
public:
	void *mResource;
	void *mFontInfo; // ptr to FontInformation
	u16 mLastCharCode;
	u16 mLastGlyphIndex;

	ResFontBase();  // 0x8022C440
	~ResFontBase(); // 0x8022C480
};

struct BinaryFileHeader {
	u32 signature;
	u16 byteOrder;
	u16 version;
	u32 fileSize;
	u16 headerSize;
	u16 dataBlocks;
};