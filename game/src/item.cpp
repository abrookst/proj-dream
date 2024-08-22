#include "item.h"

#include "entity/player.h"

const char* GetItemName(Item item){
    switch (item)
    {
    case BANDAGE:
        return "Bandage";
    
    default:
        return "Invalid Name";
    }
}

void UseItem(Item item) {
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