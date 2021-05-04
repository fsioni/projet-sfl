#ifndef __GAME_H__
#define __GAME_H__

#include "StateManager/StateManager.h"

#include "Map/Map.h"
#include "Entity/Player.h"
#include "Entity/Enemy.h"
#include "Entity/NPC.h"

#include "../SFML/AssetManager.h"
#include <string>

#include <SFML/Graphics.hpp>
#include "../txt/winTxt.h"

#include <vector>


struct Context
{
    std::unique_ptr<AssetManager> assetMan;
    std::unique_ptr<StateManager> stateMan;
    std::unique_ptr<sf::RenderWindow> renderWin;
    std::unique_ptr<Map> map;
    std::unique_ptr<Player> player;
    std::vector<std::shared_ptr<Enemy>> enemies;
    std::vector<NPC *> npc;
    bool isDebug;
    bool quit;

    Context()
    {
        assetMan = std::make_unique<AssetManager>();
        stateMan = std::make_unique<StateManager>();
        renderWin = std::make_unique<sf::RenderWindow>();
        map = std::make_unique<Map>("data/maps/tilemaps/mainTilemap.tmx", "data/maps/tilesets/mainTileSet.tsx");

        // Initialisation du joueur
        float x = map->GetSpawnsLayer()->GetPlayerSpawn().GetX();
        float y = map->GetSpawnsLayer()->GetPlayerSpawn().GetY();

        player = std::make_unique<Player>(x, y, "Player", 10, 10, 4, 10);

        map->GetCollisionLayer()->AddCollisionBoxEntity(
            player->GetID(), new CollisionBox(x, y, 32, 32));

        // Initialisation des enemies
        int count = map->GetSpawnsLayer()->GetEnemySpawns().size();
        for (int i = 0; i < count; i++){
            x = map->GetSpawnsLayer()->GetEnemySpawns()[i].GetX();
            y = map->GetSpawnsLayer()->GetEnemySpawns()[i].GetY();

            std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>(x, y, "Enemy", 100, 1, 1, 100);
            enemies.push_back(enemy);
            
            map->GetCollisionLayer()->AddCollisionBoxEntity(
                enemy->GetID(), new CollisionBox(x, y, 32, 32));
        }

        // Initialisation des NPC
        
        count = map->GetSpawnsLayer()->GetNPCSpawns().size();
        for (int i = 0; i < count; i++){
            x = map->GetSpawnsLayer()->GetNPCSpawns()[i].GetX();
            y = map->GetSpawnsLayer()->GetNPCSpawns()[i].GetY();
            
            NPC * newNPC = new NPC(x, y, "NPC");
            npc.push_back(newNPC);
            
            map->GetCollisionLayer()->AddCollisionBoxEntity(
                newNPC->GetID(), new CollisionBox(x, y, 32, 32));
        }

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