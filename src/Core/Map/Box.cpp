#include "Box.h"
#include <cassert>
#include "tmxParsing.h"

#include <iostream>

Box::Box(){
    x = -1;
    y = -1;
    width = -1;
    height = -1;
}

Box::Box(const std::string &objectTag){
    x = GetIntAttributeValue(objectTag, "x");
    y = GetIntAttributeValue(objectTag, "y");
    width = GetIntAttributeValue(objectTag, "width");
    height = GetIntAttributeValue(objectTag, "height");
}

Box::Box(int nX, int nY, int nWidth, int nHeight)
{
    x = nX;
    y = nY;
    width = nWidth;
    height = nHeight;
}

Box::~Box()
{
}


void Box::SetPosition(int nX, int nY)
{
    SetX(nX);
    SetY(nY);
}

void Box::SetDimensions(int nWidth, int nHeight)
{
    if (nWidth >= 0)
        width = nWidth;
    if (nHeight >= 0)
        height = nHeight;
}

int Box::GetX() const
{
    return x;
}

int Box::GetY() const
{
    return y;
}

void Box::SetX(int nX)
{
    if (nX >= 0)
        x = nX;
}

void Box::SetY(int nY)
{
    if (nY >= 0)
        y = nY;
}

int Box::GetWidth() const { return width; }
int Box::GetHeight() const { return height; }

void Box::Test() const
{
    std::cout << "===== Class Box =====" << std::endl;

    Box box1;
    std::cout << "Constructeur Box() : ";
    assert(box1.x == -1);
    assert(box1.y == -1);
    assert(box1.width == -1);
    assert(box1.height == -1);
    std::cout << "ok" << std::endl;

    Box box2(2, 3, 4, 5);
    std::cout << "Constructeur Box(int nX, int nY, int nWidth, "
              << "int nHeight) : ";
    assert(box2.x == 2);
    assert(box2.y == 3);
    assert(box2.width == 4);
    assert(box2.height == 5);
    std::cout << "ok" << std::endl;

    std::string tag;
    tag = "<object id=\"14\" x=\"224\" y=\"832\" width=\"64\" height=\"64\"/>";
    Box box3(tag);
    std::cout << "Constructeur Box(const std::string& objectTag) : ";
    assert(box3.x == 224);
    assert(box3.y == 832);
    assert(box3.width == 64);
    assert(box3.height == 64);
    std::cout << "ok" << std::endl;

    std::cout << "SetX(int nX) : ";
    box1.SetX(123);
    assert(box1.GetX() == 123);
    box1.SetX(-134);
    assert(box1.GetX() == 123);
    std::cout << "ok" << std::endl;

    std::cout << "SetY(int nY) : ";
    box1.SetY(123);
    assert(box1.GetY() == 123);
    box1.SetY(-134);
    assert(box1.GetY() == 123);
    std::cout << "ok" << std::endl;

    std::cout << "SetPosition(int nX, int nY) : ";
    box1.SetPosition(12, 10);
    assert(box1.GetX() == 12);
    assert(box1.GetY() == 10);

    box1.SetPosition(-19, 13);
    assert(box1.GetX() == 12);
    assert(box1.GetY() == 13);

    box1.SetPosition(17, -8);
    assert(box1.GetX() == 17);
    assert(box1.GetY() == 13);

    box1.SetPosition(-117, -5);
    assert(box1.GetX() == 17);
    assert(box1.GetY() == 13);
    std::cout << "ok" << std::endl;

    std::cout << "SetDimensions(int nWidth, int nHeight) : ";
    box1.SetDimensions(12, 10);
    assert(box1.GetWidth() == 12);
    assert(box1.GetHeight() == 10);

    box1.SetDimensions(-19, 13);
    assert(box1.GetWidth() == 12);
    assert(box1.GetHeight() == 13);

    box1.SetDimensions(17, -8);
    assert(box1.GetWidth() == 17);
    assert(box1.GetHeight() == 13);

    box1.SetDimensions(-117, -5);
    assert(box1.GetWidth() == 17);
    assert(box1.GetHeight() == 13);
    std::cout << "ok" << std::endl;

    std::cout << std::endl
              << std::endl;
}