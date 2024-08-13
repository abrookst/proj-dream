#ifndef ACTION_H
#define ACTION_H

// #include "../entity/entity.h"
#include "../text_engine.h"

class Entity; // Forward declaration

class Action
{
public:
    virtual void Perform(
            Entity&, 
            Entity&,
            TextEngine&) = 0;
};
#endif
