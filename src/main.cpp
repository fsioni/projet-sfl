#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Map/Map.h"
#include "Map/tmxParsing.h"

// Faire la fonction de tmxParsing getDataTag
/*
int main(void){

    std::string data = fileToString("data/maps/tilemaps/mainTilemap.tmx");

    std::string tag = getDataTag(data, "layer", 1);
    std::string inside = getDataTag(tag, "data", 0);
    std::cout << inside << std::endl;
    
   
    return 0;
}
*/



int main(void){
    
    std::string tmxFile = "data/maps/tilemaps/tmxLiteExample.tmx";
    std::string tsxFile = "data/maps/tilesets/tmxLiteExample.tsx";

    tmxFile = "data/maps/tilemaps/mainTilemap.tmx";
    tsxFile = "data/maps/tilesets/mainTileSet.tsx";

    Map map(tmxFile, tsxFile);
    

    // ================== Affichage SFML  ==================
    sf::Texture tileTexture;
    sf::Sprite tiles;

    // Chargement de la tileMap
    tileTexture.loadFromFile(map.GetTileset().GetTileMapPath());
    tiles.setTexture(tileTexture);

    sf::RenderWindow window(sf::VideoMode(800, 800, 32), "Tilemap loadind and displaying");
    
    int px=40;
    int py=40;

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
                case sf::Keyboard::Right:
                    px ++;
                    break;
                
                case sf::Keyboard::Left:
                    px --;
                    break;
                
                case sf::Keyboard::Up:
                    py --;
                    break;

                case sf::Keyboard::Down:
                    py ++;
                    break;            
                
                default:
                    break;
                }
            
            default:
                break;
            }

        }
        window.clear();
        
        int w = map.GetTileset().GetTileWidth();
        int h = map.GetTileset().GetTileHeight();
        int x, y, data;

        // """"Camera"""""
        
        int winWidth, winHeight;
        
        winHeight = 800;
        winWidth = 800;

        int minX = px - winWidth/w;
        int maxX = px + winWidth/w;
        int minY = py - winHeight/h;
        int maxY = py + winHeight/h;
        
        for(int k = 0; k < map.GetNbMapLayers(); k++){
            MapLayer layer = map.GetMapLayers()[k];
            for(int i = minX; i<maxX; i++){
                for(int j=minY; j<maxY; j++){

                    data = layer.GetData(i, j);
                    if(data!=0){
                        x = ((data-1) % 8)*w;
                        y = ((data-1) / 8)*h;

                        tiles.setPosition((i-minX)*w, (j-minY)*h);
                        tiles.setTextureRect(sf::IntRect(x, y, w, h));
                        window.draw(tiles);
                    }
                }
            }
        }
        window.display();
    }
    
    return 0;
}

