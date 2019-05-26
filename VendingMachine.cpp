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

void initializeMachines(vector<Machine*> pMach, Inventory &mainInventory);
void initializeInventory(Inventory &inv);

int main()
{
	Inventory mainInventory;
	Machine machineSystem;
	vector<Machine *> pMach;
	initializeInventory(mainInventory);
	mainInventory.print();
	initializeMachines(pMach, mainInventory);
	cout << endl << endl;
	mainInventory.print();

	return 0;
}

void initializeMachines(vector<Machine*> pMach, Inventory &mainInventory)
{

	int dollar = 0;
	int quarters = 0;
	int dimes = 0;
	int nickels = 0;

	int capacity = 0; //how many items in one machine
	int modelQuantity = 0; // how many of one type of machine
	string model; // type of machine (100A, 100B, 100C, 100D etc)

	string oneLine; //stores one line of text file

	ifstream machineFile;
	machineFile.open("machines.txt");

	if (!machineFile)
	{
		cout << "Error: Unable to open machine.txt";
		return;
	}
	
	istringstream machineStream;
	int index = 0; //keeps track of index for machine vector

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
				int available = 0;
				int id = 0, quantity = 0;
				getline(machineFile, oneLine);
				machineStream.clear();
				machineStream.str(oneLine);
				machineStream >> code >> id >> quantity;

				oneItem.id = id;
				oneItem.qty = quantity;

				pMach[index-1]->addProduct(code, oneItem); 
				available = mainInventory.getItem(id, quantity);
				//change quantity of main inventory here

			}
		}
		getline(machineFile, oneLine);
		machineStream.clear();
		machineStream.str(oneLine);
		machineStream >> model >> modelQuantity;
	}
	machineFile.close();
}


void initializeInventory(Inventory &inv)
{
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
	while (!productFile.eof())
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
	}

	productFile.close();	
}
