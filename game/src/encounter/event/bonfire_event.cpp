#include "bonfire_event.h"
#include "../../entity/player.h"

void BonfireEvent::startEvent()
{
    Player* player = Player::GetInstance();

    // Prompt player to rest or train
    // textEngine.Write("You are at a bonfire, what would you like to do?")
    
    // Placeholder condition until GUI is developed
    if ("rest")
    {
        // textEngine.Write("Your Health and Mana have been restored to full!")
        player->SetHealth(player->GetMaxHealth());
        player->SetMana(player->GetMaxMana());
    }
    else if ("train")
    {
        // textEngine.Write("Your max Health, Mana and attack power have each increased!")
        player->SetAttackPower(player->GetAttackPower()+1);
        player->SetMaxHealth(player->GetMaxHealth()+1);
        player->SetMaxMana(player->GetMaxMana()+1);
    }
}
