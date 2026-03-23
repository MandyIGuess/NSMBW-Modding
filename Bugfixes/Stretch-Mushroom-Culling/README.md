# Stretch Mushroom Culling
The Stretching Mushroom Platforms (sprite 228) have issues with culling prematurely when below it, as the visibilty range
doesn't take the stem length into account. This patch addresses this issue!

## Installation Instructions
Make sure you're able to compile NewerSMBW/NSMBWer+ before adding this to your code.


Take `stretchMushFix.yaml` and put it into your `/Kamek` folder. Then take `stretchMushFix.S` and put it into your `/Kamek/src` folder.

Add the following symbols into your `kamek_pal.x` file (they do not need to be added to the other `.x` files):

Make sure to reference `stretchMushFix.yaml` in your project YAML so it gets compiled!


Recompile your code, then put the files from the Build folder into the `NewerRes`/`Code` folder in the Riivolution patch.