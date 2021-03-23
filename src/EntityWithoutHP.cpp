#include "EntityWithoutHP.h"
#include <iostream>
#include <string>



EntityWithoutHP::EntityWithoutHP(){

    this->x = 0.0;
    this->y = 0.0;
    this->name = "Unknown";
}

EntityWithoutHP::EntityWithoutHP(float x, float y, string name){

    this->x = x;
    this->y = y;
    this->name = name;
}


EntityWithoutHP::~EntityWithoutHP(){

    this->x = 0.0;
    this->y= 0.0;
    this->name = "delete";
}


void EntityWithoutHP::PrintEntityInfo(){

    cout<< "x = " << x << ", y = " << y << ", nom : " << name <<endl;
}

void EntityWithoutHP::SetName(string newName){

    name = newName;
}

string EntityWithoutHP::GetName() const{

    return name;
}

void EntityWithoutHP::SetPos_x(float newx){

    x = newx;
}

float EntityWithoutHP::GetPos_x() const{

    return x;
}

void EntityWithoutHP::SetPos_y(float newy){

    y = newy;
}

float EntityWithoutHP::GetPos_y() const{

    return y;
}
