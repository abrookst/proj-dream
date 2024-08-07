#include "health_potion.h"

void HealthPotion::Perform(
        Entity& entity,
        Entity& other)
{
    entity.SetHealth(entity.GetHealth());
}
