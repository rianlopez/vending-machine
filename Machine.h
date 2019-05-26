// Header file of Machine class

#ifndef MACHINE_H
#define MACHINE_H

#include "Inventory.h"
#include <iomanip>

using namespace std;

// in cents
const int QUARTER = 25;
const int DIME = 10;
const int NICKEL = 5;

class Machine
{
private:

	struct Option
	{
		string code;
		Item *pItem; // points to an item inside the machine's inventory
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
	Option *pOption;
    Inventory products;
	Inventory *pInv;   // points to a shared inventory
	virtual void printPaymentType() const = 0;

public:
    Machine(int q = 0, int d = 0, int n = 0);
    Machine(const Machine &);
	~Machine();
    void setQuarter(int);
    void setDime(int);
    void setNickel(int);
    void setCoins(int q, int d, int n);
	void setSharedInv(Inventory *);
	void addProduct(const Item &, int qty = 1);
	int getInitQuarter() const;
	int getInitDime() const;
	int getInitNickel() const;
    int getQuarter() const;
    int getDime() const;
    int getNickel() const;
	int getPurchaseCount() const;
	int getProductCount() const;
	double getInitBalance() const;
	double getCurrBalance() const;
	Machine &operator=(const Machine &);

	friend ostream &operator<<(ostream, const Machine &);

};

#endif
