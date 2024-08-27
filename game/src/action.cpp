#include "action.h"
#include <iostream>


void Attack(Entity& e1, Entity& e2, int power)
{
    TextEngine &textEngine = *TextEngine::GetInstance();
    uint8_t attackerPower = power * 
        (rand() % 100 > e1.GetAccuracy() 
         ? 0 
         : 1);
    if (e2.GetBlock()) { attackerPower = 0; }
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

void ConsumeMana(Entity& e, int mana)
{   
    int16_t newMana = e.GetMana() - mana;
    if (newMana < 0) { e.SetMana(0); }
    else { e.SetMana(newMana); }
}

void Other(Entity& e1, Entity& e2, Action act) 
{
    TextEngine &textEngine = *TextEngine::GetInstance();

    std::cout << "other" << (act) << std::endl;
    switch (act)
    {
        case HEAVY:
            std::cout << "heavy" << std::endl;
            ConsumeMana(e1, 2);
            Attack(e1, e2, e1.GetAttackPower()*2);
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