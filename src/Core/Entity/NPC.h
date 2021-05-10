#ifndef NPC_H
#define NPC_H

#include "EntityWithoutHP.h"

#include "Player.h"

/*! \class NPC
*   \brief Classe représentant un personnage immobile non-joueur qui peut donner des points de vie et communiquer.
*
*   La classe représente un NPC avec un nom et une position.
*
*/
class NPC : public EntityWithoutHP
{
public:
    /*// ==== Fonctions membres publiques === //*/

    /*! \brief Constructeur par défaut.
    *
    *
    *   Créer un NPC avec une position x 0.0, une position y 0.0, un nom "Unknown", une largeur 0.0 , une longueur 0.0 et un
    *   décalage 0.
    *
    */
    NPC();

    /*! \brief Constructeur avec spécifités d'un NPC en paramètre.
    *
    *
    *   Créer un NPC avec une position x 0.0, une position y 0.0, un nom "Unknown", une largeur 32.0 , une longueur 32.0 et un
    *   décalage 7.
    *
    */
    NPC(float x, float y, std::string dialog_);

    /*! \brief Destructeur.
    *
    *  Destructeur de la classe NPC.
    *
    */
    ~NPC();

    
    /*! \brief Retourne la phrase que le NPC peut dire au joueur.
    *   \return std::string, la phrase type du NPC.
    */
    std::string GetDialog() const;

    /*! \brief Fonction de test de regression.
    *
    *   Effectue une série de test pour vérifié que chaque
    *   fonctions fait ce qu'elle doit faire.
    */
    void Test() const;

private:
    /*// ==== Données membres privées === //*/

    /*! \brief Phrase que peut dire le NPC. */
    std::string dialog;
};

#endif
