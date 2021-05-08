#ifndef __ANIMAL_STATES__
#define __ANIMAL_STATES__

#include "StateBehavior.h"
#include "../Animal.h"

// ======== ANIMAL WALKING STATE ===========

class AnimalWalking : public StateBehavior<Animal>
{
public:
    AnimalWalking(const AnimalWalking &other) = delete;
    void operator=(const AnimalWalking &other) = delete;
    static AnimalWalking *Instance();
    virtual void Enter(Animal *animal);
    virtual void Execute(Animal *animal, std::unique_ptr<Player> &player_,
                         CollisionLayer *collision, int dt);
    virtual void Exit(Animal *animal);

private:
    AnimalWalking(){};
    static AnimalWalking *singleton;
};

// ======== ANIMAL FOLLOWING STATE ===========

class AnimalFollowing : public StateBehavior<Animal>
{
public:
    AnimalFollowing(const AnimalFollowing &other) = delete;
    void operator=(const AnimalFollowing &other) = delete;
    static AnimalFollowing *Instance();
    virtual void Enter(Animal *animal);
    virtual void Execute(Animal *animal, std::unique_ptr<Player> &player_,
                         CollisionLayer *collision, int dt);
    virtual void Exit(Animal *animal);

private:
    AnimalFollowing(){};
    static AnimalFollowing *singleton;
};


#endif