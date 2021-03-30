#include "SpawnsLayer.h"

#include "../tmxParsing.h"
#include <iostream>

SpawnsLayer::SpawnsLayer(){

}

SpawnsLayer::SpawnsLayer(const std::string & objectgroupTagPlayer, 
                         const std::string & objectgroupTagEnnemy){
    
    std::string objectTag;
    
    objectTag = getInsideTag(objectgroupTagPlayer, "object", 0);
    playerSpawn = SpawnPoint("PlayerSpawn", objectTag);

    int count;
    count = countTag(objectgroupTagEnnemy, "object");

    
    for(int i=0; i<count; i++){
        objectTag = getInsideTag(objectgroupTagEnnemy, "object", i);
    
        SpawnPoint s("EnemySpawn", objectTag);
        ennemySpawns.push_back(s);
    }
    
}

SpawnsLayer::~SpawnsLayer(){
}

SpawnPoint SpawnsLayer::getPlayerSpawn() const{
    return playerSpawn;
}


void SpawnsLayer::ChangePlayerSpawn(SpawnPoint const &newSpawn){
    playerSpawn = newSpawn;
}

void SpawnsLayer::AddEnemy(SpawnPoint const &newSpawn){
    ennemySpawns.push_back(newSpawn);
}

void SpawnsLayer::Display() const{
    std::cout << "Name : " << playerSpawn.GetName() << std::endl;
    std::cout << "Id : " << playerSpawn.GetId() << std::endl;
    std::cout << "X : " << playerSpawn.GetX() << std::endl;
    std::cout << "Y : " << playerSpawn.GetY() << std::endl;
    std::cout << "W : " << playerSpawn.GetWidth() << std::endl;
    std::cout << "H : " << playerSpawn.GetHeight() << std::endl;
    std::cout << std::endl;

    for(int i=0; i<ennemySpawns.size(); i++){
        std::cout << "Name : " << ennemySpawns[i].GetName() << std::endl;
        std::cout << "Id : " << ennemySpawns[i].GetId() << std::endl;
        std::cout << "X : " << ennemySpawns[i].GetX() << std::endl;
        std::cout << "Y : " << ennemySpawns[i].GetY() << std::endl;
        std::cout << "W : " << ennemySpawns[i].GetWidth() << std::endl;
        std::cout << "H : " << ennemySpawns[i].GetHeight() << std::endl;
        std::cout << std::endl;
    }
}