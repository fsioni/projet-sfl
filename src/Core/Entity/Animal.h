#ifndef ANIMAL_H
#define ANIMAL_H

#include "EntityWithoutHP.h"

/*! \class Animal
*   \brief Classe représentant une entité qui se déplace aléatoirement.
*
*   La classe représente un Animal avec un nom et une position.
*
*/
class Animal : public EntityWithoutHP
{
public:

    /*! \brief Constructeur par défaut.
    *
    *
    *   Créer un Animal avec une position x 0.0, une position y 0.0, un nom "Unknown".
    *
    */
    Animal();

    /*! \brief Constructeur avec spécifités d'un Animal en paramètre.
    *   \param [in] x : réel positif, position de l'Animal sur l'axe X (horizontal).
    *   \param [in] y : réel positif, position de l'Animal sur l'axe Y (vertical).
    *   \param [in] name : chaine de caractères, nom de l'Animal.
    *
    *
    *   Créer un Animal (x, y, name)
    *
    */
    Animal(float x, float y, std::string name);

    /*! \brief Destructeur.
    *
    *  Destructeur de la classe Animal.
    *
    */
    ~Animal();

    /*! \brief Retourne une direction aléatoire.
    *
    *   Permets de retouner une direction aléatoire.
    *
    */
    EntityDirection RandDirection();


    /*! \brief Permets à un Animal de se déplacer aléatoirement.
    *   \param [in] vx : réel positif, vitesse de déplacement de l'Animal sur l'axe X (horizontal).
    *   \param [in] vy : réel positif, vitesse de déplacement de l'Animal sur l'axe Y (vertical).
    *
    *
    *   Permets à un animal de se déplacer avec une vitesse vx sur l'axe X (horizontal) et d'une vitesse vy sur l'axe Y (vertical).
    *
    */
    void MoveRandomly(float vx, float vy);
};
#endif // ANIMAL_H
