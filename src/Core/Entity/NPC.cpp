#include "NPC.h"

#include <string>
#include <iostream>
#include <assert.h>

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


std::string NPC::GetDialog() const{
    return dialog;
}


void NPC::Test() const{
    std::cout << "===== Class NPC =====" << std::endl;

    std::cout << "NPC() : ";
    NPC npc1;
    assert(npc1.GetDirection()==Down);
    assert(npc1.GetDialog()=="NULL");
    std::cout << "ok" << std::endl;

    std::cout << "NPC(float x, float y, std::string dialog_) : ";
    NPC npc2(10, 10, "TEST DE REGRESSION");
    assert(npc2.GetDirection()==Down);
    assert(npc2.GetDialog()=="TEST DE REGRESSION");
    std::cout << "ok" << std::endl;


    std::cout << std::endl << std::endl;
}