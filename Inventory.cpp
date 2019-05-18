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
	if (size != a.size)
	{
		size = a.size;
		if (pItem != nullptr)
			delete[] pItem;
		pItem = new Item[size];
	}
	for (int i = 0; i < size; i++)
		pItem[i] = a.pItem[i];
}

Inventory::~Inventory()
{
    delete[] pItem;
    pItem = nullptr;
}

void Inventory::addItem(const Item &a)
{
    Item *temp = new Item[size + 1];
    for (int i = 0; i < size; i++)
        temp[i] = pItem[i];
    temp[size] = a;
    size++;
    delete[] pItem;
    pItem = temp;
}

void Inventory::removeItem(int index)
{
    if (index < 0 || index >= size)
    {
        cout << "Error: Array index is out of bounds, exiting" << endl;
        exit(0);
    }
    else if (index != size - 1)
    {
        for (int i = index; i < size - 1; i++)
            pItem[i] = pItem[i + 1];
    }
    Item *temp = new Item[--size];
    for (int i = 0; i < size; i++)
        temp[i] = pItem[i];
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
            delete[] pItem;
            pItem = new Item[size];
        }
        for (int i = 0; i < size; i++)
            pItem[i] = a[i];
    }
}

int Inventory::getSize() const
{
    return size;
}

int Inventory::search(const Item &a) const
{
    int i = 0;
    int pos = -1;
    int key = a.getId();
    bool found = false;
    while (!found && i < size)
    {
        if (pItem[i].getId() == key)
        {
            pos = i;
            found = true;
        }
        else
            i++;
    }
    return pos;
}

Inventory &Inventory::operator=(const Inventory &a)
{
    if (this != &a)
    {
        if (size != a.size)
        {
            size = a.size;
            if (pItem != nullptr)
                delete[] pItem;
            pItem = new Item[size];
        }
        for (int i = 0; i < size; i++)
            pItem[i] = a.pItem[i];
    }
    return *this;
}

Item &Inventory::operator[](int index)
{
    return pItem[index];
}

const Item &Inventory::operator[](int index) const
{
	return pItem[index];
}
