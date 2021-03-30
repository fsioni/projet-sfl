#ifndef _TILESET_
#define _TILESET_

#include <string>


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
    Tileset(const Tileset & ts);
    ~Tileset();

    Tileset & operator=(const Tileset & ts);

    // ====== SETERS ET GETERS =======
    void SetName(std::string name_);    
    void SetTileWidth(int tw);
    void SetTileHeight(int th);
    void SetTileCount(int tc);
    void SetColumn(int col);
    void SetTileMapPath(std::string tmp);
    void SetTileMapWidth(int tmw);
    void SetTileMapHeight(int tmh);


    std::string GetName() const;
    int GetTileWidth() const;
    int GetTileHeight() const;
    int GetTileCount() const;
    int GetColumn() const;
    std::string GetTileMapPath() const;
    int GetTileMapWidth() const;
    int GetTileMapHeight() const;


    void rawDataToTileset(std::string rawData);
    void Test() const;
    void Display() const;
};

#endif