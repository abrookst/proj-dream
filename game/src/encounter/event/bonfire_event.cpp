#include "bonfire_event.h"
#include "../../entity/player.h"

void BonfireEvent::startEvent()
{
    Player* player = Player::GetInstance();

    // Prompt player to rest or train
    
    // Placeholder condition until GUI is developed
    if ("rest")
    {
        player->SetHealth(player->GetMaxHealth());
        player->SetMana(player->GetMaxMana());
    }
    else if ("train")
    {
        player->SetAttackPower(player->GetAttackPower()+1);
        player->SetMaxHealth(player->GetMaxHealth()+1);
        player->SetMaxMana(player->GetMaxMana()+1);
    }
}
