#ifndef PLAYER_H
#define PLAYER_H

#include "EntityWithHP.h"
#include <string>

using namespace std;

class Player : public EntityWithHP
{
public :

    Player();

    Player(float x, float y, string name, unsigned int hp, unsigned int damage,float speed, unsigned int maxHealth);

    ~Player();

};
#endif
