#include <iostream>
#include "tmxParsing.h"
#include "assert.h"

#include "Tileset.h"

Tileset::Tileset()
{
    tileWidth = -1;
    tileHeight = -1;
    tileCount = -1;
    column = -1;
    tileMapPath = "NULL";
    tileMapWidth = -1;
    tileMapHeight = -1;
}

Tileset::Tileset(const Tileset &ts)
{
    tileHeight = ts.tileHeight;
    tileWidth = ts.tileWidth;
    tileCount = ts.tileCount;
    column = ts.column;
    tileMapPath = ts.tileMapPath;
    tileMapWidth = ts.tileMapWidth;
    tileMapHeight = ts.tileMapHeight;
}

Tileset::Tileset(std::string rawData)
{
    // On recupère ce qu'il y a dans la balise ouvrante <tileset>
    std::string tileSet = GetInsideTag(rawData, "tileset", 0);

    tileWidth = GetIntAttributeValue(tileSet, "tilewidth");
    tileHeight = GetIntAttributeValue(tileSet, "tileheight");
    tileCount = GetIntAttributeValue(tileSet, "tilecount");
    column = GetIntAttributeValue(tileSet, "column");

    // On recupère ce qu'il y a dans la balise ouvrante <image>
    std::string img = GetInsideTag(rawData, "image", 0);

    tileMapHeight = GetIntAttributeValue(img, "height");
    tileMapWidth = GetIntAttributeValue(img, "width");

    // Chemin relatif au fichier tsx => chemin relatif
    // au repertoire racine du projet
    std::string tsxPath = GetAttributeValue(img, "source");
    tileMapPath = tsxPath.substr(5, tsxPath.length());
    tileMapPath = "./data" + tileMapPath;
}

Tileset::~Tileset()
{
}

Tileset &Tileset::operator=(const Tileset &ts)
{
    if (&ts != this)
    {
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

int Tileset::GetTileWidth() const
{
    return tileWidth;
}

int Tileset::GetTileHeight() const
{
    return tileHeight;
}

int Tileset::GetTileCount() const
{
    return tileCount;
}

int Tileset::GetColumn() const
{
    return column;
}

std::string Tileset::GetTileMapPath() const
{
    return tileMapPath;
}

int Tileset::GetTileMapWidth() const
{
    return tileMapWidth;
}

int Tileset::GetTileMapHeight() const
{
    return tileMapHeight;
}

void Tileset::Test() const
{
    std::string rawData = "<tileset version=\"1.4\" tiledversion=\"1.4.3\"";
    rawData += " name=\"mainTileSet\" tilewidth=\"32\" tileheight=\"32\"";
    rawData += " tilecount=\"1064\" columns=\"8\">\n";
    rawData += " <image source=\"../../textures/tilesets/mainTileset.png\"";
    rawData += " width=\"256\" height=\"4256\"/>\n";
    rawData += "  </tileset>";
    std::cout << "===== Class Tileset =====" << std::endl;

    std::cout << "Constructeur Tileset(string rawData) : ";
    Tileset ts(rawData);
    assert(ts.GetColumn() == 8);
    assert(ts.GetTileCount() == 1064);
    assert(ts.GetTileWidth() == 32);
    assert(ts.GetTileHeight() == 32);
    assert(ts.GetTileMapPath() == "./data/textures/tilesets/mainTileset.png");
    assert(ts.GetTileMapWidth() == 256);
    assert(ts.GetTileMapHeight() == 4256);
    std::cout << "ok" << std::endl;

    std::cout << "Constructeur Tileset(const Tileset & ts) : ";
    Tileset ts2(ts);
    assert(ts2.GetColumn() == 8);
    assert(ts2.GetTileCount() == 1064);
    assert(ts2.GetTileWidth() == 32);
    assert(ts2.GetTileHeight() == 32);
    assert(ts2.GetTileMapPath() == "./data/textures/tilesets/mainTileset.png");
    assert(ts2.GetTileMapWidth() == 256);
    assert(ts2.GetTileMapHeight() == 4256);
    std::cout << "ok" << std::endl;

    std::cout << std::endl
              << std::endl;
}