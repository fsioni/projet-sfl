#ifndef __STATE_BEHAVIOR__
#define __STATE_BEHAVIOR__

#include "../Player.h"
#include "../../Map/Layers/CollisionLayer.h"
#include <memory>

/*! \class StateBehavior<entity_type>
*   \brief Base pour créer des états de comportement à utiliser dans le StateMachine.
*/
template <class entity_type>
class StateBehavior
{
public:
    /*! \brief Entré dans l'état.
    *   Peut modifier des valeur de entity type, par exemple
    *   la vitesse et ensuite la remettre à la normal dans Exit. 
    */
    virtual void Enter(entity_type *) = 0;

    /*! \brief Execution de l'état, fait une série d'action sur l'entity_type.
    *   
    *   \param [in] entity : pointeur sur entity_type, entité utilisé par l'état.
    *   \param [in] player_ : std::unique_ptr<Player>, le joueur.
    *   \param [in] collision : pointeur sur CollisionLayer, permet d'avoir accès
    *                           à la couche de collision pour les déplacements.
    *   \param [in] dt : entier positif, deltaTime.
    */
    virtual void Execute(entity_type * entity, std::unique_ptr<Player> &player_,
                         CollisionLayer *collision, int dt) = 0;

    /*! \brief Sortie de l'état.
    *   Peut remettre une valeur à la normal si modifié dans Enter par exemple. 
    */
    virtual void Exit(entity_type *) = 0;

    /*! \brief Destructeur */
    virtual ~StateBehavior(){};
};

#endif