#ifndef ENTITYWITHOUTHP_H
#define ENTITYWITHOUTHP_H

#include <string>
#include <iostream>

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
    *   \param [in] x : réel positif, position de l'entité sur l'axe X (horizontale).
    *   \param [in] y : réel positif, position de l'entité sur l'axe Y (verticale).
    *   \param [in] name : chaine de caractères, nom de l'entité.
    *
    *   Créer une EntityWithoutHP (x, y, name)
    *
    */

    EntityWithoutHP(float x, float y, string name);


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

    float GetPos_x() const;


    /*! \brief Permets de modifier la position sur l'axe des x de l'entité (horizontale).
    *
    *
    *   \param [in] newX: réel positif, nouvelle position sur l'axe des x de l'entité.
    *
    */

    void SetPos_x(float newX);


    /*! \brief Retourne la position sur l'axe des y de l'entité (verticale).
    *
    *  Retourne un réel y, une position sur l'axe des y de l'entité (verticale).
    *
    *
    */

    float GetPos_y() const;


    /*! \brief Permets de modifier la position sur l'axe des y de l'entité (verticale).
    *
    *
    *   \param [in] newY: réel positif, nouvelle position sur l'axe des y de l'entité.
    *
    */

    void SetPos_y(float newY);

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


    /*! \brief Permet d'imprimer sur la console des informations générales concernant l'entité.
    *
    *   Imprime sur la console des informations concernant l'entité.
    *
    *
    */
    virtual void PrintEntityInfo();

    /*! \brief Retourne l'offset de l'entité
    *
    */
    int getOffset() const;

    /*! \brief Modifier l'offset actuel de l'entité
    *
    *
    *   \param [in] newO: Entier, nouvel offset de l'entité.
    *
    */
    void setOffset(int newO);

    EntityDirection GetDirection() const;

    /*! \brief Modifier la direction actuel de l'entité
    *
    *
    *   \param [in] nDirection: Nouvel direction de l'entité..
    *
    */
    void SetDirection(EntityDirection nDirection);

protected :
    /*// ==== Données membres protégées === //*/

    /*! \brief Position sur l'axe des x de l'entité (horizontal).*/
    float x;

    /*! \brief Position sur l'axe des y de l'entité (vertical). */
    float y;

    /*! \brief Décalage de la l'arête de la boite de collision de l'entité par rapport à
    son centre */
    int offset;

    /*! \brief Nom de l'entité */
    string name;

    /*! \brief Direction vers laquelle l'entité est dirigée. */
    EntityDirection direction;
};

#endif
