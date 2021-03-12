#ifndef ENTITYWITHHP_H
#define ENTITYWITHHP_H

#include "EntityWithoutHP.h"
#include <string>
using namespace std;

class EntityWithHP : public EntityWithoutHP
{
public:

    unsigned int hp;
    unsigned int damage;

    EntityWithHP();

    EntityWithHP(unsigned int x, unsigned int y, string name, unsigned int hp, unsigned int damage);

    ~EntityWithHP();

    void EntityMove(unsigned int vx, unsigned int vy);

    void SetHP(unsigned int newHp);

    int GetHP();

    void SetDamage(unsigned int newDmg);

    int GetDamage();

    int GetPos_x();

    void SetPos_x(int newX);

    int GetPos_y();

    void SetPos_y(int newY);

    string GetName();

    void SetName(string newN);

    void PrintEntityInfo() override;

    //int TakeDamage(unsigned int damage);


    //void Attack(EntityWithHP e);



};

#endif
