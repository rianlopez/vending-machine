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
    Inventory(int size = 0, Item *ptr = nullptr); // Item *ptr can pass an array
                                                  // of Item objects
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
