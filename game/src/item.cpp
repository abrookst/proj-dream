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
    default:
        return "Invalid Name";
    }
}

void UseItem(Item item) {
    Player* player = Player::GetInstance();

    std::cout << "Used Item: " << GetItemName(item) << std::endl;

    std::vector<Item>::iterator position = std::find(player->inventory.begin(), player->inventory.end(), item);
    if (position != player->inventory.end()) //Check if item was found
        player->inventory.erase(position);
    else
        std::cout << "Uh oh... tried to remove item, but item was not found" << std::endl;

    switch (item)
    {
    case BANDAGE:
        player->IncrementHealth(3);
        break;
    
    default:
        break;
    }
    
    //Reload scene to update items displayed
    UIEngine* uiengine = UIEngine::GetInstance();
    uiengine->ChangeScreen(ITEMS);
}