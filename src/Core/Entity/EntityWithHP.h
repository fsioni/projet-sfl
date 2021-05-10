#ifndef ENTITYWITHHP_H
#define ENTITYWITHHP_H

#include "EntityWithoutHP.h"

/*! \class EntityWithHP
*   \brief Classe représentant une entité qui peut infliger/subir des dégats et se déplacer.
*
*   La classe représente une entité avec un nom, des points de vie, une position, des dégats d'attaque,
*   une vitesse et un cap maximum de points de vie.
*/
class EntityWithHP : public EntityWithoutHP
{
public:
    /*// ==== Fonctions membres publiques === //*/

    /*! \brief Constructeur par défaut.
    *
    *
    *   Créer une entité EntityWithHP avec une position x 0.0, une position y 0.0, un nom "Unknown", 200 hp, 20 de damage,
    *   200 de maxHealth et une vitesse de 1,0 (entité vide).
    *
    */
    EntityWithHP();

    /*! \brief Constructeur avec spécifités de l'entité en paramètre.
    *   \param [in] x : réel positif, position de l'entité sur l'axe X (horizontal).
    *   \param [in] y : réel positif, position de l'entité sur l'axe Y (vertical).
    *   \param [in] hp : entier positif, nombre de points de vie de l'entité.
    *   \param [in] dammage : entier positif, nombre de points de vie infligé lors d'une attaque.
    *   \param [in] maxHP : entier positif, maximum de points de vie qu'une entité peut avoir.
    *   \param [in] livingStatus : Booléen, définissant si l'entité est morte ou pas.
    *   \param [in] speed : réel positif, vitesse de déplacement de l'entité.
    *
    *
    *   Créer une EntityWithHP (x, y, name, hp, dammage, maxHP, livingStatus, speed)
    *
    */
    EntityWithHP(float x, float y, int hp, int damage, int speed, int maxHP);

    /*! \brief Destructeur.
    *
    *  Destructeur de la classe EntityWithHP.
    *
    */
    virtual ~EntityWithHP();


    /*! \brief Retourne le nombre de points de vie de l'entité.
    *
    *   Retourne le nombre de points de vie Hp actuelle de l'entité EntityWithHP.
    *
    *
    */
    int GetHP() const;

    /*! \brief Permet de retourner le nombre de dégats q'inflige l'entité EntityWithHP.
    *
    *   Retourne damage le nombre de points de vie qu'inflige une entité lors d'une attaque.
    */
    int GetDamage() const;

    /*! \brief Permet d'imprimer sur la console des informations générales concernant l'entité.
    *
    *   Imprime sur la console des informations concernant l'entité.
    *
    *
    */
    void PrintEntityInfo() override;

    /*! \brief Permet de faire en sorte qu'une entité subisse le nombre "damage" dégats.
    *
    *   \param [in] damage : entier positif, dégats à infliger.
    *
    */
    void TakeDamage(int damage);

    /*! \brief Modifie l'état de vie/mort de l'entité.
    *
    *   Modifie l'état de vie/mort de l'entité.
    *
    *   \param [in] newStatus : booléen : indique si l'entitté EntityWithHP est en vie ou pas.
    *
    */
    void SetLivingStatus(bool newStatus);

    /*! \brief Retourne l'état de vie/mort de l'entité.
    *
    *   Retourne l'état de vie/mort de l'entité.
    *
    */
    bool GetLivingStatus() const;

    /*! \brief Retourne le cap maximum de points de vie de l'entité.
    *
    *   Retourne le cap maximum de points de vie de l'entité.
    *
    */
    int GetMaxHP() const;

    /*! \brief Fonction de test de regression.
    *
    *   Effectue une série de test pour vérifié que chaque
    *   fonctions fait ce qu'elle doit faire.
    */
    void Test() const;

protected:
    /*// ==== Données membres protégées === //*/

    /*! \brief Nombre entier de points de vie de l'entité */
    int hp;

    /*! \brief Nombre entier de points de vie infligé lors d'un attaque */
    int damage;

    /*! \brief Booléen définissant si l'entité est morte ou pas */
    bool livingStatus;

    /*! \brief Nombre entier maximal de points de vie de l'entité */
    int maxHP;
};

#endif
