#ifndef __UNIQUE_ID_H__
#define __UNIQUE_ID_H__


class UniqueID {
protected:
   static int nextID;
public:
   int id;
   UniqueID();
   UniqueID(const UniqueID& orig);
   UniqueID& operator=(const UniqueID& orig);
};


#endif
