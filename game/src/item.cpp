#include "item.h"

#include "entity/player.h"

const char* Item::GetItemName(ItemType item){
    switch (item)
    {
    case BANDAGE:
        return "Bandage";
    
    default:
        return "Invalid Name";
    }
}

void Item::UseItem(ItemType item) {
    Player* player = Player::GetInstance();

    switch (item)
    {
    case BANDAGE:
        player->IncrementHealth(3);
        break;
    
    default:
        break;
    }
}