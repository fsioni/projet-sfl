#ifndef __ASSET_MANAGER_H__
#define __ASSET_MANAGER_H__

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>

class AssetManager{
public:
    AssetManager();
    ~AssetManager();

    void AddTextureEnemy(std::string fileTexture);
    void AddTextureNPC(std::string fileTexture);
    void RemoveTextureEnemy(int indice);
    void RemoveTextureNPC(int indice);

    void SetPlayerTexture(std::string fileTexture);
    void SetShadowTexture(std::string fileTexture);

    const std::vector<sf::Texture> & GetTextureEnemy() const;
    const std::vector<sf::Texture> & GetTextureNPC() const;
    const sf::Texture & GetPlayerTexture() const;
    const sf::Texture & GetShadowTexture() const;
private:
    std::vector<sf::Texture> textureEnemy;
    std::vector<sf::Texture> textureNPC;
    sf::Texture texturePlayer;
    sf::Texture textureShadow;

    // Ajouter son et font

};


#endif