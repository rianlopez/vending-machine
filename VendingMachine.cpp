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
#include "Item.h"
#include "Inventory.h"
#include <vector>
#include "Model100A.h"
#include "Model100B.h"
#include "Model100C.h"
#include "Model100D.h"

using namespace std;

void initializeMachines(vector<Machine*> &pMach, Inventory &mainInventory);
void initializeInventory(Inventory &inv);
void initializeSystem(vector<Machine*> &pMach, Inventory &mainInventory);
int search(vector<Machine *> pMach, string key);
void printReport(const vector<Machine *> pMach);
void shutdownSystem(vector <Machine*> &pMach);

int main()
{
	Inventory mainInventory; //contains all the available products
	vector<Machine *> pMach; //contains pointers to all machines
	initializeSystem(pMach, mainInventory);
	printReport(pMach);
	shutdownSystem(pMach);

	return 0;
}

void initializeMachines(vector<Machine*> &pMach, Inventory &mainInventory)
{
	bool knownModel = true;
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
		for (int j = 1; j <= modelQuantity; j++)
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
				knownModel = true;
				pMach.push_back(new Model100A(quarters, dimes, nickels));
				pMach[index]->setName("100A" + to_string(j));

				index++;

			}
			else if (model == "100B")
			{
				knownModel = true;
				pMach.push_back(new Model100B(quarters, dimes, nickels));
				pMach[index]->setName("100B" + to_string(j));

				index++;
			}
			else if (model == "100C")
			{
				knownModel = true;
				pMach.push_back(new Model100C);
				pMach[index]->setName("100C" + to_string(j));

				index++;
			}
			else if (model == "100D")
			{
				knownModel = true;
				pMach.push_back(new Model100D(quarters,dimes,nickels));
				pMach[index]->setName("100D" + to_string(j));

				index++;
			}
			else 
			{
				knownModel = false;
			}

			if (knownModel) //only input if the model name is known or already implemented
			{
				for (int k = 0; k < capacity; k++)
				{
					string code;
					Item oneItem;
					int available = 0;
					int id = 0, quantity = 0;
					int i = 0;
					getline(machineFile, oneLine);
					machineStream.clear();
					machineStream.str(oneLine);
					machineStream >> code >> id >> quantity;

					oneItem = mainInventory.getItem(id, quantity);

					pMach[index - 1]->addProduct(code, oneItem);
				}
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
		Item product;
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

void initializeSystem(vector<Machine*> &pMach, Inventory &mainInventory)
{
	string startUpCode;
	string machineChoice;
	int vectorSize = 0;

	cout << "Please enter a start up code --> ";
	cin >> startUpCode;

	while (startUpCode != "spring19")
	{
		cout << "Start up code not recognized." << endl;
		cout << "Please enter a start up code --> ";
		cin >> startUpCode;
	}

	cout << "Initializing machines. Please wait ..." << endl;
	initializeInventory(mainInventory);
	initializeMachines(pMach, mainInventory);
	cout << "Machines are ready." << endl;

	vectorSize = pMach.size();

	cout << "Available Machines: ";

	for (int i = 0; i < vectorSize; i++)
	{
		cout << pMach[i]->getName();
		if (i != vectorSize - 1)
		{
			cout << ", ";
		}
		else
		{
			cout << " ";
		}
	}

	cout << endl << endl << "Select machine --> ";
	cin >> machineChoice;

	while (machineChoice != "spring19")
	{
		int index = search(pMach, machineChoice);

		while (index == -1 && machineChoice != "spring19")
		{
			cout << "Machine not found! Select machine --> ";
			cin >> machineChoice;
			index = search(pMach, machineChoice);
			cin.clear();
		}

		if (index != -1)
		{
			pMach[index]->purchase();
			cout << "Select machine --> ";
			cin >> machineChoice;
		}
	}
}

int search(vector<Machine *> pMach, string key)
{
	int i = 0;
	int pos = -1;
	bool found = false;
	while (!found && i < pMach.size())
	{
		if (pMach[i]->getName() == key)
		{
			pos = i;
			found = true;
		}
		else
			i++;
	}
	return pos;
}

void printReport(const vector <Machine*> pMach)
{
	cout << "Report is generating ..." << endl;
	for (int i = 0; i < pMach.size(); i++)
	{
		pMach[i]->print("machinesOutput.txt");
	}
}

void shutdownSystem(vector <Machine*> &pMach)
{
	cout << "System is shutting down." << endl;
	for (auto p : pMach)
	{
		delete p;
	}
	pMach.clear();
}
