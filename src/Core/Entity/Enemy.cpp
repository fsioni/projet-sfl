#include "Enemy.h"

#include <iostream>
#include <string>
#include <cassert>

Enemy::Enemy() : EntityWithHP(){}

Enemy::Enemy(float x, float y, string name, unsigned int hp, unsigned int damage,float speed, unsigned int maxHealth)
: EntityWithHP::EntityWithHP(x, y, name, hp, damage, speed, maxHealth){}

Enemy::~Enemy(){

    this->x = 0.0;
    this->y= 0.0;
    this->name = "deleted";
    this->hp = 0;
    this->damage = 0;
    this->livingStatus = false;

}
