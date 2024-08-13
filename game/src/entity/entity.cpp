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
    name = "";
}

Entity::Entity(
    uint8_t hp,
    uint8_t ap,
    uint8_t acc,
    uint8_t mp,
    std::vector<Action*>& acts,
    std::string n)
{
    health = hp;
    maxHealth = hp;
    mp = mp;
    maxMana = mp;
    attackPower = ap;
    accuracy = acc;
    actions = acts;
    name = n;

}
