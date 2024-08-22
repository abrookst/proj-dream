#ifndef ITEM_H
#define ITEM_H


enum Item 
{
    BANDAGE
};

const char* GetItemName(Item item);

void UseItem(Item item);

#endif