#ifndef _SPAWNS_LAYER_
#define _SPAWNS_LAYER_

#include "Layer.h"
#include "../SpawnPoint.h"
#include <vector>

class SpawnsLayer
{
private:
    SpawnPoint playerSpawn;
    std::vector<SpawnPoint> ennemySpawns;
public:
    SpawnsLayer(/* args */);
    ~SpawnsLayer();
};

#endif