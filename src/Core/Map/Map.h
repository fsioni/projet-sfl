#ifndef _MAP_
#define _MAP_

#include <vector>

#include "Tileset.h"
#include "Layers/CollisionLayer.h"
#include "Layers/MapLayer.h"
#include "Layers/SpawnsLayer.h"

class Map{
    std::vector<MapLayer> mapLayers;
    CollisionLayer * collisionLayer;
    SpawnsLayer * spawnsLayer;
    Tileset * tileset;

public:
    Map();
    Map(std::string tmxFile, std::string tsxFile);
    ~Map();

    void SetTileset(const Tileset& ts);
    void AddMapLayer(const MapLayer & l);
    void SetSpawnLayer(const SpawnsLayer& nLayer);

    Tileset GetTileset() const;
    CollisionLayer GetCollisionLayer() const;
    std::vector<MapLayer> GetMapLayers() const;
    SpawnsLayer GetSpawnsLayer() const;

    void TmxLoadLayers(std::string fileName);
    void TsxLoadTileset(std::string fileName);

    void Display() const;
    void Test() const;
};

#endif