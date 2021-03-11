#ifndef _MAP_

#include <vector>

#include "Layer.h"
#include "Tileset.h"


class Map{
    std::vector<Layer> layers;
    Tileset tileset;
    int nbLayers;

public:
    Map();
    Map(std::string tmxFile, std::string tsxFile);
    ~Map();

    void SetTileset(const Tileset & ts);
    void AddLayer(const Layer & l);

    Tileset GetTileset() const;
    std::vector<Layer> GetLayers() const;
    int GetNbLayers() const;

    void TmxLoadLayers(std::string fileName);
    void TsxLoadTileset(std::string fileName);
};

#endif