#ifndef __STATEGAMESFML_H__
#define __STATEGAMESFML_H__

#include "../Core/Game.h"
#include "../Core/StateManager/State.h"
#include <SFML/Audio.hpp>

class StateGameSFML : public State
{
public:
    StateGameSFML(/* args */);
    StateGameSFML(std::shared_ptr<Context> &cContext);
    ~StateGameSFML();

    void Init();

    void ProcessInput();

    void Update();
    /*! \brief Met à jour les données correspondant au joueur
    *
    */
    void UpdatePlayer();

    /*! \brief Met à jour les données correspondant aux ennemis
    *
    */
    void UpdateEnemies();

    void Display();

    /*! \brief Affichage la carte sur la fenêtre SFML
    *
    */
    void DisplayMap();

    /*! \brief Affichage le joueur sur la fenêtre SFML
    *
    */
    void DisplayPlayer();

    /*! \brief Affichage les ennemis sur la fenêtre SFML
    *
    */
    void DisplayEnemies();

    /*! \brief Affichage une CollisionBox sur la fenêtre SFML
    *
    */
    void DisplayCollisionBox(CollisionBox * cb, const sf::Color & color, int id);

    /*! \brief Affichage le mode debug sur la fenêtre SFML
    *
    */
    void DisplayDebug();

    void Pause();

    void Start();

private:
    /*! \brief Etat courant du programme */
    std::shared_ptr<Context> context;

    sf::Texture tileTexture;
    sf::Sprite tileSprite, playerSprite, shadowSprite, enemySprite;

    /*! \brief Horloge pour le delta time */
    sf::Clock deltaClock;

    /*! \brief Delta time */
    float deltaTime;

    /*! \brief Horloge pour la gestion de l'animation du joueur */
    sf::Clock spriteClock;
    /*! \brief Indique l'image à jouer pour l'animation du joueur */
    int posX = 0;

    /*! \brief Horloge pour les fps */
    sf::Clock fpsClock;
    /*! \brief nombre actuel de fps*/
    int fps;

    /*! \brief Position du joueur sur l'axe horizontale */
    int playerX;
    /*! \brief Position du joueur sur l'axe verticale */
    int playerY;

    /*! \brief Indique si la direction du joueur est vers le haut */
    bool isGoingUp;
    /*! \brief Indique si la direction du joueur est vers le bas */
    bool isGoingDown;
    /*! \brief Indique si la direction du joueur est vers la gauche */
    bool isGoingLeft;
    /*! \brief Indique si la direction du joueur est vers la droite */
    bool isGoingRight;
    /*! \brief Indique si le joueur est en train de marcher */
    bool isWalking;
    /*! \brief Indique si le joueur attaque */
    bool isAttacking;

    // Info sur la tilemap
    int w, h, nbMapLayer, x, y, data;

    // Gestion de camera qui suit le joueur
    int substX, substY;

    /*! \brief Largeur de la fenetre */
    int winWidth;
    /*! \brief Hauteur de la fenetre */
    int winHeight;

    /*! \brief Largeur de la map */
    int mapWidth;
    /*! \brief Hauteur de la map */
    int mapHeight;

    /*! \brief Police des textes */
    sf::Font textFont;
    /*! \brief Texte indiquant le nombre d'hp du joueur */
    sf::Text hpText;

    /*! \brief Texture du coeur */
    sf::Texture heartText;
    /*! \brief Sprite du coeur */
    sf::Sprite heartSprite;

    /*! \brief indique si le jeu est en pause*/
    bool isPaused;

    /*! \brief Horloge pour le scintillement du jouer lorsqu'il reçoit des dégâts */
    sf::Clock hitClock;
    /*! \brief Nombre d'HP du joueur lors du dernier update */
    int lastHP;

    /*! \brief Musique du jeu */
    sf::Music music;
    /*! \brief Son tampon des pas du joueur */
    sf::SoundBuffer runningBuffer;
    /*! \brief Son des pas du joueur */
    sf::Sound runningSound;
    /*! \brief Son tampon de coup */
    sf::SoundBuffer hitBuffer;
    /*! \brief Son de coup */
    sf::Sound hitSound;
};

#endif // __STATEGAMESFML_H__