#ifndef __STATE_MACHINE__
#define __STATE_MACHINE__

#include "StateBehavior.h"
#include "../Player.h"

#include <iostream>
#include <assert.h>

/*! \class StateMachine<entity_type> 
*   \brief Modélise un Finite State Machine (FSM) qui permet de
*          créer des comportement prédéfinit pour des entité.
*/
template <class entity_type>
class StateMachine
{
public:
    /*! \brief Constructeur prenant un pointeur sur entity_type en paramètre.*/
    StateMachine(entity_type *owner_);

    /*! \brief Modifie l'état courrant par celui passé en paramètre.
    *   \param [in] s : Pointeur sur StateBehavior<entity_type>. 
    */
    void SetCurrentState(StateBehavior<entity_type> *s);

    /*! \brief Actualise l'état courrant. 
    *
    *   \param [in] player_ : std::unique_ptr<Player>, le joueur.
    *   \param [in] collision : pointeur sur CollisionLayer, permet d'avoir accès
    *                           à la couche de collision pour les déplacements.
    *   \param [in] dt : entier positif, deltaTime.
    */
    void UpdateCurrentState(std::unique_ptr<Player> &player_,
                            CollisionLayer *collision, int dt);

    /*! \brief Permet de changer l'état courrant.
    *   \param [in] newState : pointeur sur StateBehavior<entity_type>, nouveau currentState.
    */
    void ChangeState(StateBehavior<entity_type> *newState);

    /*! \brief Fonction de test de regression.
    *
    *   Effectue une série de test pour vérifié que chaque
    *   fonctions fait ce qu'elle doit faire.
    */
    void Test() const;

private:
    /*! \brief Pointeur sur l'entité du StateMachine. */
    entity_type *owner;
    /*! \brief Pointeur sur l'état courrant. */
    StateBehavior<entity_type> *currentState;
};

// Definition dans le .h à cause des templates

template <class entity_type>
StateMachine<entity_type>::StateMachine(entity_type *owner_)
{
    owner = owner_;
    currentState = nullptr;
}

template <class entity_type>
void StateMachine<entity_type>::SetCurrentState(StateBehavior<entity_type> *s)
{
    currentState = s;
}

template <class entity_type>
void StateMachine<entity_type>::UpdateCurrentState(
    std::unique_ptr<Player> &player_, CollisionLayer *collision, int dt)
{
    if (currentState)
        currentState->Execute(owner, player_, collision, dt);
}

template <class entity_type>
void StateMachine<entity_type>::ChangeState(StateBehavior<entity_type> *newState)
{
    currentState->Exit(owner);
    currentState = newState;
    currentState->Enter(owner);
}

template <class entity_type>
void StateMachine<entity_type>::Test() const{
    std::cout << "===== Class StateMachine<entity_type> =====" << std::endl;
    std::cout << "StateMachine(entity_type *owner_) : ";
    entity_type * entity = new entity_type;
    StateMachine<entity_type> stateMachine(entity);
    assert(stateMachine.owner==entity);
    assert(stateMachine.currentState==nullptr);
    std::cout << "ok" << std::endl;

    std::cout << std::endl << std::endl;
}

#endif
