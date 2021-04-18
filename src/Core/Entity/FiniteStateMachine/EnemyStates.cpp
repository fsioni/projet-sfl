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



bool MoveWithCollision(Enemy * e, CollisionLayer * cl, float vx, float vy) 
{
    if (vx == 0 && vy == 0)
    {
        return false;
    }
    bool iscolliding = false;
    std::vector<CollisionBox> cb = cl->GetCollisionBoxes();
    std::shared_ptr<CollisionBox> cbEnemy = e->getCollisionBox();
    for (long unsigned int i = 0; i < cb.size(); i++)
    {
        // -w/2 et -h/2 pour centrer l'origine 
        int posX = cbEnemy->GetX() + 
                   vx*e->GetSpeed() - 16;
        int posY = cbEnemy->GetY() + 
                   vy*e->GetSpeed() - 16;

        

        int offset = e->getOffset();
        //Detection collision axe X
        if (posX + cbEnemy->GetWidth() - offset >= cb[i].GetX()
            && cb[i].GetX() + cb[i].GetWidth() >= posX + offset){
            //Detection collision axe Y
            if(posY +cbEnemy->GetHeight() - offset >= cb[i].GetY()
               && cb[i].GetY() + cb[i].GetHeight() >= posY + offset){

                iscolliding = true;
            }   
        }
    }

    std::vector<std::shared_ptr<CollisionBox>> cbEnemie = cl->GetCollisionBoxesEnemy();
    for (long unsigned int i = 0; i < cbEnemie.size(); i++)
    {

        // -w/2 et -h/2 pour centrer l'origine 
        int posX = e->GetPos_x() + 
                   vx*e->GetSpeed() - 16;
        int posY = e->GetPos_y() + 
                   vy*e->GetSpeed() - 16;

        int offset = e->getOffset();

        // TODO : Rajouter une condition pour ne pas tester 
        //        sa propre collision Box
        if(true){
            //Detection collision axe X
            if (posX + e->getCollisionBox()->GetWidth() - offset >= cbEnemie[i]->GetX()
                && cbEnemie[i]->GetX() + cbEnemie[i]->GetWidth() >= posX + offset){
                //Detection collision axe Y
                if(posY + e->getCollisionBox()->GetHeight() - offset >= cbEnemie[i]->GetY()
                && cbEnemie[i]->GetY() + cbEnemie[i]->GetHeight() >= posY + offset){

                    iscolliding = true;
                }   
            }
        }
    }

    if (!iscolliding)
    {
        e->Move((vx)/30, (vy)/30);
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
                          CollisionLayer * collision){
    bool colliding = false;
    
    if(enemy->GetDirection()==Right)
        colliding = MoveWithCollision(enemy, collision, 1, 0);
    if(enemy->GetDirection()==Left)
        colliding = MoveWithCollision(enemy, collision, -1, 0);
    if(enemy->GetDirection()==Down)
        colliding = MoveWithCollision(enemy, collision, 0, 1);
    if(enemy->GetDirection()==Up)
        colliding = MoveWithCollision(enemy, collision, 0, -1);

    if(enemy->GetNbUpdateChangeDir()==0 || colliding){
        enemy->randDirection();
        enemy->SetNbUpdateChangeDir();
    }

    if(distance(enemy, player_)<4 * 32){
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

void EnemyAttack::Execute(Enemy * enemy, std::unique_ptr<Player> & player_, 
                          CollisionLayer * collision){
    float x = player_->GetPos_x() - enemy->GetPos_x();
    float y = player_->GetPos_y() - enemy->GetPos_y();
    float dist = sqrt(x*x + y*y);
    x = x/abs(dist);
    y = y/abs(dist);
    enemy->SetDirection(x, y);
    MoveWithCollision(enemy, collision, x, y);
    dist = distance(enemy, player_);
    if(dist > 5*32){
        enemy->GetStateMachine()->ChangeState(EnemyPatrol::Instance());
    }

    if(dist < 1*32){
        player_->TakeDamage(enemy->GetDamage());
    }
}

void EnemyAttack::Exit(Enemy * enemy){
    std::cout << "Enemy leaving Attack State." << std::endl;
}
