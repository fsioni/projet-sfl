#ifndef _TILESET_

#include <string>


class Tileset{
public:
    std::string name;
    int tileWidth;
    int tileHeight;
    int tileCount;
    int column;
    std::string tileMapPath;
    int tileMapWidth;
    int tileMapHeight;

    Tileset();
    ~Tileset();

    void rawDataToTileset(std::string rawData);
    void display() const;
};

#endif