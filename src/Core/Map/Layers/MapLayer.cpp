#include <iostream>
#include "../tmxParsing.h"

#include "MapLayer.h"

MapLayer::MapLayer()
{
    id = -1;
    name = "NULL";
    width = -1;
    height = -1;
}

MapLayer::~MapLayer()
{
}

MapLayer::MapLayer(const MapLayer &layer)
{
    id = layer.id;
    name = layer.name;
    width = layer.width;
    height = layer.height;
    data = layer.data;
}

MapLayer::MapLayer(std::string rawData)
{
    // std::stoi(std::string) => int

    id = std::stoi(getAttributeValue(rawData, "id"));
    height = std::stoi(getAttributeValue(rawData, "height"));
    width = std::stoi(getAttributeValue(rawData, "width"));
    name = getAttributeValue(rawData, "name");

    // On recupère les données entre <data> et </data>
    std::string strData = getDataTag(rawData, "data", 0);

    // Appel de la fonction du module tmxParsing pour transformer
    // une string sous format CSV (Comma separated values) en un
    // tableau dynamique d'entier.
    data = csvToInt(strData);
}

MapLayer &MapLayer::operator=(const MapLayer &layer)
{
    if (&layer != this)
    {
        id = layer.id;
        name = layer.name;
        width = layer.width;
        height = layer.height;
        data = layer.data;
    }
    return *this;
}

// ==== SETERS ====

void MapLayer::SetWidth(int width_)
{
    width = width_;
}

void MapLayer::SetHeight(int height_)
{
    height = height_;
}
void MapLayer::SetData(std::vector<int> data_)
{
    data = data_;
}
void MapLayer::SetData(int x, int y, int value)
{
    data[y * width + x] = value;
}

// ==== GETERS ====

int MapLayer::GetWidth() const
{
    return width;
}
int MapLayer::GetHeight() const
{
    return height;
}
int MapLayer::GetData(int x, int y) const
{
    return data[y * width + x];
}
std::vector<int> MapLayer::GetVectData() const
{
    return data;
}

void MapLayer::Test() const
{
}
