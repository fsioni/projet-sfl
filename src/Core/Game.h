#ifndef __GAME_H__
#define __GAME_H__

#include "StateManager/StateManager.h"

#include "Map/Map.h"
#include "Entity/Player.h"
#include "Entity/Enemy.h"

#include "../SFML/AssetManager.h"
#include <string>

#include<SFML/Graphics.hpp>
#include "../txt/winTxt.h"

#include <vector>

struct Context
{
    std::unique_ptr<AssetManager> assetMan;
    std::unique_ptr<StateManager> stateMan;
    std::unique_ptr<sf::RenderWindow> renderWin;
    std::unique_ptr<Map> map;
    std::unique_ptr<Player> player;
    std::vector<Enemy *> enemies;
    bool isDebug;
    bool quit;

    Context(){
        assetMan = std::make_unique<AssetManager>();
        stateMan = std::make_unique<StateManager>();
        renderWin = std::make_unique<sf::RenderWindow>();
        //std::string tmxFile = "data/maps/tilemaps/mainTilemap.tmx";
        //std::string tsxFile = "data/maps/tilesets/mainTileSet.tsx";
        map = std::make_unique<Map>("data/maps/tilemaps/mainTilemap.tmx", "data/maps/tilesets/mainTileSet.tsx");
        player = std::make_unique<Player>(map->GetSpawnsLayer().getPlayerSpawn().GetX(), 
        map->GetSpawnsLayer().getPlayerSpawn().GetY(), "Player", 10, 10, 4, 10);
        isDebug = false;
        quit = false;

    }
};

class Game
{
public:
    Game(/* args */);
    ~Game();

    void Run(int mode); //mode = 0 for SFML, 1 for txt 
    void Test();
private:
    std::shared_ptr<Context> context;
};



#endif // __GAME_H__