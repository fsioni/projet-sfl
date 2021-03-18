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

std::string getFullTag(std::string data, std::string tag, int indice){
    int openTag = 0, closeTag;
    
    for(int i=0; i<=indice; i++){
        openTag = data.find("<"+tag+" ", openTag);
        closeTag = data.find("</"+tag+">", openTag);

        // Gestion du cas où <tag/> au lieu de <tag></tag>
        if(closeTag == (int)std::string::npos)
            closeTag = data.find("\n", openTag);
   
        // On incrémente pour ne pas retrouver la même balise
        openTag++;
    }
    // Décremente à la fin pour remettre la bonne valeur 
    openTag--;
    // On ajoute la longueur de la balise + 3 pour <, / et >
    int len = closeTag-openTag + tag.length() + 3;

    return data.substr(openTag, len);
}

// Si tag pas trouvé alors retourne un espace 
// les indices vont de 0 à n-1 occurence du tag
std::string getInsideTag(std::string data, std::string tag, int indice){
    int startTag = 0, endTag;

    data = getFullTag(data, tag, indice);

    startTag = data.find("<"+tag+" ", startTag);
    endTag = data.find(">", startTag);
     
    

    return data.substr(startTag, endTag-startTag);
}

std::string getDataTag(std::string data, std::string tag, int indice){
    int startOpenTag=0, endOpenTag;
    int startCloseTag;

    data = getFullTag(data, tag, indice);

    startOpenTag = data.find("<"+tag+" ", startOpenTag);
    endOpenTag   = data.find(">", startOpenTag);
    startCloseTag = data.find("</"+tag+">", endOpenTag);


    return data.substr(endOpenTag+2, startCloseTag-endOpenTag-2);
}



int countTag(std::string data, std::string tag){
    int count = 0;
    int pos = 0;
    tag = "<"+tag+" ";
    pos = data.find(tag, pos);
    while(pos != std::string::npos){
        count++;
        pos = data.find(tag, pos+1);
        
    }
    return count;
}