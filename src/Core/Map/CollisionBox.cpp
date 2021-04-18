#include "CollisionBox.h"

CollisionBox::CollisionBox() : Box(){
}

CollisionBox::CollisionBox(const std::string& objectTag): Box(objectTag){
}

CollisionBox::CollisionBox(float x, float y, float width, float height) :
                Box(0, x, y, width, height){
}

CollisionBox::~CollisionBox(){
}

void CollisionBox::Test() const{}