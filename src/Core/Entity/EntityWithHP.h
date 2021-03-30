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
    bool livingStatus;
    unsigned int maxHealth;
    float speed;

    EntityWithHP();

    EntityWithHP(float x, float y, string name, unsigned int hp, unsigned int damage, float speed, unsigned int maxHealth);

    ~EntityWithHP();

    void Move(float vx, float vy);

    void SetHP(unsigned int newHp);

    int GetHP() const;

    void SetSpeed(float newSpeed);

    float GetSpeed() const;

    void SetDamage(unsigned int newDmg);

    int GetDamage() const;

    void PrintEntityInfo() override;

    void TakeDamage(unsigned int damage);

    void Attack(EntityWithHP &target, unsigned int damage) const;

    void SetLivingStatus (bool newStatus);

    bool GetLivingStatus() const;

};

#endif
