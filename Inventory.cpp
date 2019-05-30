// Implementation file of Inventory class

#include "Inventory.h"

Inventory::Inventory()
{
    size = 0;
    pItem = nullptr;
}

Inventory::Inventory(const Item a[], int size)
{
	if (size <= 0)
	{
		this->size = 0;
		pItem = nullptr;
	}
	else
	{
		this->size = size;
		pItem = new Item[size];

		for (int i = 0; i < size; i++)
			pItem[i] = a[i];
	}
}

Inventory::Inventory(const Inventory &a)
{
	size = a.size;

	if (size > 0)
	{
		pItem = new Item[size];

		for (int i = 0; i < size; i++)
			pItem[i] = a.pItem[i];
	}
	else
		pItem = nullptr;
}

Inventory::~Inventory()
{
    delete[] pItem;
    pItem = nullptr;
}

void Inventory::addItem(int id, int qty, int price, const std::string &desc)
{
    Item *temp = new Item[size + 1];

    for (int i = 0; i < size; i++)
        temp[i] = pItem[i];

	if (qty < 0)
		qty = 0;
	if (price < 0)
		price = 0;

	temp[size].id = id;
	temp[size].initQty = temp[size].qty = qty;
	temp[size].price = price;
	temp[size].desc = desc;

    size++;

	if (pItem != nullptr)
		delete[] pItem;

    pItem = temp;
}

void Inventory::addItem(const Item &a)
{
	Item *temp = new Item[size + 1];

	for (int i = 0; i < size; i++)
		temp[i] = pItem[i];

	temp[size] = a;

	size++;

	if (pItem != nullptr)
		delete[] pItem;

	pItem = temp;
}

void Inventory::setItemList(const Item a[], int size)
{
	if (size > 0)
	{
		if (this->size != size)
		{
			this->size = size;

			if (pItem != nullptr)
				delete[] pItem;

			pItem = new Item[size];
		}

		for (int i = 0; i < size; i++)
			pItem[i] = a[i];
	}
}

Item Inventory::getItem(int id, int qty)
{
	Item temp;

	if (qty < 0)
		qty = 0;

	int i = 0;
	bool found = false;

	while (!found && i < size)
	{
		if (pItem[i].id == id)
			found = true;
		else
			i++;
	}

	if (found)
	{
		if (pItem[i].qty < qty)
		{
			temp = pItem[i];
			temp.initQty = temp.qty = pItem[i].qty;
			pItem[i].qty = 0;
		}
		else
		{
			temp = pItem[i];
			temp.initQty = temp.qty = qty;
			pItem[i].qty -= qty;
		}
	}
	else
		throw "Error: Item not found";

	return temp;
}

Inventory &Inventory::operator=(const Inventory &a)
{
    if (this != &a)
    {
        if (size != a.size)
        {
            size = a.size;

			if (size > 0)
			{
				if (pItem != nullptr)
					delete[] pItem;

				pItem = new Item[size];
			}
			else
				pItem = nullptr;
        }

        for (int i = 0; i < size; i++)
            pItem[i] = a.pItem[i];
    }

    return *this;
}
