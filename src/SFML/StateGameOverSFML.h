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
    /*! \brief Texte indiquant comment relancer la partie */
    sf::Text restartText;

    /*! \brief Sprite du fond d'écran */
    sf::Sprite bgSprite;

    /*! \brief Musique de Game Over */
    sf::Music music;
};

#endif // __STATEGAMEOVERSFML_H__