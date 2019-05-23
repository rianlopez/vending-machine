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

void initializeMachines(vector<Machine*> pMach);
void initializeInventory(Inventory &inv);
int findSize(string fileName);

int main()
{
	Inventory mainInventory;
	Machine machineSystem;
	vector<Machine *> pMach;
	initializeInventory(mainInventory);
	initializeMachines(pMach);

	//Inventory mach0 = pMach[0]->getInventory();


	return 0;
}

void initializeMachines(vector<Machine*> pMach)
{
	int dollar = 0;
	int quarters = 0;
	int dimes = 0;
	int nickels = 0;
	int capacity = 1;

	int modelQuantity = 0;
	string oneLine;
	string model;

	ifstream machineFile;
	machineFile.open("machines.txt");

	if (!machineFile)
	{
		cout << "Error: Unable to open machine.txt";
		return;
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

	istringstream machineStream;
	int index = 0;

	getline(machineFile, oneLine);
	machineStream.str(oneLine);
	machineStream >> model >> modelQuantity;

	while (!machineFile.eof())
	{
		for (int j = 0; j < modelQuantity; j++)
		{
			
			machineStream.clear();
			getline(machineFile, oneLine);
			machineStream.str(oneLine);
			machineStream >> quarters >> dimes >> nickels;
			machineStream.clear();
			getline(machineFile, oneLine);
			machineStream.str(oneLine);
			machineStream >> capacity;

			if (model == "100A")
			{
				pMach.push_back(new Machine100A(quarters, dimes, nickels, capacity));
				pMach[index]->setCapacity(capacity);

				index++;
					
			}
			else if (model == "100B")
			{
				pMach.push_back(new Machine100B(quarters, dimes, nickels, capacity));
				pMach[index]->setCapacity(capacity);

				index++;
			}
			else if (model == "100C")
			{
				pMach.push_back(new Machine100C(quarters, dimes, nickels, capacity));
				pMach[index]->setCapacity(capacity);

				index++;
			}
			else
			{
			}

			for (int k = 0; k < capacity; k++)
			{
				string code;
				Inventory::Item oneItem;
				int id = 0, quantity = 0;
				getline(machineFile, oneLine);
				machineStream.clear();
				machineStream.str(oneLine);
				machineStream >> code >> id >> quantity;

				oneItem.id = id;
				oneItem.qty = quantity;

				pMach[index-1]->addItem(oneItem); //////////////////////////////////////////////////////////////////////////////////////
			}
		}
		getline(machineFile, oneLine);
		machineStream.clear();
		machineStream.str(oneLine);
		machineStream >> model >> modelQuantity;
	}
	machineFile.close();
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

void initializeInventory(Inventory &inv)
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
		Inventory::Item product;
		istringstream productStream;

		getline(productFile, oneItem);

		productStream.str(oneItem);
		productStream >> id >> quantity >> price;
		getline(productStream, description); 

		product.id = id;
		product.price = price;
		product.initQty = quantity;
		product.qty = quantity;
		product.desc = description;

		inv.addItem(product);

		index++;
	}

	productFile.close();	
}
