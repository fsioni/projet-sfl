#include "EntityWithoutHP.h"
#include <iostream>
#include <string>



EntityWithoutHP::EntityWithoutHP(){

    this->x = 0;
    this->y = 0;
    this->name = "Unknown";
}

EntityWithoutHP::EntityWithoutHP(unsigned int x, unsigned int y, string name){

    this->x = x;
    this->y = y;
    this->name = name;
}


EntityWithoutHP::~EntityWithoutHP(){

    this->x = 0;
    this->y= 0;
    this->name = "le boug est supp";
}


void EntityWithoutHP::PrintEntityInfo(){

    cout<< "x = " << x << ", y = " << y << ", nom : " << name <<endl;
}

void EntityWithoutHP::SetName(string newn){

    name = newn;
}

string EntityWithoutHP::GetName(){

    return name;
}

void EntityWithoutHP::SetPos_x(int newx){

    x = newx;
}

int EntityWithoutHP::GetPos_x(){

    return x;
}

void EntityWithoutHP::SetPos_y(int newy){

    y = newy;
}

int EntityWithoutHP::GetPos_y(){

    return y;
}
