#ifndef _COLLISION_BOX_
#define _COLLISION_BOX_

#include "Box.h"

#include <string>

/*! \class CollisionBox 
*   \brief Classe représentant une boîte de collision dans un monde 2D
*
*   Possède des propriété basiques comme la position, dimension, ID. 
*   Hérité de la classe Box.
*/
class CollisionBox: public Box
{
public:
    /*// === Fonctions membres privées === //*/

    /*! \brief Constructeur par défaut 
    *
    *   Créer une CollisionBox quelconque avec ses données membres à -1.
    *   Ne suffit pas pour utilisation.
    */
    CollisionBox(/* args */);

    /*! \brief Constructeur depuis balise d'une map .tmx
    *
    * \param [in] objectTag : balise contenant les informations de la CollisionBox dans le .tmx.
    */
    CollisionBox(const std::string& objectTag);

    /*! \brief Constructeur depuis balise d'une map .tmx
    *
    * \param [in] x : Position sur l'axe X.
    * \param [in] y : Position sur l'axe Y.
    * \param [in] width : Largeur de la boite.
    * \param [in] height : Hauteur de la boite.
    */
    CollisionBox(float x, float y, float width, float height);
    
    /*! \brief Destructeur
    *
    * Destructeur de l'objet CollisionBox
    */
    ~CollisionBox();

    /*! \brief Fonction test de la classe CollisionBox
    *
    *   Effectue des tests pour vérifier l'intégrité de la classe CollisionBox et son fonctionnement
    */
    void Test() const;
};

#endif