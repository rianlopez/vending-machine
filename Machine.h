// Header file of Machine class

#ifndef MACHINE_H
#define MACHINE_H

#include "Inventory.h"
#include <iostream>
#include <fstream>
#include <iomanip>

// in cents
const int QUARTER = 25;
const int DIME = 10;
const int NICKEL = 5;

class Machine
{
private:
	struct Option
	{
		std::string code;
		Inventory::Item *pItem; // points to an item inside the machine's inventory
	};

	// initial amount of each coin
	int initQuarter;
	int initDime;
	int initNickel;

    int quarter;
    int dime;
    int nickel;
	int purchaseCount; // number of valid transactions
    int productCount;
	std::string name;
	Inventory products;
	Option *pOption;
	virtual void printPaymentType() const = 0;
	virtual bool payment() const = 0;

public:
    Machine(int q = 0, int d = 0, int n = 0);
	Machine(const std::string &);
    Machine(const Machine &);
	~Machine();
	void setInitQuarter(int);
	void setInitDime(int);
	void setInitNickel(int);
	void setInitCoins(int q, int d, int n);
    void setQuarter(int);
    void setDime(int);
    void setNickel(int);
    void setCoins(int q, int d, int n);
	void setName(const std::string &);
	void addProduct(const std::string & code ,int id, int qty, int price, const std::string &desc);
	void addProduct(const std::string code,const Inventory::Item &);
	void purchase();
	void print(const std::string &fileName) const;
	void print(std::ofstream &outFile);
	std::string getName() const;
	Machine &operator=(const Machine &);

};

#endif
