#ifndef _TMX_PARSING_
#define _TMX_PARSING_

#include <string>
#include <vector>


// TODO : rajouter des asserts indice < countTag
std::string getInsideTag(std::string data, std::string tag, int indice);
int countTag(std::string data, std::string tag);
std::string getDataTag(std::string data, std::string tag, int indice);
std::string getFullTag(std::string data, std::string tag, int indice);




/*! \brief Retourne un fichier dans une std::string.
*   \param [in] fileName : std::string, chemin et nom du fichier à lire.
*   
*   Prend un nom de fichier en paramètre, ici souvent d'extension
*   tmx ou tsx et retourne sont contenu stocké dans un std::string.
*/
std::string fileToString(std::string fileName);

/*! \brief Retourne la valeur d'un attribut d'un balise XML.
*   \param [in] str : std::string, chaine de caractère dans laquelle on cherche la valeur.
*   \param [in] attribute : std::string, attribut dont on veut connaitre la valeur.
*   
*   Exemple :
*   std::string str = "<layer id=\"1\" name=\"ground\">";
*   getAttributeValue(str, "id"); // renvoie => "1"
*/
std::string getAttributeValue(std::string str, std::string attribute);

/*! \brief Transforme une std::string sous format csv en tableau dynamique d'entiers.
*   \param [in] data : std::string, donnée sous forme "1, 2, 3, 4, 5"
*/
std::vector<int> csvToInt(std::string data);

#endif