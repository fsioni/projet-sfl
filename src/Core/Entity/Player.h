#ifndef PLAYER_H
#define PLAYER_H

#include "EntityWithHP.h"
#include <string>

// #include "Enemy.h" pose un problème de dépendance circulaire
class Enemy;

/*! \class Player
*   \brief Classe représentant un joueur qui peut infliger/subir des dégats et se déplacer.
*
*   La classe représente un joueur avec un nom, des points de vie, une position, des dégats d'attaque,
*   une vitesse et un cap maximum de points de vie.
*
*/
class Player : public EntityWithHP
{
public:
    /*// ==== Fonctions membres publiques === //*/

    /*! \brief Constructeur par défaut.
    *
    *
    *   Créer un Player avec une position x 0.0, une position y 0.0, un nom "Unknown", 200 hp, 20 de damage,
    *   200 de maxHP et une vitesse de 1,0 (entité vide).
    *
    */
    Player();

    /*! \brief Constructeur avec spécifités d'un Player en paramètre.
    *   \param [in] x : réel positif, position du Player sur l'axe X (horizontal).
    *   \param [in] y : réel positif, position du Player sur l'axe Y (vertical).
    *   \param [in] hp : entier, nombre de points de vie du Player.
    *   \param [in] dammage : entier, nombre de points de vie infligé lors d'une attaque.
    *   \param [in] maxHP : entier, maximum de points de vie qu'un Player peut avoir.
    *   \param [in] livingStatus : Booléen, définissant si le Player est mort ou pas.
    *   \param [in] speed : réel positif, vitesse de déplacement du Player.
    *
    *
    *   Créer un Player (x, y, name, hp, dammage, maxHP, livingStatus, speed)
    *
    */
    Player(float x, float y, int hp, int damage,
           float speed, int maxHP);

    /*! \brief Destructeur.
    *
    *  Destructeur de la classe Player.
    *
    */
    ~Player();


    /*! \brief Calcul de distance avec un enemy.
    *   
    *   \param [in] enemy : std::shared_ptr sur Enemy, 
    *                       Enemy dont on veut connaitre la distance.
    * 
    *   \return La distance entre le joueur et un Enemy.
    */
    float DistanceShared_ptr(std::shared_ptr<Enemy> enemy) const;

    /*! \brief Le joueur attaque un enemy.
    *   
    *   Test si l'Enemy est dans le rayon d'attaque du joueur,
    *   si oui, il lui inflige des dégats et le fait reculer.
    * 
    *   \param [in] enemy : std::shared_ptr sur Enemy, Enemy à attaquer.
    *   \param [in] colLayer : pointeur sur CollisionLayer, pour faire reculer 
    *                       l'Enemy en prenant en compte les collisions.
    */
    void Attack(std::shared_ptr<Enemy> enemy, CollisionLayer * colLayer) const;


    /*! \brief Fonction de test de regression.
    *
    *   Effectue une série de test pour vérifié que chaque
    *   fonctions fait ce qu'elle doit faire.
    */
    void Test() const;
};
#endif
