#include "attack.h"
#include <cstdint>
#include <cstdlib>

void Attack::Perform(
        Entity& e1,
        Entity& e2)
{
    uint8_t attackerPower = e1.GetAttackPower() * 
        (rand() % 100 > e1.GetAccuracy() 
         ? 0 
         : 1);
    if (e2.GetBlock()) { attackerPower = 1; }
    e2.SetHealth(e2.GetHealth() - attackerPower);
}
