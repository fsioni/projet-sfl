#ifndef ENEMY_H
#define ENEMY_H

#include "EntityWithHP.h"
#include <string>

using namespace std;

class Enemy : public EntityWithHP
{
public :

    Enemy();

    Enemy(float x, float y, string name, unsigned int hp, unsigned int damage,float speed, unsigned int maxHealth);

    ~Enemy();

}
#endif
