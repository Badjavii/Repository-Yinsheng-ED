#ifndef F04_4_ADD_ITEM_H
#define F04_4_ADD_ITEM_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "../FZZ_extra.h"

item *create_Item(string name, string type, int effect_value, int usages)
{
    item *newItem = new item;
    newItem->name = name;
    newItem->type_item = type;
    newItem->effect_value = effect_value;
    newItem->usages = usages;
    newItem->next = nullptr;
    return newItem;
};

void add_Item(item **item_list, item *newItem)
{
    item *current_item = *item_list;

    if (isItemListEmpty(current_item) == true)
    {
        *item_list = newItem;
        return;
    }

    while (current_item->next != nullptr)
        current_item = current_item->next;

    current_item->next = newItem;
    return;
};

#endif // F04_4_ADD_ITEM_H