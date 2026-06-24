# SpriteTex: [462] Spiked Tower Block

![Static Badge](https://img.shields.io/badge/Supports-NewerSMBW%20(1.3.0)-maroon)
![Static Badge](https://img.shields.io/badge/Supports-NSMBWer+-DCDC73)
![Static Badge](https://img.shields.io/badge/SpriteTex-eb8034)
![Static Badge](https://img.shields.io/badge/Uses-Nybble%205-275ac2)

![SpriteTex Styles:](/SpriteTex/Spiked-Tower-Block/image.png)

Included Styles:
| Value | Appearance |
| --- | --- |
| `1` | Desert Tower |
| `2` | Icy Tower |
| `3` | Sky Tower (W4/W7 Outside)|
| `4` | Lava Tower |

## Installation Instructions
First off, put `lift_zen_toge.arc` into your `Object` or `SpriteTex` folder (name will vary between Newer or NSMBWer+ based mods).

Next up, make sure you are able to compile [NewerSMBW][newerGit]/[NSMBWer+][nsmbwerGit] before you add this feature. Setup instructions can be found in their README files.

Add the following hook to `spritetex.yaml`:
```yaml
  - name: TEX_TowerSpikeWall
    type: branch_insn
    branch_type: bl
    src_addr_pal: 0x80a5e4b8
    target_func: 'TEX_TowerSpikeWall'
```
Then, add the following code to `spritetex.S`:
```
.global TEX_TowerSpikeWall
TEX_TowerSpikeWall:
	lwz r5, 4(r27)
	srwi r5, r5, 28
	andi. r5, r5, 0xF
	b GetTexFilenameForR5
```

After that, you can recompile your code and test it out in-game!

[newerGit]: https://github.com/Newer-Team/NewerSMBW
[nsmbwerGit]: https://github.com/Developers-Collective/NSMBWerPlus