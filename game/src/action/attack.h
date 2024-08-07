#ifndef ATTACK_H
#define ATTACK_H

#include "action.h"
#include "../entity/entity.h"

class Attack : public Action
{
public:
    void Perform(
            Entity&,
            Entity&);
    void Perform(
            Entity&);
};

#endif
