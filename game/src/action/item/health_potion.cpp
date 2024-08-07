#include "health_potion.h"

void HealthPotion::Perform(
        Entity& entity,
        Entity& other)
{
    entity.SetHealth(entity.GetMaxHealth());  // Set the health of the entity to the max health

    // Remove the health potion from the inventory
}

void HealthPotion::Perform(Entity& entity){}

std::string HealthPotion::GetName()
{
    return "Health Potion";
}

std::string HealthPotion::GetDescription()
{
    return "Restores health to full.";
}
