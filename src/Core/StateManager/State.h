#ifndef __STATE_H__
#define __STATE_H__

/*! \class State 
*   \brief Classe représentant un état de l'application
*
*   Un State est composé d'une initialisation, une boucle, un affichage (texte et graphique), destructeur...
*   State est une classe virtuelle pure : elle doit être héritée et toutes les fonctions héritée par State implémentée.
*   Exemple de State : SplashScreen, MainMenu, Game. 
*/
class State
{
private:
    /*// === Données membres privées === //*/

public:

    /*// === Fonctions membres publiques === //*/


    /*! \brief Fonction d'initialisation du State
    *
    *   Appelée une seule fois : au début du State
    *   Fonction virtuelle pure : doit être implémentée par l'enfant
    */
    virtual void Init()=0;

    /*! \brief Fonction de nettoyage du State
    *
    *   Appelée une seule fois : lorsque le State est quitté
    *   Fonction virtuelle pure : doit être implémentée par l'enfant
    */
    virtual void CleanUp()=0; 

    /*! \brief Fonction de mise en pause du State
    *
    *   Est appelée lorsque le State se met en pause
    *   Fonction virtuelle pure : doit être implémentée par l'enfant
    */
    virtual void Pause()=0;

    /*! \brief Fonction de remise en marche du State
    *
    *   Est appelée lorsque le State se remet en marche
    *   Fonction virtuelle pure : doit être implémentée par l'enfant
    */
    virtual void Resume()=0;

    /*! \brief Fonction de gestion des touches du State
    *
    *   Une touche peut avoir un comportement différent selon le State
    *   Fonction virtuelle pure : doit être implémentée par l'enfant
    */
    virtual void GetEvents()=0;

    /*! \brief Fonction de boucle du State
    *
    *   Est appelée à chaque mise à jour de l'application
    *   Fonction virtuelle pure : doit être implémentée par l'enfant
    */
    virtual void Update()=0;
    
    /*! \brief Fonction d'affichage du State
    *
    *   Est appelée à chaque mise à jour de l'application
    *   Permet un affichage dans la console ou en mode graphique selon le State associé
    *   Fonction virtuelle pure : doit être implémentée par l'enfant
    */
    virtual void Display()=0;

    /*! \brief Fonction test de la classe State
    *
    *   Effectue des tests pour vérifier l'intégrité de la classe State et son fonctionnement
    */
    virtual void Test()=0;
};


#endif // __STATE_H__