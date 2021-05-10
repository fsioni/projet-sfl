#ifndef _MAP_
#define _MAP_

#include <vector>

#include "Tileset.h"
#include "Layers/CollisionLayer.h"
#include "Layers/MapLayer.h"
#include "Layers/SpawnsLayer.h"

/*! \class Map
*   \brief Classe stockant la map.
*
*   Possède toutes les informations sur la map comme les différents
*   layer ou encore le tileset.
*/
class Map
{
public:
    /*! \brief Constructeur par défaut */
    Map();

    /*! \brief Constructeur prennant en parametre un fichier .tmx et un .tsx.
    *
    *   \param [in] tmxFile : Chemin vers un fichier .tmx.
    *   \param [in] tsxFile : Chemin vers un fichier .tsx.
    *
    *   Appelle les fonctions tmxLoadLayers et TsxLoadTileset avec
    *   les fichiers passés en parametre.
    */
    Map(std::string tmxFile, std::string tsxFile);

    /*! \brief Destructeur
    *
    *   Détruit l'objet Map.
    */
    ~Map();

    /*! \brief Modifie tileset par celui en paramètre.
    *
    *   \param [in] ts : Tileset à copié dans tileset.
    */
    void SetTileset(const Tileset &ts);

    /*! \brief Ajout d'un MapLayer dans le tableau dynamique mapLayers.
    *
    *   \param [in] l : MapLayer à ajouter.
    */
    void AddMapLayer(const MapLayer &l);

    /*! \brief Retourne tileset
    *
    * \return La tileset de la Map.
    */
    Tileset *GetTileset() const;

    /*! \brief Retourne collisionLayers
    *
    * \return Le collisionLayers de la Map.
    */
    CollisionLayer *GetCollisionLayer() const;

    /*! \brief Retourne mapLayers
    *
    * \return Le tableau dynamique de MapLayers de la Map.
    */
    std::vector<MapLayer> GetMapLayers() const;

    /*! \brief Retourne spawnsLayers
    *
    * \return Le SpawnsLayers de la Map.
    */
    SpawnsLayer *GetSpawnsLayer() const;

    /*! \brief Charge les données d'un fichier .tmx.
    *
    *   \param [in] fileName : Chemin vers un fichier .tmx.
    *
    *   Recupère les informations contenu dans le fichier passé
    *   en paramètre et les affecte aux données membres associés.
    */
    void TmxLoadLayers(std::string fileName);

    /*! \brief Charge les données d'un fichier .tsx.
    *
    *   \param [in] fileName : Chemin vers un fichier .tsx.
    *
    *   Recupère les informations contenu dans le fichier passé
    *   en paramètre et les affecte aux données membres associés.
    */
    void TsxLoadTileset(std::string fileName);

    /*! \brief Fonction de test de la classe Map.
    *
    *   Effectue une série de test de regression sur l'ensemble des
    *   fonction membre pour vérifié qu'elles font ce qu'elles sont
    *   censé faire.
    */
    void Test() const;

private:
    /*! \brief Tableau dynamique de mapLayer, lesdifférentes couches de la map. */
    std::vector<MapLayer> mapLayers;

    /*! \brief  CollisionLayer contenant la couche des objets avec lequel les
    *           entités peuvent entrer en collision.
    */
    CollisionLayer *collisionLayer;

    /*! \brief   SpawnLayer contenant les positions du spawn du joueur et
    *            ceux des ennemis.
    */
    SpawnsLayer *spawnsLayer;

    /*! \brief   Tileset contenant des informations sur les tuiles. */
    Tileset *tileset;
};

#endif
