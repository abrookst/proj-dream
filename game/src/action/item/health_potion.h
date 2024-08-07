#ifndef HEALTH_POTION_H
#define HEALTH_POTION_H

#include "../item.h"
#include "../../entity/entity.h"

class HealthPotion : protected Item
{
    void Perform(
            Entity&);
};

#endif
