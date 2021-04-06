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
    /*! \brief Constructeur par défaut 
    *
    *   Initialise toutes les données de type int à -1
    *   et toutes celles de type string à "NULL".
    */
    Tileset();

    /*! \brief Constructeur par copie
    *
    * \param [in] ts : Tileset à copier.
    */
    Tileset(const Tileset & ts);

    /*! \brief Constructeur par copie
    *
    * \param [in] ts : Tileset à copier.
    */
    Tileset(std::string rawData);

    /*! \brief Destructeur
    *
    *   Détruit l'objet Tileset.
    */
    ~Tileset();


    /*! \brief Surcharge de l'opérateur =
    *
    * \param [in] ts : Tileset à copier
    */
    Tileset & operator=(const Tileset & ts);

    // TODO : soit à supprimer ou à documenter => en discuter avec les autres
    void SetName(std::string name_);    
    void SetTileWidth(int tw);
    void SetTileHeight(int th);
    void SetTileCount(int tc);
    void SetColumn(int col);
    void SetTileMapPath(std::string tmp);
    void SetTileMapWidth(int tmw);
    void SetTileMapHeight(int tmh);
    
    /*! \brief Retourne name
    *
    * \return Le nom du Tileset.
    */
    std::string GetName() const;

    /*! \brief Retourne tileWidth
    *
    * \return La largeur des tuiles
    */
    int GetTileWidth() const;

    /*! \brief Retourne tileHeight
    *
    * \return La hauteur des tuiles
    */
    int GetTileHeight() const;

    /*! \brief Retourne tileCount
    *
    * \return Le nombre total de tuile.
    */
    int GetTileCount() const;

    /*! \brief Retourne column
    *
    * \return Le nombre de colonne (= nombre de tuile par ligne).
    */
    int GetColumn() const;

    /*! \brief Retourne tileMapPath
    *
    * \return Le chemin et nom de la tileset (= image).
    */
    std::string GetTileMapPath() const;

    /*! \brief Retourne tileMapWidth
    *
    * \return Largeur de la tileset (= image). 
    */
    int GetTileMapWidth() const;

    /*! \brief Retourne tileMapHeight
    *
    * \return Hauteur de la tileset (= image). 
    */
    int GetTileMapHeight() const;

    /*! \brief Fonction de test de la classe Tileset.
    *
    *   Effectue une série de test de regression sur l'ensemble des
    *   fonction membre pour vérifié qu'elles font ce qu'elles sont
    *   censé faire.
    */
    void Test() const;
};

#endif