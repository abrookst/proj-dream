#include "monster.h"

#include "../encounter/encounter.h"
#include "entity.h"
#include <cstdlib>

Monster::Monster(
    void)
    : Entity()
{
   
}

Monster::Monster(
    uint8_t hp,
    uint8_t ap,
    uint8_t acc,
    Image spr)
    : Entity(hp, ap, acc)
{
    sprite = spr;
}

// Action Monster::RandomAction()
// {
    // return actions.at(rand() % actions.size());
// }
