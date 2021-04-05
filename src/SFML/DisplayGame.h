#ifndef __DISPLAY_GAME_H__
#define __DISPLAY_GAME_H__

#include "../Core/Game.h"
#include "../Core/StateManager/State.h"
#include "AssetManager.h"

class DisplayGame : public State{
private:
    Game * game;
    AssetManager * assets;

    sf::Texture tileTexture, charTextures, shadowTexture, enemyTexture;
    sf::Sprite tileSprite, charSprite, shadowSprite, enemySprite;

public:
    DisplayGame();
    ~DisplayGame();

    void DisplaySFML() const;

    virtual void Init();

    virtual void CleanUp(); 

    virtual void Pause();

    virtual void Resume();

    virtual void GetEvents();

    virtual void Update();
    
    virtual void Display();

    virtual void Test();

};


#endif