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

Tileset::~Tileset(){

}

void Tileset::rawDataToTileset(std::string rawData){
    name = getAttributeValue(rawData, "name");
    tileWidth = stoi(getAttributeValue(rawData, "tilewidth"));
    tileHeight = stoi(getAttributeValue(rawData, "tileheight"));
    tileCount = stoi(getAttributeValue(rawData, "tilecount"));
    column = stoi(getAttributeValue(rawData, "column"));

    // Chemin relatif au fichier tsx => chemin relatif 
    // au repertoire racine du projet
    std::string tsxPath = getAttributeValue(rawData, "source");
    tileMapPath = tsxPath.substr(5, tsxPath.length());
    tileMapPath = "/data"+tileMapPath;


    // Reduction du champs de recherche à partir de la balise <image>
    int posImage = rawData.find("<image ");
    rawData = rawData.substr(posImage, rawData.length());

    tileMapHeight = stoi(getAttributeValue(rawData, "height"));
    tileMapWidth = stoi(getAttributeValue(rawData, "width"));
}

void Tileset::display() const{
    std::cout << "Name : " << name << std::endl;
    std::cout << "TileWidth : " << tileWidth << std::endl;
    std::cout << "TileHeight : " << tileHeight << std::endl;
    std::cout << "TileCount : " << tileCount << std::endl;
    std::cout << "Column : " << column << std::endl;
    std::cout << "TileMapPath : " << tileMapPath << std::endl;
    std::cout << "TileMapWidth : " << tileMapWidth << std::endl;
    std::cout << "TileMapHeight : " << tileMapHeight << std::endl; 
}