#ifndef _COLLISION_LAYER_
#define _COLLISION_LAYER_

#include <vector>
#include <string>
#include <memory>
#include <map>

#include "../Box.h"

/*! \class CollisionLayer
*   \brief Classe représentant une couche de CollisionBox
*
*   Représente toutes les CollisionBox d'une partie particulière de la Map
*   Par exemple : des objets, des ennemis...
*/
class CollisionLayer{
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
    CollisionLayer(const std::string &objectgroupTagCollision);

    /*! \brief Destructeur
    *
    * Destructeur de l'objet CollisionLayer
    */
    ~CollisionLayer();

    /*! \brief Fonction permettant d'ajouter une boîte de collision à la couche
    *
    *   Ajoute une CollisionBox au tableau dynamique de l'objet
    *   \param [in] newSpawn : nouvelle CollisionBox ajoutée.
    */
    void AddCollisionBox(const Box &newColBox);

    /*! \brief Fonction permettant d'ajouter une boîte de
    *           collision d'entité à la couche
    *
    *   Ajoute une CollisionBox au tableau dynamique des collisions
    *   des entités à l'objet
    *   \param [in] id : entier, identifiant de l'entité.
    *   \param [in] newSpawn : nouvelle CollisionBox ajoutée.
    */
    void AddCollisionBoxEntity(int id, Box* newColBox);

    /*! \brief Fonction d'affichage de l'objet en mode texte
    *
    *   Affiche toutes les données de l'objet dans le terminal
    */
    void DisplayTXT() const;

    /*! \brief Fonction permettant de récupérer les CollisionBox de l'objet.
    *
    *   \return Retourne le tableau dynamique de CollisionBox.
    */
    std::vector<Box> GetCollisionBoxes() const;

    /*! \brief Fonction permettant de récupérer les CollisionBox
    *         des entités de l'objet
    *
    *   \return Retourne le tableau associatif de CollisionBox*.
    */
    std::map<int, Box*> GetCollisionBoxesEntity() const;

    /*! \brief Permet de savoir si une clé existe.
    *
    *   \param [in] id : entier, clé de la CollisionBox * à tester.
    *
    *   \return Retourne true si la clé existe et false sinon.
    */
    bool  CollisionBoxEntityExist(int id) const;

    /*! \brief Supprime la CollisionBox d'une entité.
    *
    *   \param [in] id : id de l'entité dont on veut supprimer la CollisionBox.
    */
    void DeleteACollisionBoxEntity(int id);

    /*! \brief Test de regression.
    *
    *   Effectue une série de test sur les fonctions de la classe
    *   et vérifie qu'elles font bien ce qu'elles sont censés faire.
    */
    void Test() const;

private:
    /*// === Données membres privées === //*/

    /*! \brief Tableau dyanmique des Box de la Map. */
    std::vector<Box> collisionBoxes;

    /*! \brief Tableau associatif des Box des entités.
    *
    *    La clé est un entier correspondant à l'ID de l'entité
    *    et le pointeur sur Box est sa boite de collision
    *    associé.
    */
    std::map<int, Box*> collisionBoxesEntity;
};

#endif
