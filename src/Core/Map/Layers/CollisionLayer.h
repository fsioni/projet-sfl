#ifndef _COLLISION_LAYER_
#define _COLLISION_LAYER_

#include <vector>
#include <string>

#include "Layer.h"
#include "../CollisionBox.h"


/*! \class CollisionLayer 
*   \brief Classe représentant une couche de CollisionBox
*   Hérité de Layer
*   Représente toutes les CollisionBox d'une partie particulière de la Map
*   Par exemple : des objets, des ennemis...
*/
class CollisionLayer:Layer{
private:
    /*// === Données membres privées === //*/

    /*! \brief Tableau dyanmique des CollisionBox du Layer. */
    std::vector<CollisionBox> collisionBoxes;

public:
    /*// === Fonctions membres privées === //*/
    
    /*! \brief Constructeur par défaut 
    *
    *   Ne suffit pas pour utilisation.
    */
    CollisionLayer(/* args */);

    /*! \brief Constructeur par balise
    *
    *   Créer une couche de CollisionBox en les récupérant d'une balise de la Tilemap
    *   \param [in] objectgroupTagCollision : balise object des CollisionBox de la Map
    */
    CollisionLayer(const std::string & objectgroupTagCollision);

    /*! \brief Destructeur
    *
    * Destructeur de l'objet CollisionLayer
    */
    ~CollisionLayer();

        /*! \brief Fonction permettant d'ajouter une boîte de collision à la couche
    *
    *   Ajoute une CollisionBox au tableau dynamique de l'objet
    *   \param [in] newSpawn : nouvelle CollisionBox ajoutée
    */
    void AddCollisionBox(const CollisionBox& newColBox);

    /*! \brief Fonction d'affichage de l'objet en mode texte
    *
    *   Affiche toutes les données de l'objet dans le terminal
    */
    void DisplayTXT() const;

    /*! \brief Fonction permettant de récupérer les CollisionBox de l'objet 
    *
    *   \return Retourne le tableau dynamique de CollisionBox
    */
    std::vector<CollisionBox> GetCollisionBoxes() const;

};


#endif