#include "NPC.h"
#include "EntityWithoutHP.h"


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

NPC::NPC(float x, float y, std::string name) : EntityWithoutHP::EntityWithoutHP(x, y, name){

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

    int n = RandNumberGenerator(0, 8);

    std::cout<<DialogTab[n]<<std::endl;

}

void NPC::GiveHP (Player &p, int hpToGive){

    int temp;

    temp = p.GetHP() + hpToGive;
    p.SetHP(temp);

}


std::string NPC::GetRandDialog (){

    int n = RandNumberGenerator(0, 8);

    return DialogTab[n];

}

void NPC::TalkToPlayer(Player &p, float minX, float maxX, float minY, float maxY){

    if( p.GetPos_x() >= minX && p.GetPos_x() <= maxX && p.GetPos_y() >= minY && p.GetPos_y() <= maxY){

        ReadRandDialog();
    }

}
