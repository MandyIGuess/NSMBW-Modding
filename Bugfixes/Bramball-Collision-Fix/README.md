# Bramball Collision Fix
The Bramball's step-up collision check is messed up, which causes certain tiles to be considered valid, when they really aren't.
The most notable example is invisible blocks, which can be stepped up onto even while not hit.

For an example of this in-game, paste this ReggieClip into your level:
```
ReggieClip|0:0:17:1:45:23:2:1|0:0:26:1:37:22:2:1|0:0:26:1:41:22:2:1|0:0:17:1:33:21:2:1|1:230:632:336:0:0:0:0:0:0:0|%
```

## Installation Instructions
Make sure you're able to compile NewerSMBW/NSMBWer+ before adding this to your code.


Take `bramballFix.yaml` and put it into your `/Kamek` folder. Then take `bramballFix.cpp` and put it into your `/Kamek/src` folder.

Make sure to reference `bramballFix.yaml` in your project YAML so it gets compiled!


Recompile your code, then put the files from the Build folder into the `NewerRes`/`Code` folder in the Riivolution patch.