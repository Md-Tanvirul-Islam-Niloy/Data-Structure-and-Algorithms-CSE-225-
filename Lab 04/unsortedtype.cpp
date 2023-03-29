#include "UnsortedType.h"
#include "studentInfo.h"

template <class ItemType>
UnsortedType<ItemType>::UnsortedType()
{
    length = 0;
    currentPos = -1;
}
template <class ItemType>
void UnsortedType<ItemType>::MakeEmpty()
{
    length = 0;
}
template <class ItemType>
bool UnsortedType<ItemType>::IsFull()
{
    return (length == MAX_ITEMS);
}
template <class ItemType>
int UnsortedType<ItemType>::LengthIs()
{
    return length;
}
template <class ItemType>
void UnsortedType<ItemType>::ResetList()
{
    currentPos = -1;
}
template <class ItemType>
void
UnsortedType<ItemType>::GetNextItem(ItemType&
                                    item)
{
    currentPos++;
    item = info [currentPos] ;
}
template <class ItemType>
void
UnsortedType<ItemType>::RetrieveItem(ItemType&
                                     item, bool &found)
{
    int location = 0;
    bool moreToSearch = (location < length);
    found = false;
    while (moreToSearch && !found)
    {
        if(item == info[location])
        {
            found = true;
            item = info[location];
        }
        else
        {
            location++;
            moreToSearch = (location < length);
        }
    }
}

template <class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType
                                        item)
{
    info[length] = item;
    length++;
}
template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType
                                        item)
{
    int location = 0;
    while (item != info[location])
        location++;

    // I have changed the below loop to print the same as Lab manual.
    while (location < length - 1) {
        info[location] = info[location + 1];
        location++;
    }
    length--;
}

