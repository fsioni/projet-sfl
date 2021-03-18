#include "Box.h"


Box::Box(/* args */)
{
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
int Box::GetHeight() const{return width;}