#include "Box.h"

#include "tmxParsing.h"

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

void Box::Test() const{}

void Box::SetId(int nId){}
void Box::SetPosition(int nX, int nY){}
void Box::SetDimensions(int nWidth, int nHeight){}

int Box::GetId() const{return id;}
int Box::GetX() const{return x;}
int Box::GetY() const{return y;}
int Box::GetWidth() const{return width;}
int Box::GetHeight() const{return height;}