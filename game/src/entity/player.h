#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include <cstdint>
#include "../item.h"


class Player : public Entity
{
protected:
    static Player* instance;

public:
    Player();
    Player( uint8_t hp,
        uint8_t ap,
        uint8_t acc,
        uint8_t mp,
        std::vector<Action> acts,
        std::string n);

    std::vector<Item::ItemType> inventory;

    static Player* GetInstance( ) { return instance; };
};

#endif
