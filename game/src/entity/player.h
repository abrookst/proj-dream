#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h";


class Player : private Entity
{
public:
    Player(uint8_t, uint8_t, uint8_t);
};

#endif
