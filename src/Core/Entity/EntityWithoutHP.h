#ifndef ENTITYWITHOUTHP_H
#define ENTITYWITHOUTHP_H

#include <string>
#include <iostream>
#include <memory>
#include "../Map/CollisionBox.h"

using namespace std;
 
enum EntityDirection{
    Down, 
    Left,
    Right,
    Up
};

/*! \class EntityWithoutHP
*   \brief Classe représentant une entité immobile et immortel.
*
*   La classe représente une entité avec une position et un nom.
*
*/
class EntityWithoutHP
{
public:

    /*// ==== Fonctions membres publiques === //*/

    /*! \brief Constructeur par défaut.
    *
    *
    *   Créer une entité EntityWithoutHP avec une position x 0.0, une position y 0.0, un nom "Unknown" (entité vide).
    *
    */

    EntityWithoutHP();


    /*! \brief Constructeur avec spécifités de l'entité en paramètre.
    *   \param [in] x_ : réel positif, position de l'entité sur l'axe X (horizontale).
    *   \param [in] y_ : réel positif, position de l'entité sur l'axe Y (verticale).
    *   \param [in] speed_ : réel positif, vitesse de l'entité?.
    *   \param [in] name_ : chaine de caractères, nom de l'entité.
    *
    *   Créer une EntityWithoutHP (x_, y_, speed_, name_).
    */
    EntityWithoutHP(int x_, int y_, int speed_, string name_);


    /*! \brief Destructeur.
    *
    *  Destructeur de la classe EntityWithoutHP.
    *
    */

    virtual ~EntityWithoutHP();


    /*! \brief Retourne la position sur l'axe des x de l'entité (horizontale).
    *
    *  Retourne un réel x, une position sur l'axe des x de l'entité (horizontale).
    *
    *
    */

    int GetPos_x() const;


    /*! \brief Permets de modifier la position sur l'axe des x de l'entité (horizontale).
    *
    *
    *   \param [in] newX: réel positif, nouvelle position sur l'axe des x de l'entité.
    *
    */

    void SetPos_x(int newX);


    /*! \brief Retourne la position sur l'axe des y de l'entité (verticale).
    *
    *  Retourne un réel y, une position sur l'axe des y de l'entité (verticale).
    *
    *
    */

    int GetPos_y() const;


    /*! \brief Permets de modifier la position sur l'axe des y de l'entité (verticale).
    *
    *
    *   \param [in] newY: réel positif, nouvelle position sur l'axe des y de l'entité.
    *
    */

    void SetPos_y(int newY);

    /*! \brief Retourne le nom de l'entité.
    *
    *   Retourne une chaine de caractères, le nom de l'entité.
    *
    *
    */
    string GetName() const;

    /*! \brief Permets de modifier le nom de l'entité.
    *
    *
    *   \param [in] newName: chaine de caractères, nouveau nom de l'entité.
    *
    */

    void SetName(string newName);

    std::shared_ptr<CollisionBox> GetCollisionBox();


    /*! \brief Permet d'imprimer sur la console des informations générales concernant l'entité.
    *
    *   Imprime sur la console des informations concernant l'entité.
    *
    *
    */
    virtual void PrintEntityInfo();

    void Test() const;

    int GetOffset() const;
    void SetOffset(int newO);

    int GetSpeed() const;
    void SetSpeed(int newSpeed);

    EntityDirection GetDirection() const;

    void SetDirection(EntityDirection nDirection);
    void SetDirection(float vx, float vy);

    void Move(float vx, float vy);

protected :
    /*// ==== Données membres protégées === //*/

    /*! \brief Position sur l'axe des x de l'entité (horizontal).*/
    int x;

    /*! \brief Position sur l'axe des y de l'entité (vertical). */
    int y;

    /*! \brief Vitesse de l'entité */
    int speed;

    int width;

    int height;

    std::shared_ptr<CollisionBox> cb;

    int offset; // For collision detection

    /*! \brief Nom de l'entité */
    string name;

    EntityDirection direction;
};

#endif
