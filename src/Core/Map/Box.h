#ifndef _BOX_
#define _BOX_

#include <string>

class Box
{
private:
    int id;
    int x;
    int y;
    int width;
    int height;
public:
    Box();
    Box(const std::string& objectTag);
    Box(int nId, int nX, int nY, int nWidth, int nHeight); // Inutile ?
    ~Box();
    
    void SetId(int nId); // Inutile ?
    void SetPosition(int nX, int nY); // Inutile ?
    void SetDimensions(int nWidth, int nHeight); // Inutile ?

    int GetId() const;
    int GetX() const;
    int GetY() const;
    int GetWidth() const;
    int GetHeight() const;


    void Test() const;
};



#endif