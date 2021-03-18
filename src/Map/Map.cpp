#include "Map.h"
#include "tmxParsing.h"



Map::Map(){
    nbLayers = 0;
}

Map::Map(std::string tmxFile, std::string tsxFile){
    nbLayers = 0;
    tileset = new Tileset;
    TmxLoadLayers(tmxFile);
    TsxLoadTileset(tsxFile);
    collisionLayer = new CollisionLayer;
    

}

Map::~Map(){
    delete collisionLayer;
    delete tileset;
}

void Map::SetTileset(const Tileset& ts){
    *tileset = ts;
}

void Map::AddMapLayer(const MapLayer & layer){
    mapLayers.push_back(layer);
    nbLayers++;
}

void Map::AddSpawnLayer(const SpawnsLayer& nLayer){
    spawnsLayer.push_back(nLayer);
}

Tileset Map::GetTileset() const{
    return *tileset;
}

std::vector<MapLayer> Map::GetMapLayers() const{
    return mapLayers;
}

int Map::GetNbMapLayers() const{
    return nbLayers;
}

void Map::TmxLoadLayers(std::string fileName){
    std::string strLayer;
    std::string strFile = fileToString(fileName);
    MapLayer tmp;

    int nbLayer = countTag(strFile, "layer");

    for(int i=0; i<nbLayer; i++){
        strLayer = getFullTag(strFile, "layer", i);
        tmp.rawDataToLayer(strLayer);
        AddMapLayer(tmp);
    }
}

void Map::TsxLoadTileset(std::string fileName){
    std::string strTileset = fileToString(fileName);
    Tileset tmp;
    tmp.rawDataToTileset(strTileset);
    
    SetTileset(tmp);
}

