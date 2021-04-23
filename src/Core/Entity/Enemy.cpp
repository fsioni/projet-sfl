#include "Enemy.h"
#include "FiniteStateMachine/EnemyStates.h"


Enemy::Enemy() : EntityWithHP(){
    stateMachine = new StateMachine<Enemy>(this);

    stateMachine->SetCurrentState(EnemyPatrol::Instance());
}

Enemy::Enemy(float x, float y, std::string name, int hp, int damage,float speed, int maxHP)
: EntityWithHP::EntityWithHP(x, y, name, hp, damage, speed, maxHP){
    stateMachine = new StateMachine<Enemy>(this);

    stateMachine->SetCurrentState(EnemyPatrol::Instance());
}

Enemy::~Enemy(){

    this->x = 0.0;
    this->y= 0.0;
    this->name = "deletedEnemy";
    this->hp = 0;
    this->damage = 0;
    this->speed = 0.0;
    this->maxHP = 0;
    this->livingStatus = false;

    if(stateMachine!=nullptr){
        //delete stateMachine;
        stateMachine = nullptr;
    }
}


void Enemy::UpdateStateMachine(std::unique_ptr<Player> & player_){
    stateMachine->UpdateCurrentState(player_);
}
