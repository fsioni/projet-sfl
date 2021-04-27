#include "Player.h"


Player::Player() : EntityWithHP(){}


Player::Player(float x, float y, std::string name, int hp, int damage,
               float speed, int maxHP)
: EntityWithHP::EntityWithHP(x, y, name, hp, damage, speed, maxHP){
}


Player::~Player(){

    this->x = 0.0;
    this->y= 0.0;
    this->name = "deletedPlayer";
    this->hp = 0;
    this->damage = 0;
    this->speed = 0.0;
    this->maxHP = 0;
    this->livingStatus = false;
}

void Player::Test() const{
    std::cout << "===== Class Player =====" << std::endl;
    std::cout << "Pas de fonction ou membre supplémentaire que sa " <<
                "classe mère EntityWithHP déjà testée : ok";
    std::cout << std::endl << std::endl;
}
