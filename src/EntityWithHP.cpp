#include "EntityWithHP.h"
#include "EntityWithoutHP.h"
#include <iostream>
#include <string>

EntityWithHP::EntityWithHP() : EntityWithHP::EntityWithoutHP(){

    this->hp = 200;
    this->damage = 20;
}

EntityWithHP::EntityWithHP(unsigned int x, unsigned int y, string name, unsigned int hp, unsigned int damage) : EntityWithoutHP::EntityWithoutHP(x, y, name){

    this->hp = hp;
    this->damage = damage;
}

EntityWithHP::~EntityWithHP(){

    this->x = 0;
    this->y= 0;
    this->name = "le boug est supp";
    this->hp = 0;
    this->damage = 0;

}


void EntityWithHP::SetHP(unsigned int newHp){

    hp = newHp;
}

int EntityWithHP::GetHP(){

    return hp;
}

void EntityWithHP::PrintEntityInfo() {

    cout<< "x = " << x << ", y = " << y << ", nom : " << name << ", points de vie : " << hp << ", Damage : "<< damage <<endl;
}

void EntityWithHP::EntityMove(unsigned int vx, unsigned int vy){

    x += vx;
    y += vy;
}

int EntityWithHP::GetDamage(){

        return damage;
}

void EntityWithHP::SetDamage(unsigned int newDmg){

    damage = newDmg;
}

/*void EntityWithHP::Attack(unsigned int ){


}

void EntityWithHP::TakeDamage(unsigned int dmg){


}*/
