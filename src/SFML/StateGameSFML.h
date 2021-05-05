#ifndef __STATEGAMESFML_H__
#define __STATEGAMESFML_H__

#include "../Core/Game.h"
#include "../Core/StateManager/State.h"
#include <SFML/Audio.hpp>
#include <memory>

class StateGameSFML : public State
{
public:
    StateGameSFML(/* args */);
    StateGameSFML(std::shared_ptr<Context> &cContext);
    ~StateGameSFML();

    void Init();

    void ProcessInput();

    void Update();
    void UpdatePlayer();
    void UpdateEnemies();
    void UpdateNPCs();

    void Display();
    void DisplayMap();
    void DisplayPlayer();
    void DisplayEnemies();
    void DisplayNPC();
    void DisplayCollisionBox(
        CollisionBox * cb, const sf::Color & color, int id);
    void DisplayDebug();

    void Pause();

    void Start();

    void MovePlayerWithCollision(float vx, float vy);

private:
    std::shared_ptr<Context> context;

    sf::Texture tileTexture;
    sf::Sprite tileSprite, playerSprite, shadowSprite, enemySprite;

    // Horloge pour le delta time
    sf::Clock deltaClock;
    float deltaTime;

    // Horloge pour l'animation du sprite
    sf::Clock spriteClock;
    int posX = 0;

    // Horloge pour les fps
    sf::Clock fpsClock;
    int fps;

    // Position du joueur
    int playerX, playerY;

    // Direction mouvement du joueur
    bool isGoingUp, isGoingDown, isGoingLeft, isGoingRight;

    // Le joueur attaque
    bool isAttacking;

    // Info sur la tilemap
    int w, h, nbMapLayer, x, y, data;

    // Gestion de camera qui suit le joueur
    int substX, substY;

    //Taille de la fenêtre
    int winWidth, winHeight;

    //Taille de la map
    int mapWidth, mapHeight;

    // Texte pour l'UI
    sf::Font textFont;
    sf::Text hpText;

    // Image pour l'UI
    sf::Texture heartText;
    sf::Sprite heartSprite;

    bool isPaused;

    // Gestion scintillement rouge lorsque le joueur prend des dégâts
    sf::Clock playerHitClock;
    int playerLastHP;
    bool playerGotHitted;

    // Gestion scintillement rouge lorsque un ennemi prend des dégâts
    std::vector<sf::Clock> enemiesHitClocks;
    std::vector<int> enemiesLastHP;
    std::vector<bool> enemiesGotHitted;

    // Musique et sons
    sf::Music music;
    sf::SoundBuffer hitBuffer;
    sf::Sound hitSound;
};

#endif // __STATEGAMESFML_H__