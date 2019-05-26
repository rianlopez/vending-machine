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
	Inventory();
	Inventory(const Item[], int size);
	Inventory(const Inventory &);
	~Inventory();
	void addItem(int id, int qty = 0, int price = 0, const std::string &desc = "");
	void addItem(const Item &);
	void setItemList(const Item[], int size);
	int getSize() const { return size; }
	Item getItem(int id, int qty = 0);
	Inventory &operator=(const Inventory &);
	Item &operator[](int index) { return pItem[index]; }
	const Item &operator[](int index) const { return pItem[index]; }

};

#endif
