#ifndef _SPAWNS_LAYER_
#define _SPAWNS_LAYER_

#include "../SpawnPoint.h"
#include "../../Entity/EntityWithoutHP.h" 
#include <vector>
#include <string>

/*! \class SpawnsLayer 
*   \brief Classe représentant une couche de SpawnPoint
*
*   Représente tous les SpawnPoint du jeu, ceux des ennemis, du joueurs, des PNJ...
*/
class SpawnsLayer{
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
                const std::string &objectgroupTagNPC,
                const std::string &objectgroupTagAnimal);

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

    /*! \brief Fonction permettant de récupérer les SpawnPoint des Animal.
    *
    *   \return Retourne le tableau dynamique de SpawnPoint des Animal.
    */
    std::vector<SpawnPoint> GetAnimalSpawns() const;

    /*! \brief Test de regression.
    *
    *  Effectue une série de test sur toutes les fonctions
    *  de la classe et vérifie qu'elles font ce qu'elles sont 
    *  censé faire.
    */
    void Test() const;

    /*! \brief Retourne un dialog du tableau.
    *   Vérifie que l'indice demandé fait parti du tableau.
    *   \param [in] ind : entier positif, indice du dialog dans le tableau.
    *   \return std::string, dialog d'un NPC.
    */
    std::string GetADialog(int ind) const;

    /*! \brief Retourne une direction du tableau.
    *   Vérifie que l'indice demandé fait parti du tableau.
    *   \param [in] ind : entier positif, indice de la direction dans le tableau.
    *   \return EntityDirection, direction de l'entité.
    */
    EntityDirection GetADirection(int ind) const;
    
    /*! \brief Convertie un angle en degré en une EntityDirection.
    *
    *   \param [in] angle : entier, angle à convertir en EntityDirection.
    *   \return EntityDirection correspondant à l'angle. 
    */
    EntityDirection AngleToDirection(int angle) const;

private:
    /*! \brief SpawnPoint du joueur. */
    SpawnPoint playerSpawn;

    /*! \brief Les SpawnPoint des Ennemy. Un SpawnPoint = Un Ennemy. */
    std::vector<SpawnPoint> ennemySpawns;

    /*! \brief Les SpawnPoint des Animal. Un SpawnPoint = Un Animal. */
    std::vector<SpawnPoint> animalSpawns;

    /*! \brief Les SpawnPoint des NPC. Un SpawnPoint = Un NPC. */
    std::vector<SpawnPoint> NpcSpawns;

    /*! \brief Tableau dynamique de dialog (=phrase type) des NPC. */
    std::vector<std::string> NpcDialog;

    /*! \brief Tableau dynamique de direction EntityDirection des NPC. */
    std::vector<EntityDirection> NpcDirection;
};

#endif