#ifndef __STATEMENUSFML_H__
#define __STATEMENUSFML_H__

#include "../Core/Game.h"
#include "../Core/StateManager/State.h"
#include <SFML/Audio.hpp>

/*! \class StateMenuSFML
*   \brief Classe représentant l'état menu du mode graphique (SFML)
* 
*/
class StateMenuSFML : public State
{
public:
    StateMenuSFML(/* args */);
    StateMenuSFML(std::shared_ptr<Context> &cContext);
    ~StateMenuSFML();

    void Init();

    void ProcessInput();

    void Update();

    void Display();

    void Pause();

    void Start();

private:
    /*! \brief Etat courant du programme */
    std::shared_ptr<Context> context;

    /*! \brief Sprite du fond d'écran */
    sf::Sprite bgSprite;
    /*! \brief Sprite du logo du jeu */
    sf::Sprite logoSprite;

    /*! \brief Texte du titre du jeu */
    sf::Text gameTitle;

    // Main Menu
    /*! \brief Texte du bouton jouer */
    sf::Text playButton;
    /*! \brief Texte du bouton instructions */
    sf::Text instructionButton;
    /*! \brief Texte du bouton quitter */
    sf::Text exitButton;

    // InstructionSub Menu
    /*! \brief Texte indiquant les touches des mouvements */
    sf::Text moveText;
        /*! \brief Texte indiquant la touche d'attaque */
    sf::Text attackText;
    /*! \brief Texte indiquant la touche d'interaction */
    sf::Text interactText;
    /*! \brief Texte indiquant la touche de pause */
    sf::Text pauseText;
    /*! \brief Texte indiquant la touche de debug mode */
    sf::Text debugModeText;
    /*! \brief Texte indiquant la touche pour quitter */
    sf::Text quitSubMenuText;

    /*! \brief Indique si le bouton "jouer" est selectionné */
    bool isPlayButSelected;
    /*! \brief Indique si le bouton "jouer" est pressé */
    bool isPlayButPressed;

    /*! \brief Indique si le bouton "instruction" est selectionné */
    bool isInstructionButSelected;
    /*! \brief Indique si le bouton "instruction" est pressé */
    bool isInstructionButPressed;

    /*! \brief Indique si l'on se trouve dans le sous menu "instruction" */
    bool isInInstructionSubMenu;

    /*! \brief Indique si le bouton "quitter" est selectionné */
    bool isExitButSelected;
    /*! \brief Indique si le bouton "quitter" est pressé */
    bool isExitButPressed;

    /*! \brief Musique du menu*/
    sf::Music music;

    /*! \brief Son tampon de l'effet sonore du menu */
    sf::SoundBuffer buffer;
    /*! \brief Effet sonore du menu */
    sf::Sound sound;
};
#endif // __STATEMENUSFML_H__