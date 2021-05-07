#ifndef __STATEMENUTXT_H__
#define __STATEMENUTXT_H__

#include "../Core/StateManager/State.h"
#include "../Core/Game.h"
#include <memory>

/*! \class StateMenuTxt 
*   \brief Classe représentant l'état menu du mode texte
* 
*/
class StateMenuTxt : public State
{
public:
    StateMenuTxt(/* args */);
    StateMenuTxt(std::shared_ptr<Context> &cContext);
    ~StateMenuTxt();

    void Init();

    void ProcessInput();

    void Update();

    void Display();

    void Pause();

    void Start();

    void DisplayMenu();

private:
    /*! \brief Etat courant du programme */
    std::shared_ptr<Context> context;
    /*! \brief Choix de l'utilisateur */
    int menu;
};

#endif // __STATEMENUTXT_H__