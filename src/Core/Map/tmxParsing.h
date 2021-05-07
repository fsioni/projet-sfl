#ifndef _TMX_PARSING_
#define _TMX_PARSING_

#include <string>
#include <vector>

/*! \brief Retourne un fichier dans une std::string.
*   \param [in] fileName : std::string, chemin et nom du fichier à lire.
*   
*   Prend un nom de fichier en paramètre, ici souvent d'extension
*   tmx ou tsx et retourne sont contenu stocké dans un std::string.
*/
std::string FileToString(std::string fileName);

/*! \brief Retourne le contenu de la balise ouvrante.
*   
*   \param [in] data : std::string, chaine de caractère dans laquelle on cherche.
*   \param [in] tag : std::string, nom de la balise.
*   \param [in] indice : entier positif, ième occurence de la balise.
*
*   \return Retourne ce qu'il y a entre < et > de la balise ouvrante.
*/
std::string GetInsideTag(std::string data, std::string tag, int indice);

/*! \brief Retourne ce qu'il y entre la balise ouvrante et fermante (sans les balises).
*   
*   \param [in] data : std::string, chaine de caractère dans laquelle on cherche.
*   \param [in] tag : std::string, nom de la balise.
*   \param [in] indice : entier positif, ième occurence de la balise.
*
*   \return Retourne ce qu'il y a entre <balise> et </balise> de la balise ouvrante.
*/
std::string GetDataTag(std::string data, std::string tag, int indice);

/*! \brief Retourne ce qu'il y entre la balise ouvrante et fermante (avec les balises).
*   
*   \param [in] data : std::string, chaine de caractère dans laquelle on cherche.
*   \param [in] tag : std::string, nom de la balise.
*   \param [in] indice : entier positif, ième occurence de la balise.
*
*   \return Retourne ce qu'il y a entre < et >.
*/
std::string GetFullTag(std::string data, std::string tag, int indice);


/*! \brief Compte le nombre d'occurence d'une balise.
*   
*   \param [in] data : std::string, chaine de caractère dans laquelle on cherche.
*   \param [in] tag : std::string, nom de la balise.
*
*   \return Retourne le nombre d'occurence d'une balise.
*/
int CountTag(std::string data, std::string tag);


/*! \brief Retourne la valeur d'un attribut d'un balise XML.
*   \param [in] str : std::string, chaine de caractère dans laquelle on cherche la valeur.
*   \param [in] attribute : std::string, attribut dont on veut connaitre la valeur.
*   
*   \return La valeur en std::string d'un paramètre dans la balise ouvrante.
*/
std::string GetAttributeValue(std::string str, std::string attribute);

/*! \brief Retourne la valeur d'un attribut d'un balise XML.
*   \param [in] str : std::string, chaine de caractère dans laquelle on cherche la valeur.
*   \param [in] attribute : std::string, attribut dont on veut connaitre la valeur.
*   
*   Teste que la valeur est bien uniquement numérique.
*
*   \return La valeur en int d'un paramètre dans la balise ouvrante.
*/
int GetIntAttributeValue(std::string str, std::string attribute);

/*! \brief Transforme une std::string sous format csv en tableau dynamique d'entiers.
*   \param [in] data : std::string, donnée sous forme "1, 2, 3, 4, 5"
*/
std::vector<int> CsvToInt(std::string data);

/*! \brief Fonction de test de regression.
*
*   Effectue une série de test de regression sur l'ensemble des
*   fonction membre pour vérifié qu'elles font ce qu'elles sont
*   censé faire.
*/
void TestRegressionTmxParsing();

#endif