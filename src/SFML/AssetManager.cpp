#include "AssetManager.h"
#include <iostream>
#include <fstream>

AssetManager::AssetManager()
{
    SetPlayerTexture("data/textures/characters/Male/Male 01-1.png");
    SetShadowTexture("data/textures/characters/Shadow/Shadow 1.png");
    AddTextureEnemy("data/textures/characters/Soldier/Soldier 01-1.png");
    AddTextureNPC("data/textures/characters/Female/Female 01-1.png");
}

AssetManager::~AssetManager()
{
}

void AssetManager::AddTextureEnemy(std::string fileTexture)
{
    std::fstream file;
    file.open(fileTexture.c_str(), std::fstream::in);

    sf::Texture text;
    if (file)
    {
        text.loadFromFile(fileTexture);
        textureEnemy.push_back(text);
    }
    else
        std::cout << "Echec AddTextureEnemy( "
                  << fileTexture << " ) : fichier inexistant"
                  << std::endl;
}

void AssetManager::AddTextureNPC(std::string fileTexture)
{
    std::fstream file;
    file.open(fileTexture.c_str(), std::fstream::in);

    sf::Texture text;
    if (file)
    {
        text.loadFromFile(fileTexture);
        textureNPC.push_back(text);
    }
    else
        std::cout << "Echec AddTextureNPC("
                  << fileTexture << ") : fichier inexistant"
                  << std::endl;
}

void AssetManager::RemoveTextureEnemy(int indice)
{
}

void AssetManager::RemoveTextureNPC(int indice)
{
}

void AssetManager::SetPlayerTexture(std::string fileTexture)
{
    std::fstream file;
    file.open(fileTexture.c_str(), std::fstream::in);
    if (file)
    {
        texturePlayer.loadFromFile(fileTexture);
    }
    else
        std::cout << "Echec SetPlayerTexture( "
                  << fileTexture << " ) : fichier inexistant"
                  << std::endl;
}

void AssetManager::SetShadowTexture(std::string fileTexture)
{
    std::fstream file;
    file.open(fileTexture.c_str(), std::fstream::in);
    if (file)
    {
        textureShadow.loadFromFile(fileTexture);
    }
    else
        std::cout << "Echec SetShadowTexture( "
                  << fileTexture << " ) : fichier inexistant"
                  << std::endl;
}

const std::vector<sf::Texture> &AssetManager::GetTextureEnemy() const
{
    return textureEnemy;
}

const std::vector<sf::Texture> &AssetManager::GetTextureNPC() const
{
    return textureNPC;
}

const sf::Texture &AssetManager::GetPlayerTexture() const
{
    return texturePlayer;
}

const sf::Texture &AssetManager::GetShadowTexture() const
{
    return textureShadow;
}