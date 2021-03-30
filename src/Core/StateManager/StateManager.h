#ifndef __STATEMANAGER_H__
#define __STATEMANAGER_H__

#include "State.h"
#include <vector>

class StateManager
{
private:
    std::vector<State*> sStates; //Pile d'états représenté par un tableau dynamique. Le dernier état du tableau est celui qui doit être joué
public:
    StateManager(/* args */);
    ~StateManager();

    void ChangeState(State* state); //Supprime l'état courant et ajoute l'état en paramètre à la pile avant de le lancer
    void PushState(State* state); //Met en pause l'état actuel et ajoute l'état en paramètre à la pile avant de le lancer
    void PopState(); //Supprime l'état courant et lance le suivant dans la pile
    void Clear(); //Vide le tas
};



#endif // __STATEMANAGER_H__