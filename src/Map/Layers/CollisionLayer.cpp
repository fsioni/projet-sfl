#include "CollisionLayer.h"


CollisionLayer::CollisionLayer(/* args */)
{
}

CollisionLayer::~CollisionLayer()
{
}

void CollisionLayer::AddCollisionBox(const CollisionBox& newColBox){
    collisionBoxes.push_back(newColBox);
}


std::vector<CollisionBox> CollisionLayer::GetCollisionBoxes() const 
{
    return collisionBoxes;
}
