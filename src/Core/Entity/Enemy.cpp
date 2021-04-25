#include "Enemy.h"
#include "FiniteStateMachine/EnemyStates.h"

#include <iostream>
#include <string>
#include <cassert>


Enemy::Enemy() : EntityWithHP(){
    stateMachine = new StateMachine<Enemy>(this);
    stateMachine->SetCurrentState(EnemyPatrol::Instance());

    nbUpdateMaxChangeDir = 500;
    nbUpdateChangeDir = rand()%(nbUpdateMaxChangeDir-200) + 200;;
}

Enemy::Enemy(float x_, float y_, std::string name_, int hp_, int damage_,
             int speed_, int maxHealth_)
: EntityWithHP::EntityWithHP(x_, y_, name_, hp_, damage_, speed_, maxHealth_){
    stateMachine = new StateMachine<Enemy>(this); 
    stateMachine->SetCurrentState(EnemyPatrol::Instance());

    nbUpdateMaxChangeDir = 500;
    nbUpdateChangeDir = rand()%(nbUpdateMaxChangeDir-200) + 200;
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
                               CollisionLayer * collision, int dt){
    stateMachine->UpdateCurrentState(player_, collision, dt);
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
    nbUpdateChangeDir = rand()%(nbUpdateMaxChangeDir-200) + 200;
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

        default: direction = Right; break;
    }
}


void Enemy::Test() const{
    // TODO trouver un moyen de test StateMachine mais c'est compliqué

    std::cout << "===== Class Enemy =====" << std::endl;

    Enemy enemy1;
    std::cout << "Constructeur Enemy() : ";
    assert(enemy1.stateMachine != nullptr);
    assert(enemy1.nbUpdateMaxChangeDir == 500);
    assert(enemy1.nbUpdateChangeDir <= enemy1.nbUpdateMaxChangeDir);
    assert(enemy1.nbUpdateChangeDir >= 200);
    std::cout << "ok" << std::endl;

    std::cout << "Constructeur Enemy(int x, int y, string name, "<< 
                 "int hp, int damage,int speed, int int maxHealth) : ";
    Enemy enemy2(10, 10, "enemy", 10, 10, 2, 400);
    assert(enemy2.stateMachine != nullptr);
    assert(enemy2.nbUpdateMaxChangeDir == 500);
    assert(enemy2.nbUpdateChangeDir <= enemy2.nbUpdateMaxChangeDir);
    assert(enemy2.nbUpdateChangeDir >= 200);
    std::cout << "ok" << std::endl;


    std::cout << "SetNbUpdateChangeDir(), DecrementNbUpdateChangeDir()"<<
                 " et GetNbUpdateChangeDir() : ";
    enemy1.SetNbUpdateChangeDir();
    int nbUpdate = enemy1.GetNbUpdateChangeDir();
    assert(nbUpdate <= enemy1.nbUpdateMaxChangeDir);
    assert(nbUpdate >= 200);
    enemy1.DecrementNbUpdateChangeDir();
    assert(enemy1.GetNbUpdateChangeDir() == nbUpdate-1);
    std::cout << "ok" << std::endl;

    std::cout << "RandDirection() : ";
    enemy1.RandDirection();
    assert(enemy1.direction == Up || enemy1.direction == Down ||
           enemy1.direction == Right || enemy1.direction == Left);
    std::cout << "ok" << std::endl;

    std::cout << std::endl << std::endl;
}