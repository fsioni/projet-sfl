#include "Game.h"
#include <stdio.h>
#include <assert.h>

#include <iostream>

Game::Game(/* args */)
{
    std::string tmxFile = "data/maps/tilemaps/mainTilemap.tmx";
    std::string tsxFile = "data/maps/tilesets/mainTileSet.tsx";
    map = new Map(tmxFile, tsxFile);
    
    // Initialisation du joueur
    int x = map->GetSpawnsLayer().getPlayerSpawn().GetX();
    int y = map->GetSpawnsLayer().getPlayerSpawn().GetY();

    player = Player(x, y, "Player", 10, 10, 4, 10);

    // Initialisation des ennemies
    int count = map->GetSpawnsLayer().getEnemySpawns().size();
    
    for(int i = 0; i<count; i++){
        x = map->GetSpawnsLayer().getEnemySpawns()[i].GetX();
        y = map->GetSpawnsLayer().getEnemySpawns()[i].GetY();

        Enemy tmpEnemy(x, y, "Enemy", 10, 3, 5, 100);

        enemies.push_back(tmpEnemy);
    }


    isDebug = false;
}


Game::~Game()
{
}

void Game::Run(int mode) 
{
    assert(mode==0 || mode == 1);
    switch (mode)
    {
    case 0: //mode SFML
        /* code */
        break;
    
    case 1: //mode txt
        break;

    default:
        break;
    }
}

void Game::KeyboardPressed(const char key) 
{
    switch (key)
    {
    case 'z':
        MoveWithCollision(player, 0, -1);
        break;
    case 's':
        MoveWithCollision(player, 0, 1);
        break;
    case 'q':
        MoveWithCollision(player, -1, 0);
        break;
    case 'd':
        MoveWithCollision(player, 1, 0);
        break;
    
    default:
        break;
    }
}

Player Game::GetPlayerConst() const
{
    return player;
}

std::vector<Enemy> Game::GetEnemiesConst() const{
    return enemies;
}

Map& Game::GetMapConst() const
{
    return *map;
}

void Game::MoveWithCollision(EntityWithHP &entity, float vx, float vy) 
{
    int sizeTileEntity= 32;
    if (vx == 0 && vy == 0)
    {
        return;
    }
    bool iscolliding = false;
    std::vector<CollisionBox> cb = map->GetCollisionLayer().GetCollisionBoxes();
    for (long unsigned int i = 0; i < cb.size(); i++)
    {
        // -sizeTileEntity/2 pour centrer l'origine 
        int posX = entity.GetPos_x() + vx*entity.GetSpeed() - sizeTileEntity/2;
        int posY = entity.GetPos_y() + vy*entity.GetSpeed() - sizeTileEntity/2;

        //Detection collision axe X
        if (posX + entity.GetWidth() - entity.getOffset() >= cb[i].GetX()
            && cb[i].GetX() + cb[i].GetWidth() >= posX + entity.getOffset()){
            //Detection collision axe Y
            if(posY + entity.GetHeight() - entity.getOffset() >= cb[i].GetY()
               && cb[i].GetY() + cb[i].GetHeight() >= posY + entity.getOffset()){

                iscolliding = true;
            }   
        }
        
            
    }
    if (!iscolliding)
    {
        entity.Move(vx, vy);
    }
}

void Game::ChangeDebug() 
{
    isDebug = !isDebug;
}

int Game::GetDebug() 
{
    return isDebug;
}

void Game::Test() 
{
    
}