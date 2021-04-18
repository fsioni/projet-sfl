#include "Box.h"
#include <cassert>
#include "tmxParsing.h"

#include <iostream>

Box::Box(){
    id = x = y = width = height = -1;
}

Box::Box(const std::string& objectTag){
    id = getIntAttributeValue(objectTag, "id");
    x = getIntAttributeValue(objectTag, "x");
    y = getIntAttributeValue(objectTag, "y");
    width = getIntAttributeValue(objectTag, "width");
    height = getIntAttributeValue(objectTag, "height");
}

Box::Box(int nId, int nX, int nY, int nWidth, int nHeight){
    id = nId;
    x = nX;
    y = nY;
    width = nWidth;
    height = nHeight;
}

Box::~Box()
{
}



void Box::SetId(int nId){
    id=nId;
}

int Box::GetId() const{return id;}

void Box::SetPosition(int nX, int nY){
    x = nX;
    y = nY;
}
void Box::SetDimensions(int nWidth, int nHeight){
    width = nWidth;
    height = nHeight;
}

int Box::GetX() const{return x;}
int Box::GetY() const{return y;}

void Box::SetX(int nX) {x = nX;}
void Box::SetY(int nY) {y = nY;}

int Box::GetWidth() const{return width;}
int Box::GetHeight() const{return height;}


void Box::Test() const{
    Box b(1, 2, 3, 4, 5);
    assert(b.id==1 && b.x == 2 && b.y == 3 
           && b.width==4 && b.height == 5);

    b.SetId(10);
    assert(b.GetId()==10);

    b.SetPosition(1, 2);
    assert(b.GetX()==1 && b.GetY()==2);
    

    b.SetDimensions(11, 12);
    assert(b.GetWidth()==11 && b.GetHeight()==12);

    Box b2;
    assert(b2.id == -1 && b2.x == -1 && b2.y == -1
           && b2.height == -1 && b2.width == -1);
}