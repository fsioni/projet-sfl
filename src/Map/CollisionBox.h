#ifndef _COLLISION_BOX_
#define _COLLISION_BOX_

#include "Box.h"

class CollisionBox:Box
{
private:
    /* data */
public:
    CollisionBox(/* args */);
    ~CollisionBox();

    void Test() const;
};

#endif