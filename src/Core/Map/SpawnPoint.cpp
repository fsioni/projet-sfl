#include "SpawnPoint.h"
#include <iostream>
#include "tmxParsing.h"
#include <assert.h>

SpawnPoint::SpawnPoint(){
    x = 0;
    y = 0;
}

SpawnPoint::SpawnPoint(const std::string &objectTag)
{
    x = GetIntAttributeValue(objectTag, "x");
    y = GetIntAttributeValue(objectTag, "y");
}

SpawnPoint::~SpawnPoint()
{
}


int SpawnPoint::GetX()const{
    return x;
}


int SpawnPoint::GetY()const{
    return y;
}


void SpawnPoint::Test() const
{
    std::cout << "===== Class SpawnPoint =====" << std::endl;

    SpawnPoint spawnPoint1;
    std::cout << "SpawnPoint() : ";
    assert(spawnPoint1.GetX()==0);
    assert(spawnPoint1.GetY()==0);
    std::cout << "ok" << std::endl;

    std::cout << "SpawnPoint(const std::string &objectTag) : ";
    std::string tag = "<object id=\"14\" x=\"224\" y=\"832\"/>";
    SpawnPoint spawnPoint2(tag);
    assert(spawnPoint2.GetX()==224);
    assert(spawnPoint2.GetY()==832);
    std::cout << "ok" << std::endl;

    std::cout << std::endl << std::endl;
}