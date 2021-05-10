#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "EntityWithHP.h"
#include "FiniteStateMachine/StateMachine.h"
#include "FiniteStateMachine/EnemyStates.h"
#include <string>

// #include "Player.h" pose un problème de dépendance circulaire
class Player;

/*! \class Enemy
*   \brief Classe représentant un ennemi qui peut infliger/subir des dégats et se déplacer.
*
*   La classe représente un ennemi avec un nom, des points de vie, une position, des dégats d'attaque,
*   une vitesse et un cap maximum de points de vie.
*/
class Enemy : public EntityWithHP
{
public:
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

    /*! \brief Retourne le StateMachine.
    *   \return Pointeur sur StateMachine<Enemy>.
    */
    StateMachine<Enemy> *GetStateMachine() const;

    /*! \brief Update le StateMachine.
    *   
    *   \param [in] player_ : std::unique_ptr<Player>, le joueur.
    *   \param [in] collision : pointeur sur CollisionLayer, permet d'avoir accès
    *                           à la couche de collision pour les déplacements.
    *   \param [in] dt : entier positif, deltaTime.
    */
    void UpdateStateMachine(std::unique_ptr<Player> &player_,
                            CollisionLayer *collision, int dt);

    /*! \brief Affecte une EntityDirection aléatoire à l'Enemy.*/
    void RandDirection();

    /*! \brief Change la direction de l'Enemy.
    *   Utilise timeNextChangeDirection pour savoir si il est temps
    *   de changer de direction ou si le booléen de collision est true 
    *   alors on change la direction en utilisant RandDirection().
    *   
    *   \param [in] collision : booléen, Enemy en collision ou non.
    */
    void ChangeDirection(bool collision);

    /*! \brief Affecte à timeNextChangeDirection une valeur aléatoire.
    *   
    *   Affecte à timeNextChangeDirection l'heure actuelle + une valeur aléatoire
    *   pour définir une heure dans le future, le moment où l'Enemy pourra à nouveau
    *   changer de direction.
    */
    void SetTimeNextChangeDirection();

    /*! \brief Retourne si l'Enemy peut attaquer ou non.
    *
    *   Utilise la donnée membre timeNextAttack.
    *
    *   \return Retourne une booléen qui indique si l'Enemy peut attaquer à nouveau.
    */
    bool IsTimeToAttack();

    /*! \brief Affecte à timeNextAttack une valeur aléatoire.
    *   
    *   Affecte à timeNextAttack l'heure actuelle + une valeur aléatoire
    *   pour définir une heure dans le future, le moment où l'Enemy pourra à nouveau
    *   attaquer.
    */
    void SetTimeNextAttack();

    /*! \brief Fonction de test de regression.
    *
    *   Effectue une série de test pour vérifié que chaque
    *   fonctions fait ce qu'elle doit faire.
    */
    void Test() const;

private:
    /*! \brief Pointeur sur le StateMachine<Enemy>. */
    StateMachine<Enemy> *stateMachine;

    /*! \brief Heure du prochain changement de direction possible.
    *   Permet d'empecher l'Enemy de changer de direction trop souvent.
    */
    double timeNextChangeDirection;

    /*! \brief Heure de la prochaine attaque possible.
    *   Permet d'empecher l'Enemy d'attaquer en continu à chaque update.
    */
    double timeNextAttack;
};

#endif
