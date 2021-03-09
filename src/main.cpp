#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>


#include "Layer.h"
#include "Tileset.h"
#include "tmxParsing.h"

   
std::vector<Layer>  tmxToLayersVector(std::string filename){
    std::vector<Layer> vectLayer;
    std::string strLayer;
    std::string strFile = fileToString(filename);
    Layer tmp;
    int start, end;
    start = strFile.find("<layer ", 0);
    end = strFile.find("</layer>", 0);
    
    while(start != std::string::npos && end != std::string::npos){
        strLayer = strFile.substr(start, end-start);
        tmp.rawDataToLayer(strLayer);
        vectLayer.push_back(tmp);

        start = strFile.find("<layer ", end+1);
        end = strFile.find("</layer>", end+1);
    }

    return vectLayer;
}




int main(void){

    std::vector<Layer> vect = tmxToLayersVector("data/maps/tilemaps/tmxLiteExample.tmx");
    
    for(int i=0; i < vect.size(); i++){
        vect[i].display();
    }

    std::string tileset = fileToString("data/maps/tilesets/tmxLiteExample.tsx");
    Tileset ts;
    ts.rawDataToTileset(tileset);
    ts.display();
    
    // ================== Affichage SFML  ==================
    sf::Texture tileTexture;
    sf::Sprite tiles;

    // Chargement de la tileMap
    tileTexture.loadFromFile(ts.GetTileMapPath());
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
        
        int w = ts.GetTileWidth();
        int h =ts.GetTileHeight();
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
        
        for(int k = 0; k < vect.size(); k++){

            for(int i = minX; i<maxX; i++){
                for(int j=minY; j<maxY; j++){
                    data = vect[k].GetData(i, j);
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

