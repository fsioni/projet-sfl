#ifndef __ENEMY_STATES__
#define __ENEMY_STATES__

#include "StateBehavior.h"
#include "../Enemy.h"


class Enemy;

// ======== ENEMY PATROL STATE ===========

class EnemyPatrol : public StateBehavior<Enemy>{
public:
    EnemyPatrol(const EnemyPatrol & other)=delete;
    void operator=(const EnemyPatrol & other)=delete;
    static EnemyPatrol* Instance();
    virtual void Enter(Enemy * enemy);
    virtual void Execute(Enemy * enemy, std::unique_ptr<Player> & player_, 
                        CollisionLayer * collision, int dt);
    virtual void Exit(Enemy * enemy);

private:
    EnemyPatrol(){};
    static EnemyPatrol* singleton;
};

// ======== ENEMY PATROL STATE ===========

class EnemyAttack : public StateBehavior<Enemy>{
public:
    EnemyAttack(const EnemyAttack & other)=delete;
    void operator=(const EnemyAttack & other)=delete;
    static EnemyAttack* Instance();
    virtual void Enter(Enemy * enemy);
    virtual void Execute(Enemy * enemy, std::unique_ptr<Player> & player_,
                         CollisionLayer * collision, int dt);
    virtual void Exit(Enemy * enemy);
    
private:
    EnemyAttack(){};
    static EnemyAttack* singleton;
};


// ======== ENEMY RUNAWAY STATE ===========

class EnemyRunAway : public StateBehavior<Enemy>{
public:
    EnemyRunAway(const EnemyRunAway & other)=delete;
    void operator=(const EnemyRunAway & other)=delete;
    static EnemyRunAway* Instance();
    virtual void Enter(Enemy * enemy);
    virtual void Execute(Enemy * enemy, std::unique_ptr<Player> & player_,
                         CollisionLayer * collision, int dt);
    virtual void Exit(Enemy * enemy);
    
private:
    EnemyRunAway(){};
    static EnemyRunAway* singleton;
};

#endif