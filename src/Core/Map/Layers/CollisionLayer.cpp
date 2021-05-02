#include "CollisionLayer.h"

#include "../tmxParsing.h"
#include <iostream>
#include <memory>

CollisionLayer::CollisionLayer()
{
}

CollisionLayer::CollisionLayer(const std::string &objectgroupTagCollision)
{
    int count = countTag(objectgroupTagCollision, "object");
    std::string strObject;
    for (int i = 0; i < count; i++)
    {
        strObject = getInsideTag(objectgroupTagCollision, "object", i);
        CollisionBox cb(strObject);
        collisionBoxes.push_back(cb);
    }
}

CollisionLayer::~CollisionLayer()
{
    collisionBoxes.clear();
    collisionBoxesEntity.clear();
}

void CollisionLayer::AddCollisionBox(const CollisionBox &newColBox)
{
    collisionBoxes.push_back(newColBox);
}

void CollisionLayer::AddCollisionBoxEntity(int id, CollisionBox* newColBox){
    collisionBoxesEntity[id] = newColBox;
}

void CollisionLayer::DisplayTXT() const
{
    for (long unsigned int i = 0; i < collisionBoxes.size(); i++)
    {
        std::cout << "Id : " << collisionBoxes[i].GetId() << std::endl;
        std::cout << "X : " << collisionBoxes[i].GetX() << std::endl;
        std::cout << "Y : " << collisionBoxes[i].GetY() << std::endl;
        std::cout << "W : " << collisionBoxes[i].GetWidth() << std::endl;
        std::cout << "H : " << collisionBoxes[i].GetHeight() << std::endl;
        std::cout << std::endl;
    }
}

std::vector<CollisionBox> CollisionLayer::GetCollisionBoxes() const
{
    return collisionBoxes;
}

std::map<int, CollisionBox*> CollisionLayer::GetCollisionBoxesEntity() 
{
    return collisionBoxesEntity;
}
