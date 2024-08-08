#ifndef ACTION_H
#define ACTION_H

// #include "../entity/entity.h"

class Entity; // Forward declaration

class Action
{
public:
    virtual void Perform(
            Entity&, 
            Entity&) = 0;
};
#endif
