#ifndef F04_1_ADD_BPCK_H
#define F04_1_ADD_BPCK_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "../FZZ_extra.h"

bpck *create_Bpck(string name)
{
    bpck *newBpck = new bpck;
    newBpck->name = name;
    newBpck->list_items = nullptr;
    newBpck->next = nullptr;
    return newBpck;
};

void add_Bpck(soldier *object_soldier, bpck **backpack_list, bpck *newBpck)
{
    bpck *current_bpck = *backpack_list;

    if (isBpckListEmpty(current_bpck) == true)
    {
        *backpack_list = newBpck;
        object_soldier->backpag = newBpck;
        return;
    }

    while (current_bpck->next != nullptr)
        current_bpck = current_bpck->next;

    current_bpck->next = newBpck;

    object_soldier->backpag = newBpck;
    return;
};

#endif // F04_1_ADD_BPCK_H