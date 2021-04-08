#ifndef __STATEGAMETXT_H__
#define __STATEGAMETXT_H__

#include "../Core/Game.h"
#include "../Core/StateManager/State.h"
#include "winTxt.h"
#include <memory>

class StateGameTxt : public State
{
private:
    std::shared_ptr<Context> context;
    unique_ptr<WinTXT> win;
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

    void MoveWithCollision(float vx, float vy);
};

#endif // __STATEGAMETXT_H__