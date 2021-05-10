#ifndef __ENEMY_STATES__
#define __ENEMY_STATES__

#include "StateBehavior.h"
#include "../Enemy.h"

class Enemy;

// ======== ENEMY PATROL STATE ===========

/*! \class EnemyPatrol
*   \brief Etat de patrouille pour les Enemy, hérite de StateBehavior<Enemy>.
*
*   L'Enemy se balade sur la Map en prenant en compte les collisions et change 
*   de direction aléatoirement. Il entre dans l'état EnemyAttack si le joueur 
*   est à proximité.
*/
class EnemyPatrol : public StateBehavior<Enemy>
{
public:
    /*! \brief Constructeur par copie. */
    EnemyPatrol(const EnemyPatrol &other) = delete;

    /*! \brief Opérateur par copie. */
    void operator=(const EnemyPatrol &other) = delete;

    /*! \brief Retourne une Instance de l'objet, un singleton. */
    static EnemyPatrol *Instance();

    /*! \brief Entré dans l'état. */
    virtual void Enter(Enemy *enemy);

    /*! \brief Execution de l'état.
    *   L'Enemy se déplace aléatoirement et entre en état EnemyAttack 
    *   si le joueur est assez proche de lui.
    * 
    *   \param [in] enemy : pointeur sur Enemy, Enemy utilisé par l'état.
    *   \param [in] player_ : std::unique_ptr<Player>, le joueur.
    *   \param [in] collision : pointeur sur CollisionLayer, permet d'avoir accès
    *                           à la couche de collision pour les déplacements.
    *   \param [in] dt : entier positif, deltaTime.
    */
    virtual void Execute(Enemy *enemy, std::unique_ptr<Player> &player_,
                         CollisionLayer *collision, int dt);

    /*! \brief Sortie de l'état. */
    virtual void Exit(Enemy *enemy);

private:
    /*! \brief Constructeur par défaut. */
    EnemyPatrol(){};

    /*! \brief Singleton, instance unique de l'objet. */
    static EnemyPatrol *singleton;
};

// ======== ENEMY ATTACK STATE ===========
/*! \class EnemyAttack
*   \brief Etat d'attaque pour les Enemy, hérite de StateBehavior<Enemy>.
*
*   L'Enemy se déplace en direction du joueur et l'attaque si il est assez près.
*   Si le joueur s'éloigne trop il retourne en état EnemyPatrol et si sa vie descend
*   trop, il entre dans l'état EnemyRunAway.
*/
class EnemyAttack : public StateBehavior<Enemy>
{
public:
    /*! \brief Constructeur par copie. */
    EnemyAttack(const EnemyAttack &other) = delete;

    /*! \brief Opérateur par copie. */
    void operator=(const EnemyAttack &other) = delete;

    /*! \brief Retourne une Instance de l'objet, un singleton. */
    static EnemyAttack *Instance();

    /*! \brief Entré dans l'état. */
    virtual void Enter(Enemy *enemy);

    /*! \brief Execution de l'état.
    *   L'Enemy se déplace en direciton du Player, et si il est assez proche
    *   il l'attaque : inflige des dégats et le fait reculer (knockback).
    *   Si la vie de l'Enemy diminue trop, il entre dans l'état EnemyRunAway.
    * 
    *   \param [in] enemy : pointeur sur Enemy, Enemy utilisé par l'état.
    *   \param [in] player_ : std::unique_ptr<Player>, le joueur.
    *   \param [in] collision : pointeur sur CollisionLayer, permet d'avoir accès
    *                           à la couche de collision pour les déplacements.
    *   \param [in] dt : entier positif, deltaTime.
    */
    virtual void Execute(Enemy *enemy, std::unique_ptr<Player> &player_,
                         CollisionLayer *collision, int dt);

    /*! \brief Sortie de l'état. */
    virtual void Exit(Enemy *enemy);

private:
    /*! \brief Constructeur par défaut. */
    EnemyAttack(){};

    /*! \brief Singleton, instance unique de l'objet. */
    static EnemyAttack *singleton;
};

// ======== ENEMY RUNAWAY STATE ===========
/*! \class EnemyRunAway
*   \brief Etat de fuite pour les enemy, hérite de StateBehavior<Enemy>.
*
*   L'Enemy se déplace dans la direction opposé du joueur, si il est assez loin
*   du joueur il entre en état EnemyPatrol.
*/
class EnemyRunAway : public StateBehavior<Enemy>
{
public:
    /*! \brief Constructeur par copie. */  
    EnemyRunAway(const EnemyRunAway &other) = delete;

    /*! \brief Opérateur par copie. */
    void operator=(const EnemyRunAway &other) = delete;

    /*! \brief Retourne une Instance de l'objet, un singleton. */
    static EnemyRunAway *Instance();

    /*! \brief Entré dans l'état. 
    *   Augmente la vitesse de l'enemy.
    */
    virtual void Enter(Enemy *enemy);

    /*! \brief Execution de l'état.
    *   L'Enemy se déplace dans la direciton opposé du Player. Si il est assez loin,
    *   il entre dans l'état EnemyPatrol.
    * 
    *   \param [in] enemy : pointeur sur Enemy, Enemy utilisé par l'état.
    *   \param [in] player_ : std::unique_ptr<Player>, le joueur.
    *   \param [in] collision : pointeur sur CollisionLayer, permet d'avoir accès
    *                           à la couche de collision pour les déplacements.
    *   \param [in] dt : entier positif, deltaTime.
    */
    virtual void Execute(Enemy *enemy, std::unique_ptr<Player> &player_,
                         CollisionLayer *collision, int dt);

    /*! \brief Sortie de l'état. 
    *   Remet la vitesse à la normal.
    */
    virtual void Exit(Enemy *enemy);

private:
    /*! \brief Constructeur par défaut. */
    EnemyRunAway(){};

    /*! \brief Singleton, instance unique de l'objet. */
    static EnemyRunAway *singleton;
};

#endif