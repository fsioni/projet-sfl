#include "Layer.h"

Layer::Layer(/* args */)
{
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