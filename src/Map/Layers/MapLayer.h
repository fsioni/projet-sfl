#ifndef _MAP_LAYER_
#define _MAP_LAYER_

#include <string>
#include <vector>
#include "Layer.h"



/*! \class MapLayer
*   \brief Classe représentant une couche de tuiles.
*
*/ 

class MapLayer:Layer{
private:
    /*! \brief Largeur de la couche en nombre de tile */
    int width;
    /*! \brief Hauteur de la couche en nombre de tile */
    int height;
    /*! \brief Tableau dynamique contenant les données de la couche */
    std::vector<int> data;

public:
    /*! \brief Constructeur par défaut.
    *   Initialise id, width et height à -1,
    *   le nom est égale à "NULL".
    * */
    MapLayer();
    MapLayer(const MapLayer & layer);
    /*! \brief Destructeur. */
    ~MapLayer();

    MapLayer & operator=(const MapLayer & layer);

    // TODO ======== SETER ET GETER A COMMENTER =======
    
    void SetWidth(int width_);
    void SetHeight(int height_);
    void SetData(std::vector<int> data_);
    void SetData(int x, int y, int value);

    int GetWidth() const;
    int GetHeight() const;
    int GetData(int x, int y) const;
    std::vector<int> GetVectData() const;

    

    /*! \brief Assigne des données brut aux membres.
    *   \param [in] rawData : std::string, contenu brut des balises <layer></layer> d'un fichier .tmx.
    * 
    *   Effectue différente opération sur les std:string pour extraire 
    *   les informations des balises <layer></layer> et les stockés
    *   les membres de la class.
    */
    void rawDataToLayer(std::string rawData);

    /*! \brief Affiche les données membres dans la console.
    *   N'affiche seulement la première ligne de data
    *   pour éviter la surcharge d'information dans
    *   la console.
    */
    void Display() const;

    void Test() const;
};

#endif

