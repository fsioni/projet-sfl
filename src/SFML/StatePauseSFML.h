#ifndef __STATEPAUSEFML_H__
#define __STATEPAUSEFML_H__

#include "../Core/Game.h"
#include "../Core/StateManager/State.h"

/*! \class StatePauseSFML
*   \brief Classe représentant l'état pause du mode graphique (SFML)
* 
*/
class StatePauseSFML : public State
{
public:
    StatePauseSFML(/* args */);
    StatePauseSFML(std::shared_ptr<Context> &cContext);
    ~StatePauseSFML();

    void Init();

    void ProcessInput();

    void Update();

    void Display();

    void Pause();

    void Start();

private:
    void OnClick();

    /*! \brief Etat courant du programme */
    std::shared_ptr<Context> context;

    /*! \brief Texte du titre de pause */
    sf::Text pauseText;

    /*! \brief Sprite du fond d'écran */
    sf::Sprite bgSprite;
    /*! \brief Sprite du logo du jeu */
    sf::Sprite logoSprite;

    // Boutons

    /*! \brief Texte du bouton reprendre */
    sf::Text resumeButton;
    /*! \brief Texte du bouton menu */
    sf::Text menuButton;
    /*! \brief Texte du bouton quitter */
    sf::Text exitButton;

    /*! \brief Indique si le bouton "reprendre" est selectionné */
    bool isResumeButSelected;
    /*! \brief Indique si le bouton "reprendre" est pressé */
    bool isResumeButPressed;

    /*! \brief Indique si le bouton "Menu" est selectionné */
    bool isMenuButSelected;
    /*! \brief Indique si le bouton "Menu" est pressé */
    bool isMenuButPressed;

    /*! \brief Indique si le bouton "quitter" est selectionné */
    bool isExitButSelected;
    /*! \brief Indique si le bouton "quitter" est pressé */
    bool isExitButPressed;

    /*! \brief Son tampon de l'effet sonore du menu */
    sf::SoundBuffer buffer;
    /*! \brief Effet sonore du menu */
    sf::Sound sound;
};

#endif // __STATEPAUSESFML_H__