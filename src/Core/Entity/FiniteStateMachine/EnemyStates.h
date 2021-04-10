#ifndef __ENEMY_STATES__
#define __ENEMY_STATES__

#include "StateBehavior.h"

class Enemy;



// ======== ENEMY PATROL STATE ===========

class EnemyPatrol : public StateBehavior<Enemy>{
    EnemyPatrol(){};
    static EnemyPatrol * singleton;
public:
    EnemyPatrol(const EnemyPatrol &)=delete;
    EnemyPatrol & operator=(const EnemyPatrol &)=delete;

    static EnemyPatrol* GetInstance();
    virtual void Enter(Enemy * enemy);
    virtual void Execute(Enemy * enemy);
    virtual void Exit(Enemy * enemy);
};

// ======== ENEMY GLOBAL STATE ===========

class EnemyGlobalState : public StateBehavior<Enemy>{
    EnemyGlobalState(){}

public:
    static EnemyGlobalState* Instance();
    virtual void Enter(Enemy * enemy);
    virtual void Execute(Enemy * enemy);
    virtual void Exit(Enemy * enemy);
};

#endif