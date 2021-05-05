#ifndef __STATEMENUSFML_H__
#define __STATEMENUSFML_H__

#include "../Core/Game.h"
#include "../Core/StateManager/State.h"
#include <SFML/Audio.hpp>

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
    std::shared_ptr<Context> context;

    sf::Font textFont;

    sf::Text gameTitle;

    // Main Menu
    sf::Text playButton;
    sf::Text instructionButton;
    sf::Text exitButton;

    // InstructionSub Menu
    sf::Text moveText;
    sf::Text attackText;
    sf::Text interactText;
    sf::Text pauseText;
    sf::Text debugModeText;
    sf::Text quitSubMenuText;

    bool isPlayButSelected;
    bool isPlayButPressed;

    bool isInstructionButSelected;
    bool isInstructionButPressed;

    bool isInInstructionSubMenu;

    bool isExitButSelected;
    bool isExitButPressed;

    sf::Music music;

    sf::SoundBuffer buffer;
    sf::Sound sound;
};
#endif // __STATEMENUSFML_H__