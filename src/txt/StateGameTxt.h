#ifndef __STATEGAMETXT_H__
#define __STATEGAMETXT_H__

#include "../Core/Game.h"
#include "../Core/StateManager/State.h"
#include "winTxt.h"
#include <memory>

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

    /*! \brief Permet le mouvement du joueur à travers le monde
    *   Prend en compte les collisions
    *
    *   \param [in] vx : Nombre de cases dont l'entité doit se déplacer sur l'axe horizontale
    *   \param [in] vy : Nombre de cases dont l'entité doit se déplacer sur l'axe verticale
    */
    void MoveWithCollision(float vx, float vy);

private:
    /*! \brief Etat courant du programme */
    std::shared_ptr<Context> context;
    /*! \brief Fenetre de jeu representée par des cases */
    std::unique_ptr<WinTXT> win;
};

#endif // __STATEGAMETXT_H__