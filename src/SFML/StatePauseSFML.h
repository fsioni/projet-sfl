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
    /*! \brief Etat courant du programme */
    std::shared_ptr<Context> context;

    /*! \brief Police d'ecriture des textes */
    sf::Font textFont;
    /*! \brief Couleur des textes de l'UI */
    sf::Color textColor;

    /*! \brief Texte du titre de pause */
    sf::Text pauseText;

    /*! \brief Texte indiquant la touche pour reprendre le jeu */
    sf::Text resumeText;
};

#endif // __STATEPAUSESFML_H__