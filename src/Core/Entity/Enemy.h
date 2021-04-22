#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "EntityWithHP.h"
#include "FiniteStateMachine/StateMachine.h"
#include "FiniteStateMachine/EnemyStates.h"
#include "Player.h"
#include <string>

using namespace std;


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
    *   200 de maxHealth et une vitesse de 1,0 (entité vide).
    *
    */
    Enemy();

    /*! \brief Constructeur avec spécifités d'un Enemy en paramètre.
    *   \param [in] x : réel positif, position de l'Enemy  sur l'axe X (horizontal).
    *   \param [in] y : réel positif, position de l'Enemy  sur l'axe Y (vertical).
    *   \param [in] name : chaine de caractères, nom de l'Enemy.
    *   \param [in] hp : entier positif, nombre de points de vie de l'Enemy.
    *   \param [in] dammage : entier positif, nombre de points de vie infligé lors d'une attaque.
    *   \param [in] maxHealth : entier positif, maximum de points de vie qu'une Enemy peut avoir.
    *   \param [in] livingStatus : Booléen, définissant si l'Enemy  est mort ou pas.
    *   \param [in] speed : réel positif, vitesse de déplacement de l'Enemy.
    *
    *
    *   Créer un Enemy (x, y, name, hp, dammage, maxHealth, livingStatus, speed)
    *
    */
    Enemy(int x_, int y_, string name_, int hp_, int damage_,
          int speed_, int maxHealth_);


    /*! \brief Destructeur.
    *
    *  Destructeur de la classe Enemy.
    *
    */
    ~Enemy();

    StateMachine<Enemy>* GetStateMachine() const;

    void UpdateStateMachine(std::unique_ptr<Player> & player_, 
                            CollisionLayer * collision, int dt);

    int GetNbUpdateMaxChangeDir() const;
    int GetNbUpdateChangeDir() const;
    void SetNbUpdateChangeDir();
    void DecrementNbUpdateChangeDir();
    void RandDirection();

    void Test() const;

private:
    StateMachine<Enemy> * stateMachine;
    int nbUpdateMaxChangeDir;
    int nbUpdateChangeDir;
    
};

#endif
