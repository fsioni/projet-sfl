#ifndef __STATEGAMEOVERSFML_H__
#define __STATEGAMEOVERSFML_H__

#include "../Core/Game.h"
#include "../Core/StateManager/State.h"
#include <SFML/Audio.hpp>

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
    std::shared_ptr<Context> context;

    sf::Font textFont;
    sf::Text gameOverText;
    sf::Text restartText;

    sf::Music music;
};

#endif // __STATEGAMEOVERSFML_H__