#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>


#include "Layer.h"
#include "Tileset.h"

   
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
    tileTexture.loadFromFile(ts.tileMapPath);
    tiles.setTexture(tileTexture);

    sf::RenderWindow window(sf::VideoMode(1300, 900, 32), "Tilemap loadind and displaying");
    
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
        
        int w = ts.tileWidth;
        int h =ts.tileHeight;
        int x, y, data;
        // Affichage de seulement 1 couche
        for(int k = 0; k < vect.size(); k++){
            for(int i = 0; i < vect[k].width; i++){
                for(int j = 0; j<vect[k].height; j++){
                    data = vect[k].data[i* vect[k].width + j];
                    if(data!=0){
                        x = ((data-1) % 8)*w;
                        y = ((data-1) / 8)*h;

                        tiles.setPosition(i*w, j*h);
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

