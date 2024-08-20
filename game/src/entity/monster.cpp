#include "monster.h"

#include "entity.h"
#include <cstdlib>

Monster::Monster(
    void)
    : Entity()
{
   
}

Monster::Monster(
        Monster& monster)
    : Entity(
            monster.GetHealth(),
            monster.GetAttackPower(),
            monster.GetAccuracy(),
            monster.GetMana(),
            monster.GetActions(),
            monster.GetName())
{
}

Monster::Monster(
    uint8_t hp,
    uint8_t ap,
    uint8_t acc,
    uint8_t mp,
    std::vector<Action> acts,
    std::string n)
    : Entity(hp, ap, acc, mp, acts, n)
{
    // sprite = spr;
}

Action* Monster::RandomAction()
{
    return actions.at(rand() % actions.size());
}
