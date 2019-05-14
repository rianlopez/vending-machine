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
#include "ItemManager.h"

using namespace std;

void inputMachine(Machine arr[], int size);
void inputProducts(Item arr[], ItemManager arr2[], int size);

int main()
{
	const int size = 30; //assuming there are less than 30 kinds of products
	Item inventory[size]; //holds all the products names, ids, and prices
	ItemManager inventoryManager[size]; //holds total inventory quantities
	inputProducts(inventory, inventoryManager, size); 

	return 0;
}

void inputMachine(Machine arr[], int size)
{
	int dollar;
	int quarter;
	int dime;
	int nickel;
	int capacity;

	ifstream machineFile;
	machineFile.open("machines.txt");
	if (!machineFile)
	{
		cout << "Error: Unable to open machine.txt";
		return;
	}
}

void inputProducts(Item itemArr[], ItemManager managerArr[], int size)
{
	int index = 0;

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
		istringstream productStream;

		getline(productFile, oneItem);

		productStream.str(oneItem);
		productStream >> id >> quantity >> price;
		getline(productStream, description); //take in more than one word for description

		itemArr[index].setId(id);
		itemArr[index].setPrice(price);
		itemArr[index].setDescription(description);
		managerArr[index].setQuantity(quantity);

		index++;
	}

	itemArr[index-1].setId(0);
	itemArr[index-1].setPrice(0);
	itemArr[index-1].setDescription("");
	managerArr[index-1].setQuantity(0);

	productFile.close();

	/*
	
	// CODE TESTING
	
	int tempId;
	int tempPrice;
	int tempQuantity;
	string tempName;

	//Print to make sure correct values are input
	for (int i = 0; i < size ; i++)
	{
		tempId = itemArr[i].getId();
		tempPrice = itemArr[i].getPrice();
		tempName = itemArr[i].getDescription();
		tempQuantity = managerArr[i].getQuantity();

		cout << tempId << "   " << tempQuantity << "   " << tempPrice << " " << tempName << endl;
	}

	*/
	
}