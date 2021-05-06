#ifndef _SPAWNS_LAYER_
#define _SPAWNS_LAYER_

#include "Layer.h"
#include "../SpawnPoint.h"
#include "../../Entity/EntityWithoutHP.h" 
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
                const std::string &objectgroupTagEnnemy,
                const std::string &objectgroupTagNPC);

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

    /*! \brief Fonction permettant d'ajouter un ennemi. 
    *
    *   Un ennemi est ajouté en ajoutant un SpawnPoint pour un Ennemy
    *   \param [in] newSpawn : nouveau spawn du nouvel Ennemy
    */
    void AddEnemy(SpawnPoint const &newSpawn);

    /*! \brief Fonction permettant d'ajouter un NPC. 
    *
    *   Un ennemi est ajouté en ajoutant un SpawnPoint pour un NPC.
    *   \param [in] newSpawn : nouveau spawn du nouvel NPC.
    */
    void AddNPC(SpawnPoint const &newSpawn);

    /*! \brief Fonction permettant de récupérer le SpawnPoint du joueur
    *
    *   \return Retourne le SpawnPoint du Player en mode donnée 
    */
    SpawnPoint GetPlayerSpawn() const;

    /*! \brief Fonction permettant de récupérer les SpawnPoint des Ennemy
    *
    *   \return Retourne le tableau dynamique de SpawnPoint des Enemy.
    */
    std::vector<SpawnPoint> GetEnemySpawns() const;

    /*! \brief Fonction permettant de récupérer les SpawnPoint des NPC.
    *
    *   \return Retourne le tableau dynamique de SpawnPoint des NPC.
    */
    std::vector<SpawnPoint> GetNPCSpawns() const;

    /*! \brief Test de regression.
    *
    *  Effectue une série de test sur toutes les fonctions
    *  de la classe et vérifie qu'elles font ce qu'elles sont 
    *  censé faire.
    */
    void Test() const;

    std::string GetADialog(int ind) const;
    EntityDirection GetADirection(int ind) const;
    
    EntityDirection AngleToDirection(int angle) const;

private:
    /*// === Données membres privées === //*/
    /*! \brief SpawnPoint du joueur. */
    SpawnPoint playerSpawn;
    /*! \brief Les SpawnPoint des Ennemy. Un SpawnPoint = Un Ennemy */
    std::vector<SpawnPoint> ennemySpawns;

    /*! \brief Les SpawnPoint des NPC. Un SpawnPoint = Un NPC */
    std::vector<SpawnPoint> NpcSpawns;

    std::vector<std::string> NpcDialog;
    std::vector<EntityDirection> NpcDirection;
};

#endif