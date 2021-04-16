#include "EnemyStates.h"
#include "../Enemy.h"
#include "StateBehavior.h"

#include <iostream>
#include <math.h>

float distance(Enemy * enemy, std::unique_ptr<Player> & player_){
    int x = enemy->GetPos_x() - player_->GetPos_x();
    int y = enemy->GetPos_y() - player_->GetPos_y();
    return sqrt(x*x + y*y);
}

// ======== ENEMY PATROL STATE ===========
EnemyPatrol* EnemyPatrol::singleton = nullptr;

EnemyPatrol* EnemyPatrol::Instance(){
    if(singleton==nullptr){
        singleton = new EnemyPatrol;
    }
    return singleton;
}

void EnemyPatrol::Enter(Enemy * enemy){
    std::cout << "Enemy enter in Patrol State." << std::endl;
}


void EnemyPatrol::Execute(Enemy * enemy, std::unique_ptr<Player> & player_){
    if(distance(enemy, player_)<32.){
        enemy->GetStateMachine()->ChangeState(EnemyAttack::Instance());
    }
}

void EnemyPatrol::Exit(Enemy * enemy){
    std::cout << "Enemy leaving Patrol State." << std::endl;
}


// ======== ENEMY ATTACK STATE ===========
EnemyAttack* EnemyAttack::singleton = nullptr;

EnemyAttack* EnemyAttack::Instance(){
    if(singleton==nullptr){
        singleton = new EnemyAttack;
    }
    return singleton;
}

void EnemyAttack::Enter(Enemy * enemy){
    std::cout << "Enemy enter in Attack State." << std::endl;
}

void EnemyAttack::Execute(Enemy * enemy, std::unique_ptr<Player> & player_){
    enemy->Move(1/5., 0);
}

void EnemyAttack::Exit(Enemy * enemy){
    std::cout << "Enemy leaving Attack State." << std::endl;
}
