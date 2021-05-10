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
    *   \param [in] nState : State qui est lancé
    *   \param [in] replace : true si il doit remplacé le State actuel
    */
    void Add(std::unique_ptr<State> nState, bool replace_ = false);

    /*! \brief Passe au prochain State
    *
    *   Supprime le State courant et lance le suivant dans la pile
    */
    void PopCurrent();

    /*! \brief Gère les changements de States
    *
    */
    void ProcessStateChange();

    /*! \brief Renvoie le State en cours d'execution
    *
    * \return Le State actuel
    */
    std::unique_ptr<State> &GetCurrent();

    /*! \brief Fonction test de la classe StateManager
    *
    *   Effectue des tests pour vérifier l'intégrité de la classe StateManager et son fonctionnement
    */
    void Test() const;

private:
    /*! \brief Tas d'états. Le dernier état du tableau est celui qui doit être joué */
    std::stack<std::unique_ptr<State>> sStates;
    /*! \brief State en attente */
    std::unique_ptr<State> sNewState;

    /*! \brief Indique si un état a été ajouté */
    bool add;
    /*! \brief Indique si l'état courant doit être remplacé */
    bool replace;
    /*! \brief Indique si l'état courant doit être supprimé */
    bool remove;
};

#endif // __STATEMANAGER_H__
