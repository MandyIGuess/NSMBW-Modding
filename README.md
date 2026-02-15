# NSMBW-Modding
This repo is for me to put all the stuff I've made for NewerSMBW and NSMBWer+. It'll mainly consist of bugfixes, improvements, and some new
features. If you find any issues or bugs (with the content here, not bugs for Newer/NSMBWer+), report them in the Issues tab.

The code hacks in this repo are made either with [NewerSMBW's source code][newer] (specifically the code for v1.3.0), or [NSMBWer+][nsmbwer].
Most features are compatible with both bases, and the ones that aren't will mention it in their README.

Don't ask me to port any code hacks to older versions of NewerSMBW. If you make your own ports, feel free to release them, but link back to the
original version on this repo.

## Full List of Features

<details>
  <summary>Game Bugfixes: Small fixes and improvements. Most work for both Newer and NSMBWer+, unless specified otherwise.</summary>
  <p></p>

  - [Jellybeam Lighting Fix](/Bugfixes/Jellybeam-Lighting)
  - [(Retail) Map HUD Star Coin Fix](/Bugfixes/Map-Hud-Star-Coins)
</details>

<!--<details>
  <summary>Custom Sprites: Brand new custom sprites for use in levels!</summary>
  <p></p>

  - 
</details>-->

<details>
  <summary>Layout Hacks: Changes and new features related to user-interface layouts.</summary>
  <p></p>

  - [Single-Row Number of Players](/Layout-Hacks/Single-Row-Number-of-Players): Code hack that allows the 1 button on the Number of players screen to be on the same row as the others!
  - [Game Over Fix (for Modern MarioFont)](/Layout-Hacks/MarioFont-GameOver-Fix): Small hack that fixes the Game Over screen for mods that use the modern MarioFont!
  - [MoreFonts](/Layout-Hacks/MoreFonts): Adds support for loading more than four global fonts, and loading fonts from archives!
</details>

<details>
  <summary>Newer Specific: Features that ONLY work in NewerSMBW-based mods.</summary>
  <p></p>

  - [Improved Level Nodes](/Newer-Specific/Improved-Level-Nodes): Color animations and fixed rotation for Newer's level nodes!
  - [Retail Map HUD in Newer](/Newer-Specific/Retail-Map-Hud-In-Newer): Recreation of the retail game's World Map HUD in Koopatlas!
  <!-- - [Better Koopatlas Lighting](/Newer-Specific/Better-KP-Lighting): Support for using different lighting between Koopatlas maps/worlds! -->
</details>

<details>
  <summary>Sprite Hacks: Changes and new features related to already-existing sprites.</summary>
  <p></p>

  - [Rotation Controlled Coin Improvements](/Sprite-Hacks/Rotation-Coins): Adds various new settings to the Rotation Controlled Coin sprite!
</details>

<details>
  <summary>World Map Hacks: Changes and new features for the retail map system.</summary>
  <p></p>

  - [Start Node Directions](/World-Map-Hacks/Start-Node-Directions): Allows Start Nodes to point in any direction, not just up or right!
  - [Culling Hack](/World-Map-Hacks/Culling-Hack): Allows you to edit hardcoded map model/actor culling info!
</details>

<details>
  <summary>Miscellaneous Releases: Features that don't fit into the other categories.</summary>
  <p></p>

  - [TPC Opening Port](/Miscellaneous/TPC-Opening-Port): Opening from NSMBW The Prankster Comets, ported to Newer 1.30 and NSMBWer+!
  - [Randomized Lighting](/Miscellaneous/Randomized-Lighting): Randomly selects the World Map and level lightings rather than choosing based on world/zone settings.
</details>

## Crediting and Usage
If you want to use anything from this for your own projects, be sure to credit me for it (credit me as `MandyIGuess`).

Each released feature can be obtained either by downloading the entire repo (`Code -> Download ZIP`), or by finding the latest release of it in the Releases tab.

Installation instructions can be found in the readme file in each folder.

[newer]: https://github.com/Newer-Team/NewerSMBW
[nsmbwer]: https://github.com/Developers-Collective/NSMBWerPlus