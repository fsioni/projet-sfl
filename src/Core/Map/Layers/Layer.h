#ifndef _LAYER_
#define _LAYER_

#include <string>

/*! \class Layer 
*   \brief Classe représentant une couche.
*   Doit être héritée.
*   Hérité par CollisionLayer et SpawnsLayer
*/
class Layer
{
public:
    /*! \brief Constructeur par défaut. */
    Layer(/* args */);

    /*! \brief Destructeur. */
    ~Layer();

    /*! \brief Modifie l'id du Layer par celui en paramètre
    *
    * \param [in] id_ : nouvel id du Layer.
    */
    void SetId(int id_);


    /*! \brief Retourne id
    *
    * \return L'id du Layer.
    */
    int GetID() const;


    /*! \brief Test de regression.
    *
    *  Effectue une série de test sur toutes les fonctions
    *  de la classe et vérifie qu'elles font ce qu'elles sont 
    *  censé faire.
    */
    void Test() const;

protected:
    /*! \brief Identifiant de la couche représenté par un entier. */
    int id;
};

#endif