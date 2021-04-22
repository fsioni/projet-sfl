#include "Layer.h"
#include <iostream>
#include <assert.h>

Layer::Layer(/* args */)
{
    id = -1;
    name = "NULL";
}

Layer::~Layer()
{
}

void Layer::SetId(int id_){
    id = id_;
}

void Layer::SetName(std::string name_){
    name = name_;
}

int Layer::GetID() const{
    return id;
}

std::string Layer::GetName() const{
    return name;
}


void Layer::Test() const{
    std::cout << "===== Class Layer =====" << std::endl;

    Layer layer;
    std::cout << "Constructeur Layer() : ";
    assert(layer.id == -1);
    assert(layer.name == "NULL");
    std::cout << "ok" << std::endl;

    std::cout << "SetId(int id_) : ";
    layer.SetId(10);
    assert(layer.GetID() == 10);
    std::cout << "ok" << std::endl;

    std::cout << "SetName(int name_) : ";
    layer.SetName("layer");
    assert(layer.GetName() == "layer");
    std::cout << "ok" << std::endl;

    std::cout << std::endl << std::endl;
}