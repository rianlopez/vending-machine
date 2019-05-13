// Implementation file of Item class

#include "Item.h"

Item::Item(int i, const string &d, int p)
{
    id = i;
    description = d;
    if (p >= 0)
        price = p;
    else
        price = 0;
}

void Item::setId(int i)
{
    id = i;
}

void Item::setPrice(int p)
{
    if (p >= 0)
        price = p;
}

void Item::setDescription(const string &d)
{
    description = d;
}

int Item::getId() const
{
    return id;
}

int Item::getPrice() const
{
    return price;
}

string Item::getDescription() const
{
    return description;
}
