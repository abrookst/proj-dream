#include "entity.h"

#include <cstdint>
#include <vector>
#include <raylib.h>


Entity::Entity()
{
    health = 0;
    maxHealth = 0;
    attackPower = 0;
    accuracy = 0;
    actions = std::vector<Action*>();
}

Entity::Entity(
    uint8_t hp,
    uint8_t ap,
    uint8_t acc,
    std::vector<Action*>& acts)
{
    health = hp;
    maxHealth = hp;
    attackPower = ap;
    accuracy = acc;
    actions = acts;
}
