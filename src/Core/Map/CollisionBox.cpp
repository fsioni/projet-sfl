#include "CollisionBox.h"

#include <iostream>

CollisionBox::CollisionBox() : Box()
{
}

CollisionBox::CollisionBox(const std::string &objectTag) : Box(objectTag)
{
}

CollisionBox::CollisionBox(float x, float y, float width, float height) : 
                            Box(0, x, y, width, height)
{
}

CollisionBox::~CollisionBox()
{
}

void CollisionBox::Test() const
{
    std::cout << "===== Class CollisionBox =====" << std::endl;
    std::cout << "Pas de fonction ou membre supplémentaire que sa "
              << "classe mère Box déjà testée : ok";
    std::cout << std::endl
              << std::endl;
}