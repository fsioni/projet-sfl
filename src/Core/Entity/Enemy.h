#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "EntityWithHP.h"
#include <string>

using namespace std;

class Enemy : public EntityWithHP
{
public :

    Enemy();

    Enemy(float x, float y, string name, unsigned int hp, unsigned int damage,float speed, unsigned int maxHealth);

    ~Enemy();

};

#endif // __ENEMY_H__