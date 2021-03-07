#include "tmxParsing.h"


std::string fileToString(std::string filename){
    std::string fileContent;
    std::fstream file;
    file.open(filename.c_str(), std::fstream::in);

    if(file){
        file.seekg (0, file.end);
        int length = file.tellg();
        file.seekg (0, file.beg);

        char * buffer = new char[length];

        file.read(buffer, length);
        fileContent = buffer;

        delete [] buffer;
        file.close();
    }
    return fileContent;
}


std::string getAttributeValue(std::string str, std::string attribute){
    int pos = str.find(attribute);
    int start = str.find("\"", pos+attribute.length());
    int end = str.find("\"", start+1);
    std::string res = str.substr(start+1, end-start-1);
    return res;
}

std::vector<int> csvToInt(std::string data){
    
    std::vector<int> vect;
    std::stringstream ss(data);

    for(int i; ss >> i ;){
        vect.push_back(i);
        if(ss.peek()==',') ss.ignore();
    }
    return vect;
}