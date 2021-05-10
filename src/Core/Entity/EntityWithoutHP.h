#ifndef ENTITYWITHOUTHP_H
#define ENTITYWITHOUTHP_H

#include <assert.h>
#include <string>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <memory>
#include "../Map/Layers/CollisionLayer.h"
#include "UniqueID.h"


enum EntityDirection
{
    Down,
    Left,
    Right,
    Up
};

/*! \class EntityWithoutHP
*   \brief Classe représentant une entité immobile et immortel.
*
*   La classe représente une entité avec une position, direction,
*   vitesse, ID, status de mouvement, offset.
*
*/
class EntityWithoutHP
{
public:
    /*// ==== Fonctions membres publiques === //*/

    /*! \brief Constructeur par défaut.
    *
    *
    *   Créer une entité EntityWithoutHP avec une position x 0.0, une position y 0.0, un nom "Unknown" (entité vide).
    *
    */

    EntityWithoutHP();

    /*! \brief Constructeur avec spécifités de l'entité en paramètre.
    *   \param [in] x_ : réel positif, position de l'entité sur l'axe X (horizontale).
    *   \param [in] y_ : réel positif, position de l'entité sur l'axe Y (verticale).
    *   \param [in] speed_ : réel positif, vitesse de l'entité.
    *
    *   Créer une EntityWithoutHP (x_, y_, speed_, name_).
    */
    EntityWithoutHP(float x_, float y_, int speed_);

    /*! \brief Destructeur.
    *
    *  Destructeur de la classe EntityWithoutHP.
    *
    */
    virtual ~EntityWithoutHP();

    /*! \brief Retourne la position sur l'axe des x de l'entité (horizontale).
    *
    *  Retourne un réel x, une position sur l'axe des x de l'entité (horizontale).
    *
    *
    */
    float GetPos_x() const;

    /*! \brief Retourne la position sur l'axe des y de l'entité (verticale).
    *
    *  Retourne un réel y, une position sur l'axe des y de l'entité (verticale).
    *
    *
    */
    float GetPos_y() const;

    /*! \brief Permet d'imprimer sur la console des informations générales concernant l'entité.
    *
    *   Imprime sur la console des informations concernant l'entité.
    */
    virtual void PrintEntityInfo();


    /*! \brief Retourne la vitesse de l'entité.
    *
    *   Retourne un entier, la vitesse de l'entité.
    */
    int GetSpeed() const;

    /*! \brief Permets de modifier la vitesse de l'entité.
    *
    *   \param [in] newSpeed: entier positif, nouvelle vitesse de l'entité.
    *
    *   Vérifie que newSpeed est positif.
    */
    void SetSpeed(int newSpeed);

    /*! \brief Retourne la direction de l'entité.
    *
    */
    EntityDirection GetDirection() const;

    /*! \brief Permets de modifier la direction de l'entité.
    *
    *   \param [in] nDirection: EntityDirection, nouvelle direction de l'entité.
    */
    void SetDirection(EntityDirection nDirection);


    /*! \brief Permets de modifier la direction de l'entité.
    *
    *   Assigne la direction en fonction de l'axe sur lequel
    *   il y a le plus grand déplacement.
    *
    *   \param [in] vx: réel, valeur de déplacement sur l'axe X.
    *   \param [in] vy: réel, valeur de déplacement sur l'axe Y.
    *
    */
    void SetDirection(float vx, float vy);

    /*! \brief Déplace l'entité.
    *
    *   Modifie la position de l'entité en fonction de sa vitesse
    *   et des valeur de déplacement passé en paramètre
    *
    *   \param [in] vx: réel, valeur de déplacement sur l'axe X.
    *   \param [in] vy: réel, valeur de déplacement sur l'axe Y.
    */
    void Move(float vx, float vy);


    /*! \brief Retourne le statut de déplacement de l'entité.
    *  False, l'entité est immobile et True elle est en mouvement.
    */
    bool GetIsMoving() const;

    /*! \brief Remet isMoving à false.
    *
    */
    void SetIsMovingFalse();

    /*! \brief Calcul de distance entre l'entité et une autre entité.
    *
    *   \param [in] entity : Pointeur sur EntityWithoutHP, l'autre entité.
    */
    float Distance(const EntityWithoutHP * entity) const;

    /*! \brief Retourne l'ID de l'entité.
    *
    *   Retourne la valeur de UniqueID de l'entité.
    */
    int GetID() const;


    /*! \brief Déplace l'entité en vérifiant les collisions.
    *
    *   Modifie la position de l'entité en fonction de sa vitesse,
    *   des valeur de déplacement, de la couche de collision et du delta
    *   time passé en paramètre. Vérifie les collisions avec la map et
    *   avec les autres entités. Si il n'y a pas de collision, fait appel
    *   à Move(float vx, float vy).
    *
    *   \param [in] vx: réel, valeur de déplacement sur l'axe X.
    *   \param [in] vy: réel, valeur de déplacement sur l'axe Y.
    *   \param [in] colLayer: pointeur sur CollisionLayer, couche qui stocke
    *                         les boites de collision.
    *   \param [in] dt : entier, deltaTime.
    */
    bool MoveWithCollision(float vx, float vy, CollisionLayer * colLayer, int dt);

    /*! \brief Test de regression.
    *
    *   Effectue une série de test sur les fonctions de la classe
    *   et vérifie qu'elles font bien ce qu'elles sont censés faire.
    */
    void Test() const;

    /*! \brief Retourne l'offset de l'entité.
    *
    *   \return Valeur de l'offset de l'entité.
    */
    int GetOffset() const;

protected :
    /*// ==== Données membres protégées === //*/

    /*! \brief Position sur l'axe des x de l'entité (horizontal).*/
    float x;

    /*! \brief Position sur l'axe des y de l'entité (vertical). */
    float y;

    /*! \brief Vitesse de l'entité. */
    int speed;

    /*! \brief Direction de l'entité. */
    EntityDirection direction;

    /*! \brief Statut de déplacement.
    *  False, l'entité est immobile et True elle est en mouvement.
    */
    bool isMoving;

    /*! \brief Id unique. */
    UniqueID id;

    /*! \brief Offset de la CollisionBox */
    int offset;


};

#endif
