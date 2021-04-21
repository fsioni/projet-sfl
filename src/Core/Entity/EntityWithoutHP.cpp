#include "EntityWithoutHP.h"
#include <cassert>
#include <iostream>
#include <string>
#include <assert.h>
#include <math.h>
#include <memory>


EntityWithoutHP::EntityWithoutHP(){
    x = 0;
    y = 0;
    width = 32;
    height = 32;
    offset = 7;
    speed = 1;
    name = "Unknown";
    cb = std::make_shared<CollisionBox>(x, y, width, height);
    direction = Right;
}

EntityWithoutHP::EntityWithoutHP(int x_, int y_, int speed_, string name_){
    if(x_ < 0) x = 0;
    else x = x_;

    if(y_ < 0) y = 0;
    else y = y_;
    
    width = 32;
    height = 32;
    offset = 7;
    name = name_;
    speed = speed_;
    cb = std::make_shared<CollisionBox>(x, y, width, height);

    direction = Right;
}


EntityWithoutHP::~EntityWithoutHP(){

    x = 0;
    y= 0;
    width = 0;
    height = 0;
    offset =0;
    name = "delete";
    direction = Right;
}


void EntityWithoutHP::PrintEntityInfo(){

    cout<< "x = " << x << ", y = " << y << ", nom : " << name <<endl;
}


void EntityWithoutHP::SetName(string newName){
    name = newName;
}

std::shared_ptr<CollisionBox> EntityWithoutHP::GetCollisionBox(){
    return cb;
}

string EntityWithoutHP::GetName() const{
    return name;
}

void EntityWithoutHP::SetPos_x(int newx){
    if(newx >= 0)
        x = newx;
}

int EntityWithoutHP::GetPos_x() const{
    return x;
}

void EntityWithoutHP::SetPos_y(int newy){
    if(newy >= 0)
        y = newy; 
}

int EntityWithoutHP::GetOffset() const
{
    return offset;
}

void EntityWithoutHP::SetOffset(int newO)
{
    if(newO >= 0) 
        offset = newO;
}

int EntityWithoutHP::GetPos_y() const{
    return y;
}


 EntityDirection EntityWithoutHP::GetDirection() const{
     return direction;
 }

void EntityWithoutHP::SetDirection(EntityDirection nDirection){
    direction = nDirection;
}

void EntityWithoutHP::SetDirection(float vx, float vy){
    if(abs(vx) > abs(vy)){
        if(vx > 0) direction = Right;
        else direction = Left;
    }
    else{
        if(vy > 0) direction = Down;
        else direction = Up;
    }
}

void EntityWithoutHP::Move(float vx, float vy){

    x += vx*speed;
    y += vy*speed;

    if (x < 0){
        x = 0;
    }
    if (y < 0){
        y = 0;
    }
}

int EntityWithoutHP::GetSpeed() const{
    return speed;
}

void EntityWithoutHP::SetSpeed(int newSpeed){
    if(newSpeed>=0)
        speed = newSpeed;  
}


void EntityWithoutHP::Test() const{
    std::cout << "===== Class EntityWithoutHP =====" << std::endl;
    EntityWithoutHP entity1;
    std::cout << "Constructeur EntityWithoutHP() : ";
    assert(entity1.x == 0 && entity1.y == 0);
    assert(entity1.width == 32 && entity1.height == 32);
    assert(entity1.offset == 7 && entity1.speed == 1);
    assert(entity1.name == "Unknown");
    assert(entity1.direction == Right);
    assert(entity1.cb->GetX() == 0 && entity1.cb->GetY() == 0);
    assert(entity1.cb->GetWidth() == 32 && entity1.cb->GetHeight()==32);
    std::cout << "ok" << std::endl;

    std::cout << "Constructeur EntityWithoutHP(float x_, float y_," << 
                "float speed_, string name_) : ";
    EntityWithoutHP entity2(12, 13, 3, "Entity2");
    assert(entity2.x == 12 && entity2.y == 13);
    assert(entity2.width == 32 && entity2.height == 32);
    assert(entity2.offset == 7 && entity2.speed == 3);
    assert(entity2.name == "Entity2");
    assert(entity2.direction == Right);
    assert(entity2.cb->GetX() == 12 && entity2.cb->GetY() == 13);
    assert(entity2.cb->GetWidth() == 32 && entity2.cb->GetHeight()== 32);
    std::cout << "ok" << std::endl;

    std::cout << "SetPos_x(float newX) et GetPos_x() : ";
    entity1.SetPos_x(10);
    assert(entity1.GetPos_x()== 10);
    entity1.SetPos_x(-2);
    assert(entity1.GetPos_x()== 10);
    std::cout << "ok" << std::endl;

    std::cout << "SetPos_y(float newY) et GetPos_y() : ";
    entity1.SetPos_y(20);
    assert(entity1.GetPos_y()== 20);
    entity1.SetPos_y(-4);
    assert(entity1.GetPos_y()== 20);
    std::cout << "ok" << std::endl;

    std::cout << "SetName(float newName) et GetName() : ";
    entity1.SetName("Méchant");
    assert(entity1.GetName()== "Méchant");
    std::cout << "ok" << std::endl;

    std::cout << "SetOffset(int newO) et GetOffSet() : ";
    entity1.SetOffset(10);
    assert(entity1.GetOffset() == 10);
    entity1.SetOffset(-5);
    assert(entity1.GetOffset() == 10);
    std::cout << "ok" << std::endl;

    std::cout << "SetSpeed(int newSpeed) et GetSpeed() : ";
    entity1.SetSpeed(11);
    assert(entity1.GetSpeed() == 11);
    entity1.SetSpeed(-3);
    assert(entity1.GetSpeed() == 11);
    std::cout << "ok" << std::endl;

    std::cout << "SetDirection(EntityDirection nDirection) et GetDirection() : ";
    entity1.SetDirection(Up);
    assert(entity1.GetDirection()== Up);
    std::cout << "ok" << std::endl;

    std::cout << "SetDirection(float nx, float ny) et GetDirection() : ";
    entity1.SetDirection(0.9, 0.7);
    assert(entity1.GetDirection()== Right);
    entity1.SetDirection(0.5, 0.5);
    assert(entity1.GetDirection()== Down);
    std::cout << "ok" << std::endl;

    std::cout << "Move(float vx, float vy) : ";
    int x_ = entity1.x;
    int y_ = entity1.y;
    entity1.Move(0.8, 0);

    assert(entity1.x == int(x_ + entity1.speed*0.8));
    assert(entity1.y == int(y_ + entity1.speed*0.));
    std::cout << "ok" << std::endl;

    std::cout << std::endl << std::endl;
}