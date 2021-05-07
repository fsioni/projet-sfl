#include "SpawnsLayer.h"

#include "../tmxParsing.h"
#include <iostream>
#include <cassert>

SpawnsLayer::SpawnsLayer()
{
}

SpawnsLayer::SpawnsLayer(const std::string &objectgroupTagPlayer,
                         const std::string &objectgroupTagEnnemy,
                         const std::string &objectgroupTagNPC)
{
    std::string objectTag;
    
    objectTag = GetInsideTag(objectgroupTagPlayer, "object", 0);
    playerSpawn = SpawnPoint(objectTag);

    int count = CountTag(objectgroupTagEnnemy, "object");
    for (int i = 0; i < count; i++)
    {
        objectTag = GetInsideTag(objectgroupTagEnnemy, "object", i);
        ennemySpawns.push_back(SpawnPoint(objectTag));
    }



    std::string dialog, propertyTag, dataTag;
    count = CountTag(objectgroupTagNPC, "object");
    for (int i = 0; i < count; i++)
    {
        objectTag = GetFullTag(objectgroupTagNPC, "object", i);
        NpcSpawns.push_back(SpawnPoint(objectTag));

        // Si balise rotation pas trouvé renvoie -1 donc direction Up
        int angle = GetIntAttributeValue(objectTag, "rotation");
        NpcDirection.push_back(AngleToDirection(angle));
       
        
        // On cherche la balise property
        propertyTag = GetInsideTag(objectTag, "property", 0);
        
        // Si on trouve, on cheche la valeur du paramètre value
        // et on la met dans le tableau de dialog associé à l'indice
        // du npc.
        if(propertyTag!="NULL"){
            dialog = GetAttributeValue(propertyTag, "value");
            NpcDialog.push_back(dialog);
        }
        // Sinon on met au npc la phrase "Nothing to say."
        else{
            NpcDialog.push_back("Nothing to say.");
        }
        
    }
}

SpawnsLayer::~SpawnsLayer()
{
}

SpawnPoint SpawnsLayer::GetPlayerSpawn() const
{
    return playerSpawn;
}

std::vector<SpawnPoint> SpawnsLayer::GetEnemySpawns() const
{
    return ennemySpawns;
}

void SpawnsLayer::ChangePlayerSpawn(SpawnPoint const &newSpawn)
{
    playerSpawn = newSpawn;
}

void SpawnsLayer::AddEnemy(SpawnPoint const &newSpawn)
{
    ennemySpawns.push_back(newSpawn);
}

std::vector<SpawnPoint> SpawnsLayer::GetNPCSpawns() const
{
    return NpcSpawns;
}

void SpawnsLayer::AddNPC(SpawnPoint const &newSpawn)
{
    NpcSpawns.push_back(newSpawn);
}


std::string SpawnsLayer::GetADialog(int ind) const{
    if(ind < (int)NpcDialog.size())
        return NpcDialog[ind];
    return "NULL";
}

EntityDirection SpawnsLayer::GetADirection(int ind) const{
    if(ind < (int)NpcDirection.size())
        return NpcDirection[ind];
    return Down;
}

EntityDirection SpawnsLayer::AngleToDirection(int angle) const{
    // On replace angle dans l'intervalle [0, 360]
    angle = angle%360;
    if(angle >=315 && angle < 45)
        return Up;
    if(angle >=45 && angle < 135)
        return Right;
    if(angle >=135 && angle < 225)
        return Down;
    if(angle >=225 && angle < 315)
        return Left;
    return Up;
}

void SpawnsLayer::Test() const{
    std::cout << "===== Class SpawnsLayer =====" << std::endl;

    std::cout << "SpawnsLayer() : ";
    SpawnsLayer spawnsLayer1;
    assert(spawnsLayer1.GetPlayerSpawn().GetX()==0);
    assert(spawnsLayer1.GetPlayerSpawn().GetY()==0);
    assert(spawnsLayer1.GetEnemySpawns().empty());
    std::cout << "ok" << std::endl;

    std::cout << "SpawnsLayer(const std::string &objectgroupTagPlayer,"<<
                         "const std::string &objectgroupTagEnnemy) : ";
    std::string tagPlayer = "<objectgroup id=\"4\" name=\"PlayerSpawn\">\n<object id=\"14\" x=\"575\" y=\"473\"/>\n</objectgroup>";
    std::string tagEnemies = "<objectgroup id=\"6\" name=\"EnemySpawn\">\n<object id=\"11\" x=\"368.374\" y=\"190.925\"/>\n<object id=\"12\" x=\"316.712\" y=\"372.866\"/>\n<object id=\"13\" x=\"183.064\" y=\"216.757\"/>\n</objectgroup>";
    std::string tagNPC = "<objectgroup id=\"7\" name=\"NPCSpawn\">\n<object id=\"11\" x=\"368.374\" y=\"190.925\"/>\n<object id=\"12\" x=\"316.712\" y=\"372.866\"/>\n<object id=\"13\" x=\"183.064\" y=\"216.757\"/>\n</objectgroup>";
    SpawnsLayer spawnsLayer2(tagPlayer, tagEnemies, tagNPC);
    assert(spawnsLayer2.GetPlayerSpawn().GetX()==575);
    assert(spawnsLayer2.GetPlayerSpawn().GetY()==473);
    assert(spawnsLayer2.GetEnemySpawns().size()==3);
    assert(spawnsLayer2.GetNPCSpawns().size()==3);
    std::cout << "ok" << std::endl;

    std::cout << "AddEnemy(SpawnPoint const &newSpawn) : ";
    spawnsLayer2.AddEnemy(SpawnPoint("<object id=\"11\" x=\"368\" y=\"190\"/>"));
    assert(spawnsLayer2.GetEnemySpawns().size()==4);
    assert(spawnsLayer2.GetEnemySpawns()[3].GetX()==368);
    assert(spawnsLayer2.GetEnemySpawns()[3].GetY()==190);
    std::cout << "ok" << std::endl;

    std::cout << "AddNPC(SpawnPoint const &newSpawn) : ";
    spawnsLayer2.AddNPC(SpawnPoint("<object id=\"11\" x=\"368\" y=\"190\"/>"));
    assert(spawnsLayer2.GetNPCSpawns().size()==4);
    assert(spawnsLayer2.GetNPCSpawns()[3].GetX()==368);
    assert(spawnsLayer2.GetNPCSpawns()[3].GetY()==190);
    std::cout << "ok" << std::endl;

    std::cout << "ChangePlayerSpawn(SpawnPoint const &newSpawn) : ";
    spawnsLayer2.ChangePlayerSpawn(SpawnPoint("<object id=\"11\" x=\"368\" y=\"190\"/>"));
    assert(spawnsLayer2.GetPlayerSpawn().GetX()==368);
    assert(spawnsLayer2.GetPlayerSpawn().GetY()==190);
    std::cout << "ok" << std::endl;

    std::cout << std::endl << std::endl;
}