// Implementation file of Item class

#include "Item.h"

Item::Item(int id, int qty, int price, const string &desc)
{
	if (qty < 0)
		qty = 0;
	if (price < 0)
		price = 0;
    this->id = id;
	quantity = qty;
	this->price = price;
	description = desc;
}

void Item::setId(int a)
{
    id = a;
}

void Item::setQuantity(int a)
{
    if (a >= 0)
        quantity = a;
}

void Item::setPrice(int a)
{
    if (a >= 0)
        price = a;
}

void Item::setDescription(const string &a)
{
    description = a;
}

int Item::getId() const
{
    return id;
}

int Item::getQuantity() const
{
    return quantity;
}

int Item::getPrice() const
{
    return price;
}

string Item::getDescription() const
{
    return description;
}
