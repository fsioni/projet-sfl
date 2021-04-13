#ifndef NPC_H
#define NPC_H

#include "EntityWithoutHP.h"
#include "Player.h"
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

    void GiveHP (Player &p, int hpToGive);

    string GetRandDialog();

    int RandSentenceLine(int minimum, int maximum);

};

#endif

