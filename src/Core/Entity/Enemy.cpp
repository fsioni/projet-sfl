#include "Enemy.h"


#include "FiniteStateMachine/EnemyStates.h"


#include <iostream>
#include <string>
#include <cassert>

Enemy::Enemy() : EntityWithHP(){
    stateMachine = new StateMachine<Enemy>(this);
    
    stateMachine->SetCurrentState(EnemyPatrol::GetInstance());
    stateMachine->SetGlobalState(EnemyGlobalState::Instance());
}

Enemy::Enemy(float x, float y, string name, unsigned int hp, unsigned int damage,float speed, unsigned int maxHealth)
: EntityWithHP::EntityWithHP(x, y, name, hp, damage, speed, maxHealth){
    stateMachine = new StateMachine<Enemy>(this);
    //std::cout << this << std::endl;
    stateMachine->SetCurrentState(EnemyPatrol::GetInstance());
    stateMachine->SetGlobalState(EnemyGlobalState::Instance());
}

Enemy::~Enemy(){

    this->x = 0.0;
    this->y= 0.0;
    this->name = "deletedEnemy";
    this->hp = 0;
    this->damage = 0;
    this->speed = 0.0;
    this->maxHealth = 0;
    this->livingStatus = false;

    if(stateMachine!=nullptr){
        //delete stateMachine;
        stateMachine = nullptr;
    }
}


void Enemy::Update(){
    stateMachine->Update();
}
