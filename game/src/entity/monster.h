#ifndef MONSTER_H
#define MONSTER_H

#include <vector>
#include <raylib.h>
#include "entity.h"

class Monster : public Entity
{

public:
    Monster();
    Monster(
        Monster&);
    Monster(
        uint8_t hp,
        uint8_t ap,
        uint8_t acc,
        uint8_t mp,
        std::vector<Action> acts,
        std::string name);

    Action* RandomAction();

private:
    Image sprite;
};

#endif
