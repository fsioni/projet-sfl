#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "EntityWithHP.h"
#include "FiniteStateMachine/StateMachine.h"
#include "FiniteStateMachine/EnemyStates.h"
#include "Player.h"
#include <string>



/*! \class Enemy
*   \brief Classe représentant un ennemi qui peut infliger/subir des dégats et se déplacer.
*
*   La classe représente un ennemi avec un nom, des points de vie, une position, des dégats d'attaque,
*   une vitesse et un cap maximum de points de vie.
*/
class Enemy : public EntityWithHP
{
public :
    /*// ==== Fonctions membres publiques === //*/

    /*! \brief Constructeur par défaut.
    *
    *
    *   Créer un Enemy avec une position x 0.0, une position y 0.0, un nom "Unknown", 100 hp, 30 de damage,
    *   200 de maxHP et une vitesse de 1,0 (entité vide).
    *
    */
    Enemy();

    /*! \brief Constructeur avec spécifités d'un Enemy en paramètre.
    *   \param [in] x : réel positif, position de l'Enemy  sur l'axe X (horizontal).
    *   \param [in] y : réel positif, position de l'Enemy  sur l'axe Y (vertical).
    *   \param [in] name : chaine de caractères, nom de l'Enemy.
    *   \param [in] hp : entier, nombre de points de vie de l'Enemy.
    *   \param [in] dammage : entier, nombre de points de vie infligé lors d'une attaque.
    *   \param [in] maxHP : entier, maximum de points de vie qu'une Enemy peut avoir.
    *   \param [in] livingStatus : Booléen, définissant si l'Enemy  est mort ou pas.
    *   \param [in] speed : réel positif, vitesse de déplacement de l'Enemy.
    *
    *
    *   Créer un Enemy (x, y, name, hp, dammage, maxHP, livingStatus, speed)
    *
    */
    Enemy(float x_, float y_, std::string name_, int hp_, int damage_,
          int speed_, int maxHP_);


    /*! \brief Destructeur.
    *
    *  Destructeur de la classe Enemy.
    *
    */
    ~Enemy();

    StateMachine<Enemy>* GetStateMachine() const;

    void UpdateStateMachine(std::unique_ptr<Player> & player_,
                            CollisionLayer * collision, int dt);


    void RandDirection();
    void ChangeDirection(bool collision);
    void SetTimeNextChangeDirection();

    bool IsTimeToAttack();
    void SetTimeNextAttack();

    void Test() const;

private:
    StateMachine<Enemy> * stateMachine;
    double timeNextChangeDirection;
    double timeNextAttack;

};

#endif
