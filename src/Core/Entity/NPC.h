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

    /*! \brief Permet à un NPC de donner des points de vie à un Player.
    *
    *   \param [in] p : Player, Player qui va recevoir les points de vie de la part du NPC.
    *   \param [in] hpToGive : entier positif, nombre de points de vie qui vont etre attribué au Player p.
    *
    *   Permet à un NPC de donner des points de vie à un joueur.
    *
    */
    void GiveHP(Player &p, int hpToGive);

    /*! \brief Retourne la phrase que le NPC peut dire au joueur.
    *   \return std::string, la phrase type du NPC.
    */
    std::string GetDialog() const;

private:
    /*// ==== Données membres privées === //*/

    /*! \brief Phrase que peut dire le NPC. */
    std::string dialog;
};

#endif
