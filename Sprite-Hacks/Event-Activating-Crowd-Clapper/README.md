# Event Activating Crowd Clapper
This allows the Crowd Clapper sprites (459 and 461) to activate an event when the required number of coins are collected!

![Static Badge](https://img.shields.io/badge/Version-1.0.0-default)
![Static Badge](https://img.shields.io/badge/Supports-NewerSMBW%20(1.3.0)-maroon)
![Static Badge](https://img.shields.io/badge/Supports-NSMBWer+-DCDC73)
![Static Badge](https://img.shields.io/badge/Modifies-Stages-25a86d)

For a video of this in-game, see [this YouTube video](https://youtu.be/148-Bsny3KI)!

## Installation Instructions
First off, take the contents of the `reggie_spritedata.xml` file, and add them to your Reggie Next game patch's `spritedata.xml` (not the file in `/reggiedata/`).

Next, make sure you are able to compile [NewerSMBW][newerGit]/[NSMBWer+][nsmbwerGit] before you add this feature. Setup instructions can be found in their README files.

Take `niceCoin.yaml` and put it into your `/Kamek` folder, Then put `niceCoin.cpp` into your `/Kamek/src` folder.

Make sure to reference `niceCoin.yaml` in your project YAML, and then you can recompile your code.

[newerGit]: https://github.com/Newer-Team/NewerSMBW
[nsmbwerGit]: https://github.com/Ryguy0777/NSMBWerPlus
