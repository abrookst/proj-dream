#include "magic_blast.h"

void MagicBlast::Perform(
        Entity& e1, 
        Entity& e2,
        TextEngine& textEngine)
{
    uint8_t attackerPower = 2 * e1.GetAttackPower() * 
        (rand() % 100 > e1.GetAccuracy() 
         ? 0 
         : 1);
    if (e2.GetBlock()) { attackerPower = 1; }

    int16_t newMana = e1.GetMana() - 2;
    if (newMana < 0) { e1.SetMana(0); }
    else { e1.SetMana(newMana); }


    int16_t newHealth = e2.GetHealth() - attackerPower;
    if (newHealth < 0) { e2.SetHealth(0); }
    else { e2.SetHealth(newHealth); }
}
