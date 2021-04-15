#ifndef __STATE_BEHAVIOR__
#define __STATE_BEHAVIOR__

#include "../Player.h"

template <class entity_type>
class StateBehavior{
public:
    virtual void Enter(entity_type *)=0;
    virtual void Execute(entity_type *, std::unique_ptr<Player> & player_)=0; 
    virtual void Exit(entity_type *)=0;
    virtual ~StateBehavior(){};
};



#endif