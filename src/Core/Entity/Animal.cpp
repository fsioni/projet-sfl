#include "Animal.h"
#include "EntityWithoutHP.h"

Animal::Animal() : EntityWithoutHP(){}

Animal::Animal(float x, float y, std::string name) : EntityWithoutHP::EntityWithoutHP(x, y, name){}

Animal::~Animal(){

    x = 0.0;
    y = 0.0;
    name = "deletedAnimal";
}


EntityDirection Animal::RandDirection(){

    int temp = RandNumberGenerator(1, 4);

    return EntityDirection(temp);
}


void Animal::MoveRandomly(float vx, float vy){

    x += vx*1.5;
    y += vy*1.5;

    if (x < 0.0){
        x = 0.0;
    }
    if (y < 0.0){
        y = 0.0;
    }

    EntityDirection temporary = RandDirection();

    SetDirection(temporary);
}
