# Culling Hack
This allows you to easily modify the array used for culling bones on the World Map!

![Static Badge](https://img.shields.io/badge/Version-1.0.1-default)
![Static Badge](https://img.shields.io/badge/Supports-NSMBWer+-DCDC73)
![Static Badge](https://img.shields.io/badge/Modifies-World%20Maps-skyblue)

## Usage
Please note, you can only cull a total of 30 bones per map, due to the way the data is stored.<br>
Additionally, this may only work with the main map, and not submaps.


An entry in the table is formatted like this:
```
{300.0f, "snow00"},
```
* The float specifies a radius around the bone. The game uses this as a radius for a sphere (centered on the bone), which is then used to determine if its currently on-screen.<br>
* The string is the name of the bone that will be culled.

### Removing Bones
To remove a bone, simply replace an entry with the `WM_EMPTY_CULL` define, this will add a dummy entry to the list.

### Adding Bones
To *add* a bone, replace a `WM_EMPTY_CULL` with an entry like the one above. Make sure the bone name is correct, or else it won't work in-game!

## Installation Instructions
Make sure you are able to compile [NSMBWer+][nsmbwerGit] before you add this feature. Setup instructions can be found in the README file.

Add the following symbols below to your `kamek_pal.x` file. You do not need to add them to the other `.x` files.
```
returnToCullCode = 0x808E3188;
returnToCullCode2 = 0x808E3260;
```

Take `wmCullHack.yaml` and put it into your `/Kamek` folder.<br>
Then, take `wmCullHack.cpp` as well as `wmCullHack.S`, and put them into your `/Kamek/src` folder.

Make sure to reference `wmCullHack.yaml` in your project YAML so it gets compiled!

## Changelog

### v1.0.1 (November 16th, 2025)
- This release fixes a few inconvenient bugs with the retail game's culling:
  - If a non-existent bone is referenced in a table, the game would set the bone index wrong, causing the root bone for the map to be culled instead. (This is the cause for the entire map disappearing once you past a certain point)
  - This was only triggered by fixing the above bug, but the code for culling a map bone would cancel out of the entire process if a bone's index was -1. This has been changed so having a bone with an index of -1 will allow any bones after it to still be culled.

### v1.0.0 (November 15th, 2025)
- Initial release

[nsmbwerGit]: https://github.com/Developers-Collective/NSMBWerPlus
