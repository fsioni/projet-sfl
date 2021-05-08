#ifndef __STATEGAMESFML_H__
#define __STATEGAMESFML_H__

#include "../Core/Game.h"
#include "../Core/StateManager/State.h"
#include <SFML/Audio.hpp>
#include <memory>


/*! \class StateGameSFML
*   \brief Classe représentant l'état jeu du mode graphique (SFML)
* 
*/
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
    void UpdateNPCs();

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

    void DisplayNPC();

    /*! \brief Affichage une CollisionBox sur la fenêtre SFML
    *
    */
    void DisplayCollisionBox(
        Box * cb, const sf::Color & color, int id);

    /*! \brief Affichage le mode debug sur la fenêtre SFML
    *
    */
    void DisplayDebug();

    void Pause();

    void Start();

private:
    /*! \brief Etat courant du programme */
    std::shared_ptr<Context> context;

    sf::Sprite tileSprite, playerSprite, shadowSprite, enemySprite, npcSprite;
    std::vector<int> enemySpritesID, npcSpritesID; 

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
    /*! \brief Indique si le joueur a intéragi depuis le dernier update */
    bool hasInteracted;

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

    /*! \brief Texte indiquant le nombre d'hp du joueur */
    sf::Text hpText;
    /*! \brief Texte indiquant la phrase que dit le PNJ à proximité*/
    sf::Text npcText;

    /*! \brief Sprite du coeur */
    sf::Sprite heartSprite;

    /*! \brief indique si le jeu est en pause*/
    bool isPaused;

    // Gestion scintillement rouge lorsque le joueur prend des dégâts

    /*! \brief Horloge pour le scintillement du joueur lorsqu'il reçoit des dégâts */
    sf::Clock playerHitClock;
    /*! \brief Nombre d'HP du joueur lors du dernier update */
    int playerLastHP;

    // Gestion scintillement rouge lorsque un ennemi prend des dégâts

    /*! \brief Horloges pour le scintillement des ennemis lorsqu'ils reçoivent des dégâts */
    std::vector<sf::Clock> enemiesHitClocks;
    /*! \brief Nombre d'HP des ennemis lors du dernier update */
    std::vector<int> enemiesLastHP;
    /*! \brief Indique si l'ennemi a perdu des HP depuis le dernier update */
    std::vector<bool> enemiesGotHitted;

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