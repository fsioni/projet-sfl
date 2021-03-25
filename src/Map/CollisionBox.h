#ifndef _COLLISION_BOX_
#define _COLLISION_BOX_

#include "Box.h"

#include <string>

class CollisionBox: public Box
{
private:
    /* data */
public:
    CollisionBox(/* args */);
    CollisionBox(const std::string& objectTag);
    ~CollisionBox();

    void Test() const;
};

#endif