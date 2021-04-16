#ifndef __STATE_MACHINE__
#define __STATE_MACHINE__

#include "StateBehavior.h"
#include "../Player.h"

template <class entity_type>
class StateMachine{
public:
    StateMachine(entity_type * owner_);
    void SetCurrentState(StateBehavior<entity_type> * s);
    void UpdateCurrentState(std::unique_ptr<Player> & player_, 
                            CollisionLayer * collision);
    void ChangeState(StateBehavior<entity_type> * newState);
    void RevertToPreviousState();

private:
    entity_type * owner;
    StateBehavior<entity_type> * currentState;
    StateBehavior<entity_type> * previousState;
};

// Definition dans le .h à cause des templates

template <class entity_type>
StateMachine<entity_type>::StateMachine(entity_type * owner_){
    owner = owner_;
    currentState = nullptr;
    previousState = nullptr;
}

template <class entity_type>
void StateMachine<entity_type>::SetCurrentState(StateBehavior<entity_type> * s){
    currentState = s;
}

template <class entity_type>
void StateMachine<entity_type>::UpdateCurrentState(
    std::unique_ptr<Player> & player_, CollisionLayer * collision){
    if(currentState) currentState->Execute(owner, player_, collision);
}

template <class entity_type>
void StateMachine<entity_type>::ChangeState(StateBehavior<entity_type> * newState){
    previousState = currentState;     
    currentState->Exit(owner);
    currentState = newState;
    currentState->Enter(owner);
}

template <class entity_type>
void StateMachine<entity_type>::RevertToPreviousState(){
    ChangeState(previousState);
}

#endif
