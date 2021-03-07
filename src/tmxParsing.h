#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


std::string fileToString(std::string fileName);
std::string getAttributeValue(std::string str, std::string attribute);
std::vector<int> csvToInt(std::string data);