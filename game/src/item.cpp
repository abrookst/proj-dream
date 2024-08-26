#include "item.h"

#include "entity/player.h"
#include <iostream>
#include <algorithm>
#include "ui.h"

const char* GetItemName(Item item){
    switch (item)
    {
    case BANDAGE:
        return "Bandage";
    case PILLS:
        return "Pills";
    case GREEBLE:
        return "Greeble";
    default:
        return "Invalid Name";
    }
}

void UseItem(Item item) {
    Player* player = Player::GetInstance();
    Encounter* encounter = Encounter::GetInstance();
    Monster* monster = nullptr;
    if (typeid(encounter) == typeid(BattleEncounter*)) {
        monster = ((BattleEncounter*) encounter)->GetMonster();
    }

    std::cout << "Used Item: " << GetItemName(item) << std::endl;

    std::vector<Item>::iterator position = std::find(player->inventory.begin(), player->inventory.end(), item);
    if (position != player->inventory.end()) //Check if item was found
        player->inventory.erase(position);
    else
        std::cout << "Uh oh... tried to remove item, but item was not found" << std::endl;
        return;

    switch (item)
    {
    case BANDAGE:
        player->IncrementHealth(3);
        break;
    case GREEBLE:
        if (monster != nullptr) {
            monster->IncrementHealth(-2);
        }
    default:
        break;
    }
    
    //Reload scene to update items displayed
    UIEngine* uiengine = UIEngine::GetInstance();
    uiengine->ChangeScreen(ITEMS);
}