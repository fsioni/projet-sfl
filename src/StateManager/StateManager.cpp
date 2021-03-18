#include "StateManager.h"

StateManager::StateManager(/* args */) 
{
    
}


StateManager::~StateManager() 
{
    
}

void StateManager::ChangeState(State* state) 
{
    //Efface l'ancien état
    if (!sStates.empty())
    {
        sStates.back()->CleanUp();
        sStates.pop_back();
    }

    //Ajoute le nouvel état à la pile et l'initialise
    sStates.push_back(state);
    sStates.back()->Init();
}

void StateManager::PushState(State* state) 
{
    if (!sStates.empty())
        sStates.back()->Pause();

    sStates.push_back(state);
    sStates.back()->Init();
}

void StateManager::PopState() 
{
    if (!sStates.empty())
    {
        sStates.back()->CleanUp();
        sStates.pop_back();
    }

    if (!sStates.empty())
    {
        sStates.back()->Resume();
    }
}

void StateManager::Clear() 
{
    while (!sStates.empty())
    {
        sStates.back()->CleanUp();
        sStates.pop_back();
    }
    
}

