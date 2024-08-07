#ifndef ATTACK_H
#define ATTACK_H

#include "action.h"
#include "../entity/entity.h"

class Attack : protected Action
{
public:
    void Preform(
            Entity,
            Entity);
};

#endif
