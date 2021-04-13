#include "EntityWithoutHP.h"
#include <cassert>
#include <iostream>
#include <string>
#include <assert.h>



EntityWithoutHP::EntityWithoutHP(){

    this->x = 0.0;
    this->y = 0.0;
    this->offset = 0;
    this->name = "Unknown";

    direction = Right;
}

EntityWithoutHP::EntityWithoutHP(float x, float y, string name){
    assert (x >= 0.0 && y >= 0.0);

    this->x = x;
    this->y = y;
    this->offset = 7;
    this->name = name;

    direction = Right;
}


EntityWithoutHP::~EntityWithoutHP(){

    this->x = 0.0;
    this->y= 0.0;
    this->offset =0;
    this->name = "delete";
    direction = Right;
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
    assert (newx >= 0.0);

    x = newx;
}

float EntityWithoutHP::GetPos_x() const{

    return x;
}

void EntityWithoutHP::SetPos_y(float newy){
    assert (newy >= 0.0);

    y = newy;
}

int EntityWithoutHP::getOffset() const
{
    return offset;
}

void EntityWithoutHP::setOffset(int newO)
{
    offset = newO;
}

float EntityWithoutHP::GetPos_y() const{

    return y;
}


 EntityDirection EntityWithoutHP::GetDirection() const{
     return direction;
 }

void EntityWithoutHP::SetDirection(EntityDirection nDirection){
    direction = nDirection;
}