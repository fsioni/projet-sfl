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

    /*! \brief Police d'ecriture des textes */
    sf::Font textFont;

    /*! \brief Texte du titre du jeu */
    sf::Text gameTitle;

    /*! \brief Texte du bouton "jouer" */
    sf::Text playButton;

    /*! \brief Texte du bouton "quitter" */
    sf::Text exitButton;

    /*! \brief Indique si le bouton "jouer" est selectionné */
    bool isPlayButSelected;
    /*! \brief Indique si le bouton "jouer" est pressé */
    bool isPlayButPressed;

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