#ifndef __STATESPLASHSCREENSFML_H__
#define __STATESPLASHSCREENSFML_H__

#include "../Core/Game.h"
#include "../Core/StateManager/State.h"
#include <SFML/Audio.hpp>


class StateSplashScreenSFML : public State
{
public:
    StateSplashScreenSFML(/* args */);
    StateSplashScreenSFML(std::shared_ptr<Context> &cContext);
    ~StateSplashScreenSFML();

    void Init();

    void ProcessInput();

    void Update();

    void Display();

    void Pause();

    void Start();

private:
    std::shared_ptr<Context> context;

    std::clock_t start;
    double duration;

    sf::Font textFont;
    sf::Text gameText;
    sf::Text madeByText;

    sf::Music music;    
};

#endif // __STATESPLASHSCREENSFML_H__