#include "EntityWithoutHP.h"

#include <cassert>
#include <iostream>
#include <string>
#include <assert.h>
#include <math.h>
#include <memory>

EntityWithoutHP::EntityWithoutHP()
{
    x = 0;
    y = 0;
    speed = 1;
    name = "Unknown";
    direction = Right;
    isMoving = false;

    offset= 7;
}

EntityWithoutHP::EntityWithoutHP(float x_, float y_, int speed_, std::string name_)
{
    if (x_ < 0) x = 0;
    else x = x_;

    if(y_ < 0) y = 0;
    else y = y_;
    
    name = name_;
    speed = speed_;


    direction = Right;
    isMoving = false;
    offset = 7;
}

EntityWithoutHP::~EntityWithoutHP()
{
    x = 0;
    y= 0;
    name = "delete";
    direction = Right;
}

void EntityWithoutHP::PrintEntityInfo()
{

    std::cout << "x = " << x << ", y = " << y << ", nom : " << name 
                << std::endl;
}

void EntityWithoutHP::SetName(std::string newName)
{

    name = newName;
}

std::string EntityWithoutHP::GetName() const
{

    return name;
}


void EntityWithoutHP::SetPos_x(float newx)
{
    if (newx >= 0)
        x = newx;
}

float EntityWithoutHP::GetPos_x() const
{
    return x;
}

void EntityWithoutHP::SetPos_y(float newy)
{
    if (newy >= 0)
        y = newy;
}


float EntityWithoutHP::GetPos_y() const
{
    return y;
}

EntityDirection EntityWithoutHP::GetDirection() const
{

    return direction;
}

void EntityWithoutHP::SetDirection(EntityDirection nDirection)
{

    direction = nDirection;
}

int EntityWithoutHP::RandNumberGenerator(int minimum, int maximum)
{

    int random;
    int plage = maximum - minimum + 1;

    random = (rand() % plage) + minimum;

    return random;
}

void EntityWithoutHP::SetDirection(float vx, float vy)
{
    if (abs(vx) > abs(vy))
    {
        if (vx > 0)
            direction = Right;
        else
            direction = Left;
    }
    else
    {
        if (vy > 0)
            direction = Down;
        else
            direction = Up;
    }
}

void EntityWithoutHP::Move(float vx, float vy)
{
    // Si au moins une des valeurs de déplacement 
    // est différente de 0 alors on fait les calculs
    if(vx!=0 || vy!=0){
        x += vx * speed;
        y += vy * speed;

        if (x < 0) x = 0;

        if (y < 0) y = 0;

        isMoving = true;
    }
    else isMoving = false;
}

int EntityWithoutHP::GetSpeed() const
{

    return speed;
}

void EntityWithoutHP::SetSpeed(int newSpeed)
{
    if (newSpeed >= 0)
        speed = newSpeed;
}

bool EntityWithoutHP::GetIsMoving() const
{
    return isMoving;
}

void EntityWithoutHP::SetIsMovingFalse()
{
    isMoving = false;
}

float EntityWithoutHP::Distance(const EntityWithoutHP * entity) const{
    int x_ = x - entity->x;
    int y_ = y - entity->y;
    return sqrt(x_*x_ + y_*y_);
}

int EntityWithoutHP::GetID() const{
    return id.id;
}

bool EntityWithoutHP::MoveWithCollision(float vx, float vy, CollisionLayer * colLayer, int dt){
    
    bool isColliding = false;

    // Si pas de mouvement alors pas de collision
    if(vx==0 && vy==0) return isColliding;

    // CollisionBox de l'entité
    
    Box * cbThisEntity = colLayer->GetCollisionBoxesEntity()[GetID()];
    
    int posX = cbThisEntity->GetX() + vx*speed;
    int posY = cbThisEntity->GetY() + vy*speed;
    
    // Collision avec la map
    std::vector<Box> cbMap = colLayer->GetCollisionBoxes();
    for(int i=0; i< (int)cbMap.size(); i++){

        //Detection collision axe X
        if (posX - offset + cbThisEntity->GetWidth()/2>= cbMap[i].GetX()
            && cbMap[i].GetX() + cbMap[i].GetWidth() >= posX - offset){
            //Detection collision axe Y
            if(posY - offset + cbThisEntity->GetHeight()/2>= cbMap[i].GetY()
               && cbMap[i].GetY() + cbMap[i].GetHeight() >= posY - offset){

                isColliding = true;
            }   
        }
    }
    // Si c'est le joueur on augmente son offset de 3 
    // pour empecher de se bloquer entre 2 enemy
    if(GetID()==1) offset+=3;
    // Collision entre entity
    std::map<int, Box *> cbEntities = colLayer->GetCollisionBoxesEntity();
    for(std::map<int, Box *>::iterator it= cbEntities.begin();
        it != cbEntities.end(); it++){
        if(it->first != GetID()){
            Box * cbEntity = it->second;
            // X
            if(posX + cbThisEntity->GetWidth() - offset>= cbEntity->GetX()
                && posX - offset <= cbEntity->GetX() + cbEntity->GetWidth()){
                // Y
                if(posY + cbThisEntity->GetHeight() >= cbEntity->GetY()
                    && posY <= cbEntity->GetY() + cbEntity->GetHeight()){
                    isColliding=true;
                }
            }

        }
    }
    // On remet l'offset du joueur à la normale
    if(GetID()==1) offset-=3;

    // Si pas de collision alors on bouge l'entité
    if(!isColliding)
        Move((vx*dt)/30, (vy*dt)/30);

    return isColliding;
}




