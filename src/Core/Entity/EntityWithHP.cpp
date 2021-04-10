#include "EntityWithHP.h"
#include "EntityWithoutHP.h"
#include <iostream>
#include <string>
#include <cassert>

EntityWithHP::EntityWithHP() : EntityWithHP::EntityWithoutHP(){

    this->hp = 200;
    this->damage = 20;
    this->maxHealth = 200;
    this->livingStatus = true;
    this->speed = 1.0;
}

EntityWithHP::EntityWithHP(float x, float y, string name, unsigned int hp, unsigned int damage,float speed, unsigned int maxHealth)
: EntityWithoutHP::EntityWithoutHP(x, y, name){

    this->hp = hp;
    this->damage = damage;
    this->maxHealth = maxHealth;
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
    this->maxHealth = 0;

}


void EntityWithHP::SetHP(unsigned int newHp){
    assert (newHp >= 0  && newHp <= maxHealth);

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
    cout<<"points de vie max : "<< maxHealth <<endl;

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

void EntityWithHP::SetDamage(unsigned int newDmg){
    assert (newDmg >= 0);
    damage = newDmg;
}

void EntityWithHP::TakeDamage(unsigned int damage){
    assert (damage >= 0);
    hp -= damage;
}

void EntityWithHP::Attack(EntityWithHP &target, unsigned int damage) const{

    target.TakeDamage(damage);
}

void EntityWithHP::SetLivingStatus (bool newStatus){

    livingStatus = newStatus;
}

bool EntityWithHP::GetLivingStatus() const{

    return livingStatus;
}

int EntityWithHP::GetMaxHealth() const{

    return maxHealth;
}
