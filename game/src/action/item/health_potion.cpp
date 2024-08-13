#include "health_potion.h"

void HealthPotion::Perform(
        Entity& entity,
        Entity& other,
        TextEngine& textEngine)
{
    entity.SetHealth(entity.GetMaxHealth());  // Set the health of the entity to the max health
    textEngine.Write("Your Health has been restored!");

    // Remove the health potion from the inventory
}

std::string HealthPotion::GetName()
{
    return "Health Potion";
}

std::string HealthPotion::GetDescription()
{
    return "Restores health to full.";
}
