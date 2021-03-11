#ifndef _COLLISION_LAYER_
#define _COLLISION_LAYER_

#include "Layer.h"
#include "../CollisionBox.h"

class CollisionLayer:Layer{
private:
    std::vector<CollisionBox> collisionBoxes;
public:
    CollisionLayer(/* args */);
    ~CollisionLayer();
};


#endif