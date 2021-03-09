#ifndef _TILESET_

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
    ~Tileset();

    // ====== SETERS ET GETERS =======
    void SetName(std::string name_);    
    void SetTileWidth(int tw);
    void SetTileHeight(int th);
    void SetTileCount(int tc);
    void SetColumn(int col);
    void SetTileMapPath(int tmp);
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
    void display() const;
};

#endif