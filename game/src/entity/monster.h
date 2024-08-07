#ifndef MONSTER_H
#define MONSTER_H

#include "entity.h"
#include <vector>
#include <raylib.h>

class Monster : private Entity
{

public:
    Monster();

    Monster(
        uint8_t hp,
        uint8_t ap,
        uint8_t acc,
        std::vector<Action*> acts,
        Image spr);

    Action* RandomAction();

private:
    Image sprite;
};

#endif
