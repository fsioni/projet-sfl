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

    /*! \brief Retourne la largeur de la map.
    *   \return Un entier positif, la largeur de la map. 
    */
    int GetWidth() const;

    /*! \brief Retourne la hauteur de la map.
    *   \return Un entier positif, la hauteur de la map. 
    */
    int GetHeight() const;

    /*! \brief Retourne la valeur de la MapLayer au coordonnées (x, y).
    *   Converti les indices du tableau 1D en indice de tableau 2D.   
    *
    *   \return Un entier positif, la valeur de la map au coordonnées (x, y).
    */
    int GetData(int x, int y) const;

    /*! \brief Fonction de test de regression.
    *
    *   Effectue une série de test pour vérifié que chaque
    *   fonctions fait ce qu'elle doit faire.
    */
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
