#include "EntityWithHP.h"

EntityWithHP::EntityWithHP() : EntityWithHP::EntityWithoutHP()
{

    this->hp = 200;
    this->damage = 20;
    this->maxHP = 200000;
    this->livingStatus = true;
    this->speed = 1.0;
}

EntityWithHP::EntityWithHP(float x_, float y_, std::string name_, int hp_,
                        int damage_, int speed_, int maxHP_)
                        : EntityWithoutHP::EntityWithoutHP(x_, y_, speed_, name_)
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

void EntityWithHP::SetHP(int newHp)
{
    if (newHp >= 0)
    {
        if (newHp > maxHP)
            hp = maxHP;
        else
            hp = newHp;
    }
}

int EntityWithHP::GetHP() const
{
    return hp;
}

void EntityWithHP::PrintEntityInfo()
{

    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "nom : " << name << std::endl;
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

void EntityWithHP::SetDamage(int newDmg)
{
    if (newDmg >= 0)
        damage = newDmg;
}

void EntityWithHP::TakeDamage(int damage)
{
    assert(damage >= 0);

    if (hp <= 0)
    {

        livingStatus = false;
        hp = 0;
    }
    else
        hp -= damage;
}

void EntityWithHP::Attack(EntityWithHP &target) const
{
    target.TakeDamage(damage);
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

    std::cout << "Constructeur EntityWithHP(int x_, int y_, string name_, "
              << "int hp_, int damage_, int speed_, int maxHealth_) : ";
    EntityWithHP entity2(10, 10, "Entité", 120, 23, 10, 300);
    assert(entity2.hp == 120);
    assert(entity2.damage == 23);
    assert(entity2.maxHP == 300);
    assert(entity2.livingStatus);
    std::cout << "ok" << std::endl;

    std::cout << "SetHP(int newHP) et GetHP() : ";
    entity1.SetHP(13);
    assert(entity1.GetHP() == 13);
    entity1.SetHP(-15);
    assert(entity1.GetHP() == 13);
    std::cout << "ok" << std::endl;

    std::cout << "SetDamage(int newDmg) et GetDamage() : ";
    entity1.SetDamage(30);
    assert(entity1.GetDamage() == 30);
    entity1.SetDamage(-10);
    assert(entity1.GetDamage() == 30);
    std::cout << "ok" << std::endl;

    std::cout << "TakeDamage(int damage) : ";
    int hp = entity1.hp;
    entity1.TakeDamage(4);
    assert(entity1.GetHP() == hp - 4);

    hp = entity1.hp;
    entity1.TakeDamage(-8);
    assert(entity1.GetHP() == hp);

    entity1.SetHP(10);
    entity1.TakeDamage(13);
    assert(!entity1.livingStatus);
    assert(entity1.hp == 0);
    std::cout << "ok" << std::endl;

    std::cout << "Attack(EntityWithHP &target) : ";
    entity1.SetDamage(10);
    entity2.SetHP(30);
    hp = entity2.GetHP();
    entity1.Attack(entity2);
    assert(entity2.GetHP() == 20);
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
