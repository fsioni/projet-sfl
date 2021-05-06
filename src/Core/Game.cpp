#include "Game.h"
#include <stdio.h>
#include <assert.h>
#include "../SFML/StateSplashScreenSFML.h"
#include "../txt/StateSplashScreenTxt.h"
#include "Map/tmxParsing.h"

#include <iostream>

Game::Game(/* args */)
{
    context = std::make_shared<Context>();
}

Game::~Game()
{
}

void Game::Run(int mode)
{
    switch (mode)
    {
    case 0: //mode SFML
    {
        int winWidth = 700;
        int winHeight = 700;
        context->renderWin->create(sf::VideoMode(winWidth, winHeight, 32),
                                    "Legend Of Nautibus");
        context->stateMan->Add(std::make_unique<StateSplashScreenSFML>
                            (context));
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

    case 2:{
        EntityWithoutHP entityWithoutHP;
        entityWithoutHP.Test();

        EntityWithHP entityWithHP;
        entityWithHP.Test();

        Enemy enemy;
        enemy.Test();

        Player player;
        player.Test();

        Tileset tileset;
        tileset.Test();

        Box box;
        box.Test();

        CollisionBox collisionBox;
        collisionBox.Test();

        SpawnPoint spawnPoint;
        spawnPoint.Test();

        Layer layer;
        layer.Test();

        CollisionLayer collisionLayer;
        collisionLayer.Test();
        
        Map * map = new Map;
        map->Test();

        SpawnsLayer spawnsLayer;
        spawnsLayer.Test();

        MapLayer mapLayer;
        mapLayer.Test();

        UniqueID uniqueID;
        uniqueID.Test();

        
        testRegressionTmxParsing();

        std::cout << "TOUS LES TESTS ONT ETE PASSES AVEC SUCCES !" << std::endl;
        break;
    }

    default:
        break;
    }
}

void Game::Test()
{
}
