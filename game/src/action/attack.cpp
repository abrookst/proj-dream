#include "attack.h"
#include <cstdint>
#include <cstdlib>

void Attack::Preform(
        Entity e1,
        Entity e2)
{
    uint8_t attackerPower = e1.GetAttackPower() * 
        (rand() % 100 > e1.GetAccuracy() 
         ? 1 
         : 0);
    e2.SetHealth(e2.GetHealth() - attackerPower);
}
