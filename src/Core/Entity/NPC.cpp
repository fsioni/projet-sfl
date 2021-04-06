/*#include "NPC.h"
#include "EntityWithoutHP.h"
#include <iostream>
#include <string>
#include <cstring>
#include <assert.h>
#include <random>

using namespace std;

NPC::NPC() : EntityWithoutHP::EntityWithoutHP(){

    const char *DialogTab[9] = {"Wesh mon lossa","s/o roi nouveau rap mondial", "OV chasse les loups dans la ville",
    "Santa fé","focus comme si j'ai bu 100 cafés", "jfinis la tache en balle","Bezos, envoie la prod jla désosse"};

}

NPC::NPC(float x, float y, string name) : EntityWithoutHP::EntityWithoutHP(x, y, name){

    const char *DialogTab[9] = {"Wesh mon lossa","s/o roi nouveau rap mondial", "OV chasse les loups dans la ville",
    "Santa fé","focus comme si j'ai bu 100 cafés", "jfinis la tache en balle","Bezos, envoie la prod jla désosse"};

}

NPC::~NPC(){

    x = 0.0;
    y = 0.0;
}

void NPC::ReadDialog (){

    int lineNumber = rand()%10;

    cout<<*DialogTab[lineNumber]<<endl;

}

char* NPC::GetDialog (){

    strcpy(actuallyTelling,DialogTab[2]);

    return actuallyTelling;

}

*/

















