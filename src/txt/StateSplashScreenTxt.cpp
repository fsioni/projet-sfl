#include "StateSplashScreenTxt.h"
#include "StateMenuTxt.h"
#include <unistd.h>
#include <memory>
#include <iostream>

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
    std::cout << std::endl
              << "Welcome in Legend of Nautibus" << std::endl
              << std::endl
              << "A game created by : " << std::endl
              << "SIONI Farès" << std::endl
              << "BAGNOL Stanislas " << std::endl
              << "CHOUGAR Lyes" << std::endl
              << std::flush;

    start = std::clock();
}

void StateSplashScreenTxt::ProcessInput()
{
}

void StateSplashScreenTxt::Update()
{
    duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

    if (duration > 3)
    {
        context->stateMan->Add(std::make_unique<StateMenuTxt>(context), true);
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
