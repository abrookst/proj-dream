#include "action.h"


void Attack(Entity& e1, Entity& e2)
{
    TextEngine &textEngine = *TextEngine::GetInstance();
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


void Block(Entity& entity)
{
    TextEngine &textEngine = *TextEngine::GetInstance();
    entity.SetBlock(true);
    textEngine.Write(entity.GetName() + " is now blocking.");
}

void Talk(Monster& mon)
{
    TextEngine &textEngine = *TextEngine::GetInstance();

}
void Other(Entity& e1, Entity& e2, Action act) 
{
    TextEngine &textEngine = *TextEngine::GetInstance();

    switch (act)
    {
        case HEALTH_POTION:
            break;
        case HEAVY:
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
            break;
    }
}

std::string GetActionName(Action act) {
    switch (act)
    {
    case HEAVY:
        return "HEAVY";
    
    default:
        return "Unknown";
    }
}