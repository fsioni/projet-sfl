#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Map/Map.h"



int main(void){
    
    std::string tmxFile = "data/maps/tilemaps/tmxLiteExample.tmx";
    std::string tsxFile = "data/maps/tilesets/tmxLiteExample.tsx";

    Map map(tmxFile, tsxFile);
    

    // ================== Affichage SFML  ==================
    sf::Texture tileTexture;
    sf::Sprite tiles;

    // Chargement de la tileMap
    tileTexture.loadFromFile(map.GetTileset().GetTileMapPath());
    tiles.setTexture(tileTexture);

    sf::RenderWindow window(sf::VideoMode(800, 800, 32), "Tilemap loadind and displaying");
    
   

    while(window.isOpen()){
        sf::Event Event;
        while(window.pollEvent(Event)){
            
            switch (Event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            
            default:
                break;
            }

        }
        window.clear();
        
        int w = map.GetTileset().GetTileWidth();
        int h = map.GetTileset().GetTileHeight();
        int x, y, data;

        // """"Camera"""""
        int px=40;
        int py=40;
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

