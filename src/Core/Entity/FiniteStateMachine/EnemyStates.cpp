#include "EnemyStates.h"
#include "../Enemy.h"
#include "StateBehavior.h"

#include <iostream>
#include <math.h>

// Fonctions génériques 
float distance(Enemy * enemy, std::unique_ptr<Player> & player_){
    int x = enemy->GetPos_x() - player_->GetPos_x();
    int y = enemy->GetPos_y() - player_->GetPos_y();
    return sqrt(x*x + y*y);
}



bool MoveWithCollision(Enemy * e, CollisionLayer * cl, float vx, float vy, std::unique_ptr<Player> & player_, int dt) 
{
    if (vx == 0 && vy == 0)
    {
        return false;
    }
    bool iscolliding = false;
    std::vector<CollisionBox> cb = cl->GetCollisionBoxes();
    std::shared_ptr<CollisionBox> cbEnemy = e->GetCollisionBox();
        int posX = cbEnemy->GetX() + 
                   vx*e->GetSpeed();
        int posY = cbEnemy->GetY() + 
                   vy*e->GetSpeed();


    for (long unsigned int i = 0; i < cb.size(); i++)
    {
        //Detection collision axe X
        if (posX + cbEnemy->GetWidth() >= cb[i].GetX()
            && cb[i].GetX() + cb[i].GetWidth() >= posX){
            //Detection collision axe Y
            if(posY +cbEnemy->GetHeight() >= cb[i].GetY()
               && cb[i].GetY() + cb[i].GetHeight() >= posY){
                iscolliding = true;
            }   
        }
    }

   
    std::vector<std::shared_ptr<CollisionBox> > cbEnemies = cl->GetCollisionBoxesEnemy();
    
    
    for (long unsigned int i = 0; i < cbEnemies.size(); i++)
    {
        if(e->GetCollisionBox()->GetId() != cbEnemies[i]->GetId()){

            //Detection collision axe X
            if (posX + e->GetCollisionBox()->GetWidth() >= cbEnemies[i]->GetX()
                && cbEnemies[i]->GetX() + cbEnemies[i]->GetWidth() >= posX){
                //Detection collision axe Y
                if(posY + e->GetCollisionBox()->GetHeight() >= cbEnemies[i]->GetY()
                && cbEnemies[i]->GetY() + cbEnemies[i]->GetHeight() >= posY){
                
                    iscolliding = true;
                }   
            }
        }
    }
    

    std::shared_ptr<CollisionBox> cbPlayer = player_->GetCollisionBox();
    int offsetPlayer = player_->GetOffset();
    float pX = cbPlayer->GetX() - 16;
    float pY = cbPlayer->GetY() -16;
    
    //Detection collision axe X
    if (posX + e->GetCollisionBox()->GetWidth() >= pX + offsetPlayer
        && pX + cbPlayer->GetWidth() - offsetPlayer >= posX)
    {
        //Detection collision axe Y
        if(posY + e->GetCollisionBox()->GetHeight() >= pY + offsetPlayer
        && pY + cbPlayer->GetHeight() - offsetPlayer >= posY)
        {
            iscolliding = true;
        }   
    }
    
    

    if (!iscolliding)
    {
        e->Move((vx*dt)/30, (vy*dt)/30);
    }

    return iscolliding;
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


void EnemyPatrol::Execute(Enemy * enemy, std::unique_ptr<Player> & player_,
                          CollisionLayer * collision, int dt){
    bool colliding = false;
    
    if(enemy->GetDirection()==Right)
        colliding = MoveWithCollision(enemy, collision, 1, 0, player_, dt);
    if(enemy->GetDirection()==Left)
        colliding = MoveWithCollision(enemy, collision, -1, 0, player_, dt);
    if(enemy->GetDirection()==Down)
        colliding = MoveWithCollision(enemy, collision, 0, 1, player_, dt);
    if(enemy->GetDirection()==Up)
        colliding = MoveWithCollision(enemy, collision, 0, -1, player_, dt);

    enemy->ChangeDirection(colliding);
    
    // Si player dans rayon 4 bloc, il entre en état Attack
    if(distance(enemy, player_)<4 * 32){
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
    MoveWithCollision(enemy, collision, x, y, player_, dt);
    dist = distance(enemy, player_);
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
    MoveWithCollision(enemy, collision, x, y, player_, dt);

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
