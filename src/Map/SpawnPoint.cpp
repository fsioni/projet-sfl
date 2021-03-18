#include "SpawnPoint.h"

SpawnPoint::SpawnPoint(/* args */)
{
}

SpawnPoint::~SpawnPoint()
{
}

void SpawnPoint::SetName(const std::string& nName){name = nName;}
std::string SpawnPoint::GetName() const{return name;}

void SpawnPoint::Test() const{}