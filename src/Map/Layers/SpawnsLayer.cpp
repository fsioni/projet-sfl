#include "SpawnsLayer.h"

SpawnsLayer::SpawnsLayer(/* args */)
{
}

SpawnsLayer::~SpawnsLayer()
{
}

void SpawnsLayer::ChangePlayerSpawn(SpawnPoint const &newSpawn){
    playerSpawn = newSpawn;
}

void SpawnsLayer::AddEnemy(SpawnPoint const &newSpawn){
    ennemySpawns.push_back(newSpawn);
}