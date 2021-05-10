#ifndef __ANIMAL_STATES__
#define __ANIMAL_STATES__

#include "StateBehavior.h"
#include "../Animal.h"


// ======== ANIMAL WALKING STATE ===========

/*! \class AnimalWalking
*   \brief Etat de "balade" d'un Animal, il se déplace aléatoirement.
*
*   L'Animal se balade sur la Map en prenant en compte les collisions et change 
*   de direction aléatoirement. Il entre dans l'état AnimalFollowing si le joueur 
*   est à proximité.
*/
class AnimalWalking : public StateBehavior<Animal>
{
public:
    /*! \brief Constructeur par copie. */
    AnimalWalking(const AnimalWalking &other) = delete;

    /*! \brief Opérateur par copie. */
    void operator=(const AnimalWalking &other) = delete;

    /*! \brief Retourne une Instance de l'objet, un singleton. */
    static AnimalWalking *Instance();

    /*! \brief Entré dans l'état. */
    virtual void Enter(Animal *animal);

    /*! \brief Execution de l'état.
    *   L'Animal se déplace aléatoirement et entre en état AnimalFollowing 
    *   si le joueur est assez proche de lui.
    * 
    *   \param [in] animal : pointeur sur Animal, Animal utilisé par l'état.
    *   \param [in] player_ : std::unique_ptr<Player>, le joueur.
    *   \param [in] collision : pointeur sur CollisionLayer, permet d'avoir accès
    *                           à la couche de collision pour les déplacements.
    *   \param [in] dt : entier positif, deltaTime.
    */
    virtual void Execute(Animal *animal, std::unique_ptr<Player> &player_,
                         CollisionLayer *collision, int dt);

    /*! \brief Sortie de l'état. */
    virtual void Exit(Animal *animal);

private:
    /*! \brief Constructeur par défaut. */
    AnimalWalking(){};

    /*! \brief Singleton, instance unique de l'objet. */
    static AnimalWalking *singleton;
};

// ======== ANIMAL FOLLOWING STATE ===========

/*! \class AnimalFollowing
*   \brief Etat de suivi d'un Animal, il se déplace en direction du joueur, pour jouer ?
*
*   L'Animal se déplace en direction du joueur. Il entre en état AnimalWalking si il
*   le joueur s'éloigne trop.
*/
class AnimalFollowing : public StateBehavior<Animal>
{
public:
    /*! \brief Constructeur par copie. */
    AnimalFollowing(const AnimalFollowing &other) = delete;

    /*! \brief Opérateur par copie. */
    void operator=(const AnimalFollowing &other) = delete;

    /*! \brief Retourne une Instance de l'objet, un singleton. */
    static AnimalFollowing *Instance();

    /*! \brief Entré dans l'état. */
    virtual void Enter(Animal *animal);

    /*! \brief Execution de l'état.
    *   L'Animal se déplace en direction du joueur. Il entre en état
    *   AnimalWalking si il le joueur s'éloigne trop.
    * 
    *   \param [in] animal : pointeur sur Animal, Animal utilisé par l'état.
    *   \param [in] player_ : std::unique_ptr<Player>, le joueur.
    *   \param [in] collision : pointeur sur CollisionLayer, permet d'avoir accès
    *                           à la couche de collision pour les déplacements.
    *   \param [in] dt : entier positif, deltaTime.
    */
    virtual void Execute(Animal *animal, std::unique_ptr<Player> &player_,
                         CollisionLayer *collision, int dt);

    /*! \brief Sortie de l'état. */
    virtual void Exit(Animal *animal);

private:
    /*! \brief Constructeur par défaut. */
    AnimalFollowing(){};

    /*! \brief Singleton, instance unique de l'objet. */
    static AnimalFollowing *singleton;
};


#endif