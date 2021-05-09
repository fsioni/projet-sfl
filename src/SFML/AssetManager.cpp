#include "AssetManager.h"
#include <iostream>
#include <fstream>

AssetManager::AssetManager()
{
    SetPlayerTexture("data/textures/characters/Male/Male 01-1.png");
    SetShadowTexture("data/textures/characters/Shadow/Shadow 1.png");
    SetBackgroundTexture("data/textures/UI/menuBackground.png");
    SetHeartTexture("data/textures/UI/heart.png");
    SetLogoTexture("data/textures/logo.png");
    SetMainFont("data/fonts/BebasNeue-Regular.ttf");
    setMainTextColor(sf::Color(245, 222, 92));
    SetSoundTexture("data/textures/UI/volume.png");

    AddTextureEnemy("data/textures/characters/Soldier/Soldier 01-1.png");
    AddTextureEnemy("data/textures/characters/Soldier/Soldier 01-2.png");
    AddTextureEnemy("data/textures/characters/Soldier/Soldier 01-3.png");
    AddTextureEnemy("data/textures/characters/Soldier/Soldier 01-4.png");

    AddTextureEnemy("data/textures/characters/Soldier/Soldier 02-1.png");
    AddTextureEnemy("data/textures/characters/Soldier/Soldier 02-2.png");
    AddTextureEnemy("data/textures/characters/Soldier/Soldier 02-3.png");
    AddTextureEnemy("data/textures/characters/Soldier/Soldier 02-4.png");

    AddTextureEnemy("data/textures/characters/Soldier/Soldier 03-1.png");
    AddTextureEnemy("data/textures/characters/Soldier/Soldier 03-2.png");
    AddTextureEnemy("data/textures/characters/Soldier/Soldier 03-3.png");
    AddTextureEnemy("data/textures/characters/Soldier/Soldier 03-4.png");

    AddTextureEnemy("data/textures/characters/Soldier/Soldier 04-1.png");
    AddTextureEnemy("data/textures/characters/Soldier/Soldier 04-2.png");
    AddTextureEnemy("data/textures/characters/Soldier/Soldier 04-2.png");
    AddTextureEnemy("data/textures/characters/Soldier/Soldier 04-2.png");

    AddTextureEnemy("data/textures/characters/Soldier/Soldier 05-1.png");
    AddTextureEnemy("data/textures/characters/Soldier/Soldier 05-2.png");
    AddTextureEnemy("data/textures/characters/Soldier/Soldier 05-3.png");
    AddTextureEnemy("data/textures/characters/Soldier/Soldier 05-4.png");

    AddTextureEnemy("data/textures/characters/Soldier/Soldier 06-1.png");
    AddTextureEnemy("data/textures/characters/Soldier/Soldier 06-2.png");
    AddTextureEnemy("data/textures/characters/Soldier/Soldier 06-3.png");
    AddTextureEnemy("data/textures/characters/Soldier/Soldier 06-4.png");

    AddTextureEnemy("data/textures/characters/Soldier/Soldier 07-1.png");
    AddTextureEnemy("data/textures/characters/Soldier/Soldier 07-2.png");
    AddTextureEnemy("data/textures/characters/Soldier/Soldier 07-3.png");
    AddTextureEnemy("data/textures/characters/Soldier/Soldier 07-4.png");


    AddTextureNPC("data/textures/characters/Female/Female 01-1.png");
    AddTextureNPC("data/textures/characters/Female/Female 01-2.png");
    AddTextureNPC("data/textures/characters/Female/Female 01-3.png");
    AddTextureNPC("data/textures/characters/Female/Female 01-4.png");

    AddTextureNPC("data/textures/characters/Female/Female 02-1.png");
    AddTextureNPC("data/textures/characters/Female/Female 02-2.png");
    AddTextureNPC("data/textures/characters/Female/Female 02-3.png");
    AddTextureNPC("data/textures/characters/Female/Female 02-4.png");

    AddTextureNPC("data/textures/characters/Female/Female 03-1.png");
    AddTextureNPC("data/textures/characters/Female/Female 03-2.png");
    AddTextureNPC("data/textures/characters/Female/Female 03-3.png");
    AddTextureNPC("data/textures/characters/Female/Female 03-4.png");

    AddTextureNPC("data/textures/characters/Female/Female 04-1.png");
    AddTextureNPC("data/textures/characters/Female/Female 04-2.png");
    AddTextureNPC("data/textures/characters/Female/Female 04-3.png");
    AddTextureNPC("data/textures/characters/Female/Female 04-4.png");

    AddSoundBuffer("data/sounds/sfx/menuNav.wav");
    AddSoundBuffer("data/sounds/sfx/walking.wav");
    AddSoundBuffer("data/sounds/sfx/Slash_1.wav");
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

void AssetManager::SetLogoTexture(std::string fileTexture) 
{
    std::fstream file;
    file.open(fileTexture.c_str(), std::fstream::in);
    if (file)
    {
        textureLogo.loadFromFile(fileTexture);
    }
    else
        std::cout << "Echec SetLogoTexture( "
                  << fileTexture << " ) : fichier inexistant"
                  << std::endl;
}

void AssetManager::SetSoundTexture(std::string fileTexture) 
{
    std::fstream file;
    file.open(fileTexture.c_str(), std::fstream::in);
    if (file)
    {
        textureSound.loadFromFile(fileTexture);
    }
    else
        std::cout << "Echec SetSoundTexture( "
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

const sf::Texture& AssetManager::GetTextureLogo() const
{
    return textureLogo;
}

const sf::Texture& AssetManager::GetTextureSound() const
{
    return textureSound;
}

const sf::Font& AssetManager::GetMainFont() const
{
    return mainFont;
}

const sf::Color& AssetManager::GetMainTextColor() const
{
    return textColor;
}

const std::vector<sf::SoundBuffer>& AssetManager::GetSoundBuffers() const
{
    return soundBuffers;
}