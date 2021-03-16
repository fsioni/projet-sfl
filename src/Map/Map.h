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
    std::vector<SpawnsLayer> spawnsLayer;
    
    Tileset* tileset;
    int nbLayers;

public:
    Map();
    Map(std::string tmxFile, std::string tsxFile);
    ~Map();

    void SetTileset(Tileset& ts);
    void AddMapLayer(const MapLayer & l);
    void AddSpawnLayer(const SpawnsLayer& nLayer);

    Tileset GetTileset() const;
    std::vector<MapLayer> GetMapLayers() const;
    int GetNbMapLayers() const;

    void TmxLoadLayers(std::string fileName);
    void TsxLoadTileset(std::string fileName);
};

#endif