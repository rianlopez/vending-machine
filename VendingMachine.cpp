/*  Program: VendingMachine.cpp
	Author:
	Class: CSCI 140
	Date: 05/13/2019
	Description: Main class

	I certify that the code below is my own work.

	Exception(s): N/A

*/

#include <iostream>
#include <fstream>
#include <sstream>	
#include <string>
#include "Machine.h"
#include "100A.h"
#include "100B.h"
#include "100C.h"
#include "Item.h"
#include "Inventory.h"
#include <vector>


using namespace std;

void initializeMachines(vector<Machine*> pMach, int size);
void initializeInventory(Inventory inv);
int findSize(string fileName);

int main()
{
	Inventory mainInventory;
	Machine machineSystem;
	initializeInventory(mainInventory);
	vector<Machine *> pMach;

	//Inventory tempInv = mainInventory;

	//for (int i = 0; i < 2; i++)
	//{
	//	cout << tempInv[i].getId() << " " << tempInv[i].getQuantity() << endl;
	//}


	return 0;
}

void initializeMachines(vector<Machine*> pMach, int size)
{
	int dollar = 0;
	int quarters = 0;
	int dimes = 0;
	int nickels = 0;
	int capacity = 0;

	int modelQuantity;
	string oneLine;
	string model;
	istringstream machineStream;

	ifstream machineFile;
	machineFile.open("machines.txt");


	if (!machineFile)
	{
		cout << "Error: Unable to open machine.txt";
		return;
	}
	else
	{
		getline(machineFile, oneLine);
	}


	while (!machineFile.eof())
	{
		for (int i = 0; i < 4; i++)
		{
			machineStream.str(oneLine);
			machineStream >> model >> modelQuantity;

			for (int j = 0; j < modelQuantity; j++)
			{

				getline(machineFile, oneLine);
				machineStream >> quarters >> dimes >> nickels;
				getline(machineFile, oneLine);
				machineStream.str(oneLine);
				machineStream >> capacity;

				if (model == "100A")
				{
					pMach[j] = new Machine100A(quarters, dimes, nickels, capacity);
				}
				else if (model == "100B")
				{
					pMach[j] = new Machine100B(quarters, dimes, nickels, capacity);
				}
				else if (model == "100C")
				{
					pMach[j] = new Machine100C(quarters, dimes, nickels, capacity);
				}
				else
				{

				}

				for (int k = 0; k < capacity; k++)
				{
					int code, id, quantity;
					getline(machineFile, oneLine);
					machineStream >> code >> id >> quantity;
					pMach[j]->addItem(code, id, quantity, k);
				}
			}
		}

		getline(machineFile, oneLine);
	}
}

/*

ifstream machines();
macines >> model >> quantity
loop quantity times
	use if/ switch statement for model
	use vector
	input coins
	input numItems
	loop numIteams
		create a machine w/ an id




*/


	//get model, how many machines for that model
	//input quarters, dimes, nickels,

	//outer loop # of machines
	//get number of items in the machine
	//inner for loop i < # of items in the machine

	//parallel arrays, keep one for code
	//input item id for each code and quantity inside machine Inventory
	//subtract from mainInventory
//}

int findSize(string fileName)
{
	ifstream oneFile;
	int index = 0;
	oneFile.open(fileName);

	if (!oneFile)
	{
		cout << "Error: Unable to open " << fileName;
	}

	while (!oneFile.eof())
	{
		string oneItem;
		getline(oneFile, oneItem);
		index++;
	}
	oneFile.close();

	return index - 1;;
}

void initializeInventory(Inventory inv)
{
	int index = 0;
	int size = findSize("products.txt");

	//item local variables
	int id, price, quantity;
	string description = "";

	string oneItem;
	ifstream productFile;
	productFile.open("products.txt");

	if (!productFile)
	{
		cout << "Error: Unable to open products.txt";
		return;
	}

	//using while loop
	//declare Item product
	//input product id, quantity, price, description
	//add product to Inventory

	while (!productFile.eof() && size != index)
	{
		Item product;
		istringstream productStream;

		getline(productFile, oneItem);

		productStream.str(oneItem);
		productStream >> id >> quantity >> price;
		getline(productStream, description); 

		product.setId(id);
		product.setPrice(price);
		product.setQuantity(quantity);
		product.setDescription(description);

		inv.addItem(product);

		cout << product.getId() << endl;

		index++;
	}



	productFile.close();	
}
