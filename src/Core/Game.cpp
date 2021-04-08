#include "Game.h"
#include <stdio.h>
#include <assert.h>
#include "../SFML/StateSplashScreenSFML.h"
#include "../txt/StateSplashScreenTxt.h"

#include <iostream>

Game::Game(/* args */)
{
    context = make_shared<Context>();

    // Initialisation des ennemies
    int count = context->map->GetSpawnsLayer().getEnemySpawns().size();

    for(int i = 0; i<count; i++){
        int x = context->map->GetSpawnsLayer().getEnemySpawns()[i].GetX();
        int y = context->map->GetSpawnsLayer().getEnemySpawns()[i].GetY();

        Enemy tmpEnemy(x, y, "Enemy", 10, 3, 5, 100);

        context->enemies.push_back(tmpEnemy);
    }



    context->isDebug = false;
}


Game::~Game()
{
}

void Game::Run(int mode) 
{
    assert(mode==0 || mode == 1);
    switch (mode)
    {
    case 0: //mode SFML
    {
        int winWidth = 700;
        int winHeight = 700;
        context->renderWin->create(sf::VideoMode(winWidth, winHeight, 32), "Legend Of Nautibus", sf::Style::Close);
        context->stateMan->Add(std::make_unique<StateSplashScreenSFML>(context));
        while (!context->quit)
        {
            context->stateMan->ProcessStateChange();
            context->stateMan->GetCurrent()->ProcessInput();
            context->stateMan->GetCurrent()->Update();
            context->stateMan->GetCurrent()->Display();
        }
    break;
    }
    
    case 1: //mode txt
        context->stateMan->Add(std::make_unique<StateSplashScreenTxt>(context));
        while (!context->quit)
        {
            context->stateMan->ProcessStateChange();
            context->stateMan->GetCurrent()->ProcessInput();
            context->stateMan->GetCurrent()->Update();
            context->stateMan->GetCurrent()->Display();
        }
    break;

    default:
    break;

    }
}


Player Game::GetPlayerConst() const
{
    //return context->player;
}

std::vector<Enemy> Game::GetEnemiesConst() const{
    return context->enemies;
}

Map& Game::GetMapConst() const
{
    //return context->*map;
}


sf::RenderWindow* Game::GetWindow() 
{
    //return &window;
}

void Game::Test() 
{
    
}