#ifndef _LAYER_
#define _LAYER_

#include <string>

class Layer
{
protected:
    /*! \brief Identifiant de la couche représenté par un entier. */
    int id;
    /*! \brief Nom de la couche. */
    std::string name;
public:
    Layer(/* args */);
    ~Layer();

    void SetId(int id_);
    void SetName(std::string name_);
    int GetID() const;
    std::string GetName() const;
};


#endif