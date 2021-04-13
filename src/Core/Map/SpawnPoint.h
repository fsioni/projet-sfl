#ifndef _SPAWN_POINT_
#define _SPAWN_POINT_

#include "Box.h"
#include <string>

/*! \class SpawnPoint 
*   \brief Classe représentant un point d'apparition dans un monde 2D
*
*   Possède des propriété basiques comme la position, dimension, ID. 
*   Hérité de Box.
*   Possède un nom. 
*/
class SpawnPoint: public Box
{
public:
    /*// === Fonctions membres publiques === //*/

    /*! \brief Constructeur par défaut 
    *
    * Créer un SpawnPoint quelconque avec ses données membres à -1 ou NULL.
    * Ne suffit pas pour utilisation.
    */
    SpawnPoint(/* args */);

    /*! \brief Constructeur depuis balise d'une map .tmx
    * \param [in] name : String contenant le nom du SpawnPoint
    * \param [in] objectTag : balise contenant les informations de la Box dans le .tmx.
    */
    SpawnPoint(const std::string& _name, const std::string& objectTag);

    /*! \brief Destructeur
    *
    * Destructeur de l'objet SpawnPoint
    */
    ~SpawnPoint();

    /*! \brief Modifie le du SpawnPoint par celui en paramètre
    *
    * \param [in] nName : nouveau nom du SpawnPoint
    */
    void SetName(const std::string& nName);

    /*! \brief Retourne anme
    *
    * \return Le nom du SpawnPoint
    */
    std::string GetName() const;

    /*! \brief Fonction test de la classe Box
    *
    *   Effectue des tests pour vérifier l'intégrité de la classe SpawnPoint et son fonctionnement
    */
    void Test() const;

private:
    /*// === Données membres privées === //*/

    /*! \brief Nom du SpawnPoint */
    std::string name;
};

#endif
