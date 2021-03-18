#ifndef _BOX_
#define _BOX_

class Box
{
private:
    int id;
    int x;
    int y;
    int width;
    int height;
public:
    Box(/* args */);
    Box(int nId, int nX, int nY, int nWidth, int nHeight);
    ~Box();
    
    void SetId(int nId);
    void SetPosition(int nX, int nY);
    void SetDimensions(int nWidth, int nHeight);

    int GetId() const;
    int GetX() const;
    int GetY() const;
    int GetWidth() const;
    int GetHeight() const;


    void Test() const;
};



#endif