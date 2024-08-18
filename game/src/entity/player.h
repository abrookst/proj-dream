#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include <cstdint>


class Player : public Entity
{
protected:
    static Player* instance;

public:
    Player();
    Player(uint8_t, uint8_t, uint8_t, uint8_t, std::vector<Action*>&, std::string);

    static Player* GetInstance( ) { return instance; };
};

#endif
