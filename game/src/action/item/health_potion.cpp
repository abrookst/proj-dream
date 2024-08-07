#include "health_potion.h"

void HealthPotion::Perform(
        Entity& entity)
{
    entity.SetHealth(entity.GetHealth());
}
