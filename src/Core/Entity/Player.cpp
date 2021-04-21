#include "Player.h"

#include <iostream>
#include <string>
#include <cassert>

Player::Player() : EntityWithHP(){}

Player::Player(float x, float y, string name, unsigned int hp, unsigned int damage,float speed,int maxHP)
: EntityWithHP::EntityWithHP(x, y, name, hp, damage, speed, maxHP){}

Player::~Player(){

    this->x = 0.0;
    this->y= 0.0;
    this->name = "deletedPlayer";
    this->hp = 0;
    this->damage = 0;
    this->speed = 0.0;
    this->maxHP = 0;
    this->livingStatus = false;

}

