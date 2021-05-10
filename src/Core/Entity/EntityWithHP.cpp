#include "EntityWithHP.h"

EntityWithHP::EntityWithHP() : EntityWithHP::EntityWithoutHP()
{

    this->hp = 200;
    this->damage = 20;
    this->maxHP = 200;
    this->livingStatus = true;
    this->speed = 1.0;
}

EntityWithHP::EntityWithHP(float x_, float y_, int hp_,
                        int damage_, int speed_, int maxHP_)
                        : EntityWithoutHP::EntityWithoutHP(x_, y_, speed_)
{
    hp = hp_;
    damage = damage_;
    maxHP = maxHP_;
    livingStatus = true;
}

EntityWithHP::~EntityWithHP()
{

    this->hp = 0;
    this->damage = 0;
    this->maxHP = 0;
}


int EntityWithHP::GetHP() const
{
    return hp;
}

void EntityWithHP::PrintEntityInfo()
{

    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "points de vie : " << hp << std::endl;
    std::cout << "Dégâts : " << damage << std::endl;
    std::cout << "Speed : " << speed << std::endl;
    std::cout << "points de vie max : " << maxHP << std::endl;

    if (livingStatus)
        std::cout << "Le personnage est en vie " << std::endl;
    else
        std::cout << "Le personnage est mort" << std::endl;

    std::cout << std::endl;
}

int EntityWithHP::GetDamage() const
{

    return damage;
}


void EntityWithHP::TakeDamage(int damage)
{
    if(damage>0){
        hp-=damage;
        
        if (hp <= 0)
        {
            livingStatus = false;
            hp = 0;
        }
    }
}


void EntityWithHP::SetLivingStatus(bool newStatus)
{
    livingStatus = newStatus;
}

bool EntityWithHP::GetLivingStatus() const
{
    return livingStatus;
}

int EntityWithHP::GetMaxHP() const
{

    return maxHP;
}

void EntityWithHP::Test() const
{
    std::cout << "===== Class EntityWithHP =====" << std::endl;

    EntityWithHP entity1;
    std::cout << "Constructeur EntityWithHP() : ";
    assert(entity1.hp == 200);
    assert(entity1.damage == 20);
    assert(entity1.maxHP == 200);
    assert(entity1.livingStatus);
    std::cout << "ok" << std::endl;

    std::cout << "Constructeur EntityWithHP(int x_, int y_, int hp_,"
              << " int damage_, int speed_, int maxHealth_) : ";
    EntityWithHP entity2(10, 10, 120, 23, 10, 300);
    assert(entity2.hp == 120);
    assert(entity2.damage == 23);
    assert(entity2.maxHP == 300);
    assert(entity2.livingStatus);
    std::cout << "ok" << std::endl;

    std::cout << "TakeDamage(int damage) : ";
    int hp = entity1.hp;
    entity1.TakeDamage(4);
    assert(entity1.GetHP() == hp - 4);

    hp = entity1.hp;
    entity1.TakeDamage(-8);
    assert(entity1.GetHP() == hp);

    entity1.hp = 10;
    entity1.TakeDamage(13);
    assert(!entity1.livingStatus);
    assert(entity1.hp == 0);
    std::cout << "ok" << std::endl;

    std::cout << "SetLivingStatus(bool newStatus) et GetLivingStatus : ";
    entity1.SetLivingStatus(true);
    assert(entity1.GetLivingStatus());
    entity1.SetLivingStatus(false);
    assert(!entity1.GetLivingStatus());
    std::cout << "ok" << std::endl;

    std::cout << "GetHP() : ";
    entity1.maxHP = 100;
    assert(entity1.GetMaxHP() == 100);
    std::cout << "ok" << std::endl;

    std::cout << std::endl
              << std::endl;
}
