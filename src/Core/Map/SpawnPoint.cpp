#include "SpawnPoint.h"
#include <iostream>
#include <assert.h>

SpawnPoint::SpawnPoint() : Box(){
    name = "NULL";
}

SpawnPoint::SpawnPoint(const std::string& _name,const std::string& objectTag) : Box(objectTag){
    name = _name;
}

SpawnPoint::~SpawnPoint()
{
}

void SpawnPoint::SetName(const std::string& nName){
    name = nName;
}

std::string SpawnPoint::GetName() const{
    return name;
}

void SpawnPoint::Test() const{
    std::cout << "===== Class SpawnPoint =====" << std::endl;

    SpawnPoint spawnPoint1;
    std::cout << "Constructeur SpawnPoint() : ";
    assert(spawnPoint1.GetName() == "NULL");
    std::cout << "ok" << std::endl;

    
    std::cout << "Constructeur SpawnPoint(const std::string& _name, "<<
                 "const std::string& objectTag) : ";
    std::string tag;
    tag = "<object id=\"14\" x=\"224\" y=\"832\" width=\"64\" height=\"64\"/>";
    SpawnPoint spawnPoint2("spawn", tag);
    assert(spawnPoint2.GetName() == "spawn");
    std::cout << "ok" << std::endl;


    std::cout << "SetName(const std::string & name_) et GetName() : ";
    spawnPoint1.SetName("spawnPlayer");
    assert(spawnPoint1.GetName()=="spawnPlayer");
    std::cout << "ok" << std::endl;

    std::cout << std::endl << std::endl;
}