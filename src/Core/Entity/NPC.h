#ifndef NPC_H
#define NPC_H

#include "EntityWithoutHP.h"
#include <string>

using namespace std;

class NPC : public EntityWithoutHP
{
public:

    string DialogTab[9];

    char* actuallyTelling;

    NPC();

    NPC(float x, float y, string name);

    ~NPC();

    void ReadRandDialog();

    string GetRandDialog();

    int RandSentenceLine(int mini, int maxi);

};

#endif

