#include "Game.h"
#include <stdio.h>
#include <assert.h>

Game::Game(/* args */)
{
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
        /* code */
        break;
    
    case 1: //mode txt
        break;

    default:
        break;
    }
}

void Game::KeyboardPressed(const char key) 
{
    switch (key)
    {
    case 'z':
        player.EntityMove(0,-1);
        break;
    case 's':
        player.EntityMove(0,1);
        break;
    case 'q':
        player.EntityMove(-1,0);
        break;
    case 'd':
        player.EntityMove(1,0);
        break;
    
    default:
        break;
    }
}

EntityWithHP Game::GetPlayerConst() const
{
    return player;
}

void Game::SetMap(Map nMap) 
{
    this->map = nMap;
}

void Game::Test() 
{
    
}