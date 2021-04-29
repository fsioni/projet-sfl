#include <iostream>
#include "tmxParsing.h"
#include "assert.h"

#include "Tileset.h"

Tileset::Tileset()
{
    name = "NULL";
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
    name = ts.name;
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
    tileMapPath = "./data" + tileMapPath;
}

Tileset::~Tileset()
{
}

Tileset &Tileset::operator=(const Tileset &ts)
{
    if (&ts != this)
    {
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
void Tileset::SetName(std::string name_)
{
    name = name_;
}
void Tileset::SetTileWidth(int tw)
{
    tileWidth = tw;
}
void Tileset::SetTileHeight(int th)
{
    tileHeight = th;
}
void Tileset::SetTileCount(int tc)
{
    tileCount = tc;
}
void Tileset::SetColumn(int col)
{
    column = col;
}
void Tileset::SetTileMapPath(std::string tmp)
{
    tileMapPath = tmp;
}
void Tileset::SetTileMapWidth(int tmw)
{
    tileMapWidth = tmw;
}
void Tileset::SetTileMapHeight(int tmh)
{
    tileMapHeight = tmh;
}

std::string Tileset::GetName() const
{
    return name;
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
    assert(ts.GetName() == "mainTileSet");
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
    assert(ts2.GetName() == "mainTileSet");
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