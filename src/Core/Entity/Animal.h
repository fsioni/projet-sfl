#ifndef ANIMAL_H
#define ANIMAL_H

#include "EntityWithoutHP.h"

class Animal : public EntityWithoutHP
{
public :

    Animal();

    Animal(float x, float y, std::string name);

    ~Animal();

    EntityDirection RandDirection();

    void MoveRandomly(float vx, float vy);


};
#endif // ANIMAL_H
