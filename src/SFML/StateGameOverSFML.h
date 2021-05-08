#ifndef __STATEGAMEOVERSFML_H__
#define __STATEGAMEOVERSFML_H__

#include "../Core/Game.h"
#include "../Core/StateManager/State.h"
#include <SFML/Audio.hpp>

/*! \class StateGameOverSFML
*   \brief Classe représentant l'état game over du mode graphique (SFML)
* 
*/
class StateGameOverSFML : public State
{
public:
    StateGameOverSFML(/* args */);
    StateGameOverSFML(std::shared_ptr<Context> &cContext);
    ~StateGameOverSFML();

    void Init();

    void ProcessInput();

    void RestartGame();

    void Update();

    void Display();

    void Pause();

    void Start();

private:
    /*! \brief Etat courant du programme */
    std::shared_ptr<Context> context;

    /*! \brief Texte de game over */
    sf::Text gameOverText;

    /*! \brief Sprite du fond d'écran */
    sf::Sprite bgSprite;
    /*! \brief Sprite du logo du jeu */
    sf::Sprite logoSprite;


 /*! \brief Texte du bouton rejouer */
    sf::Text restartButton;
    /*! \brief Texte du bouton menu */
    sf::Text menuButton;
    /*! \brief Texte du bouton quitter */
    sf::Text exitButton;

    /*! \brief Indique si le bouton "rejouer" est selectionné */
    bool isRestartButSelected;
    /*! \brief Indique si le bouton "rejouer" est pressé */
    bool isRestartButPressed;

    /*! \brief Indique si le bouton "Menu" est selectionné */
    bool isMenuButSelected;
    /*! \brief Indique si le bouton "Menu" est pressé */
    bool isMenuButPressed;

    /*! \brief Indique si le bouton "quitter" est selectionné */
    bool isExitButSelected;
    /*! \brief Indique si le bouton "quitter" est pressé */
    bool isExitButPressed;


    /*! \brief Musique de Game Over */
    sf::Music music;

    /*! \brief Son tampon de l'effet sonore du menu */
    sf::SoundBuffer buffer;
    /*! \brief Effet sonore du menu */
    sf::Sound sound;
};

#endif // __STATEGAMEOVERSFML_H__