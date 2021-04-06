/*#ifndef NPC_H
#define NPC_H

#include "EntityWithoutHP.h"
#include <string>

using namespace std;

class NPC : public EntityWithoutHP
{
public:

    static const char * DialogTab[9];

    char* actuallyTelling;

    NPC();

    NPC(float x, float y, string name);

    ~NPC();

    void ReadDialog ();

    char* GetDialog();
};

#endif
*/
