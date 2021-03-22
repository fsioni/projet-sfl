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

    int GetPos_x() const;

    void SetPos_x(int newX);

    int GetPos_y() const;

    void SetPos_y(int newY);

    string GetName() const;

    void SetName(string newN);

    virtual void PrintEntityInfo();

};

#endif
