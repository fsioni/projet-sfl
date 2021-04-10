#include "EnemyStates.h"
#include "../Enemy.h"
#include "StateBehavior.h"

#include <iostream>



// ======== ENEMY PATROL STATE ===========
EnemyPatrol * EnemyPatrol::singleton = nullptr;

EnemyPatrol* EnemyPatrol::GetInstance(){
    if(!singleton) singleton = new EnemyPatrol;
    return singleton;
}

void EnemyPatrol::Enter(Enemy * enemy){
    std::cout << "Enemy enter in Patrol State." << std::endl;
}

void EnemyPatrol::Execute(Enemy * enemy){
    std::cout << "Enemy executing Patrol State." << std::endl;
    
    enemy->GetStateMachine()->ChangeState(EnemyPatrol::GetInstance());
}

void EnemyPatrol::Exit(Enemy * enemy){
    std::cout << "Enemy leaving Patrol State." << std::endl;
}

// ======== ENEMY GLOBAL STATE ===========


void EnemyGlobalState::Enter(Enemy * enemy){
    std::cout << "Enemy enter in Global State." << std::endl;
}

void EnemyGlobalState::Execute(Enemy * enemy){
    std::cout << "Enemy executing Global State." << std::endl;
}

void EnemyGlobalState::Exit(Enemy * enemy){
    std::cout << "Enemy leaving Global State." << std::endl;
}

EnemyGlobalState* EnemyGlobalState::Instance(){
    static EnemyGlobalState instance;
    return &instance;
}