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
    float width;
    float height;
    int offset; // For collision detection
    string name;

    EntityWithoutHP();

    EntityWithoutHP(float x, float y, string name);

    ~EntityWithoutHP();

    float GetPos_x() const;

    void SetPos_x(float newX);

    float GetPos_y() const;

    void SetPos_y(float newY);

    

    int GetWidth() const;

    void SetWidth(int newW);

    int GetHeight() const;

    void SetHeight(int newH);

    int getOffset();

    void setOffset(int newO);

    

    string GetName() const;

    void SetName(string newName);

    virtual void PrintEntityInfo();

};

#endif
