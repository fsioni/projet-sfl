#ifndef _OBJECT_LAYER_
#define _OBJECT_LAYER_

#include <string>
#include <vector>

class ObjectLayer
{
private:
    /*! \brief Identifiant de la couche représenté par un entier. */
    int id;
    /*! \brief Nom de la couche. */
    std::string name;

public:
    ObjectLayer(/* args */);
    ~ObjectLayer();
};  



#endif