#ifndef _TILESET_
#define _TILESET_

#include <string>

/*! \class Tileset 
*   \brief Classe représentant un tileset 
*          (ensemble de tuile stocké sur une image).
*
*   Possède toutes les informations sur le tileset comme la taille
*   en pixel des tuiles, le nombre de tuile par ligne ou le chemin
*   vers l'image.
*/
class Tileset{
    /*! \brief  Nom du tileset. */
    std::string name;

    /*! \brief  Largeur des tuiles en pixel. */
    int tileWidth;

    /*! \brief  Longueur des tuiles en pixel. */
    int tileHeight;

    /*! \brief  Nombre de tuile dans le tileset. */
    int tileCount;

    /*! \brief  Nombre de tuile par ligne (= nombre de colonnes). */
    int column;

    /*! \brief  Chemin et nom de la tileset (= image). */
    std::string tileMapPath;

    /*! \brief  Largeur de la tileset (= image). */
    int tileMapWidth;

    /*! \brief  Longueur de la tileset (= image).*/
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