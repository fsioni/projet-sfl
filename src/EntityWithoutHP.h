#ifndef ENTITYWITHOUTHP_H
#define ENTITYWITHOUTHP_H

#include <string>
#include <iostream>

using namespace std;


class EntityWithoutHP
{
public:

    unsigned int x;
    unsigned int y;
    string name;

    EntityWithoutHP();

    EntityWithoutHP(unsigned int x, unsigned int y, string name);

    ~EntityWithoutHP();

    virtual int GetPos_x();

    virtual void SetPos_x(int newX);

    virtual int GetPos_y();

    virtual void SetPos_y(int newY);

    virtual string GetName();

    virtual void SetName(string newN);

    virtual void PrintEntityInfo();

};

#endif
