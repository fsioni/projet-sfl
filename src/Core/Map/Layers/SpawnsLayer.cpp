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

std::vector<SpawnPoint> SpawnsLayer::getEnemySpawns() const{
    return ennemySpawns;
}

void SpawnsLayer::ChangePlayerSpawn(SpawnPoint const &newSpawn){
    playerSpawn = newSpawn;
}

void SpawnsLayer::AddEnemy(SpawnPoint const &newSpawn){
    ennemySpawns.push_back(newSpawn);
}
