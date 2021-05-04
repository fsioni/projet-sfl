#ifndef __ASSET_MANAGER_H__
#define __ASSET_MANAGER_H__

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>

class AssetManager
{
public:
    AssetManager();
    ~AssetManager();

    void AddTextureEnemy(std::string fileTexture);
    void AddTextureNPC(std::string fileTexture);
    void RemoveTextureEnemy(int indice);
    void RemoveTextureNPC(int indice);

    void SetPlayerTexture(std::string fileTexture);
    void SetShadowTexture(std::string fileTexture);

    const std::vector<sf::Texture> &GetTextureEnemy() const;
    const std::vector<sf::Texture> &GetTextureNPC() const;
    const sf::Texture &GetPlayerTexture() const;
    const sf::Texture &GetShadowTexture() const;

private:
    /*! \brief Tableau vers les textures des ennemis */
    std::vector<sf::Texture> textureEnemy;
    /*! \brief Tableau vers les textures des personnages non joueur */
    std::vector<sf::Texture> textureNPC;
    /*! \brief Texture du joueur */
    sf::Texture texturePlayer;

    /*! \brief Texture d'ombre */
    sf::Texture textureShadow;
};

#endif