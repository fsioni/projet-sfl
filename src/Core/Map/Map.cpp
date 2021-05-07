#include "Map.h"
#include "tmxParsing.h"
#include <iostream>
#include <assert.h>
#include "Box.h"

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
    Box colBox;

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
    std::string strFile = FileToString(fileName);

    // MapLayers
    std::string strLayer;

    int nbLayer = CountTag(strFile, "layer");

    for (int i = 0; i < nbLayer; i++)
    {
        strLayer = GetFullTag(strFile, "layer", i);
        MapLayer tmp(strLayer);
        AddMapLayer(tmp);
    }

    // objectgroup => CollisionLayers + SpawnLayer
    int nbObjectgroup = CountTag(strFile, "objectgroup");
    int indCollision = 0;
    int indSpawnPlayer = 0;
    int indSpawnEnnemy = 0;
    int indSpawnNPC = 0;
    std::string tmpObjectGroup;
    std::string name;

    for (int i = 0; i < nbObjectgroup; i++)
    {
        tmpObjectGroup = GetInsideTag(strFile, "objectgroup", i);
        name = GetAttributeValue(tmpObjectGroup, "name");

        if(name == "Collision")
            indCollision = i;
        if(name == "EnemySpawn")
            indSpawnEnnemy = i;
        if(name == "PlayerSpawn")
            indSpawnPlayer = i;
        if(name == "NPCSpawn")
            indSpawnNPC = i;
    }

    std::string strCollisionLayer = GetFullTag(strFile, "objectgroup",
                                                indCollision);
    collisionLayer = new CollisionLayer(strCollisionLayer);

    std::string strPlayerSpawn = GetFullTag(strFile, "objectgroup",
                                            indSpawnPlayer);
    std::string strEnnemySpawn = GetFullTag(strFile, "objectgroup", 
                                            indSpawnEnnemy);
    std::string strNpcSpawn = GetFullTag(strFile, "objectgroup",
                                            indSpawnNPC);

    spawnsLayer = new SpawnsLayer(strPlayerSpawn, strEnnemySpawn, strNpcSpawn);
}

void Map::TsxLoadTileset(std::string fileName)
{
    std::string strTileset = FileToString(fileName);
    Tileset tmp(strTileset);

    SetTileset(tmp);
}

void Map::Test() const
{
    std::cout << "===== Class Map =====" << std::endl;
    std::string tmxFile = "data/maps/tilemaps/mapTestRegression.tmx";
    std::string tsxFile = "data/maps/tilesets/mainTileSet.tsx";
    Map map(tmxFile, tsxFile);
    std::cout << "TmxLoadLayers(std::string fileName) : " << std::endl;
    std::cout << "  -mapLayer : "; 
    assert(map.mapLayers.size()==3);
    assert(map.mapLayers[0].GetWidth()==20);
    assert(map.mapLayers[0].GetHeight()==20);
    std::cout << "ok" << std::endl;

    std::cout << "  -collisionLayer : ";
    // 5 collision dans le fichier + 
    // ajout "à la main" des 4 collision des bord de map
    assert(map.collisionLayer->GetCollisionBoxes().size()==5+4);
    std::cout << "ok" << std::endl;
    
    std::cout << "  -spawnLayer : ";
    // 3 spawn enemy dans le fichier
    assert(map.spawnsLayer->GetEnemySpawns().size()==3);
    // 3 spawn NPC dans le fichier
    assert(map.spawnsLayer->GetNPCSpawns().size()==3);
    // Test des valeurs du spawnPlayer
    assert(map.spawnsLayer->GetPlayerSpawn().GetX()==575);
    assert(map.spawnsLayer->GetPlayerSpawn().GetY()==473);
    std::cout << "ok" << std::endl;
  

    std::cout << "TsxLoadTileset(std::string fileName) : ";
    assert(map.tileset->GetTileWidth()==32);
    assert(map.tileset->GetTileHeight()==32);
    assert(map.tileset->GetTileCount()==1064);
    assert(map.tileset->GetColumn()==8);
    assert(map.tileset->GetTileMapHeight()==4256);
    assert(map.tileset->GetTileMapWidth()==256);
    assert(map.tileset->GetTileMapPath()=="./data/textures/tilesets/mainTileset.png");
    std::cout << "ok" << std::endl;


    std::cout << std::endl << std::endl;
}
