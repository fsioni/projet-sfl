#ifndef __GAME_H__
#define __GAME_H__

#include "StateManager/StateManager.h"
#include "Map/Map.h"
#include "Entity/Player.h"
#include "Entity/Enemy.h"

#include <vector>


class Game
{
private:
    StateManager stateMan;
    Map *map;
    Player player;
    std::vector<Enemy> enemies;
    int isDebug;

public:
    Game(/* args */);
    ~Game();

    void Run(int mode); //mode = 0 for SFML, 1 for txt 
    void KeyboardPressed(const char key);
    Player GetPlayerConst() const;
    std::vector<Enemy> GetEnemiesConst() const;
    Map& GetMapConst() const;
    void MoveWithCollision(EntityWithHP &entity, float vx, float vy);
    void ChangeDebug();
    int GetDebug();
    void Test();

};



#endif // __GAME_H__