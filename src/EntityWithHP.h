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

    int GetHP() const;

    void SetDamage(unsigned int newDmg);

    int GetDamage() const;

    void PrintEntityInfo() override;

    void TakeDamage(unsigned int damage);

    void Attack(EntityWithHP &target, unsigned int damage) const;

};

#endif
