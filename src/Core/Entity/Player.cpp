#include "Player.h"
#include "Enemy.h"

Player::Player() : EntityWithHP() {}

Player::Player(float x, float y, int hp, int damage,
               float speed, int maxHP)
    : EntityWithHP::EntityWithHP(x, y, hp, damage, speed, maxHP)
{
}

Player::~Player()
{

    this->x = 0.0;
    this->y = 0.0;
    this->hp = 0;
    this->damage = 0;
    this->speed = 0.0;
    this->maxHP = 0;
    this->livingStatus = false;
}

float Player::DistanceShared_ptr(std::shared_ptr<Enemy> enemy) const{
    int x_ = x - enemy->GetPos_x();
    int y_ = y - enemy->GetPos_y();
    return sqrt(x_*x_ + y_*y_);
}

void Player::Attack(std::shared_ptr<Enemy> enemy, CollisionLayer * colLayer) const{
    int radius = 3*32; // <=> 3 cases;
    float dist = DistanceShared_ptr(enemy);

    
    if(dist <= radius){
        float vx = x - enemy->GetPos_x();
        float vy = y - enemy->GetPos_y();
        vx = -vx/dist;
        vy = -vy/dist;
        enemy->TakeDamage(10);
        enemy->MoveWithCollision(vx*10, vy*10, colLayer, 20);
    }
} 

void Player::Test() const
{
    std::cout << "===== Class Player =====" << std::endl;
    std::cout << "Pas de fonction ou membre supplémentaire que sa "
              << "classe mère EntityWithHP déjà testée : ok";
    std::cout << std::endl
              << std::endl;
}