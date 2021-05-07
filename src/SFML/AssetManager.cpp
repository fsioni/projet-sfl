#include "AssetManager.h"
#include <iostream>
#include <fstream>

AssetManager::AssetManager()
{
    SetPlayerTexture("data/textures/characters/Male/Male 01-1.png");
    SetShadowTexture("data/textures/characters/Shadow/Shadow 1.png");
    AddTextureEnemy("data/textures/characters/Soldier/Soldier 01-1.png");
    AddTextureNPC("data/textures/characters/Female/Female 01-1.png");
    SetBackgroundTexture("data/textures/UI/menuBackground.png");
    SetHeartTexture("./data/textures/UI/heart.png");
    SetMainFont("data/fonts/BebasNeue-Regular.ttf");
    setMainTextColor(sf::Color(245, 222, 92));
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

void AssetManager::SetTileTexture(std::string fileTexture) 
{
    std::fstream file;
    file.open(fileTexture.c_str(), std::fstream::in);
    if (file)
    {
        tileTexture.loadFromFile(fileTexture);
    }
    else
        std::cout << "Echec SetTileTexture( "
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

void AssetManager::SetBackgroundTexture(std::string fileTexture) 
{
    std::fstream file;
    file.open(fileTexture.c_str(), std::fstream::in);
    if (file)
    {
        textureBackground.loadFromFile(fileTexture);
    }
    else
        std::cout << "Echec SetBackgroundTexture( "
                  << fileTexture << " ) : fichier inexistant"
                  << std::endl;
}

void AssetManager::SetHeartTexture(std::string fileTexture) 
{
    std::fstream file;
    file.open(fileTexture.c_str(), std::fstream::in);
    if (file)
    {
        textureHeart.loadFromFile(fileTexture);
    }
    else
        std::cout << "Echec SetHeartTexture( "
                  << fileTexture << " ) : fichier inexistant"
                  << std::endl;
}

void AssetManager::SetMainFont(std::string fileFont) 
{
    std::fstream file;
    file.open(fileFont.c_str(), std::fstream::in);
    if (file)
    {
        mainFont.loadFromFile(fileFont);
    }
    else
        std::cout << "Echec SetMainFont( "
                  << fileFont << " ) : fichier inexistant"
                  << std::endl;
}

void AssetManager::setMainTextColor(sf::Color color) 
{
    textColor = color;
}

/*void AssetManager::AddMusic(std::string fileMusic) 
{
    std::fstream file;
    file.open(fileMusic.c_str(), std::fstream::in);

    sf::Music music;
    if (file)
    {
        music.openFromFile(fileMusic);
        musics.push_back(music);
    }
    else
        std::cout << "Echec AddMusic("
                  << fileMusic << ") : fichier inexistant"
                  << std::endl;
}

void AssetManager::AddSoundBuffer(std::string fileBuffer) 
{
        std::fstream file;
    file.open(fileBuffer.c_str(), std::fstream::in);

    sf::SoundBuffer buffer;
    if (file)
    {
        buffer.loadFromFile(fileBuffer);
        soundBuffers.push_back(buffer);
    }
    else
        std::cout << "Echec AddSoundBuffer("
                  << fileBuffer << ") : fichier inexistant"
                  << std::endl;
}*/

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

const sf::Texture& AssetManager::GetTileTexture() const
{
    return tileTexture;
}

const sf::Texture &AssetManager::GetShadowTexture() const
{
    return textureShadow;
}

const sf::Texture& AssetManager::GetTextureBackground() const
{
    return textureBackground;
}

const sf::Texture& AssetManager::GetTextureHeart() const
{
    return textureHeart;
}

const sf::Font& AssetManager::GetMainFont() const
{
    return mainFont;
}

const sf::Color& AssetManager::GetMainTextColor() const
{
    return textColor;
}

const std::vector<sf::Music>& AssetManager::GetMusics() const
{
    return musics;
}

const std::vector<sf::SoundBuffer>& AssetManager::GetSoundBuffers() const
{
    return soundBuffers;
}