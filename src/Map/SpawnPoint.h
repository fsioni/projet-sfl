#ifndef _SPAWN_POINT_
#define _SPAWN_POINT_

#include "Box.h"
#include <string>

class SpawnPoint:Box
{
private:
    std::string name;
public:
    SpawnPoint
(/* args */);
    ~SpawnPoint
();
};

#endif
