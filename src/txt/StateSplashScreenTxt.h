#ifndef __STATESPLASHSCREENTXT_H__
#define __STATESPLASHSCREENTXT_H__

#include "../Core/StateManager/State.h"
#include "../Core/Game.h"
#include <memory>
#include <ctime>

/*! \class StateSplashScreenTxt 
*   \brief Classe représentant l'état SplashScreen du mode texte
* 
*/
class StateSplashScreenTxt : public State
{
public:
    StateSplashScreenTxt(/* args */);
    StateSplashScreenTxt(std::shared_ptr<Context> &cContext);
    ~StateSplashScreenTxt();

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
};

#endif // __STATESPLASHSCREENTXT_H__