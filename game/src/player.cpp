#include "entity.cpp"

class Player : private Entity
{
public:
    Player(uint8_t, uint8_t, uint8_t, std::vector<Action>);
};

Player::Player(
        uint8_t hp,
        uint8_t ap,
        uint8_t acc,
        std::vector<Action> acts)
{
    health = hp;
    maxHealth = hp;
    attackPower = ap;
    accuracy = acc;
    actions = acts;
}
