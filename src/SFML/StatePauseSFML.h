#ifndef __STATEPAUSEFML_H__
#define __STATEPAUSEFML_H__

#include "../Core/Game.h"
#include "../Core/StateManager/State.h"

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
    std::shared_ptr<Context> context;
    sf::Font textFont;
    sf::Text pauseText;
    sf::Text resumeText;
};

#endif // __STATEPAUSESFML_H__