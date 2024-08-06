#include "encounter.cpp"
#include "entity.cpp"
#include <cstdlib>

class Monster : private Entity
{

public:
    Monster(uint8_t, uint8_t, uint8_t, std::vector<Action>);
    Action RandomAction();
};

Monster::Monster(
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

Action Monster::RandomAction()
{
    return actions.at(rand() % actions.size());
}
