#include "Layer.h"
#include <iostream>
#include <assert.h>

Layer::Layer(/* args */)
{
    id = -1;
}

Layer::~Layer()
{
}

void Layer::SetId(int id_)
{
    id = id_;
}


int Layer::GetID() const
{
    return id;
}

void Layer::Test() const
{
    std::cout << "===== Class Layer =====" << std::endl;

    Layer layer;
    std::cout << "Constructeur Layer() : ";
    assert(layer.id == -1);
    std::cout << "ok" << std::endl;

    std::cout << "SetId(int id_) : ";
    layer.SetId(10);
    assert(layer.GetID() == 10);
    std::cout << "ok" << std::endl;

    

    std::cout << std::endl
              << std::endl;
}