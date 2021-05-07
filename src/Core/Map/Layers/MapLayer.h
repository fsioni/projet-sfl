#ifndef _MAP_LAYER_
#define _MAP_LAYER_

#include <string>
#include <vector>

/*! \class MapLayer
*   \brief Classe représentant une couche de tuiles.
*
*/

class MapLayer{
public:
    /*! \brief Constructeur par défaut.
    *   Initialise id, width et height à -1,
    *   le nom est égale à "NULL". 
    */
    MapLayer();

    /*! \brief Constructeur avec data brut comme parametre.
    *   
    *   \param [in] rawData : std::string, contenu brut des balises <layer></layer> d'un fichier .tmx.
    * 
    *   Effectue différente opération sur les std:string pour extraire 
    *   les informations des balises <layer></layer> et les stockés
    *   les membres de la class.
    */
    MapLayer(std::string rawData);

    /*! \brief Destructeur. */
    ~MapLayer();

    int GetWidth() const;
    int GetHeight() const;
    int GetData(int x, int y) const;

    void Test() const;

private:
    /*! \brief Largeur de la couche en nombre de tile */
    int width;
    /*! \brief Hauteur de la couche en nombre de tile */
    int height;
    /*! \brief Tableau dynamique contenant les données de la couche */
    std::vector<int> data;
};

#endif
