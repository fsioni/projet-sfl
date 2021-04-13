#include "EnemyStates.h"
#include "../Enemy.h"
#include "StateBehavior.h"

#include <iostream>
#include <math.h>


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


void EnemyPatrol::Execute(Enemy * enemy){
    if(enemy->GetLivingStatus()){
        enemy->Move(1, 0);
        enemy->TakeDamage(1);
    }
    else{
        std::cout << "Enemy mort !" << std::endl;
        enemy->GetStateMachine()->ChangeState(EnemyGlobalState::Instance());
    } 
}

void EnemyPatrol::Exit(Enemy * enemy){
    std::cout << "Enemy leaving Patrol State." << std::endl;
}

// ======== ENEMY GLOBAL STATE ===========
EnemyGlobalState* EnemyGlobalState::singleton = nullptr;

EnemyGlobalState* EnemyGlobalState::Instance(){
    if(singleton==nullptr){
        singleton = new EnemyGlobalState;
    }
    return singleton;
}

void EnemyGlobalState::Enter(Enemy * enemy){
    std::cout << "Enemy enter in Global State." << std::endl;
}

void EnemyGlobalState::Execute(Enemy * enemy){
    
}

void EnemyGlobalState::Exit(Enemy * enemy){
    std::cout << "Enemy leaving Global State." << std::endl;
}
