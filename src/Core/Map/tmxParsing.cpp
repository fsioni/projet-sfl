#include <sstream>
#include <iostream>
#include <fstream>
#include <regex>
#include "assert.h"

#include "tmxParsing.h"

std::string FileToString(std::string filename)
{
    std::string fileContent;
    std::fstream file;

    // Ouvre le fichier filename en lecture seule
    file.open(filename.c_str(), std::fstream::in);

    // Si pas ouvert correctement on retourn "NULL"
    if(!file) return "NULL";


    // Calcul de la longueur du fichier
    file.seekg(0, file.end);
    int length = file.tellg();
    file.seekg(0, file.beg);

    // Enregistrement des données lues dans un tableau de caractère
    char *buffer = new char[length];
    file.read(buffer, length);

    // Copie du tableau de caractère dans un std::string
    fileContent = buffer;

    // Desallocation du buffer et fermeture du fichier
    delete[] buffer;
    file.close();
    
    
    return fileContent;
}

std::string GetAttributeValue(std::string str, std::string attribute)
{
    // Recherche de la position de début de l'attribut
    // on ajoute un espace car par exemple si on cherche "id" et q'un
    // "width" se trouve avant et qu'il contient "id" alors on renvoira
    // la position du "id" dans "width"
    int pos = str.find(" " + attribute);
    if (pos == (int)std::string::npos)
        return "NULL";
    // Recherche position du premier " qui suit l'attribut <=> ouverture pour la valeur
    int start = str.find("\"", pos + attribute.length());
    // Recherche position du deuxième " qui suit l'attribut <=> fermeture pour la valeur
    int end = str.find("\"", start + 1);
    // On recupère ce qui est entre les " "  et on le retourne
    std::string res = str.substr(start + 1, end - start - 1);
    return res;
}

int GetIntAttributeValue(std::string str, std::string attribute)
{   
    std::string strRes = GetAttributeValue(str, attribute);
    if (strRes == "NULL")
        return -1;

    bool isNumber = std::regex_match(strRes, std::regex{"[+-]?[0-9]+(.[0-9]+)?"});
    if(!isNumber)  
        return -1;  
    
    return stoi(strRes);
}

std::vector<int> CsvToInt(std::string data)
{

    std::vector<int> vect;
    std::stringstream ss(data);

    // Tant qu'on lit dans la std::string on continu
    for (int i; ss >> i;)
    {
        // On stock dans le std::vector les entiers
        vect.push_back(i);
        // Si le caractère est une virgule on passe
        if (ss.peek() == ',')
            ss.ignore();
    }
    return vect;
}

std::string GetFullTag(std::string data, std::string tag, int indice)
{
    if(indice<0) return "NULL";
    int openTag = 0, closeTag;

    for (int i = 0; i <= indice; i++)
    {
        openTag = data.find("<" + tag + " ", openTag);

        if(openTag!=int(std::string::npos)){
            closeTag = data.find("</" + tag + ">", openTag);

            // Gestion du cas où <tag/> au lieu de <tag></tag>
            if (closeTag == (int)std::string::npos)
                closeTag = data.find("\n", openTag);

            // On incrémente pour ne pas retrouver la même balise
            openTag++;
        }
        else return "NULL";
    }
    // Décremente à la fin pour remettre la bonne valeur
    openTag--;
    // On ajoute la longueur de la balise + 3 pour <, / et >
    int len = closeTag - openTag + tag.length() + 3;

    return data.substr(openTag, len);
}

// Si tag pas trouvé alors retourne un espace
// les indices vont de 0 à n-1 occurence du tag
std::string GetInsideTag(std::string data, std::string tag, int indice)
{
    if(indice<0) return "NULL";
    int startTag = 0, endTag;
    
    data = GetFullTag(data, tag, indice);
    // Si balise complete non trouvé on retourn "NULL"
    if(data=="NULL") return "NULL";

    startTag = data.find("<" + tag + " ", startTag);
    // Si balise ouvrante non trouvé on retourne "NULL"
    if(startTag == int(std::string::npos)) return "NULL";
    
    endTag = data.find(">", startTag);
    // +1 pour inclure le ">"
    int len = endTag - startTag + 1;
    return data.substr(startTag, len);
}

// TODO : Gestion des erreur car pour l'instant ne marche
//        que sur les tag de la forme <tag></tag> et pas
//        <tag/>
std::string GetDataTag(std::string data, std::string tag, int indice)
{
    if(indice<0) return "NULL";
    int startOpenTag = 0, endOpenTag;
    int startCloseTag;

    data = GetFullTag(data, tag, indice);
    // Si balise complete non trouvé on retourn "NULL"
    if(data=="NULL") return "NULL";

    startOpenTag = data.find("<" + tag + " ", startOpenTag);
    // Si balise ouvrante non trouvé on retourne "NULL"
    if(startOpenTag == int(std::string::npos)) return "NULL";

    endOpenTag = data.find(">", startOpenTag);
    startCloseTag = data.find("</" + tag + ">", endOpenTag);

    return data.substr(endOpenTag + 1, startCloseTag - endOpenTag - 1);
}

