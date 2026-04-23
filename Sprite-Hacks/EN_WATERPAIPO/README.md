# EN_WATERPAIPO Restoration
This allows you to spawn the unused `EN_WATERPAIPO` actor (which does not normally have an assigned Sprite ID)!

![Static Badge](https://img.shields.io/badge/Supports-NSMBWer+-DCDC73)
![Static Badge](https://img.shields.io/badge/Modifies-Stages-25a86d)

For a video of this in-game, see [this YouTube video](https://youtu.be/GwQQkOI_1CA)!

## Installation Instructions
First off, make sure you are able to compile [NSMBWer+][nsmbwerGit] before you add this feature. Setup instructions can be found in its README.

> [!IMPORTANT]
> This can be ported to NewerSMBW, however you will need to install [MoreSprites][moreSprites], and put the code block below into its own C++ file (and reference it in a YAML), as Newer does not have that file.

Add the following lines of code into `/Kamek/src/unusedActorSprites.cpp`:
```cpp
const char* WaterPaipoFileList[] = {"paipo", NULL};
extern "C" dActor_c *EN_WATERPAIPO_classInit(); // 0x80AC4E70
const SpriteData WaterPaipoSpriteData = { ProfileId::EN_WATERPAIPO, 8, 0, 0 , 0, 0x10, 0x10, 0, 0, 0, 0, 0};
Profile WaterPaipoProfile(&EN_WATERPAIPO_classInit, SpriteId::EN_WATERPAIPO, &WaterPaipoSpriteData, ProfileId::EN_WATERPAIPO, ProfileId::KAZAN_ROCK, "EN_WATERPAIPO", WaterPaipoFileList, 0x12);
```

Next up, add the following sprite ID to the `SpriteId` enum in `/Kamek/include/profileid.h`:
```cpp
	EN_WATERPAIPO = XXX,
```
Replace `XXX` with the next available sprite ID. Make sure this comes *before* the `Num` value.

After that, add the following symbol to your `kamek_pal.x` file. You do not need to add it to the other `.x` files.
```
EN_WATERPAIPO_classInit = 0x80AC4E70;
```

With that done, compile the code and test it out in-game!

### Adding to Reggie Next
To add this into Reggie Next, add the following to your `spritedata.xml`:
```xml
  <sprite id="XXX" name="Floating Spiny" notes="A balled-up Spiny that will float on the surface of the water. Add [243] Water Current Controller to make them float to the left.">
    <dependency>
      <suggested sprite="243"/>
    </dependency>
  </sprite> <!-- #XXX: Floating Spiny -->
```
Replace `XXX` with the sprite ID you used earlier.

[moreSprites]: https://github.com/Developers-Collective/NSMBW-Custom-Sprites/tree/main/Utility/MoreSprites
[nsmbwerGit]: https://github.com/Developers-Collective/NSMBWerPlus