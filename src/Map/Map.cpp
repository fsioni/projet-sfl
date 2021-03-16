#include "Map.h"
#include "tmxParsing.h"


Map::Map(){
    nbLayers = 0;
}

Map::Map(std::string tmxFile, std::string tsxFile){
    nbLayers = 0;
    TmxLoadLayers(tmxFile);
    TsxLoadTileset(tsxFile);
    collisionLayer = new CollisionLayer;
    tileset = new Tileset;

}

Map::~Map(){
    delete collisionLayer;
    delete tileset;
}

void Map::SetTileset(Tileset& ts){
    tileset = &ts;
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
    int start, end;
    start = strFile.find("<layer ", 0);
    end = strFile.find("</layer>", 0);

    while(start != (int)std::string::npos && end != (int)std::string::npos){
        strLayer = strFile.substr(start, end-start);
        tmp.rawDataToLayer(strLayer);

        AddMapLayer(tmp);

        start = strFile.find("<layer ", end+1);
        end = strFile.find("</layer>", end+1);
    }
}

void Map::TsxLoadTileset(std::string fileName){
    std::string strTileset = fileToString(fileName);
    Tileset tmp;
    tmp.rawDataToTileset(strTileset);
    SetTileset(tmp);
}




