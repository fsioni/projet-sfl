#ifndef _SPAWNS_LAYER_
#define _SPAWNS_LAYER_

#include "Layer.h"
#include "../SpawnPoint.h"
#include <vector>
#include <string>

/*! \class SpawnsLayer 
*   \brief Classe représentant une couche de SpawnPoint
*   Hérité de Layer
*   Représente tous les SpawnPoint du jeu, ceux des ennemis, du joueurs, des PNJ...
*/
class SpawnsLayer : Layer
{
public:
    /*// === Fonctions membres privées === //*/

    /*! \brief Constructeur par défaut. */
    SpawnsLayer(/* args */);

    /*! \brief Constructeur avec la balise des spawns du joueur et 
    *           celle des ennemis.
    *   
    *   \param [in] objectgroupTagPlayer : balise brut <objectgroup> contenant le spawn du joueur.
    *   \param [in] objectgroupTagEnnemy : balise brut <objectgroup> contenant les spawns des ennemis.
    */
    SpawnsLayer(const std::string &objectgroupTagPlayer,
                const std::string &objectgroupTagEnnemy);

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

    /*! \brief Fonction permettant de récupérer les SpawnPoint des Ennemy
    *
    *   \return Retourne le tableau dynamique de SpawnPoint des joueurs
    */
    std::vector<SpawnPoint> getEnemySpawns() const;

private:
    /*// === Données membres privées === //*/
    /*! \brief SpawnPoint du joueur. */
    SpawnPoint playerSpawn;
    /*! \brief Les SpawnPoint des Ennemy. Un SpawnPoint = Un Ennemy */
    std::vector<SpawnPoint> ennemySpawns;
};

#endif