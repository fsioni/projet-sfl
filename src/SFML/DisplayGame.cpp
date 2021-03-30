#include "DisplayGame.h"


DisplayGame::DisplayGame(){
    game = new Game();
    assets = new AssetManager();
}

DisplayGame::~DisplayGame(){
    delete game;
    game = nullptr;
    delete assets;
    assets = nullptr;
}

void DisplayGame::DisplaySFML() const{
    // ================== Affichage SFML  ==================
        sf::Texture tileTexture, charTextures;
        sf::Sprite tileSprite, charSprite;

        // Chargement de la tileMap
        tileTexture.loadFromFile(game->GetMapConst().GetTileset().GetTileMapPath());
        tileSprite.setTexture(tileTexture);

        // Chargement des charactères
        charTextures.loadFromFile("data/textures/characters/Male/Male 01-1.png");
        charSprite.setTexture(charTextures);

        // Initialisation de la fenetre
        int winWidth = 800;
        int winHeight = 800;
        sf::RenderWindow window(sf::VideoMode(winWidth, winHeight, 32), "Legend Of Nautibus");

        // Horloge
        sf::Clock clock;
        int posX = 0;

        // Direction du joueur 
        // 0 : bas
        // 1 : gauche
        // 2 : droite 
        // 3 : haut
        int direction = 2;

        while(window.isOpen()){
            sf::Event Event;
            while(window.pollEvent(Event)){
                
                switch (Event.type)
                {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    switch (Event.key.code)
                    {
                    case sf::Keyboard::Z:
                        game->KeyboardPressed('z');
                        direction = 3;
                        break;
                    
                    case sf::Keyboard::Q:
                        game->KeyboardPressed('q');
                        direction = 1;
                        break;
                    
                    case sf::Keyboard::S:
                        game->KeyboardPressed('s');
                        direction = 0;
                        break;

                    case sf::Keyboard::D:
                        game->KeyboardPressed('d');
                        direction = 2;
                        break;          

                    case sf::Keyboard::X:
                        window.close();  
                    
                    case sf::Keyboard::Escape:
                        window.close();
                    
                    default:
                        break;
                    }
                
                default:
                    break;
                }

            }
            window.clear();


            // Position du joueur
            int playerX = game->GetPlayerConst().GetPos_x();
            int playerY = game->GetPlayerConst().GetPos_y();

            // Info sur la tilemap
            int w = game->GetMapConst().GetTileset().GetTileWidth();
            int h = game->GetMapConst().GetTileset().GetTileHeight();
            int nbMapLayer = game->GetMapConst().GetMapLayers().size();
            int x, y, data;
            
            // Gestion de camera qui suit le joueur
            int substX = playerX-400;
            int substY = playerY-400;


            // Gestion des bords de map
            if(substX<0) substX = 0;
            if(substX>winWidth) substX = winWidth;
            if(substY<0) substY = 0;
            if(substY>winHeight) substY = winHeight;
            

            // Affichage de la map
            for(int k=0; k<nbMapLayer; k++){
                MapLayer layer = game->GetMapConst().GetMapLayers()[k];
                for(int i=0; i<50; i++){
                    for(int j=0; j<50; j++){
                        data = layer.GetData(i, j);
                        if(data!=0){
                            x = ((data-1) % 8)*w;
                            y = ((data-1) / 8)*h;

                            // Ne pas afficher les tiles non-visibles
                            int tileX = i*w - substX;
                            int tileY = j*h - substY;
                            if(tileX > -w && tileX < winWidth+w && 
                               tileY > -h && tileY < winHeight+h ){

                                tileSprite.setPosition(
                                    i*w-substX, j*h-substY
                                );

                                tileSprite.setTextureRect(
                                    sf::IntRect(x, y, w, h)
                                );

                                window.draw(tileSprite);       
                            }

                               
                        }
                    }
                }
            }

            
            

            
            if(clock.getElapsedTime().asSeconds() > 0.3){
                if(posX==64) posX=0;
                else posX +=32;
                
                clock.restart();
            }
            
           

            // Affichage du joueur
            charSprite.setPosition(playerX-substX, playerY-substY);
            charSprite.setTextureRect(sf::IntRect(posX, direction*32, 32, 32));
            charSprite.scale(w/32, h/32);
            window.draw(charSprite);


            window.display();
        }
}