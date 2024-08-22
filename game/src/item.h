#ifndef ITEM_H
#define ITEM_H


enum Item 
{
    BANDAGE,
    PILLS
};

const char* GetItemName(Item item);

void UseItem(Item item);

#endif