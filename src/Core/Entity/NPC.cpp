#include "NPC.h"

#include <string>

NPC::NPC() : EntityWithoutHP::EntityWithoutHP()
{
    direction = Down;
    dialog = "NULL";
}

NPC::NPC(float x, float y, std::string dialog_) : 
            EntityWithoutHP::EntityWithoutHP(x, y, 1)
{
    direction = Down;
    dialog = dialog_;
}

NPC::~NPC(){
    dialog.clear();
}



void NPC::GiveHP(Player &p, int hpToGive){
    int temp;

    temp = p.GetHP() + hpToGive;
    p.SetHP(temp);
}

std::string NPC::GetDialog() const{
    return dialog;
}
