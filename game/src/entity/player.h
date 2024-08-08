#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include <cstdint>


class Player : public Entity
{
protected:
    static Player* instance;
    uint8_t mp;
    uint8_t maxMP;

public:
    Player(uint8_t, uint8_t, uint8_t, std::vector<Action*>&);

    uint8_t GetMana() { return mp; }
    uint8_t GetMaxMana() { return maxMP; }

    void SetMana(uint8_t m) { mp = m; }
    void SetMaxMana(uint8_t m) { maxMP = m; }
    static Player* GetInstance( ) { return instance; };
};

#endif
