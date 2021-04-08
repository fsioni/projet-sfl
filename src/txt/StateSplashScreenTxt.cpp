#include "StateSplashScreenTxt.h"
#include "StateMenuTxt.h"
#include <unistd.h>
#include <memory>
#include <iostream>
using namespace std;

StateSplashScreenTxt::StateSplashScreenTxt(/* args */) 
{
    
}

StateSplashScreenTxt::StateSplashScreenTxt(std::shared_ptr<Context> &cContext) 
    : context(cContext)
{
    
}

StateSplashScreenTxt::~StateSplashScreenTxt() 
{
    
}

void StateSplashScreenTxt::Init() 
{
    cout << endl << "Welcome in Legend of Nautibus" << endl
    << endl << "A game created by : " << endl << "SIONI Farès" <<
    endl << "BAGNOL Stanislas " << endl << "CHOUGAR Lyes" << endl << flush;

    start = std::clock();
}

void StateSplashScreenTxt::ProcessInput() 
{
    
}

void StateSplashScreenTxt::Update() 
{
    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;

    if (duration > 3)
    {
        context->stateMan->Add(make_unique<StateMenuTxt>(context), true);
    }
}

void StateSplashScreenTxt::Display() 
{
    
}

void StateSplashScreenTxt::Pause() 
{
    
}

void StateSplashScreenTxt::Start() 
{
    
}
