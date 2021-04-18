#ifndef _BOX_
#define _BOX_

#include <string>

/*! \class Box 
*   \brief Classe représentant une boîte dans un monde 2D
*
*   Possède des propriété basiques comme la position, dimension, ID.
*/
class Box
{
public:
    /*// === Fonctions membres publiques === //*/

    /*! \brief Constructeur par défaut 
    *
    * Créer une Box quelconque avec ses données membres à -1.
    * Ne suffit pas pour utilisation.
    */
    Box();

    /*! \brief Constructeur depuis balise d'une map .tmx
    *
    * \param [in] objectTag : balise contenant les informations de la Box dans le .tmx.
    */
    Box(const std::string& objectTag);

    /*! \brief Constructeur depuis les paramètres entrés
    *
    * \param [in] nID : id de la Box
    * \param [in] nX : position horizontale de la Box
    * \param [in] nY : position verticale de la Box
    * \param [in] nWidth : largeur de la Box
    * \param [in] nHeight : hauteur de la Box
    */
    Box(int nId, int nX, int nY, int nWidth, int nHeight);

    /*! \brief Destructeur
    *
    * Destructeur de l'objet Box
    */
    ~Box();
    
    /*! \brief Modifie l'id de la Box par celui en paramètre
    *
    * \param [in] nID : nouvel id de la Box
    */
    void SetId(int nId);

    /*! \brief Modifie la position de la Box par celle en paramètre
    *
    * \param [in] nX : nouvel position horizontale de la Box
    * \param [in] nY : nouvel position verticale de la Box
    */
    void SetPosition(int nX, int nY);

    /*! \brief Modifie la taille de la Box par celle en paramètre
    *
    * \param [in] nWidth : nouvel largeur horizontale de la Box
    * \param [in] nHeight : nouvel hauteur verticale de la Box
    */
    void SetDimensions(int nWidth, int nHeight);

    /*! \brief Retourne id
    *
    * \return id de la Box
    */
    int GetId() const;
    
    /*! \brief Retourne x
    *
    * \return La position horizontale de la Box
    */
    int GetX() const;

    /*! \brief Retourne y
    *
    * \return La position verticale de la Box
    */
    int GetY() const;

    /*! \brief Retourne width
    *
    * \return La largeur de la Box
    */
    int GetWidth() const;

    /*! \brief Retourne height
    *
    * \return La haut de la Box
    */
    int GetHeight() const;

    /*! \brief Fonction test de la classe Box
    *
    *   Effectue des tests pour vérifier l'intégrité de la classe Box et son fonctionnement
    */
    void Test() const;

private:
    /*// === Données membres privées === //*/

    /*! \brief ID de la Box (unique car information récupéré de la map .tmx). */
    int id; 

    /*! \brief Position de la Box sur l'axe x (horizontal, avec l'origine en haut à gauche). */
    int x;

    /*! \brief Position de la Box sur l'axe y (vertical, avec l'origine en haut à gauche). */
    int y;
    
    /*! \brief  Largeur de la Box. */
    int width;
    
    /*! \brief Hauteur de la Box. */
    int height;
};



#endif