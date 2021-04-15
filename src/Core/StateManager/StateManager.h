#ifndef __STATEMANAGER_H__
#define __STATEMANAGER_H__

#include "State.h"
#include <stack>
#include <memory>

/*! \class StateManager 
*   \brief Classe représentant un gestionnaire d'états (State)
*
*   Possède un tas de State
*   Gère tous les passages d'un état à un autre
*   Exemple : Passage du SplashScreen au MainMenu, Pause du jeu pendant modification dans le menu...
*/
class StateManager
{
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
    
    /*! \brief Ajoute le State en paramètre à la pile
    *
    *   Met en pause l'état actuel et ajoute l'état en paramètre à la pile avant de le lancer
    *   \param [in] nID : State qui est lancé
    *   \param [in] replace : true si il doit remplacé le State actuel
    */
    void Add(std::unique_ptr<State> nState, bool replace_ = false);
    
    /*! \brief Passe au prochain State
    *
    *   Supprime le State courant et lance le suivant dans la pile
    */
    void PopCurrent();

    void ProcessStateChange();

    std::unique_ptr<State>& GetCurrent();
private:
    /*// === Données membres privées === //*/
    std::stack<std::unique_ptr<State>> sStates; //Tas d'états. Le dernier état du tableau est celui qui doit être joué
    std::unique_ptr<State> sNewState; //State en attente
    bool add;
    bool replace;
    bool remove;
};



#endif // __STATEMANAGER_H__