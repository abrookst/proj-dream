#include "encounter.cpp"
#include <cstdlib>

class Monster
{
    uint8_t health;
    uint8_t maxHealth;
    uint8_t attackPower;
    uint8_t accuracy;

    std::vector<Action> actions;

    Image sprite;

public:
    Monster();
    Monster(uint8_t, uint8_t, uint8_t, std::vector<Action>);

    std::vector<Action> GetActions() { return actions; }
    ACTION RandomAction();

    void SetHealth(uint8_t hp) { health = hp; }
    uint8_t GetHealth() { return health; }
    uint8_t GetMaxHealth() { return maxHealth; }
    uint8_t GetAttackPower() { return attackPower; }
    uint8_t GetAccuracy() { return accuracy; }
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
