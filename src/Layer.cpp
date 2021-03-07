#include "Layer.h"
#include "tmxParsing.h"

Layer::Layer(){
    id = -1;
    name = "NULL";
    width = -1;
    height = -1;
}

Layer::Layer(int id_, std::string name_, int width_,
             int height_, std::vector<int> data_){
    id = id_;
    name = name_;
    width = width_;
    height = height_;
    data = data_;
}

Layer::~Layer(){

}

void Layer::rawDataToLayer(std::string rawData){
    id = std::stoi(getAttributeValue(rawData, "id"));
    height = std::stoi(getAttributeValue(rawData, "height"));
    width = std::stoi(getAttributeValue(rawData, "width"));
    name = getAttributeValue(rawData, "name");

    int startData, endData;
    startData = rawData.find("<data ");
    // on ne sait pas combien de caractère dans <data .... >
    startData = rawData.find(">", startData); 
    // prochain char + retour à la ligne
    startData+=3; 
    endData = rawData.find("</data>");

    // on recupère les caractères entre <data> et </data>
    std::string strData = rawData.substr(startData, endData-startData);
    
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



