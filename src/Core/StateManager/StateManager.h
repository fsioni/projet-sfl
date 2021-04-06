#ifndef __STATEMANAGER_H__
#define __STATEMANAGER_H__

#include "State.h"
#include <vector>

/*! \class StateManager 
*   \brief Classe représentant un gestionnaire d'états (State)
*
*   Possède un tas de State
*   Gère tous les passages d'un état à un autre
*   Exemple : Passage du SplashScreen au MainMenu, Pause du jeu pendant modification dans le menu...
*/
class StateManager
{
private:
    /*// === Données membres privées === //*/
    std::vector<State*> sStates; //Tas d'états représenté par un tableau dynamique. Le dernier état du tableau est celui qui doit être joué
public:
    /*// === Fonctions membres publiques === //*/

    /*! \brief Constructeur par défaut 
    *
    */
    StateManager(/* args */);

    /*! \brief Destructeur
    *
    *   Destructeur de l'objet StateManager
    */
    ~StateManager();

    /*! \brief Change le State courant par celui en paramètre
    *
    *   Supprime le State courant et ajoute le State en paramètre à la pile avant de le lancer
    *   \param [in] nState : State qui est lancé
    */
    void ChangeState(State* nState);
    
    /*! \brief Pause le State courant. Lance celui en paramètre
    *
    *   Met en pause l'état actuel et ajoute l'état en paramètre à la pile avant de le lancer
    *   \param [in] nID : State qui est lancé
    */
    void PushState(State* nState);
    
    /*! \brief Passe au prochain State
    *
    *   Supprime le State courant et lance le suivant dans la pile
    */
    void PopState();
    
    /*! \brief Vide le tas de State
    *
    */
    void Clear();
};



#endif // __STATEMANAGER_H__