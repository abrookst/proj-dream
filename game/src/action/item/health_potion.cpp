#include "health_potion.h"

void HealthPotion::Preform(
        Entity& entity)
{
    entity.SetHealth(entity.GetHealth());
}
