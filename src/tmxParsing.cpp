#include <sstream>
#include <iostream>
#include <fstream>
#include "tmxParsing.h"


std::string fileToString(std::string filename){
    std::string fileContent;
    std::fstream file;

    // Ouvre le fichier filename en lecture seule
    file.open(filename.c_str(), std::fstream::in);

    // Si ouvert correctement
    if(file){

        // Calcul de la longueur du fichier
        file.seekg (0, file.end);
        int length = file.tellg();
        file.seekg (0, file.beg);

        // Enregistrement des données lues dans un tableau de caractère
        char * buffer = new char[length];
        file.read(buffer, length);

        // Copie du tableau de caractère dans un std::string
        fileContent = buffer;

        // Desallocation du buffer et fermeture du fichier
        delete [] buffer;
        file.close();
    }
    return fileContent;
}


std::string getAttributeValue(std::string str, std::string attribute){
    // Recherche de la position de début de l'attribut
    int pos = str.find(attribute);
    // Recherche position du premier " qui suit l'attribut <=> ouverture pour la valeur
    int start = str.find("\"", pos+attribute.length());
    // Recherche position du deuxième " qui suit l'attribut <=> fermeture pour la valeur
    int end = str.find("\"", start+1);
    // On recupère ce qui est entre les " "  et on le retourne
    std::string res = str.substr(start+1, end-start-1);
    return res;
}

std::vector<int> csvToInt(std::string data){
    
    std::vector<int> vect;
    std::stringstream ss(data);

    // Tant qu'on lit dans la std::string on continu
    for(int i; ss >> i ;){
        // On stock dans le std::vector les entiers
        vect.push_back(i);
        // Si le caractère est une virgule on passe
        if(ss.peek()==',') ss.ignore();
    }
    return vect;
}