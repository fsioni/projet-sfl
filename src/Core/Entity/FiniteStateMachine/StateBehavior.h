#ifndef __STATE_BEHAVIOR__
#define __STATE_BEHAVIOR__

#include "../Player.h"
#include "../../Map/Layers/CollisionLayer.h"
#include <memory>

template <class entity_type>
class StateBehavior{
public:
    virtual void Enter(entity_type *)=0;
    virtual void Execute(entity_type *, std::unique_ptr<Player> & player_,
                         CollisionLayer * collision)=0; 
    virtual void Exit(entity_type *)=0;
    virtual ~StateBehavior(){};
};



#endif