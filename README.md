# Projet SFL

## Required :
- For LINUX : G++, SFML 
- For MacOSX : G++ (SFML files are included in the project)

## How to use
Open a terminal.
- Compile using 'Make'.
- Execute ./bin/exec 0 for SFML or ./bin/exec 1 for txt.
- Clean all the object files and executables with 'Make clean'.
### For SFML mode :
blabla
### For txt mode :
Use ZQSD to move along all axis. Press 'X' to quit.

## Specifications 
You can find our specifications [here](https://docs.google.com/document/d/1M3ReGvUai9tsUhxqgG_X2tHgvNp70VFRoiY18aw6FXw/edit#heading=h.z6ne0og04bp5).

## UML Class Diagram
You can find our UML Class Diagram [here](https://app.diagrams.net/?state=%7B%22ids%22:%5B%221cDj2nZ69OLlIY6NArtj_65bF8BKCwmA5%22%5D,%22action%22:%22open%22,%22userId%22:%22101499938783679469280%22,%22resourceKeys%22:%7B%7D%7D).


## Creating your own maps with the Tiled software :
### Collision and spawn layers :
You should use object layers named :
- "PlayerSpawn" for the spawn of players
- "EnemySpawn" for spawns of enemies
- "Collision" for every objects that players, NPC and enemies couldn't go throught

