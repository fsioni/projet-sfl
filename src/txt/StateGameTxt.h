#ifndef __STATEGAMETXT_H__
#define __STATEGAMETXT_H__

#include "../Core/Game.h"
#include "../Core/StateManager/State.h"
#include "winTxt.h"
#include <memory>

/*! \class StateGameTxt 
*   \brief Classe représentant l'état jeu du mode texte
* 
*/
class StateGameTxt : public State
{
public:
    StateGameTxt(/* args */);
    StateGameTxt(std::shared_ptr<Context> &cContext);
    ~StateGameTxt();

    void Init();

    void ProcessInput();

    void Update();

    void Display();

    void Pause();

    void Start();

private:
    /*! \brief Etat courant du programme */
    std::shared_ptr<Context> context;
    /*! \brief Fenetre de jeu representée par des cases */
    std::unique_ptr<WinTXT> win;
};

#endif // __STATEGAMETXT_H__