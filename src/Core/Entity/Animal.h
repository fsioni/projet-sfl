#ifndef ANIMAL_H
#define ANIMAL_H

#include "EntityWithoutHP.h"
#include "FiniteStateMachine/StateMachine.h"

/*! \class Animal
*   \brief Représente un animal, hérite de EntityWithouHP.
*
*/
class Animal : public EntityWithoutHP
{
    /*! \brief Constructeur par défaut. */
    Animal();


    /*! \brief Constructeur paramétré.
    *
    *   \param [in] x : entier positif, position sur l'axe x.
    *   \param [in] y : entier positif, position sur l'axe y.
    *   \param [in] speed : entier positif, vitesse.
    */
    Animal(float x, float y, float speed);


    /*! \brief Destructeur. */
    ~Animal();


    /*! \brief Retourne le StateMachine.
    *   \return Pointeur sur StateMachine<Animal>.
    */
    StateMachine<Animal> *GetStateMachine() const;


    /*! \brief Update le StateMachine.
    *
    *   \param [in] player_ : std::unique_ptr<Player>, le joueur.
    *   \param [in] collision : pointeur sur CollisionLayer, permet d'avoir accès
    *                           à la couche de collision pour les déplacements.
    *   \param [in] dt : entier positif, deltaTime.
    */
    void UpdateStateMachine(std::unique_ptr<Player> &player_,
                            CollisionLayer *collision, int dt);

    /*! \brief Affecte une EntityDirection aléatoire à l'Animal.*/
    void RandDirection();

    /*! \brief Change la direction de l'Animal.
    *   Utilise timeNextChangeDirection pour savoir si il est temps
    *   de changer de direction ou si le booléen de collision est true
    *   alors on change la direction en utilisant RandDirection().
    *
    *   \param [in] collision : booléen, Animal en collision ou non.
    */
    void ChangeDirection(bool collision);

    /*! \brief Affecte à timeNextChangeDirection une valeur aléatoire.
    *
    *   Affecte à timeNextChangeDirection l'heure actuelle + une valeur aléatoire
    *   pour définir une heure dans le future, le moment où l'Enemy pourra à nouveau
    *   changer de direction.
    */
    void SetTimeNextChangeDirection();

    /*! \brief Fonction de test de regression.
    *
    *   Effectue une série de test pour vérifié que chaque
    *   fonctions fait ce qu'elle doit faire.
    */
    void Test() const;
private:

    /*! \brief Pointeur sur le StateMachine<Animal>. */
    StateMachine<Animal> *stateMachine;


    /*! \brief Heure du prochain changement de direction possible.
    *   Permet d'empecher l'Enemy de changer de direction trop souvent.
    */
    double timeNextChangeDirection;

};
#endif // ANIMAL_H
