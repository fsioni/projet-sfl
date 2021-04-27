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
    *   \param [in] name : chaine de caractères, nom de l'entité.
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
    EntityWithHP(float x, float y, std::string name, int hp, int damage, int speed, int maxHP);


    /*! \brief Destructeur.
    *
    *  Destructeur de la classe EntityWithHP.
    *
    */
    virtual ~EntityWithHP();

    /*! \brief Permets de modifier le nombre de points de vie d'une entité EntityWithHP.
    *
    *
    *   Permet de remplacer la valeur actuelle de Hp de l'entité en une valeur newHp.
    *
    *   \param [in] newHp : entier positif, nouveau nombre de points de vie de l'entité.
    *
    *
    */
    void SetHP(int newHp);

    /*! \brief Retourne le nombre de points de vie de l'entité.
    *
    *   Retourne le nombre de points de vie Hp actuelle de l'entité EntityWithHP.
    *
    *
    */
    int GetHP() const;


    /*! \brief Permet de modofier les dégats infligés par l'entité EntityWithHP.
    *
    *   Modifie la quantité de dégats qu'inflige l'entité EntityWithP.
    *
    *   \param [in] newDmg : entier positif, nouveau nombre de points de vie de l'entité.
    *
    *
    */
    void SetDamage(int newDmg);


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


    /*! \brief Permet d'infliger damage dégats à l'entité target.
    *
    *
    *   \param [in] target : EntityWithHP qui va subir le nombre "damage" dégats.
    *
    *
    */
    void Attack(EntityWithHP &target) const;


    /*! \brief Modifie l'état de vie/mort de l'entité.
    *
    *   Modifie l'état de vie/mort de l'entité.
    *
    *   \param [in] newStatus : booléen : indique si l'entitté EntityWithHP est en vie ou pas.
    *
    */
    void SetLivingStatus (bool newStatus);


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

protected :
    /*// ==== Données membres protégées === //*/

    /*! \brief Nombre entier de points de vie de l'entité */
    int hp;

    /*! \brief Nombre entier de points de vie infligé lors d'un attaque */
    int damage;

    /*! \brief Booléen définissant si l'entité est morte ou pas */
    bool livingStatus;

    /*! \brief Nombre entier maximal de points de vie de l'entité */
    int maxHP;

    /*! \brief Vitesse de l'entité */
    float speed;
};

#endif
