#ifndef _SPAWN_POINT_
#define _SPAWN_POINT_

#include "Box.h"
#include <string>

class SpawnPoint: public Box
{
private:
    std::string name;
public:
    SpawnPoint(/* args */);
    SpawnPoint(const std::string& _name, const std::string& objectTag);
    ~SpawnPoint();

    void SetName(const std::string& nName);
    std::string GetName() const;

    void Test() const;
};

#endif
