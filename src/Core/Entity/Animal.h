#ifndef ANIMAL_H
#define ANIMAL_H

#include "EntityWithoutHP.h"
#include "FiniteStateMachine/StateMachine.h"

class Animal : public EntityWithoutHP
{
public:
    Animal();

    Animal(float x, float y, float speed, std::string name);

    ~Animal();

    StateMachine<Animal> *GetStateMachine() const;

    void UpdateStateMachine(std::unique_ptr<Player> &player_,
                            CollisionLayer *collision, int dt);

    void RandDirection();
    void ChangeDirection(bool collision);
    void SetTimeNextChangeDirection();
private:
    StateMachine<Animal> *stateMachine;
    double timeNextChangeDirection;
};
#endif // ANIMAL_H
