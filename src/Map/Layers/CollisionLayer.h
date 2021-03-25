#ifndef _COLLISION_LAYER_
#define _COLLISION_LAYER_

#include <vector>
#include <string>

#include "Layer.h"
#include "../CollisionBox.h"

class CollisionLayer:Layer{
private:
    std::vector<CollisionBox> collisionBoxes;
public:
    CollisionLayer(/* args */);
    CollisionLayer(const std::string & objectgroupTagCollision);
    ~CollisionLayer();
    void AddCollisionBox(const CollisionBox& newColBox);
    void Display() const;
    std::vector<CollisionBox> GetCollisionBoxes() const;

};


#endif