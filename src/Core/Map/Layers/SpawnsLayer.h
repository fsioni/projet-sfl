#ifndef _SPAWNS_LAYER_
#define _SPAWNS_LAYER_

#include "Layer.h"
#include "../SpawnPoint.h"
#include <vector>
#include <string>


class SpawnsLayer
{
private:
    /*! \brief SpawnPoint du joueur. */
    SpawnPoint playerSpawn;

    /*! \brief Tableau dynamique des SpawnPoint des ennemis. */
    std::vector<SpawnPoint> ennemySpawns;
public:
    /*! \brief Constructeur par défaut. */
    SpawnsLayer(/* args */);

    /*! \brief Constructeur avec la balise des spawns du joueur et 
    *           celle des ennemis.
    *   
    *   \param [in] objectgroupTagPlayer : balise brut <objectgroup> contenant le spawn du joueur.
    *   \param [in] objectgroupTagEnnemy : balise brut <objectgroup> contenant les spawns des ennemis.
    */
    SpawnsLayer(const std::string & objectgroupTagPlayer, 
                const std::string & objectgroupTagEnnemy);

    /*! \brief Destructeur. */
    ~SpawnsLayer();

    /*! \brief Modifie le spawn du joueur.
    * 
    *   \param [in] newSpawn : SpawnPoint affecté à playerSpawn.
    */
    void ChangePlayerSpawn(SpawnPoint const &newSpawn);

    /*! \brief Ajout d'un spawn au Tableau Dynamique des spawns des ennemis.
    * 
    *   \param [in] newSpawn : SpawnPoint à ajouter à ennemySpawns
    */
    void AddEnemy(SpawnPoint const &newSpawn);

    /*! \brief Retourne playerSpawn.
    *
    * \return Le SpawnPoint du joueur
    */
    SpawnPoint getPlayerSpawn() const;

    /*! \brief Retourne enemySpawns.
    *
    * \return Le Tableau Dynamique de SpawnPoint des ennemis.
    */
    std::vector<SpawnPoint> getEnemySpawns() const;
};

#endif