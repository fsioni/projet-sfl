#include "Player.h"

#include <iostream>
#include <string>
#include <cassert>

Player::Player() : EntityWithHP(){}

Player::Player(float x, float y, std::string name, int hp, int damage,
               float speed, int maxHealth)
: EntityWithHP::EntityWithHP(x, y, name, hp, damage, speed, maxHealth){
}

Player::~Player(){

    x = 0;
    y= 0;
    name = "deletedPlayer";
    hp = 0;
    damage = 0;
    speed = 0;
    maxHealth = 0;
    livingStatus = false;
}

void Player::Test() const{
    std::cout << "===== Class Player =====" << std::endl;
    std::cout << "Pas de fonction ou membre supplémentaire que sa " <<
                "classe mère EntityWithHP déjà testée : ok";
    std::cout << std::endl << std::endl;
}
