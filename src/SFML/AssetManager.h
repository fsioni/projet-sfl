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

    /*! \brief Ajoute une texture au tableau de textures des ennemis
    *   \param [in] fileTexture : Chemin relatif vers la texture
    */
    void AddTextureEnemy(std::string fileTexture);

    /*! \brief Ajoute une texture au tableau de textures des PNJ
    *   \param [in] fileTexture : Chemin relatif vers la texture
    */
    void AddTextureNPC(std::string fileTexture);

    /*! \brief Ajoute la texture du joueur
    *   \param [in] fileTexture : Chemin relatif vers la texture
    */
    void SetPlayerTexture(std::string fileTexture);

    /*! \brief Ajoute la texture des tuiles
    *   \param [in] fileTexture : Chemin relatif vers la texture
    */
    void SetTileTexture(std::string fileTexture);

    /*! \brief Ajoute la texture de l'ombre
    *   \param [in] fileTexture : Chemin relatif vers la texture
    */
    void SetShadowTexture(std::string fileTexture);

    /*! \brief Ajoute la texture du fond d'écran
    *   \param [in] fileTexture : Chemin relatif vers la texture
    */
    void SetBackgroundTexture(std::string fileTexture);

    /*! \brief Ajoute la texture du coeur
    *   \param [in] fileTexture : Chemin relatif vers la texture
    */
    void SetHeartTexture(std::string fileTexture);

    /*! \brief Ajoute la texture du logo
    *   \param [in] fileTexture : Chemin relatif vers la texture
    */
    void SetLogoTexture(std::string fileTexture);

    /*! \brief Ajoute la texture du son
    *   \param [in] fileTexture : Chemin relatif vers la texture
    */
    void SetSoundTexture(std::string fileTexture);

    /*! \brief Ajoute la texture des animaux
    *   \param [in] fileTexture : Chemin relatif vers la texture
    */
    void SetAnimalTexture(std::string fileTexture);

    /*! \brief Ajoute la police d'écriture principale
    *   \param [in] fileTexture : Chemin relatif vers la texture
    */
    void SetMainFont(std::string fileFont);

    /*! \brief Ajoute la couleur d'écriture principale
    *   \param [in] fileTexture : Chemin relatif vers la texture
    */
    void setMainTextColor(sf::Color color);

    /*! \brief Ajoute un buffer de son au tableau des SoundBuffer
    *   \param [in] fileTexture : Chemin relatif vers la texture
    */
    void AddSoundBuffer(std::string fileBuffer);

    /*! \brief Renvoie le tableau vers les textures des ennemis
    *
    * \return Tableau vers les textures des ennemis
    */
    const std::vector<sf::Texture> &GetTextureEnemy() const;

    /*! \brief Renvoie le tableau vers les textures des personnages non joueur
    *
    * \return Tableau vers les textures des personnages non joueur
    */    
    const std::vector<sf::Texture> &GetTextureNPC() const;

    /*! \brief Renvoie la texture du joueur
    *
    * \return Texture du joueur
    */    
    const sf::Texture &GetPlayerTexture() const;

    /*! \brief Renvoie la texture des tuiles
    *
    * \return Texture des tuiles
    */    
    const sf::Texture &GetTileTexture() const;

    /*! \brief Renvoie la texture d'ombre
    *
    * \return Texture d'ombre
    */    
    const sf::Texture &GetShadowTexture() const;

    /*! \brief Renvoie la texture du fond d'ecran du SplashScreen et du menu principal
    *
    * \return Texture du fond d'ecran du SplashScreen et du menu principal
    */    
    const sf::Texture &GetTextureBackground() const;

    /*! \brief Renvoie la texture du coeur 
    *
    * \return Texture du coeur
    */    
    const sf::Texture &GetTextureHeart() const;
    
    /*! \brief Renvoie la texture du logo du jeu
    *
    * \return Texture du logo du jeu
    */
    const sf::Texture &GetTextureLogo() const;
    
    /*! \brief Renvoie la texture de l'icone son du jeu
    *
    * \return Texture de l'icone son du jeu
    */
    const sf::Texture &GetTextureSound() const;
    
    /*! \brief Renvoie la texture des animaux
    *
    * \return Texture des animaux
    */
    const sf::Texture &GetTextureAnimal() const;

    /*! \brief Renvoie la police d'écriture principale 
    *
    * \return Police d'écriture principale 
    */
    const sf::Font &GetMainFont() const;

    /*! \brief Renvoie la couleur d'écriture principale
    *
    * \return Couleur d'écriture principale
    */
    const sf::Color &GetMainTextColor() const;

    /*! \brief Renvoie le tableau vers les buffers des sons du jeu
    *
    * \return Tableau vers les buffers des sons du jeu
    */
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
    /*! \brief Texture des animaux */
    sf::Texture textureAnimal;

    /*! \brief Police d'écriture principale */
    sf::Font mainFont;
    /*! \brief Couleur d'écriture principale */
    sf::Color textColor;
    
    /*! \brief Tableau vers les buffers des sons du jeu */
    std::vector<sf::SoundBuffer> soundBuffers;
};

#endif