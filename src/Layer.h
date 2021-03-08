#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "tmxParsing.h"

/*! \class Layer
*   \brief Classe représentant une couche (layer).
*
*/ 

class Layer{
public :
    /*! \brief Idententifiant de la couche représenté par un entier. */
    int id;
    /*! \brief Nom de la couche. */
    std::string name;
    /*! \brief Largeur de la couche en nombre de tile */
    int width;
    /*! \brief Hauteur de la couche en nombre de tile */
    int height;
    /*! \brief Tableau dynamique contenant les données de la couche */
    std::vector<int> data;


    /*! \brief Constructeur par défaut.
    *   Initialise id, width et height à -1,
    *   le nom est égale à "NULL".
    * */
    Layer();
    /*! \brief Destructeur. */
    ~Layer();

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
    void display() const;


};

