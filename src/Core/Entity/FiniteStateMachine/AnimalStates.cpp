#include "AnimalStates.h"
#include "../Animal.h"


// ======== ENEMY PATROL STATE ===========
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
    
}

void AnimalWalking::Exit(Animal * animal){
}

