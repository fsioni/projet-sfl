#include <string>
#include <iostream>
#include "tmxParsing.h"

class Tileset{
    std::string name;
    int tileWidth;
    int tileHeight;
    int tileCount;
    int column;
    std::string tileMapPath;
    int tileMapWidth;
    int tileMapHeight;
public:
    Tileset();
    ~Tileset();

    void rawDataToTileset(std::string rawData);
    void display() const;
};