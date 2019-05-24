// Header file of Inventory class

#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>

class Inventory
{
public:
	struct Item
	{
		int id;
		int initQty; // initial quantity
		int qty;
		int price;
		std::string desc;
	};

	Inventory();
	Inventory(const Item[], int size);
	Inventory(const Inventory &);
	~Inventory();
	void addItem(int id, int qty = 1, int price = 0, const std::string &desc = "");
	void addItem(const Item &, int qty = 1);
	void setItemList(const Item[], int size);
	int getItem(int id, int qty = 1);
	int getSize() const { return size; }
	Inventory &operator=(const Inventory &);
	Item &operator[](int index) { return pItem[index]; }
	const Item &operator[](int index) const { return pItem[index]; }

private:
	int size;
	Item *pItem;

};

#endif
