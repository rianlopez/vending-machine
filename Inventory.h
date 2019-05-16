// Header file of Inventory class

#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include <iostream>

using namespace std;

class Inventory
{
private:
    int size;
    Item *pItem;

public:
    Inventory();
    Inventory(const Item [], int size);
    Inventory(const Inventory &);
    ~Inventory();
    void addItem(const Item &);
    void removeItem(int index);
    void setItemList(const Item [], int size);
    int getSize() const;
    int search(const Item &) const;
    Inventory &operator=(const Inventory &);
    Item &operator[](int index);

};

#endif
