#ifndef _SPAWNS_LAYER_
#define _SPAWNS_LAYER_

#include "Layer.h"
#include "../SpawnPoint.h"
#include <vector>
#include <string>
class SpawnsLayer
{
private:
    SpawnPoint playerSpawn;
    std::vector<SpawnPoint> ennemySpawns;
public:
    SpawnsLayer(/* args */);
    SpawnsLayer(const std::string & objectgroupTagPlayer, 
                const std::string & objectgroupTagEnnemy);
    ~SpawnsLayer();
    void ChangePlayerSpawn(SpawnPoint const &newSpawn);
    void AddEnemy(SpawnPoint const &newSpawn);

    void Display()const;
};

#endif