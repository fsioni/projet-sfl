#include "Enemy.h"


#include "FiniteStateMachine/EnemyStates.h"


#include <iostream>
#include <string>
#include <cassert>

Enemy::Enemy() : EntityWithHP(){
    stateMachine = new StateMachine<Enemy>(this);
    stateMachine->SetCurrentState(EnemyPatrol::Instance());

    nbUpdateMaxChangeDir = 5;
    nbUpdateChangeDir = 5;
}

Enemy::Enemy(float x, float y, string name, unsigned int hp, unsigned int damage,float speed, unsigned int maxHealth)
: EntityWithHP::EntityWithHP(x, y, name, hp, damage, speed, maxHealth){
    stateMachine = new StateMachine<Enemy>(this); 
    stateMachine->SetCurrentState(EnemyPatrol::Instance());

    nbUpdateMaxChangeDir = 500;
    nbUpdateChangeDir = rand()%nbUpdateMaxChangeDir;
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


void Enemy::UpdateStateMachine(std::unique_ptr<Player> & player_, 
                               CollisionLayer * collision){
    stateMachine->UpdateCurrentState(player_, collision);
}


StateMachine<Enemy>* Enemy::GetStateMachine() const{
    return stateMachine;
}

int Enemy::GetNbUpdateMaxChangeDir() const{
    return nbUpdateMaxChangeDir;
}

int Enemy::GetNbUpdateChangeDir() const{
    return nbUpdateChangeDir;
}


void Enemy::SetNbUpdateChangeDir(){
        int nb = rand()% nbUpdateMaxChangeDir + 1;
    while(nb <200){
            nb = rand()% nbUpdateMaxChangeDir + 1;
    }
    nbUpdateChangeDir = nb;
}

void Enemy::DecrementNbUpdateChangeDir(){
    nbUpdateChangeDir--;
}

void Enemy::RandDirection(){
        int nb = rand() % 4;
    switch (nb)
    {
        case 0 : direction = Down; break;
    case 1 : direction = Left ; break;
    case 2 : direction = Right ; break;
    case 3 : direction = Up ; break;

    default: direction = Right;
        break;
    }
}
