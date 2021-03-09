#include <iostream>
#include "tmxParsing.h"

#include "Layer.h"

Layer::Layer(){
    id = -1;
    name = "NULL";
    width = -1;
    height = -1;
}


Layer::~Layer(){

}

void Layer::rawDataToLayer(std::string rawData){
    // std::stoi => string to int
    // getAttributeValue du module tmxParsing
    // => prend un attribut et renvoie sa valeur
    // ex : attribut = id="2" => 2

    id = std::stoi(getAttributeValue(rawData, "id"));
    height = std::stoi(getAttributeValue(rawData, "height"));
    width = std::stoi(getAttributeValue(rawData, "width"));
    name = getAttributeValue(rawData, "name");

    int startData, endData;
    startData = rawData.find("<data ");
    // Recherche de la fin de la balise ouvrante car il y a des
    // des paramètres dedans donc longueur variable
    startData = rawData.find(">", startData); 
    // Ajout de +2 pour avancer la position juste avant le premier entier
    startData+=2; 
    // Position de la balise fermantes
    endData = rawData.find("</data>");

    // Recupère les caractères entre <data> et </data>
    std::string strData = rawData.substr(startData, endData-startData);
    
    // Appel de la fonction du module tmxParsing pour transformer
    // une string sous format CSV (Comma separated values) en un
    // tableau dynamique d'entier.
    data = csvToInt(strData);
}

void Layer::display() const{
    std::cout << "Name : " << name << std::endl;
    std::cout << "Id : " << id << std::endl;
    std::cout << "Height : " << height << std::endl;
    std::cout << "Width : " << width << std::endl;

    std::cout << "Affichage de la première ligne de données :" << std::endl;
    for(int i =0; i<width; i++) std::cout << data[i];
    
    std::cout << std::endl << std::endl;
}



