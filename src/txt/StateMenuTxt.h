#ifndef __STATEMENUTXT_H__
#define __STATEMENUTXT_H__

#include "../Core/StateManager/State.h"
#include "../Core/Game.h"
#include <memory>

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
    std::shared_ptr<Context> context;
    int menu;
};

#endif // __STATEMENUTXT_H__