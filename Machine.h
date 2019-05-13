// Header file of Machine class

#ifndef MACHINE_H
#define MACHINE_H

#include "Item.h"
#include "ItemManager.h"
#include <string>

class Machine
{
private:
    int dollar;
    int quarter;
    int dime;
    int nickel;
    int capacity;
    Item **pItem;
    ItemManager **pItemManager;

public:
};

#endif