int CountTag(std::string data, std::string tag)
{
    int count = 0;
    int pos = 0;
    tag = "<" + tag + " ";
    pos = data.find(tag, pos);
    while (pos != (int)std::string::npos)
    {
        count++;
        pos = data.find(tag, pos + 1);
    }
    return count;
}

void TestRegressionTmxParsing()
{
    std::cout << "===== TmxParsing =====" << std::endl;
    std::string str = "<tag1 param1=\"test1\" param2=\"test2\"> ceci est un premier test </tag1> \n <tag1 param1=\"test_1\" param2=\"test_2\"> ceci est un deuxième test </tag1>";

    std::string fullTag, insideTag, dataTag;
    
    std::cout << "GetFullTag(std::string data, std::string tag, int indice) : ";

    // Test indice et balise correct
    fullTag = GetFullTag(str, "tag1", 0);
    assert(fullTag == "<tag1 param1=\"test1\" param2=\"test2\"> ceci est un premier test </tag1>");
    fullTag = GetFullTag(str, "tag1", 1);
    assert(fullTag == "<tag1 param1=\"test_1\" param2=\"test_2\"> ceci est un deuxième test </tag1>");
    
    // Test indice trop grand
    fullTag = GetFullTag(str, "tag1", 3);
    assert(fullTag == "NULL");

    // Test indice négatif
    fullTag = GetFullTag(str, "tag1", -3);
    assert(fullTag == "NULL");

    // Test balise non présente
    fullTag = GetFullTag(str, "tag11232", 0);
    assert(fullTag == "NULL");
    std::cout << "ok" << std::endl;


    std::cout << "CountTag(std::string data, std::string tag) : ";
    assert(CountTag(str, "tag1") == 2);
    assert(CountTag(str, "tag2") == 0);
    std::cout << "ok" << std::endl;

    
    std::cout << "GetInsideTag(std::string data, std::string tag, int indice) : ";

    // Test indice et balise correct
    insideTag = GetInsideTag(str, "tag1", 0);
    assert(insideTag == "<tag1 param1=\"test1\" param2=\"test2\">");
    insideTag = GetInsideTag(str, "tag1", 1);
    assert(insideTag == "<tag1 param1=\"test_1\" param2=\"test_2\">");
    
    // Test indice trop grand
    insideTag = GetInsideTag(str, "tag1", 3);
    assert(insideTag == "NULL");

    // Test indice négatif
    insideTag = GetInsideTag(str, "tag1", -3);
    assert(insideTag == "NULL");

    // Test balise non présente
    insideTag = GetInsideTag(str, "tag11232", 0);
    assert(insideTag == "NULL");
    std::cout << "ok" << std::endl;


    std::cout << "GetDataTag(std::string data, std::string tag, int indice) : ";

    // Test indice et balise correct
    dataTag = GetDataTag(str, "tag1", 0);
    assert(dataTag == " ceci est un premier test ");
    dataTag = GetDataTag(str, "tag1", 1);
    assert(dataTag == " ceci est un deuxième test ");

    // Test indice trop grand
    dataTag = GetDataTag(str, "tag1", 3);
    assert(dataTag == "NULL");

    // Test indice négatif
    dataTag = GetDataTag(str, "tag1", -3);
    assert(dataTag == "NULL");

    // Test balise non présente
    dataTag = GetDataTag(str, "tag11232", 0);
    assert(dataTag == "NULL");
    std::cout << "ok" << std::endl;




    str = "<tag param1=\"12\" param2=\"salut\" param3=\"12.322\" param4=\"12.23.2\"/>";
    
    std::cout << "GetAttributeValue(std::string str, std::string attribute) : ";
    assert(GetAttributeValue(str, "param1")=="12");
    assert(GetAttributeValue(str, "param2")=="salut");
    assert(GetAttributeValue(str, "param3")=="12.322");
    assert(GetAttributeValue(str, "param4")=="12.23.2");
    assert(GetAttributeValue(str, "param5")=="NULL");
    std::cout << "ok" << std::endl;


    std::cout << "GetIntAttributeValue(std::string str, std::string attribute) : ";
    assert(GetIntAttributeValue(str, "param1")==12);
    assert(GetIntAttributeValue(str, "param3")==12);
    assert(GetIntAttributeValue(str, "param2")==-1);
    assert(GetIntAttributeValue(str, "param4")==-1);
    std::cout << "ok" << std::endl;


    std::cout << "CsvToInt(std::string data) : ";
    str = "0, 1, 2, 3, 4, 5";
    std::vector<int> res = CsvToInt(str);
    assert(res[0]==0);
    assert(res[1]==1);
    assert(res[2]==2);
    assert(res[3]==3);
    assert(res[4]==4);
    assert(res[5]==5);
    std::cout << "ok"<< std::endl;

    std::cout << std::endl << std::endl;
}