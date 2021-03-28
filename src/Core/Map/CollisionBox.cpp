#include "CollisionBox.h"

CollisionBox::CollisionBox() : Box(){
}

CollisionBox::CollisionBox(const std::string& objectTag): Box(objectTag){
}

CollisionBox::~CollisionBox(){
}

void CollisionBox::Test() const{}