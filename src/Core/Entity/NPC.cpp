#include "NPC.h"
#include "EntityWithoutHP.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstring>
#include <assert.h>
#include <time.h>

using namespace std;

NPC::NPC() : EntityWithoutHP::EntityWithoutHP(){

    DialogTab[0] = "Wesh mon lossa";
    DialogTab[1] = "s/o roi nouveau rap mondial";
    DialogTab[2] = "OV chasse les loups dans la ville";
    DialogTab[3] = "Santa fé";
    DialogTab[4] = "focus comme si j'ai bu 100 cafés";
    DialogTab[5] = "jfinis la tache en balle";
    DialogTab[6] = "Bezos, envoie la prod jla désosse";
    DialogTab[7] = "mot8";
    DialogTab[8] = "mot9";

}

NPC::NPC(float x, float y, string name) : EntityWithoutHP::EntityWithoutHP(x, y, name){

    DialogTab[0] = "Wesh mon lossa";
    DialogTab[1] = "s/o roi nouveau rap mondial";
    DialogTab[2] = "OV chasse les loups dans la ville";
    DialogTab[3] = "Santa fé";
    DialogTab[4] = "focus comme si j'ai bu 100 cafés";
    DialogTab[5] = "jfinis la tache en balle";
    DialogTab[6] = "Bezos, envoie la prod jla désosse";
    DialogTab[7] = "mot8";
    DialogTab[8] = "mot9";

}

NPC::~NPC(){

    x = 0.0;
    y = 0.0;
}


void NPC::ReadRandDialog (){

    int n = RandSentenceLine(0, 8);

    cout<<DialogTab[n]<<endl;

}


string NPC::GetRandDialog (){

    int n = RandSentenceLine(0, 8);

    return DialogTab[n];

}


int NPC:: RandSentenceLine (int mini, int maxi){

    int random;

    int plage = maxi - mini + 1;

    for (int i = 0; i < 100; i++) random = (rand() % plage) + mini;

    return random;
}

















