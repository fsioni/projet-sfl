#include "AssetManager.h"
#include <iostream>
#include <fstream>



AssetManager::AssetManager(){
    SetPlayerTexture("data/textures/characters/Male/Male 01-1.png");
    AddTextureEnemy("data/textures/characters/Enemy/Enemy 01-1.png");
    AddTextureNPC("data/textures/characters/Female/Female 01-1.png");
}

AssetManager::~AssetManager(){
    
}

void AssetManager::AddTextureEnemy(std::string fileTexture){
    std::fstream file;
    file.open(fileTexture.c_str(), std::fstream::in);

    sf::Texture text;
    if(file){
        text.loadFromFile(fileTexture);
        textureEnemy.push_back(text);
    }
    else std::cout << "Echec AddTextureEnemy( " 
                   << fileTexture << " ) : fichier inexistant" 
                   << std::endl;
}

void AssetManager::AddTextureNPC(std::string fileTexture){
    std::fstream file;
    file.open(fileTexture.c_str(), std::fstream::in);

    sf::Texture text;
    if(file){
        text.loadFromFile(fileTexture);
        textureNPC.push_back(text);
    }
    else std::cout << "Echec AddTextureNPC(" 
                   << fileTexture << ") : fichier inexistant" 
                   << std::endl;
}

void AssetManager::RemoveTextureEnemy(int indice){

}

void AssetManager::RemoveTextureNPC(int indice){

}

void AssetManager::SetPlayerTexture(std::string fileTexture){
    std::fstream file;
    file.open(fileTexture.c_str(), std::fstream::in);
    if(file){
        texturePlayer.loadFromFile(fileTexture);
    }
    else std::cout << "Echec SetPlayerTexture( " 
                   << fileTexture << " ) : fichier inexistant" 
                   << std::endl;
}