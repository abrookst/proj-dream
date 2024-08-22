#ifndef ITEM_H
#define ITEM_H

class Item {
public:
    enum ItemType 
    {
        BANDAGE
    };

    static const char* GetItemName(ItemType item);

    static void UseItem(ItemType item);
};

#endif