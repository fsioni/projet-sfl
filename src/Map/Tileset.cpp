#include <iostream>
#include "tmxParsing.h"

#include "Tileset.h"

Tileset::Tileset(){
    name = "NULL";
    tileWidth = -1;
    tileHeight = -1;
    tileCount = -1;
    column = -1;
    tileMapPath = "NULL";
    tileMapWidth = -1;
    tileMapHeight = -1;
}

Tileset::Tileset(const Tileset & ts){
    name = ts.name;
    tileHeight = ts.tileHeight;
    tileWidth = ts.tileWidth;
    tileCount = ts.tileCount;
    column = ts.column;
    tileMapPath = ts.tileMapPath;
    tileMapWidth = ts.tileMapWidth;
    tileMapHeight = ts.tileMapHeight;
}

Tileset::~Tileset(){

}

Tileset & Tileset::operator=(const Tileset & ts){
    if(&ts != this){
        name = ts.name;
        tileHeight = ts.tileHeight;
        tileWidth = ts.tileWidth;
        tileCount = ts.tileCount;
        column = ts.column;
        tileMapPath = ts.tileMapPath;
        tileMapWidth = ts.tileMapWidth;
        tileMapHeight = ts.tileMapHeight;
    }
    return *this;
}

// ====== SETERS ET GETERS =======
void Tileset::SetName(std::string name_){
    name = name_;
}    
void Tileset::SetTileWidth(int tw){
    tileWidth = tw;
}
void Tileset::SetTileHeight(int th){
    tileHeight = th;
}
void Tileset::SetTileCount(int tc){
    tileCount = tc;
}
void Tileset::SetColumn(int col){
    column = col;
}
void Tileset::SetTileMapPath(std::string tmp){
    tileMapPath = tmp;
}
void Tileset::SetTileMapWidth(int tmw){
    tileMapWidth = tmw;
}
void Tileset::SetTileMapHeight(int tmh){
    tileMapHeight = tmh;
}


std::string Tileset::GetName() const{
    return name;
}
int Tileset::GetTileWidth() const{
    return tileWidth;
}
int Tileset::GetTileHeight() const{
    return tileHeight;
}
int Tileset::GetTileCount() const{
    return tileCount;
}
int Tileset::GetColumn() const{
    return column;
}
std::string Tileset::GetTileMapPath() const{
    return tileMapPath;
}
int Tileset::GetTileMapWidth() const{
    return tileMapWidth;
}
int Tileset::GetTileMapHeight() const{
    return tileMapHeight;
}




void Tileset::rawDataToTileset(std::string rawData){
    // On recupère ce qu'il y a dans la balise ouvrante <tileset>
    std::string tileSet = getInsideTag(rawData, "tileset", 0);

    name = getAttributeValue(tileSet, "name");
    // std::stoi(std::string) => int
    tileWidth = stoi(getAttributeValue(tileSet, "tilewidth"));
    tileHeight = stoi(getAttributeValue(tileSet, "tileheight"));
    tileCount = stoi(getAttributeValue(tileSet, "tilecount"));
    column = stoi(getAttributeValue(tileSet, "column"));

    // On recupère ce qu'il y a dans la balise ouvrante <image>
    std::string img = getInsideTag(rawData, "image", 0);

    tileMapHeight = stoi(getAttributeValue(img, "height"));
    tileMapWidth = stoi(getAttributeValue(img, "width"));

    // Chemin relatif au fichier tsx => chemin relatif 
    // au repertoire racine du projet
    std::string tsxPath = getAttributeValue(img, "source");
    tileMapPath = tsxPath.substr(5, tsxPath.length());
    tileMapPath = "./data"+tileMapPath;

}

void Tileset::Display() const{
    std::cout << "Name : " << name << std::endl;
    std::cout << "TileWidth : " << tileWidth << std::endl;
    std::cout << "TileHeight : " << tileHeight << std::endl;
    std::cout << "TileCount : " << tileCount << std::endl;
    std::cout << "Column : " << column << std::endl;
    std::cout << "TileMapPath : " << tileMapPath << std::endl;
    std::cout << "TileMapWidth : " << tileMapWidth << std::endl;
    std::cout << "TileMapHeight : " << tileMapHeight << std::endl; 
}