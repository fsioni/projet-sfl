#include "Animal.h"
#include "EntityWithoutHP.h"
#include "FiniteStateMachine/AnimalStates.h"

Animal::Animal() : EntityWithoutHP() {
    stateMachine = new StateMachine<Animal>(this);
    stateMachine->SetCurrentState(AnimalWalking::Instance());

    SetTimeNextChangeDirection();
}

Animal::Animal(float x, float y, float speed) :
     EntityWithoutHP(x, y, speed) {
    stateMachine = new StateMachine<Animal>(this);
    stateMachine->SetCurrentState(AnimalWalking::Instance());

    SetTimeNextChangeDirection();
}

Animal::~Animal(){
}

void Animal::UpdateStateMachine(std::unique_ptr<Player> &player_,
                               CollisionLayer *collision, int dt)
{
    stateMachine->UpdateCurrentState(player_, collision, dt);
}

StateMachine<Animal> *Animal::GetStateMachine() const{
    return stateMachine;
}

void Animal::RandDirection(){
    int nb = rand() % 4;
    switch (nb)
    {
    case 0:
        direction = Down;
        break;
    case 1:
        direction = Left;
        break;
    case 2:
        direction = Right;
        break;
    case 3:
        direction = Up;
        break;

    default:
        direction = Right;
        break;
    }
}

void Animal::SetTimeNextChangeDirection(){
    int min = 3;
    int max = 7;
    double timer = time(NULL);
    timeNextChangeDirection = timer + rand() % (max - min) + min;
}

void Animal::ChangeDirection(bool collision){
    double timer = time(NULL);
    if (collision)
    {
        RandDirection();
        SetTimeNextChangeDirection();
    }
    else if (timer > timeNextChangeDirection)
    {
        RandDirection();
        SetTimeNextChangeDirection();
    }
}
