#include "attack.h"
#include <cstdint>
#include <cstdlib>

void Attack::Perform(
        Entity& e1,
        Entity& e2,
        TextEngine& textEngine)
{
    uint8_t attackerPower = e1.GetAttackPower() * 
        (rand() % 100 > e1.GetAccuracy() 
         ? 0 
         : 1);
    if (e2.GetBlock()) { attackerPower = 1; }
    int16_t newHealth = e2.GetHealth() - attackerPower;
    if (newHealth < 0) { e2.SetHealth(0); }
    else { e2.SetHealth(newHealth); }
    textEngine.Write(e1.GetName() + " did " + std::to_string(attackerPower) + " dmg to " + e2.GetName() + ".");
}
