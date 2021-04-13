#ifndef __STATESPLASHSCREENTXT_H__
#define __STATESPLASHSCREENTXT_H__

#include "../Core/StateManager/State.h"
#include "../Core/Game.h"
#include <memory>
#include <ctime>

class StateSplashScreenTxt : public State
{
public:
    StateSplashScreenTxt(/* args */);
    StateSplashScreenTxt(std::shared_ptr<Context> &cContext);
    ~StateSplashScreenTxt();

    void Init();

    void ProcessInput();

    void Update();

    void Display();

    void Pause();

    void Start();
private:
    std::shared_ptr<Context> context;

    std::clock_t start;
    double duration;
};


#endif // __STATESPLASHSCREENTXT_H__