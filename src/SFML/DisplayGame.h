#ifndef __DISPLAY_GAME_H__
#define __DISPLAY_GAME_H__

#include "../Core/Game.h"
#include "AssetManager.h"

class DisplayGame{
    Game * game;
    AssetManager * assets;

public:
    DisplayGame();
    ~DisplayGame();

    void DisplaySFML() const;

};


#endif