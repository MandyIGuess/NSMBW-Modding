# World Map Culling Hack
This allows you to easily modify the map model and actor culling on the World Map!

![Static Badge](https://img.shields.io/badge/Version-1.3.1-default)
![Static Badge](https://img.shields.io/badge/Supports-NSMBWer+-DCDC73)
![Static Badge](https://img.shields.io/badge/Modifies-World%20Maps-skyblue)

## Usage
Please note, for the map itself you can only cull a total of 30 bones, due to the way the data is stored.<br>
Additionally, this will only work with the main map, and not submaps.

### Culling Maps
An entry in the table is formatted like this:
```
{300.0f, "snow00"},
```
* The float specifies a radius around the bone. The game uses this to make a "sphere" centered on the bone, which is then used to determine if its currently on-screen.<br>
* The string is the name of the bone that will be culled.

#### Removing Bones
To remove a bone, simply replace an entry with the `WM_EMPTY_CULL` define, this will add a dummy entry to the list.

#### Adding Bones
To *add* a bone, replace a `WM_EMPTY_CULL` with an entry like the one above. Make sure the bone name is correct, or else it won't work in-game!

### Culling Actors
Actor culling is simple, there's a table in `wmActorCull.cpp` with all the retail culling values for each actor. Simply replace this float with
another value, and it will be culled. A value of `0.0f` appears to make the actor never cull.

### Culling World 7's Clouds
The world 7 clouds are a separate model from the main map, and are handled by a WM_CLOUD actor with its own culling system, similar to the map model's
culling system. The bone names and sphere radius values can be found in `wmActorCull.cpp`.

### Culling World 5's Vines
The world 5 vines, similar to the clouds from W7, are separate from the map model, and thus use their own culling system.

Like before, the bone names can be found at the bottom of `wmActorCull.cpp`, as well as the *single* radius value. All of the vines are the same
size, so they all use the same radius value.

## Installation Instructions
Make sure you are able to compile [NSMBWer+][nsmbwerGit] before you add this feature. Setup instructions can be found in the README file.

Add the following symbol below to your `kamek_pal.x` file. You do not need to add it to the other `.x` files.
```
returnFromWmActorCull = 0x800F2A4C;
```

Take `wmCullHack.yaml` and put it into your `/Kamek` folder.<br>
Then, take `wmCullHack.cpp` as well as `wmCullHack.S`, and put them into your `/Kamek/src` folder.
Also do the same for `wmActorCull.cpp` and `wmActorCull.S`.

Make sure to reference `wmCullHack.yaml` in your project YAML so it gets compiled!

## Changelog

### v1.3.1 (May 9th, 2026)
- Fixed WM_BOSS_KAMEK actor being culled during the 8-Castle cutscene (radius was wrong)

### v1.3.0 (April 2nd, 2026)
- Added support for culling the World 5 vines (WM_IBARA), as it uses its own culling sytem
  - Additionally, this fixes a bug with the original culling, which caused the last bone in the list to not be culled in-game
- Cleaned up the code hacks a bit, removing some symbols that weren't necessary

### v1.2.0 (February 20th, 2026)
- Added proper support for culling the World 7 clouds (WM_CLOUD), as it uses its own culling system

### v1.1.0 (February 15th, 2026)
- Added support for culling all* World Map actors!
  - This works by using a custom table with copies of the culling values, and overwriting the actual originals with the new ones

\* *Not counting unused map actors, or the few that cannot make any use of the culling system.*

### v1.0.1 (November 16th, 2025)
- This release fixes a few inconvenient bugs with the retail game's culling:
  - If a non-existent bone is referenced in a table, the game would set the bone index wrong, causing the root bone for the map to be culled instead. (This is the cause for the entire map disappearing once you past a certain point)
  - This was only triggered by fixing the above bug, but the code for culling a map bone would cancel out of the entire process if a bone's index was -1. This has been changed so having a bone with an index of -1 will allow any bones after it to still be culled.

### v1.0.0 (November 15th, 2025)
- Initial release

[nsmbwerGit]: https://github.com/Developers-Collective/NSMBWerPlus
