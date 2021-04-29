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


void EnemyPatrol::Execute(Enemy * enemy, std::unique_ptr<Player> & player_,
                          CollisionLayer * collision, int dt){
    bool colliding = false;
    
    if(enemy->GetDirection()==Right)
        colliding = enemy->MoveWithCollision(1, 0, collision, dt);
    if(enemy->GetDirection()==Left)
        colliding = enemy->MoveWithCollision(-1, 0, collision, dt);
    if(enemy->GetDirection()==Down)
        colliding = enemy->MoveWithCollision(0, 1, collision, dt);
    if(enemy->GetDirection()==Up)
        colliding = enemy->MoveWithCollision(0, -1, collision, dt);
    
    enemy->ChangeDirection(colliding);
    
    // Si player dans rayon 4 bloc, il entre en état Attack
    if(player_->Distance(enemy)<4 * 32){
        enemy->GetStateMachine()->ChangeState(EnemyAttack::Instance());
    }

    // Si vie de l'enemy est inférieur à 10%, il entre en état RunAway
    if(enemy->GetHP() < enemy->GetMaxHealth()*0.1){
        enemy->GetStateMachine()->ChangeState(EnemyRunAway::Instance());
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

void EnemyAttack::Execute(Enemy * enemy, std::unique_ptr<Player> & player_, 
                          CollisionLayer * collision, int dt){
    float x = player_->GetPos_x() - enemy->GetPos_x();
    float y = player_->GetPos_y() - enemy->GetPos_y();
    float dist = sqrt(x*x + y*y);
    x = x/abs(dist);
    y = y/abs(dist);
    enemy->SetDirection(x, y);
    enemy->MoveWithCollision(x, y, collision, dt);
    dist = player_->Distance(enemy);
    if(dist > 5*32){
        enemy->GetStateMachine()->ChangeState(EnemyPatrol::Instance());
    }
    
    if(enemy->IsTimeToAttack()){
        if(dist < 1.3*32){
            player_->TakeDamage(1);
            enemy->SetTimeNextAttack();
        }
    }
    
}

void EnemyAttack::Exit(Enemy * enemy){
    std::cout << "Enemy leaving Attack State." << std::endl;
}



// ======== ENEMY RUNAWAY STATE ===========
EnemyRunAway* EnemyRunAway::singleton = nullptr;

EnemyRunAway* EnemyRunAway::Instance(){
    if(singleton==nullptr){
        singleton = new EnemyRunAway;
    }
    return singleton;
}

void EnemyRunAway::Enter(Enemy * enemy){
    std::cout << "Enemy enter in RunAway State." << std::endl;

    // On double la vitesse de l'enemy
    int speed = enemy->GetSpeed();
    enemy->SetSpeed(speed *2);
}

void EnemyRunAway::Execute(Enemy * enemy, std::unique_ptr<Player> & player_, 
                          CollisionLayer * collision, int dt){
    float x = player_->GetPos_x() - enemy->GetPos_x();
    float y = player_->GetPos_y() - enemy->GetPos_y();
    float dist = sqrt(x*x + y*y);
    x = -x/abs(dist);
    y = -y/abs(dist);
    enemy->SetDirection(x, y);
    enemy->MoveWithCollision(x, y, collision, dt);

    if(dist > 5*32){
        enemy->GetStateMachine()->ChangeState(EnemyPatrol::Instance());
    }
}

void EnemyRunAway::Exit(Enemy * enemy){
    std::cout << "Enemy leaving RunAway State." << std::endl;

    // On remet la vitesse de base de l'enemy
    int speed = enemy->GetSpeed();
    enemy->SetSpeed(speed /2);
}
