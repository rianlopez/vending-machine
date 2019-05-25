// Header file of Item struct

#ifndef ITEM_H
#define ITEM_H

#include <string>

struct Item
{
	int id;
	int initQty; // initial quantity
	int qty;
	int price;   // in cents
	std::string desc;
};

#endif