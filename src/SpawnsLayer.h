#ifndef _SPAWNS_LAYER_
#define _SPAWNS_LAYER_

#include "ObjectLayer.h"
#include "SpawnPoint.h"
#include <vector>

class SpawnsLayer:ObjectLayer
{
private:
    SpawnPoint playerSpawn;
    std::vector<SpawnPoint> ennemySpawns;
public:
    SpawnsLayer(/* args */);
    ~SpawnsLayer();
};

SpawnsLayer::SpawnsLayer(/* args */)
{
}

SpawnsLayer::~SpawnsLayer()
{
}


#endif