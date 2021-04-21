#include "EntityWithHP.h"
#include "EntityWithoutHP.h"
#include <iostream>
#include <string>
#include <cassert>

EntityWithHP::EntityWithHP() : EntityWithHP::EntityWithoutHP(){

    this->hp = 200;
    this->damage = 20;
    this->maxHP = 200;
    this->livingStatus = true;
    this->speed = 1.0;
}

EntityWithHP::EntityWithHP(float x, float y, string name, int hp, int damage, float speed, int maxHP)
: EntityWithoutHP::EntityWithoutHP(x, y, name){
    this->hp = hp;
    this->damage = damage;
    this->maxHP = maxHP;
    this->livingStatus = true;
    this->speed = speed;
}

EntityWithHP::~EntityWithHP(){

    this->x = 0.0;
    this->y= 0.0;
    this->name = "deleted";
    this->hp = 0;
    this->damage = 0;
    this->speed = 0.0;
    this->maxHP = 0;

}


void EntityWithHP::SetHP(int newHp){
    assert (newHp >= 0  && newHp <= maxHP);

    hp = newHp;
}

int EntityWithHP::GetHP() const{

    return hp;
}

float EntityWithHP::GetSpeed() const{

    return speed;
}

void EntityWithHP::SetSpeed(float newSpeed){

    speed = newSpeed;
}

void EntityWithHP::PrintEntityInfo() {

    cout<< "x = " << x << ", y = " << y <<endl;
    cout<<"nom : " << name <<endl;
    cout<<"points de vie : " << hp <<endl;
    cout<<"Dégâts : "<< damage <<endl;
    cout<<"Speed : "<< speed <<endl;
    cout<<"points de vie max : "<< maxHP <<endl;

    if(livingStatus) cout<<"Le personnage est en vie "<<endl;
    else cout<<"Le personnage est mort"<<endl;

    cout << endl;
}

void EntityWithHP::Move(float vx, float vy){

    x += vx*speed;
    y += vy*speed;

    if (x < 0.0){
        x = 0.0;
    }
    if (y < 0.0){
        y = 0.0;
    }
}

int EntityWithHP::GetDamage() const{

    return damage;
}

void EntityWithHP::SetDamage(int newDmg){
    assert (newDmg >= 0);
    damage = newDmg;
}

void EntityWithHP::TakeDamage(int damage){
    assert (damage >= 0);
    if(hp<=0){
        livingStatus=false;
        hp=0;
    }
    else hp -= damage;
}

void EntityWithHP::Attack(EntityWithHP &target, int damage) const{

    target.TakeDamage(damage);
}

void EntityWithHP::SetLivingStatus (bool newStatus){

    livingStatus = newStatus;
}

bool EntityWithHP::GetLivingStatus() const{

    return livingStatus;
}

int EntityWithHP::GetMaxHP() const{

    return maxHP;
}
