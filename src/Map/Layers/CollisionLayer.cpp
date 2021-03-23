#include "CollisionLayer.h"

#include "../tmxParsing.h"
#include <iostream>

CollisionLayer::CollisionLayer(){
}

CollisionLayer::CollisionLayer(const std::string & objectgroupTagCollision){
    int count = countTag(objectgroupTagCollision, "object");
    std::string strObject;
    for(int i=0; i<count; i++){
        strObject = getInsideTag(objectgroupTagCollision, "object", i);
        CollisionBox cb(strObject);
        collisionBoxes.push_back(cb);
    }
}



CollisionLayer::~CollisionLayer()
{
}

void CollisionLayer::AddCollisionBox(const CollisionBox& newColBox){
    collisionBoxes.push_back(newColBox);
}

void CollisionLayer::Display() const{
    for(int i = 0; i<collisionBoxes.size(); i++){
        std::cout << "Id : " << collisionBoxes[i].GetId() << std::endl;
        std::cout << "X : " << collisionBoxes[i].GetX() << std::endl;
        std::cout << "Y : " << collisionBoxes[i].GetY() << std::endl;
        std::cout << "W : " << collisionBoxes[i].GetWidth() << std::endl;
        std::cout << "H : " << collisionBoxes[i].GetHeight() << std::endl;
        std::cout << std::endl;
    }
}