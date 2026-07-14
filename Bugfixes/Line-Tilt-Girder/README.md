# Line Controlled Tilt Girder Fixes
The line-riding Tilt-Controlled Girder platform seen in retail 8-5 have some strange issues outside of that stage.

If dragged along the left screen edge, they will cause **massive** lag spikes when going off of its line path, which makes
them pretty much impossible to use outside of the retail use case (autoscroller stages). Additionally, this fix allows
the screen-drag behavior to be toggled via spritedata!

## Installation Instructions
First off, take the contents of the `reggie_spritedata.xml` file, and add them to your Reggie Next game patch's `spritedata.xml` (not the file in `/reggiedata/`).

Next, make sure you're able to compile NewerSMBW/NSMBWer+ before adding this to your code.

Take `remoLiftLine.yaml` and put it into your `/Kamek` folder. Then put `remoLiftLine.cpp` and `remoLiftLine.S` into your `/Kamek/src` folder.

Add the following symbols into your `kamek_pal.x` file (they do not need to be added to the other `.x` files):
```
LineMng_SetPos = 0x800C1320;
afterFixRemoLineLift1 = 0x80840410;
afterFixRemoLineLift2 = 0x8084044C;
```

Make sure to reference `remoLiftLine.yaml` in your project YAML so it gets compiled!


Recompile your code, then put the files from the Build folder into the `NewerRes`/`Code` folder in the Riivolution patch.
