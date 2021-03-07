#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "Layer.h"

   
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

    
    // Affichage SFML
    sf::Texture tileTexture;
    sf::Sprite tiles;

    sf::RenderWindow window(sf::VideoMode(640, 480, 32), "Tilemap loadind and displaying");
    
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

        window.display();
    }
    

    return 0;
}

