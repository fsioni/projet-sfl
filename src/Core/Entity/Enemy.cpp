#include "Enemy.h"
#include "FiniteStateMachine/EnemyStates.h"

#include <iostream>
#include <string>
#include <cassert>
#include <time.h>


Enemy::Enemy() : EntityWithHP(){
    stateMachine = new StateMachine<Enemy>(this);
    stateMachine->SetCurrentState(EnemyPatrol::Instance());

    SetTimeNextChangeDirection();
    SetTimeNextAttack();
}


Enemy::Enemy(float x_, float y_, std::string name_, int hp_, int damage_,
             int speed_, int maxHP_)
: EntityWithHP::EntityWithHP(x_, y_, name_, hp_, damage_, speed_, maxHP_){
    stateMachine = new StateMachine<Enemy>(this);
    stateMachine->SetCurrentState(EnemyPatrol::Instance());

    SetTimeNextChangeDirection();
    SetTimeNextAttack();
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


void Enemy::UpdateStateMachine(std::unique_ptr<Player> & player_,
                               CollisionLayer * collision, int dt){
    stateMachine->UpdateCurrentState(player_, collision, dt);
}

StateMachine<Enemy>* Enemy::GetStateMachine() const{
    return stateMachine;
}

void Enemy::RandDirection(){
    int nb = rand() % 4;
    switch (nb)
    {
        case 0 : direction = Down; break;
        case 1 : direction = Left ; break;
        case 2 : direction = Right ; break;
        case 3 : direction = Up ; break;

        default: direction = Right; break;
    }
}

void Enemy::SetTimeNextChangeDirection(){
    int min = 3;
    int max = 7;
    double timer = time(NULL);
    timeNextChangeDirection = timer + rand()%(max-min) + min;
}

void Enemy::ChangeDirection(bool collision){
    double timer = time(NULL);
    if(collision){
        RandDirection();
        SetTimeNextChangeDirection();
    }
    else if(timer > timeNextChangeDirection){
        RandDirection();
        SetTimeNextChangeDirection();
    }
 }

void Enemy::SetTimeNextAttack(){
    // 2 attaque par seconde
    double timeBetween2Attack = 0.5;
    double timer = time(NULL);
    timeNextAttack = timer + timeBetween2Attack;
}

bool Enemy::IsTimeToAttack(){
    double timer = time(NULL);
    return timer > timeNextAttack;
}

void Enemy::Test() const{
    // TODO trouver un moyen de test StateMachine mais c'est compliqué

    std::cout << "===== Class Enemy =====" << std::endl;

    Enemy enemy1;
    std::cout << "Constructeur Enemy() : ";
    assert(enemy1.stateMachine != nullptr);
    std::cout << "ok" << std::endl;

    std::cout << "Constructeur Enemy(int x, int y, string name, "<<
                 "int hp, int damage,int speed, int int maxHealth) : ";
    Enemy enemy2(10, 10, "enemy", 10, 10, 2, 400);
    assert(enemy2.stateMachine != nullptr);
    std::cout << "ok" << std::endl;


    std::cout << "RandDirection() : ";
    enemy1.RandDirection();
    assert(enemy1.direction == Up || enemy1.direction == Down ||
           enemy1.direction == Right || enemy1.direction == Left);
    std::cout << "ok" << std::endl;

    std::cout << std::endl << std::endl;
}
