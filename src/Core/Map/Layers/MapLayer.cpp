#include <iostream>
#include <assert.h>
#include "../tmxParsing.h"

#include "MapLayer.h"

MapLayer::MapLayer() : Layer(){
    width = -1;
    height = -1;
}

MapLayer::~MapLayer()
{
}

MapLayer::MapLayer(std::string rawData){
    // std::stoi(std::string) => int

    id = GetIntAttributeValue(rawData, "id");
    height = GetIntAttributeValue(rawData, "height");
    width = GetIntAttributeValue(rawData, "width");
    name = GetAttributeValue(rawData, "name");

    // On recupère les données entre <data> et </data>
    std::string strData = GetDataTag(rawData, "data", 0);

    // Appel de la fonction du module tmxParsing pour transformer
    // une string sous format CSV (Comma separated values) en un
    // tableau dynamique d'entier.
    data = CsvToInt(strData);
}

int MapLayer::GetWidth() const{
    return width;
}
int MapLayer::GetHeight() const{
    return height;
}

int MapLayer::GetData(int x, int y) const{
    return data[y * width + x];
}

void MapLayer::Test() const{
    std::cout << "===== Class MapLayer =====" << std::endl;

    std::cout << "MapLayer() : ";
    MapLayer mapLayer1;
    assert(mapLayer1.GetWidth()==-1);
    assert(mapLayer1.GetHeight()==-1);
    assert(mapLayer1.GetName()=="NULL");
    assert(mapLayer1.data.empty());
    std::cout << "ok"<<std::endl;

    std::cout << "MapLayer(std::string rawData) : ";
    std::string rawData = 
    std::string("<layer id=\"1\" name=\"Paths\" width=\"20\" height=\"20\">\n")+
        std::string("<data encoding=\"csv\">\n")+
            std::string("0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,5,5,0,0,0,\n")+
            std::string("0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,5,5,0,0,0,\n")+
            std::string("0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,5,5,0,0,0,\n")+
            std::string("5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,5,5,0,0,0,\n")+
            std::string("5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,5,5,0,0,0,\n")+
            std::string("0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,5,5,0,0,0,\n")+
            std::string("0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,5,5,0,0,0,\n")+
            std::string("0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,5,5,0,0,0,\n")+
            std::string("0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,5,5,0,0,0,\n")+
            std::string("0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,5,5,0,0,0,\n")+
            std::string("0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,\n")+
            std::string("0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,\n")+
            std::string("0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,\n")+
            std::string("0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,\n")+
            std::string("0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,5,5,5,5,5,\n")+
            std::string("0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,5,5,5,5,5,\n")+
            std::string("0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,\n")+
            std::string("0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,\n")+
            std::string("0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,\n")+
            std::string("0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0\n")+
        std::string("</data>\n")+
    std::string("</layer>\n");
    MapLayer mapLayer2(rawData);
    assert(mapLayer2.GetWidth()==20);
    assert(mapLayer2.GetHeight()==20);
    assert(mapLayer2.GetData(0, 0)==0);
    assert(mapLayer2.GetData(7, 0)==5);
    std::cout << "ok" << std::endl;

    std::cout << std::endl << std::endl;
}
