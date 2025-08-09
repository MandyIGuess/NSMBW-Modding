# Rotation Controlled Coin Improvements
This adds various new settings to the Rotation Controlled Coin sprite!

![Static Badge](https://img.shields.io/badge/Version-1.0.0-default)
![Static Badge](https://img.shields.io/badge/Supports-NewerSMBW%20(1.3.0)-maroon)
![Static Badge](https://img.shields.io/badge/Supports-NSMBWer+-DCDC73)
![Static Badge](https://img.shields.io/badge/Modifies-Stages-25a86d)

![Screenshot of the new rotation options added to the Rotation Coin.](/Sprite-Hacks/Rotation-Coins/image.png)

For a video of this in-game, see [this YouTube video](https://youtu.be/UnnHCc9OBcU)!

## Changes
The biggest feature is the Tilted Coins option, which allows coins to automatically angle their bottom towards the linked Rotation Controller! This allows
coin circles to look much nicer, since the coins won't all be facing the same direction.

Additionally, you can lock the coins to a specific rotation. There are 16 possible rotations, each in increments of 22.5 degrees, as well as a separate Always Upright
option, which locks the coin at a rotation of 0.0 degrees.

## Installation Instructions
First off, take the contents of the `reggie_spritedata.xml` file, and add them to your Reggie Next game patch's `spritedata.xml` (not the file in `/reggiedata/`).

Next, make sure you are able to compile [NewerSMBW][newerGit]/[NSMBWer+][nsmbwerGit] before you add this feature. Setup instructions can be found in their README files.

Add the following symbol to your `kamek_pal.x` file. You do not need to add it to the other `.x` files.
```
handleRotation__15daEnCoinAngle_cFv = 0x809E5660;
```

Take `rotationCoin.yaml` and put it into your `/Kamek` folder.<br>
Then, take `rotationCoin.cpp` and put it into your `/Kamek/src` folder.

> [!IMPORTANT]
> If installing this into NewerSMBW (and you don't have MoreSprites installed), open `rotationCoin.cpp`, and on line **28**, change `fBase_c::searchById` to `fBase_c::search`.

Make sure to reference `rotationCoin.yaml` in your project YAML so it gets compiled!

[newerGit]: https://github.com/Newer-Team/NewerSMBW
[nsmbwerGit]: https://github.com/Developers-Collective/NSMBWerPlus