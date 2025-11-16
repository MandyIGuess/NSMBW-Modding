# Culling Hack
This allows you to easily modify the array used for culling bones on the World Map!

![Static Badge](https://img.shields.io/badge/Version-1.0.0-default)
![Static Badge](https://img.shields.io/badge/Supports-NSMBWer+-DCDC73)
![Static Badge](https://img.shields.io/badge/Modifies-World%20Maps-skyblue)

## Usage
Please note, you can only cull a total of 30 bones per map, due to the way the data is stored.<br>
Additionally, this may only work with the main map, and not submaps.


An entry in the table is formatted like this:
```
{300.0f, "snow00"},
```
* The float determines when the bone is culled. It isn't known what the value is relative to, so you may need to test different values.<br>
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

[nsmbwerGit]: https://github.com/Developers-Collective/NSMBWerPlus