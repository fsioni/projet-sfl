#ifndef __STATESPLASHSCREENSFML_H__
#define __STATESPLASHSCREENSFML_H__

#include "../Core/Game.h"
#include "../Core/StateManager/State.h"
#include <SFML/Audio.hpp>

/*! \class StateSplashScreenSFML
*   \brief Classe représentant l'état SplashScreen du mode graphique (SFML)
* 
*/
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
    /*! \brief Etat courant du programme */
    std::shared_ptr<Context> context;

    /*! \brief Horloge correspondant au temps d'execution de l'Etat */
    std::clock_t start;

    /*! \brief Correspond à la durée de l'Etat */
    double duration;

    /*! \brief Sprite du fond d'écran */
    sf::Sprite bgSprite;
    /*! \brief Sprite du logo du jeu */
    sf::Sprite logoSprite;

    /*! \brief Texte du sous titre */
    sf::Text madeByText;

    /*! \brief Musique de lancement */
    sf::Music music;
};

#endif // __STATESPLASHSCREENSFML_H__