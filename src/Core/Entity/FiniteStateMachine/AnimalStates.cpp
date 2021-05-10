#include "AnimalStates.h"
#include "../Animal.h"


// ======== ANIMAL WALKING STATE ===========
AnimalWalking *AnimalWalking::singleton = nullptr;

AnimalWalking *AnimalWalking::Instance()
{
    if (singleton == nullptr)
    {
        singleton = new AnimalWalking;
    }
    return singleton;
}

void AnimalWalking::Enter(Animal * animal){
}

void AnimalWalking::Execute(Animal * animal, std::unique_ptr<Player> &player_,
                          CollisionLayer *collision, int dt)
{
    bool colliding = false;
    
    if(animal->GetDirection()==Right)
        colliding = animal->MoveWithCollision(1, 0, collision, dt);
    if(animal->GetDirection()==Left)
        colliding = animal->MoveWithCollision(-1, 0, collision, dt);
    if(animal->GetDirection()==Down)
        colliding = animal->MoveWithCollision(0, 1, collision, dt);
    if(animal->GetDirection()==Up)
        colliding = animal->MoveWithCollision(0, -1, collision, dt);
    
    animal->ChangeDirection(colliding);

    if(player_->Distance(animal)<5 * 32){
        animal->GetStateMachine()->ChangeState(AnimalFollowing::Instance());
    }
    
}

void AnimalWalking::Exit(Animal * animal){
}


// ======== ANIMAL FOLLOWING STATE ===========
AnimalFollowing *AnimalFollowing::singleton = nullptr;

AnimalFollowing *AnimalFollowing::Instance()
{
    if (singleton == nullptr)
    {
        singleton = new AnimalFollowing;
    }
    return singleton;
}

void AnimalFollowing::Enter(Animal * animal){
}

void AnimalFollowing::Execute(Animal * animal, std::unique_ptr<Player> &player_,
                          CollisionLayer *collision, int dt)
{
    animal->SetIsMovingFalse();
    float x = player_->GetPos_x() - animal->GetPos_x();
    float y = player_->GetPos_y() - animal->GetPos_y();
    float dist = player_->Distance(animal);
    x = x / abs(dist);
    y = y / abs(dist);
    animal->SetDirection(x, y);
    animal->MoveWithCollision(x, y, collision, dt);
    
    if(dist > 3*32){
        animal->GetStateMachine()->ChangeState(AnimalWalking::Instance());
    }
    
}

void AnimalFollowing::Exit(Animal * animal){
}
