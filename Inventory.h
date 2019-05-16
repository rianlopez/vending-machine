// Header file of Inventory class

#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"

class Inventory
{
private:
    int size;
    Item *pItem;

public:
    Inventory(int size = 0, Item *ptr = nullptr);
    Inventory(const Inventory &);
    ~Inventory();
    void addItem(const Item &);
    void removeItem(int);
    void setItemList(const Item [], int);
    int getSize() const;
    int search(const Item &) const;
    Inventory &operator=(const Inventory &);
    Item &operator[](int);

};

#endif
