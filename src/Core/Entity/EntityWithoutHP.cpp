#include "EntityWithoutHP.h"

EntityWithoutHP::EntityWithoutHP(){

    this->x = 0.0;
    this->y = 0.0;
    this->width = 0.0;
    this->height = 0.0;
    this->offset = 0;
    this->name = "Unknown";

    direction = Right;
}

EntityWithoutHP::EntityWithoutHP(float x, float y, std::string name){
    assert (x >= 0.0 && y >= 0.0);

    this->x = x;
    this->y = y;
    this->width = 32.0;
    this->height = 32.0;
    this->offset = 7;
    this->name = name;

    direction = Right;
}


EntityWithoutHP::~EntityWithoutHP(){

    this->x = 0.0;
    this->y= 0.0;
    this->width = 0.0;
    this->height = 0.0;
    this->offset =0;
    this->name = "delete";
    direction = Right;
}


void EntityWithoutHP::PrintEntityInfo(){

    std::cout<< "x = " << x << ", y = " << y << ", nom : " << name <<std::endl;
}


void EntityWithoutHP::SetName(std::string newName){

    name = newName;
}

std::string EntityWithoutHP::GetName() const{

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

float EntityWithoutHP::GetWidth() const{

    return width;
}

void EntityWithoutHP::SetWidth(int newW){
    assert (newW >= 0.0);

    width = newW;
}

float EntityWithoutHP::GetHeight() const{

    return height;
}

void EntityWithoutHP::SetHeight(int newH){
    assert (newH >= 0.0);

    height = newH;
}

int EntityWithoutHP::GetOffset() const
{
    return offset;
}

void EntityWithoutHP::SetOffset(int newO){

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

int EntityWithoutHP::RandNumberGenerator(int minimum, int maximum){

    int random;
    int plage = maximum - minimum + 1;

    for (int i = 0; i < 100; i++) random = (rand() % plage) + minimum;

    return random;
}

