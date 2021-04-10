#ifndef __STATE_MACHINE__
#define __STATE_MACHINE__

#include "StateBehavior.h"


template <class entity_type>
class StateMachine{
private:
    entity_type * owner;

    StateBehavior<entity_type> * currentState;
    StateBehavior<entity_type> * previousState;
    StateBehavior<entity_type> * globalState;

public:
    StateMachine(entity_type * owner_);
    
    void SetCurrentState(StateBehavior<entity_type> * s);
    void SetPreviousState(StateBehavior<entity_type> * s);
    void SetGlobalState(StateBehavior<entity_type> * s);

    StateBehavior<entity_type> * GetCurrentState() const;
    StateBehavior<entity_type> * GetPreviousState() const;
    StateBehavior<entity_type> * GetGlobalState() const;

    entity_type * GetOwner() const;

    void Update();
    void ChangeState(StateBehavior<entity_type> * newState);
    void RevertToPreviousState();
};

// Definition dans le .h à cause des templates

template <class entity_type>
StateMachine<entity_type>::StateMachine(entity_type * owner_){
    owner = owner_;
    
    currentState = nullptr;
    previousState = nullptr;
    globalState = nullptr;
}



template <class entity_type>
void StateMachine<entity_type>::SetCurrentState(StateBehavior<entity_type> * s){
    currentState = s;
}

template <class entity_type>
void StateMachine<entity_type>::SetPreviousState(StateBehavior<entity_type> * s){
    previousState = s;
}


template <class entity_type>
void StateMachine<entity_type>::SetGlobalState(StateBehavior<entity_type> * s){
    globalState = s;
}


template <class entity_type>
void StateMachine<entity_type>::Update(){
    if(currentState) currentState->Execute(owner);
    
    if(globalState) globalState->Execute(owner);
}

template <class entity_type>
void StateMachine<entity_type>::ChangeState(StateBehavior<entity_type> * newState){
    // Sauvegarde de l'état sortant
    previousState = currentState;

    // Exit de l'état sortant
    currentState->Exit(owner);

    // Change l'état courant vers le nouvel état
    currentState = newState;

    // Appelle de Enter sur le nouvel état courant
    currentState->Enter(owner);
}

template <class entity_type>
void StateMachine<entity_type>::RevertToPreviousState(){
    ChangeState(previousState);
}

template <class entity_type>
StateBehavior<entity_type> * StateMachine<entity_type>::GetCurrentState() const{
    return currentState;
}

template <class entity_type>
StateBehavior<entity_type> * StateMachine<entity_type>::GetPreviousState() const{
    return previousState;
}


template <class entity_type>
StateBehavior<entity_type> * StateMachine<entity_type>::GetGlobalState() const{
    return globalState;
}


template <class entity_type>
entity_type * StateMachine<entity_type>::GetOwner() const{
     return owner;
 }

#endif
