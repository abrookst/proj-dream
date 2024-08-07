#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <cstdint>
#include "../encounter/encounter.h"

class Entity
{
public:
    Entity();

    Entity(
        uint8_t hp,
        uint8_t ap,
        uint8_t acc);

    
    void SetHealth(uint8_t hp) { health = hp; }
    void SetMaxHealth(uint8_t hp) { maxHealth = hp; }
    void SetAttackPower(uint8_t ap) { attackPower = ap; }
    void SetAccuracy(uint8_t acc) { accuracy = acc; }
    void SetBlock(bool bl) { isBlocking = bl; }
    //create action setters (?)
    const bool GetBlock() { return isBlocking; }
    const uint8_t GetHealth() { return health; }
    const uint8_t GetMaxHealth() { return maxHealth; }
    const uint8_t GetAttackPower() { return attackPower; }
    const uint8_t GetAccuracy() { return accuracy; }

protected:
    uint8_t health;
    uint8_t maxHealth;
    uint8_t attackPower;
    uint8_t accuracy;
    bool isBlocking;
};

#endif