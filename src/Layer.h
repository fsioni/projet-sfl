#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "tmxParsing.h"


class Layer{

    int id;
    std::string name;
    int width;
    int height;
    std::vector<int> data;

public :
    Layer();
    Layer(int id_, std::string name_, int width_, int height_, std::vector<int> data_);
    ~Layer();

    void rawDataToLayer(std::string rawData);
    void display() const;


};

