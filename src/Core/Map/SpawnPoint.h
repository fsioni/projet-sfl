#ifndef _SPAWN_POINT_
#define _SPAWN_POINT_

#include "Box.h"
#include <string>

/*! \class SpawnPoint 
*   \brief Classe représentant un point d'apparition dans un monde 2D
*
*   Possède une position sur un plan 2D : x et y.
*/
class SpawnPoint{
public:
    /*// === Fonctions membres publiques === //*/

    /*! \brief Constructeur par défaut 
    *
    * Créer un SpawnPoint quelconque avec ses données membres à -1 ou NULL.
    * Ne suffit pas pour utilisation.
    */
    SpawnPoint(/* args */);

    /*! \brief Constructeur depuis balise d'une map .tmx
    * 
    * \param [in] objectTag : balise contenant les informations du spawn dans le .tmx.
    */
    SpawnPoint(const std::string &objectTag);

    /*! \brief Destructeur
    *
    * Destructeur de l'objet SpawnPoint
    */
    ~SpawnPoint();

    /*! \brief Retourne x. */
    int GetX()const;

    /*! \brief Retourne y. */
    int GetY()const;

    /*! \brief Fonction test de la classe Box
    *
    *   Effectue des tests pour vérifier l'intégrité de la classe SpawnPoint et son fonctionnement
    */
    void Test() const;

private:
    /*! \brief Position sur l'axe X. */
    int x;

    /*! \brief Position sur l'axe X. */
    int y;
};

#endif
