#include "SpawnPoint.h"

SpawnPoint::SpawnPoint() : Box(){
    name = "NULL";
}

SpawnPoint::SpawnPoint(const std::string& _name,const std::string& objectTag) : Box(objectTag){
    name = _name;
}

SpawnPoint::~SpawnPoint()
{
}

void SpawnPoint::SetName(const std::string& nName){name = nName;}
std::string SpawnPoint::GetName() const{return name;}

void SpawnPoint::Test() const{}