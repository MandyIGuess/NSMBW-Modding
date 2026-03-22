# Toad Balloon Spawning Fix
Toad Balloons appear about 1 second after an ambush level begins, however the way this is implemented causes off-screen
balloons to not appear. This simple hack fixes that issue, for mods that want ambushes larger than a single screen!

## Installation Instructions
Make sure you're able to compile NewerSMBW/NSMBWer+ before adding this to your code.


Take `toadBalloonFix.yaml` and put it into your `/Kamek` folder. Then take `toadBalloonFix.cpp` and put it into your `/Kamek/src` folder.

Add the following symbols into your `kamek_pal.x` file (they do not need to be added to the other `.x` files):
```
StateID_DemoStart_SoundStartWait__14daBattleGame_c = 0x80995F50;
StateID_Move__15daEnGreenCoin_c = 0x80B156D0;
```

Make sure to reference `toadBalloonFix.yaml` in your project YAML so it gets compiled!


Recompile your code, then put the files from the Build folder into the `NewerRes`/`Code` folder in the Riivolution patch.