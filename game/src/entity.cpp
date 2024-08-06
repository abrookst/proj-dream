class Entity
{
public:
    uint8_t health;
    uint8_t maxHealth;
    uint8_t attackPower;
    uint8_t accuracy;

    std::vector<Action> actions;
    Image sprite;

    std::vector<Action> GetActions() { return actions; }
    void SetHealth(uint8_t hp) { health = hp; }
    void SetMaxHealth(uint8_t hp) { maxHealth = hp; }
    void SetAttackPower(uint8_t ap) { attackPower = ap; }
    void SetAccuracy(uint8_t acc) { accuracy = acc; }
    uint8_t GetHealth() { return health; }
    uint8_t GetMaxHealth() { return maxHealth; }
    uint8_t GetAttackPower() { return attackPower; }
    uint8_t GetAccuracy() { return accuracy; }
};
