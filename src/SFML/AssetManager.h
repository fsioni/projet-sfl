#ifndef __ASSET_MANAGER_H__
#define __ASSET_MANAGER_H__

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>

/*! \class AssetManager
*   \brief Classe représentant le gestionnaire des données de l'application
*   (Textures, sons, polices...)
* 
*/
class AssetManager
{
public:
    AssetManager();
    ~AssetManager();

    void AddTextureEnemy(std::string fileTexture);
    void AddTextureNPC(std::string fileTexture);

    void SetPlayerTexture(std::string fileTexture);
    void SetTileTexture(std::string fileTexture);
    void SetShadowTexture(std::string fileTexture);
    void SetBackgroundTexture(std::string fileTexture);
    void SetHeartTexture(std::string fileTexture);
    void SetLogoTexture(std::string fileTexture);
    void SetSoundTexture(std::string fileTexture);

    void SetMainFont(std::string fileFont);
    void setMainTextColor(sf::Color color);

    void AddSoundBuffer(std::string fileBuffer);

    const std::vector<sf::Texture> &GetTextureEnemy() const;
    const std::vector<sf::Texture> &GetTextureNPC() const;
    const sf::Texture &GetPlayerTexture() const;
    const sf::Texture &GetTileTexture() const;
    const sf::Texture &GetShadowTexture() const;
    const sf::Texture &GetTextureBackground() const;
    const sf::Texture &GetTextureHeart() const;
    const sf::Texture &GetTextureLogo() const;
    const sf::Texture &GetTextureSound() const;

    const sf::Font &GetMainFont() const;
    const sf::Color &GetMainTextColor() const;
    const std::vector<sf::SoundBuffer> &GetSoundBuffers() const;

private:
    /*! \brief Tableau vers les textures des ennemis */
    std::vector<sf::Texture> textureEnemy;
    /*! \brief Tableau vers les textures des personnages non joueur */
    std::vector<sf::Texture> textureNPC;

    /*! \brief Texture du joueur */
    sf::Texture texturePlayer;
    /*! \brief Texture des tuiles */
    sf::Texture tileTexture;
    /*! \brief Texture d'ombre */
    sf::Texture textureShadow;
    /*! \brief Texture du fond d'ecran du SplashScreen et du menu principal */
    sf::Texture textureBackground;
    /*! \brief Texture du coeur */
    sf::Texture textureHeart;
    /*! \brief Texture du logo du jeu */
    sf::Texture textureLogo;
    /*! \brief Texture de l'icone son du jeu */
    sf::Texture textureSound;

    /*! \brief Police d'écriture principale */
    sf::Font mainFont;
    /*! \brief Couleur d'écriture principale */
    sf::Color textColor;
    
    /*! \brief Tableau vers les buffers des sons du jeu */
    std::vector<sf::SoundBuffer> soundBuffers;
};

#endif