void EntityWithoutHP::Test() const{
    std::cout << "===== Class EntityWithoutHP =====" << std::endl;
    EntityWithoutHP entity1;
    std::cout << "Constructeur EntityWithoutHP() : ";
    assert(entity1.x == 0.);
    assert(entity1.y == 0.);
    assert(entity1.speed == 1);
    assert(entity1.name == "Unknown");
    assert(entity1.direction == Right);
    assert(!entity1.isMoving);
    std::cout << "ok" << std::endl;

    std::cout << "Constructeur EntityWithoutHP(float x_, float y_,"
              << "float speed_, string name_) : ";
    EntityWithoutHP entity2(12.3, 13.4, 3, "Entity2");
    assert(entity2.x == float(12.3));
    assert(entity2.y == float(13.4));
    assert(entity2.speed == 3);
    assert(entity2.name == "Entity2");
    assert(entity2.direction == Right);
    assert(!entity2.isMoving);
    std::cout << "ok" << std::endl;

    std::cout << "SetPos_x(float newX) et GetPos_x() : ";
    entity1.SetPos_x(10.3);
    assert(entity1.GetPos_x() == float(10.3));
    entity1.SetPos_x(-2);
    assert(entity1.GetPos_x() == float(10.3));
    std::cout << "ok" << std::endl;

    std::cout << "SetPos_y(float newY) et GetPos_y() : ";
    entity1.SetPos_y(20.4);
    assert(entity1.GetPos_y() == float(20.4));
    entity1.SetPos_y(-4);
    assert(entity1.GetPos_y() == float(20.4));
    std::cout << "ok" << std::endl;

    std::cout << "SetName(float newName) et GetName() : ";
    entity1.SetName("Méchant");
    assert(entity1.GetName() == "Méchant");
    std::cout << "ok" << std::endl;


    std::cout << "SetSpeed(int newSpeed) et GetSpeed() : ";
    entity1.SetSpeed(11);
    assert(entity1.GetSpeed() == 11);
    entity1.SetSpeed(-3);
    assert(entity1.GetSpeed() == 11);
    std::cout << "ok" << std::endl;

    std::cout << "SetDirection(EntityDirection nDirection) et GetDirection() : ";
    entity1.SetDirection(Up);
    assert(entity1.GetDirection() == Up);
    std::cout << "ok" << std::endl;

    std::cout << "SetDirection(float nx, float ny) et GetDirection() : ";
    entity1.SetDirection(0.9, 0.7);
    assert(entity1.GetDirection() == Right);
    entity1.SetDirection(0.5, 0.5);
    assert(entity1.GetDirection() == Down);
    std::cout << "ok" << std::endl;

    std::cout << "Move(float vx, float vy) : ";
    float x_ = entity1.x;
    float y_ = entity1.y;
    entity1.Move(0.8, 0);

    assert(entity1.x == float(x_ + entity1.speed * 0.8));
    assert(entity1.y == float(y_ + entity1.speed * 0.));
    std::cout << "ok" << std::endl;

    std::cout << "SetIsMovingFalse() et GetIsMoving() : ";
    entity1.isMoving = true;
    entity1.SetIsMovingFalse();
    assert(!entity1.GetIsMoving());
    entity1.SetIsMovingFalse();
    assert(!entity1.GetIsMoving());
    std::cout << "ok" << std::endl;

    std::cout << "Id bien unique et GetID() : ";
    assert(entity1.GetID()!= entity2.GetID());
    std::cout << "ok" << std::endl;

    std::cout << std::endl
              << std::endl;
}
