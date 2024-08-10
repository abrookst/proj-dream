#ifndef MONSTER_H
#define MONSTER_H

#include "entity.h"
#include <vector>
#include <raylib.h>

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
        std::vector<Action*>& acts);

    Action* RandomAction();

private:
    Image sprite;
};

#endif
