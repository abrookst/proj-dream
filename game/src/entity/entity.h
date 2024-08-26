#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <string>
#include <cstdint>

enum Action
{
    ATTACK,
    BLOCK,
    TALK,
    HEALTH_POTION,
    HEAVY,
};

class Entity
{
public:
    Entity();
    Entity(
        uint8_t hp,
        uint8_t ap,
        uint8_t acc,
        uint8_t mp,
        std::vector<Action> acts,
        std::string n);

    
    void SetHealth(uint8_t hp) { health = hp; }
    void IncrementHealth(uint8_t amount) { health += amount; }
    void SetMaxHealth(uint8_t hp) { maxHealth = hp; }
    void SetMana(uint8_t m) { mana = m; }
    void IncrementMana(uint8_t amount) { mana += amount; }
    void SetMaxMana(uint8_t m) { maxMana = m; }
    void SetAttackPower(uint8_t ap) { attackPower = ap; }
    void SetAccuracy(uint8_t acc) { accuracy = acc; }
    void SetBlock(bool bl) { isBlocking = bl; }
    //create action setters (?)
    const bool GetBlock() { return isBlocking; }
    std::string GetName() { return name; }
    const uint8_t GetHealth() { return health; }
    const float GetHealthPercentage() { return (float)health / (float)maxHealth; }
    const uint8_t GetMaxHealth() { return maxHealth; }
    const uint8_t GetAttackPower() { return attackPower; }
    const uint8_t GetAccuracy() { return accuracy; }
    const uint8_t GetMana() { return mana; }
    const float GetManaPercentage() { return (float)mana / (float)maxMana; }
    const uint8_t GetMaxMana() { return maxMana; }

    std::vector<Action>& GetActions() { return actions; }

protected:
    uint8_t health;
    uint8_t maxHealth;
    uint8_t attackPower;
    uint8_t accuracy;
    uint8_t mana;
    uint8_t maxMana;
    bool isBlocking;
    std::string name;
    std::vector<Action> actions;
};

#endif
