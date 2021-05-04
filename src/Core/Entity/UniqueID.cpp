#include "UniqueID.h"

#include <iostream>
#include <assert.h>

int UniqueID::nextID = 0;

UniqueID::UniqueID() {
   id = ++nextID;
}


void UniqueID::Test() const{
   std::cout << "===== Class UniqueID =====" << std::endl;

   std::cout << "Initialisation de plusieurs UniqueID avec UniqueID() "<< 
                "et vérif qu'ils soient bien uniques : ";
   UniqueID id1;
   UniqueID id2;
   UniqueID id3;
   UniqueID id4;
   assert(id1.id != id2.id != id3.id != id4.id);
   std::cout << "ok" << std::endl;

   std::cout << std::endl << std::endl;
}