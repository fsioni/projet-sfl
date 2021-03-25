# Projet SFL

## Required :
- For LINUX : G++, SFML 
- For MacOSX : G++

## How to use
Open a terminal.
- Compile using Make.
- Execute ./bin/exec 0 for SFML or ./bin/exec 1 for txt.

## Specification 
You can find our specification [Lien](https://docs.google.com/document/d/1M3ReGvUai9tsUhxqgG_X2tHgvNp70VFRoiY18aw6FXw/edit#heading=h.z6ne0og04bp5 "here").

## UML Class Diagram
You can fin our UML Class Diagram [Lien](https://app.diagrams.net/?state=%7B%22ids%22:%5B%221cDj2nZ69OLlIY6NArtj_65bF8BKCwmA5%22%5D,%22action%22:%22open%22,%22userId%22:%22101499938783679469280%22,%22resourceKeys%22:%7B%7D%7D "here").


## Creating your own maps with Tiled :
### Collision and spawn layers :
You should use object layers named :
- "PlayerSpawn" for the spawn of players
- "EnemySpawn" for spawns of enemies
- "Collision" for every objects players, NPC and enemies couldn't go throught

