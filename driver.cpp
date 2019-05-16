// A driver to test functions of the program

#include "Item.h"
#include "Inventory.h"
#include <iostream>

using namespace std;

const int SIZE = 4;

int main()
{
	Inventory inv1;
	cout << "size of inv1: " << inv1.getSize() << endl;

	Item i1(1000);

	inv1.addItem(i1);
	cout << "size of inv1: " << inv1.getSize() << endl
		<< "index of i1: " << inv1.search(i1) << endl
		<< "id of i1: " << inv1[0].getId() << endl;

	Inventory inv2(inv1);

	cout << "size of inv2: " << inv2.getSize() << endl
		<< "index of i1: " << inv2.search(i1) << endl
		<< "id of i1: " << inv2[0].getId() << endl;

	Item list[] = { (1000), (1034) };

	inv2.setItemList(list, 2);

	cout << "size of inv2: " << inv2.getSize() << endl;
	for (int i = 0; i < inv2.getSize(); i++)
		cout << inv2[i].getId() << endl;
	// uncomment to test array bounds
	// inv2[2].getId();

	Inventory inv3;
	inv3 = inv1;

	cout << "size of inv3: " << inv3.getSize() << endl
		<< "index of i1: " << inv3.search(i1) << endl
		<< "id of i1: " << inv3[0].getId() << endl;

	inv3.removeItem(0);

	cout << "size of inv3: " << inv3.getSize() << endl;

	return 0;
}
