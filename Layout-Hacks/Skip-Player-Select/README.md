# Skip Player Selection
This allows you to go from the File Selection screen, directly into the World Map! This is most useful for mods that
intend for only singleplayer, making the Player Selection screen rather useless.
![Static Badge](https://img.shields.io/badge/Version-1.0.0-default)
![Static Badge](https://img.shields.io/badge/Supports-NewerSMBW%20(1.3.0)-maroon)
![Static Badge](https://img.shields.io/badge/Supports-NSMBWer+-DCDC73)
![Static Badge](https://img.shields.io/badge/Modifies-User%20Interfaces-blue)

If you find any bugs, issues, or have any questions, make an issue in the Issues tab.

## Installation Instructions
Make sure you're able to compile NewerSMBW/NSMBWer+ before adding this to your code.

Add the symbol below to your `kamek_pal.x` file. You do not need to add it to the other `.x` files.
```
StateID_LowBatteryCheck__14dScGameSetup_c = 0x809A16A0;
```

Take `skipPlayerSelect.yaml` and put it into your `/Kamek` folder. Then take `skipPlayerSelect.cpp` and put it into your `/Kamek/src` folder.

Make sure to reference `skipPlayerSelect.yaml` in your project YAML so it gets compiled!

---

Now, test it in-game. If you have any issues, make sure you set it up correctly.

If you cannot get it to work, make an issue on the Issues page, and I'll try to respond as soon as I can.
