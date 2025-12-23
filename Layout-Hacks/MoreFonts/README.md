# MoreFonts
This allows you to load more than four global fonts, as well as load fonts from archives!

![Static Badge](https://img.shields.io/badge/Version-1.0.0-default)
![Static Badge](https://img.shields.io/badge/Supports-NewerSMBW%20(1.3.0)-maroon)
![Static Badge](https://img.shields.io/badge/Supports-NSMBWer+-DCDC73)
![Static Badge](https://img.shields.io/badge/Modifies-User%20Interfaces-blue)

If you find any bugs, issues, or have any questions, make an issue in the Issues tab.

## Usage
Using this is simple, in `moreFonts.cpp` you can find the global font list (`FONT_NAME_TBL`), as well as a define for how many fonts are listed.

You can add/remove global fonts by changing that value, however make sure you add new fonts to the list when incrementing the font count.

To use a new font, you can either edit a layout, or the BMG:
* When editing a layout, simply specify the font filename inside the BRLYT's font list, then set any Textbox to use that font index.
* When editing the BMG, set the font ID flag for that message to the font's index in the name table (first font is `0`, next is `1`, etc). For more info, see [this page][wikiBmgFlags].

### Archive Fonts
NintendoWare normally allows for fonts to be loaded from the `/arc/font` folder inside of layout archives, however NSMBW overrides this to always load a global font. This code hack reimplements this functionality, which can be useful in some cases (such as saving memory by only loading a single-use font when needed, instead of loading it for the duration of the entire game).

These are simple to setup, just create a `font` folder, and put the font you wish to load in there. Then, put it in the BRLYT's font list, and set a Textbox to use it.

**Note:** You cannot use archive fonts with BMG-printed text, as the BMG has no way of accessing archive fonts.

## Installation Instructions
Add the symbols below to your `kamek_pal.x` file. You do not need to add them to the other `.x` files.
```
AreaLanguageFolder__FPCcPCc = 0x800B4670;
ResFontSetResource__FP11ResFontBaseP16BinaryFileHeader = 0x8022C4E0;
s_FontManagerHeap = 0x8042A378;
__ct__11ResFontBaseFv = 0x8022C440;
__dt__11ResFontBaseFv = 0x8022C480;
memset__FPviUl = 0x800046B4;
strcat__FPcPCc = 0x802E1D2C;
```

Take `moreFonts.yaml` and put it into your `/Kamek` folder. Then take `moreFonts.cpp` and `moreFonts.h`, and put them into `/Kamek/src`.

Make sure to reference `moreFonts.yaml` in your project YAML so it gets compiled!

---

If you have any issues in-game, make sure you set it up correctly.

If you cannot get it to work, make an issue on the Issues page, and I'll try to respond as soon as I can.

## Changelog

### v1.0.0 (December 23rd, 2025)
- Initial release

[wikiBmgFlags]: https://horizon.miraheze.org/wiki/Game_Text_Editing#Message_Flags