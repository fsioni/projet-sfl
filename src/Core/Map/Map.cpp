#include "Map.h"
#include "tmxParsing.h"
#include <iostream>
#include <assert.h>
#include "CollisionBox.h"

Map::Map()
{
}

Map::Map(std::string tmxFile, std::string tsxFile)
{
    tileset = new Tileset;
    TmxLoadLayers(tmxFile);
    TsxLoadTileset(tsxFile);

    // Info sur la taille de la map
    int w = mapLayers[0].GetWidth();
    int h = mapLayers[0].GetHeight();
    int tileW = tileset->GetTileWidth();
    int tileH = tileset->GetTileHeight();

    // Ajout de collisionBox tout autour de la Map
    CollisionBox colBox;

    // bottom colBox
    colBox.SetPosition(0, h * tileH - 10);
    colBox.SetDimensions(w * tileW, 1);
    collisionLayer->AddCollisionBox(colBox);

    // top colBox
    colBox.SetPosition(0, 5);
    colBox.SetDimensions(w * tileW, 1);
    collisionLayer->AddCollisionBox(colBox);

    // right colBox
    colBox.SetPosition(w * tileW, 0);
    colBox.SetDimensions(1, h * tileH);
    collisionLayer->AddCollisionBox(colBox);

    // left colBox
    colBox.SetPosition(0, 0);
    colBox.SetDimensions(1, h * tileH);
    collisionLayer->AddCollisionBox(colBox);
}

Map::~Map()
{
    delete collisionLayer;
    collisionLayer = nullptr;
    delete tileset;
    tileset = nullptr;
    delete spawnsLayer;
    spawnsLayer = nullptr;
}

void Map::SetTileset(const Tileset &ts)
{
    *tileset = ts;
}

void Map::AddMapLayer(const MapLayer &layer)
{
    mapLayers.push_back(layer);
}

void Map::SetSpawnLayer(const SpawnsLayer &nLayer)
{
    *spawnsLayer = nLayer;
}

Tileset *Map::GetTileset() const
{
    return tileset;
}

CollisionLayer *Map::GetCollisionLayer()
{
    return collisionLayer;
}

SpawnsLayer *Map::GetSpawnsLayer() const
{
    return spawnsLayer;
}

std::vector<MapLayer> Map::GetMapLayers() const
{
    return mapLayers;
}

void Map::TmxLoadLayers(std::string fileName)
{
    std::string strFile = fileToString(fileName);

    // MapLayers
    std::string strLayer;

    int nbLayer = countTag(strFile, "layer");

    for (int i = 0; i < nbLayer; i++)
    {
        strLayer = getFullTag(strFile, "layer", i);
        MapLayer tmp(strLayer);
        AddMapLayer(tmp);
    }

    // objectgroup => CollisionLayers + SpawnLayer
    int nbObjectgroup = countTag(strFile, "objectgroup");
    int indCollision = 0, indSpawnPlayer = 0, indSpawnEnnemy = 0;
    std::string tmpObjectGroup;
    std::string name;

    for (int i = 0; i < nbObjectgroup; i++)
    {
        tmpObjectGroup = getInsideTag(strFile, "objectgroup", i);
        name = getAttributeValue(tmpObjectGroup, "name");

        if (name == "Collision")
            indCollision = i;
        if (name == "EnemySpawn")
            indSpawnEnnemy = i;
        if (name == "PlayerSpawn")
            indSpawnPlayer = i;
    }

    std::string strCollisionLayer = getFullTag(strFile, "objectgroup",
                                                indCollision);
    collisionLayer = new CollisionLayer(strCollisionLayer);

    std::string strPlayerSpawn = getFullTag(strFile, "objectgroup",
                                            indSpawnPlayer);
    std::string strEnnemySpawn = getFullTag(strFile, "objectgroup", 
                                            indSpawnEnnemy);
    spawnsLayer = new SpawnsLayer(strPlayerSpawn, strEnnemySpawn);
}

void Map::TsxLoadTileset(std::string fileName)
{
    std::string strTileset = fileToString(fileName);
    Tileset tmp(strTileset);

    SetTileset(tmp);
}

void Map::Test() const
{
    std::string tmxFile = "data/maps/tilemaps/mainTilemap.tmx";
    std::string tsxFile = "data/maps/tilesets/mainTileSet.tsx";
    Map map(tmxFile, tsxFile);
}
