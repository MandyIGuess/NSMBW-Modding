# Death Music Effects
This makes normal deaths execute the music slowdown + pitch lowering behavior that's seen when all players fail
from bubbling in multiplayer! To restore the original multi fail sound, remove the `PatchDeathSound` hook.
![Static Badge](https://img.shields.io/badge/Version-1.0.0-default)
![Static Badge](https://img.shields.io/badge/Supports-NewerSMBW%20(1.3.0)-maroon)
![Static Badge](https://img.shields.io/badge/Supports-NSMBWer+-DCDC73)
![Static Badge](https://img.shields.io/badge/Modifies-Stages-25a86d)

If you find any bugs, issues, or have any questions, make an issue in the Issues tab.

## Installation Instructions
Make sure you're able to compile NewerSMBW/NSMBWer+ before adding this to your code.

Add the symbols below to your `kamek_pal.x` file. You do not need to add them to the other `.x` files.
```
startFanfare__11SndAudioMgrFUl = 0x801955E0;
moveMissFin__11SndSceneMgrFv = 0x8019C4B0;
sInstance__11SndSceneMgr = 0x8042A788;
```

Take `deathMusicEff.yaml` and put it into your `/Kamek` folder. Then take `deathMusicEff.cpp` and put it into your `/Kamek/src` folder.

Make sure to reference `deathMusicEff.yaml` in your project YAML so it gets compiled!

---

Now, test it in-game. If you have any issues, make sure you set it up correctly.

If you cannot get it to work, make an issue on the Issues page, and I'll try to respond as soon as I can.

[benzin]: https://horizon.miraheze.org/wiki/Benzin
[newerGit]: https://github.com/Newer-Team/NewerSMBW
[newerSetup]: https://github.com/Newer-Team/NewerSMBW?tab=readme-ov-file#installation