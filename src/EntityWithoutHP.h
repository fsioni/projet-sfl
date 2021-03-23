#ifndef ENTITYWITHOUTHP_H
#define ENTITYWITHOUTHP_H

#include <string>
#include <iostream>

using namespace std;


class EntityWithoutHP
{
public:

    float x;
    float y;
    string name;

    EntityWithoutHP();

    EntityWithoutHP(float x, float y, string name);

    ~EntityWithoutHP();

    float GetPos_x() const;

    void SetPos_x(float newX);

    float GetPos_y() const;

    void SetPos_y(float newY);

    string GetName() const;

    void SetName(string newName);

    virtual void PrintEntityInfo();

};

#endif
