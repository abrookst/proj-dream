#include "player.h"

#include "entity.h"

Player* Player::instance = nullptr;

Player::Player(
        uint8_t hp,
        uint8_t ap,
        uint8_t acc,
        std::vector<Action*>& acts)
    : Entity(hp, ap, acc, acts)
{
    //init future player exclusive vars here
    instance = this;
}
