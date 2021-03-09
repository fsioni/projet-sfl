#ifndef _COLLISION_LAYER_
#define _COLLISION_LAYER_

#include "ObjectLayer.h"
#include "CollisionBox.h"

class CollisionLayer:ObjectLayer
{
private:
    std:vector<CollisionBox> collisionBoxes;
public:
    CollisionLayer(/* args */);
    ~CollisionLayer();
};


#endif