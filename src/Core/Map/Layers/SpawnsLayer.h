#ifndef _SPAWNS_LAYER_
#define _SPAWNS_LAYER_

#include "Layer.h"
#include "../SpawnPoint.h"
#include <vector>
#include <string>

/*! \class SpawnsLayer 
*   \brief Classe représentant une couche de SpawnPoint
*
*   Représente tous les SpawnPoint du jeu, ceux des ennemis, du joueurs, des PNJ...
*/
class SpawnsLayer
{
private:
    /*// === Données membres privées === //*/
    SpawnPoint playerSpawn;
    std::vector<SpawnPoint> ennemySpawns;

public:
    /*// === Fonctions membres privées === //*/

    /*! \brief Constructeur par défaut 
    *
    *   Ne suffit pas pour utilisation.
    */
    SpawnsLayer(/* args */);

    /*! \brief Constructeur par balises
    *
    *   Créer un SpawnsLayer depuis les balises object d'une Tilemap.
    *   \param [in] objectgroupTagPlayer : balise object du SpawnPoint du Player 
    *   \param [in] objectgroupTagEnnemy : balise object du SpawnPoint des Ennemy
    */
    SpawnsLayer(const std::string & objectgroupTagPlayer, 
                const std::string & objectgroupTagEnnemy);

     /*! \brief Destructeur
    *
    * Destructeur de l'objet SpawnsPoint
    */
    ~SpawnsLayer();

    /*! \brief Fonction permettant de modifier le SpawnPoint du joueur
    *
    *   Remplace le SpawnPoint du Player actuel par celui en paramètre.
    *   \param [in] newSpawn : nouveau spawn du joueur 
    */
    void ChangePlayerSpawn(SpawnPoint const &newSpawn);

    /*! \brief Fonction permettant d'ajouter un ennemi 
    *
    *   Un ennemi est ajouté en ajoutant un SpawnPoint pour un Ennemy
    *   \param [in] newSpawn : nouveau spawn du nouvel Ennemy
    */
    void AddEnemy(SpawnPoint const &newSpawn);

    /*! \brief Fonction permettant de récupérer le SpawnPoint du joueur
    *
    *   \return Retourne le SpawnPoint du Player en mode donnée 
    */
    SpawnPoint getPlayerSpawn() const;

    /*! \brief Fonction d'affichage de l'objet en mode texte
    *
    *   Affiche toutes les données de l'objet dans le terminal
    */
    void DisplayTXT()const;
};

#endif