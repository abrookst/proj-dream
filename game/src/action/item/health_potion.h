#ifndef HEALTH_POTION_H
#define HEALTH_POTION_H

#include "../item.h"
#include "../../entity/entity.h"

class HealthPotion : public Item
{
protected:
    void Perform(
            Entity&,
            Entity&);
};

const std::string Item::name = "Health Potion";

#endif
