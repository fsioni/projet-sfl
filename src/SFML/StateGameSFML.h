#ifndef __STATEGAMESFML_H__
#define __STATEGAMESFML_H__

#include "../Core/Game.h"
#include "../Core/StateManager/State.h"


class StateGameSFML : public State
{
public:
    StateGameSFML(/* args */);
    StateGameSFML(std::shared_ptr<Context> &cContext);
    ~StateGameSFML();

    void Init();

    void ProcessInput();

    void Update();

    void Display();

    void Pause();

    void Start();

    void MoveWithCollision(float vx, float vy);
private:
    std::shared_ptr<Context> context;

    sf::Texture tileTexture;
    sf::Sprite tileSprite, playerSprite, shadowSprite, enemySprite;

    // Horloge
    sf::Clock clock;
    int posX = 0;

    // Direction du joueur 
    // 0 : bas
    // 1 : gauche
    // 2 : droite 
    // 3 : haut
    //int direction = 2;

    // Position du joueur
    int playerX, playerY;
    // Info sur la tilemap
    int w, h, nbMapLayer, x, y, data;
    
    // Gestion de camera qui suit le joueur
    int substX, substY;

    //Taille de la fenêtre
    int winWidth, winHeight;

    //Taille de la map
    int mapWidth, mapHeight;
};

#endif // __STATEGAMESFML_H__