// Header file of Machine class

#ifndef MACHINE_H
#define MACHINE_H

#include "Inventory.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// in cents
const int DOLLAR = 100;
const int QUARTER = 25;
const int DIME = 10;
const int NICKEL = 5;

class Machine
{
protected:
	// initial amount
	int initDollar;
	int initQuarter;
	int initDime;
	int initNickel;

	int dollar;
    int quarter;
    int dime;
    int nickel;
	int balance;	   // in cents
	int purchaseCount; // number of valid transactions
    int productCount;
	string name;
	string *pStr;
	Inventory products;

	virtual void printPaymentType() const = 0;
	virtual bool payment(int cost) = 0;

public:
    Machine(int q = 0, int d = 0, int n = 0);
	Machine(const string &);
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
	void setName(const string &);
	void addProduct(const string &code, int id, int qty = 0, int price = 0, const string &desc = "");
	void addProduct(const string &, const Item &);
	void purchase();
	void print(ofstream &outFile) const;
	void print(const string &fileName) const;
	int getQuarter() const { return quarter; }
	int getDime() const { return dime; }
	int getNickel() const { return nickel; }
	string getName() const { return name; }
	Machine &operator=(const Machine &);

	virtual int getNumOfModel() const = 0;

};

#endif
