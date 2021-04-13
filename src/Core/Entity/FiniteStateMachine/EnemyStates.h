#ifndef __ENEMY_STATES__
#define __ENEMY_STATES__

#include "StateBehavior.h"
#include "../Enemy.h"


class Enemy;



// ======== ENEMY PATROL STATE ===========

class EnemyPatrol : public StateBehavior<Enemy>{
protected:
    EnemyPatrol(){};
    static EnemyPatrol* singleton;
public:
    EnemyPatrol(const EnemyPatrol & other)=delete;
    void operator=(const EnemyPatrol & other)=delete;

    static EnemyPatrol* Instance();
    virtual void Enter(Enemy * enemy);
    virtual void Execute(Enemy * enemy);
    virtual void Exit(Enemy * enemy);
};

// ======== ENEMY GLOBAL STATE ===========

class EnemyGlobalState : public StateBehavior<Enemy>{
protected:
    EnemyGlobalState(){}
    static EnemyGlobalState* singleton;
public:
    EnemyGlobalState(const EnemyGlobalState & other)=delete;
    void operator=(const EnemyGlobalState & other)=delete;

    static EnemyGlobalState* Instance();
    virtual void Enter(Enemy * enemy);
    virtual void Execute(Enemy * enemy);
    virtual void Exit(Enemy * enemy);
};

#endif