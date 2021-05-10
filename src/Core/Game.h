#ifndef __GAME_H__
#define __GAME_H__

#include "StateManager/StateManager.h"

#include "Map/Map.h"
#include "Entity/Player.h"
#include "Entity/Enemy.h"
#include "Entity/NPC.h"
#include "Entity/Animal.h"

#include "../SFML/AssetManager.h"
#include <string>

#include <SFML/Graphics.hpp>
#include "../txt/winTxt.h"

#include <vector>

/*! \class Context
*   \brief Classe représentant l'état du programme.
* 
*/
struct Context
{
    std::unique_ptr<AssetManager> assetMan;
    std::unique_ptr<StateManager> stateMan;
    std::unique_ptr<sf::RenderWindow> renderWin;
    std::unique_ptr<Map> map;
    std::unique_ptr<Player> player;
    std::vector<std::shared_ptr<Enemy>> enemies;
    std::vector<NPC *> npc;
    std::vector<Animal *> animals;
    bool isDebug;
    bool isMute;
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
            player->GetID(), new Box(x, y, 32, 32));

        // Initialisation des enemies
        int count = map->GetSpawnsLayer()->GetEnemySpawns().size();
        for (int i = 0; i < count; i++){
            x = map->GetSpawnsLayer()->GetEnemySpawns()[i].GetX();
            y = map->GetSpawnsLayer()->GetEnemySpawns()[i].GetY();

            std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>(x, y, "Enemy", 100, 1, 1, 100);
            enemies.push_back(enemy);
            
            map->GetCollisionLayer()->AddCollisionBoxEntity(
                enemy->GetID(), new Box(x, y, 32, 32));
        }

        // Initialisation des NPC
        std::string dialog;
        EntityDirection direction;
        count = map->GetSpawnsLayer()->GetNPCSpawns().size();
        for (int i = 0; i < count; i++){
            x = map->GetSpawnsLayer()->GetNPCSpawns()[i].GetX();
            y = map->GetSpawnsLayer()->GetNPCSpawns()[i].GetY();
            dialog = map->GetSpawnsLayer()->GetADialog(i);
            direction = map->GetSpawnsLayer()->GetADirection(i);
            // Ajout du npc au vector
            NPC * newNPC = new NPC(x, y, dialog);
            newNPC->SetDirection(direction);

            npc.push_back(newNPC);
            
            // Ajout de sa CollisionBox au CollisionLayer
            // y + 5 pour descendre la collisionBox au niveau des pieds
            map->GetCollisionLayer()->AddCollisionBoxEntity(
                newNPC->GetID(), new Box(x, y+5, 32, 32));

        }

        
        // Initialisation des animaux
        count = map->GetSpawnsLayer()->GetAnimalSpawns().size();
        for (int i = 0; i < count; i++){
            x = map->GetSpawnsLayer()->GetAnimalSpawns()[i].GetX();
            y = map->GetSpawnsLayer()->GetAnimalSpawns()[i].GetY();

            Animal * animal = new Animal(x, y, 1, "animal");
            animals.push_back(animal);
            
            map->GetCollisionLayer()->AddCollisionBoxEntity(
                animal->GetID(), new Box(x, y, 32, 32));
        }

        isDebug = false;
        isMute = false;
        quit = false;
    }
};

/*! \class Game
*   \brief Classe représentant le programme dans sa généralité. 
* 
*/
class Game
{
public:
    /*! \brief Constructeur par défaut. */
    Game(/* args */);

    /*! \brief Destructeur. */
    ~Game();

    /*! \brief Lance le jeu dans le mode selectionné
    *
    *   \param [in] mode : Selectionne le mode à lancer
    */
    void Run(int mode); //mode = 0 for SFML, 1 for txt, 2 for tests

    /*! \brief Fonction de test de la classe Tileset.
    *
    *   Effectue une série de test de regression sur l'ensemble des
    *   fonction membre pour vérifié qu'elles font ce qu'elles sont
    *   censé faire.
    */
    void Test();

private:
    /*! \brief Etat courant du programme */
    std::shared_ptr<Context> context;
};

#endif // __GAME_H__