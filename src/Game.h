#ifndef __GAME_H__
#define __GAME_H__

#include "StateManager/StateManager.h"
#include "Map/Map.h"
#include "EntityWithHP.h"


class Game
{
private:
    StateManager stateMan;
    Map map;
    EntityWithHP player;

public:
    Game(/* args */);
    ~Game();

    void Run(int mode); //mode = 0 for SFML, 1 for txt 
    void KeyboardPressed(const char key);
    EntityWithHP GetPlayerConst() const;
    void SetMap(Map nMap);
    void Test();

};



#endif // __GAME_H__