#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"


class Player : public Entity
{
public:
    Player(uint8_t, uint8_t, uint8_t, std::vector<Action*>);
};

#endif
