#include "Machine.h"

Machine::Machine(int q, int d, int n)
{
	if (q < 0)
		q = 0;
	if (d < 0)
		d = 0;
	if (n < 0)
		n = 0;

	initDollarBill = dollarBill = 0;
	initQuarter = quarter = q;
	initDime = dime = d;
	initNickel = nickel = n;
	purchaseCount = 0;
	productCount = 0;
	name = "";
	pStr = nullptr;
}

Machine::Machine(const string &s)
{
	initDollarBill = dollarBill = 0;
	initQuarter = quarter = 0;
	initDime = dime = 0;
	initNickel = nickel = 0;
	purchaseCount = 0;
	productCount = 0;
	name = s;
	pStr = nullptr;
}

Machine::Machine(const Machine &a)
{
	initDollarBill = a.initDollarBill;
	initQuarter = a.initQuarter;
	initDime = a.initDime;
	initNickel = a.initNickel;
	dollarBill = a.dollarBill;
	quarter = a.quarter;
	dime = a.dime;
	nickel = a.nickel;
	purchaseCount = a.purchaseCount;
	productCount = a.productCount;
	name = a.name;
	products = a.products;
	
	if (productCount > 0)
	{
		pStr = new string[productCount];

		for (int i = 0; i < productCount; i++)
			pStr[i] = a.pStr[i];

	}
	else
		pStr = nullptr;

}

Machine::~Machine()
{
	delete[] pStr;
	pStr = nullptr;
}

void Machine::setInitQuarter(int q)
{
	initQuarter = q < 0 ? 0 : q;
}

void Machine::setInitDime(int d)
{
	initDime = d < 0 ? 0 : d;
}

void Machine::setInitNickel(int n)
{
	initNickel = n < 0 ? 0 : n;
}

void Machine::setInitCoins(int q, int d, int n)
{
	setInitQuarter(q);
	setInitDime(d);
	setInitNickel(n);
}

void Machine::setQuarter(int q)
{
	quarter = q < 0 ? 0 : q;
}

void Machine::setDime(int d)
{
	dime = d < 0 ? 0 : d;
}

void Machine::setNickel(int n)
{
	nickel = n < 0 ? 0 : n;
}

void Machine::setCoins(int q, int d, int n)
{
	setQuarter(q);
	setDime(d);
	setNickel(n);
}

void Machine::setName(const string &s)
{
	name = s;
}

void Machine::addProduct(const string &code, int id, int qty, int price, const string &desc)
{
	products.addItem(id, qty, price, desc);

	string *temp = new string[productCount + 1];

	for (int i = 0; i < productCount; i++)
		temp[i] = pStr[i];

	temp[productCount] = code;

	productCount++;

	if (pStr != nullptr)
		delete[] pStr;

	pStr = temp;
}

void Machine::addProduct(const string &code, const Item &a)
{
	products.addItem(a);

	string *temp = new string[productCount + 1];

	for (int i = 0; i < productCount; i++)
		temp[i] = pStr[i];

	temp[productCount] = code;

	productCount++;

	if (pStr != nullptr)
		delete[] pStr;

	pStr = temp;
}

void Machine::purchase()
{
	printPaymentType();

	cout << "Available items:" << endl;

	for (int i = 0; i < productCount; i++)
	{
		if (products[i].qty != 0)
			cout << setw(7) << pStr[i] << setw(4) << products[i].price << " " << products[i].desc << endl;
	}

	int pos;
	bool valid = false;

	do
	{
		cout << "Select an item --> ";
		string code;
		cin >> code;

		int i = 0;
		bool found = false;

		while (!found && i < productCount)
		{
			if (pStr[i] == code)
			{
				pos = i;
				found = true;
			}
			else
				i++;
		}

		if (!found || products[pos].qty == 0)
			cerr << "Error: Invalid option. Please try again" << endl;
		else
			valid = true;

	} while (!valid);

	cout << "You selected \"" << products[pos].desc << "\"." << endl
		<< "The cost of this item is " << products[pos].price << " cents." << endl;

	if (payment())
	{
		products[pos].qty--;
		purchaseCount++;
	}
}

void Machine::print(ofstream &outFile) const
{
	double initBalance = (initQuarter * QUARTER + initDime * DIME + initNickel * NICKEL) / 100.0;
	double currBalance = (quarter * QUARTER + dime * DIME + nickel * NICKEL) / 100.0;
	double cost = currBalance - initBalance;

	outFile << "Machine: " << name << endl
		<< fixed << showpoint << setprecision(2)
		<< "Initial balance: $" << initBalance;
	outFile << " (" << initDollarBill << " $, " << initQuarter << " Q, "
		<< initDime << " D, " << initNickel << " N)" << endl
		<< "Number of valid transactions: " << purchaseCount << endl;
	outFile << fixed << showpoint << setprecision(2)
		<< "Total cost: $" << cost << endl
		<< "Current balance: $" << currBalance;
	outFile << " (" << dollarBill << " $, " << quarter << " Q, "
		<< dime << " D, " << nickel << " N)" << endl << endl
		<< "Machine inventory:" << endl
		<< "Code" << setw(8) << "Id" << "    "
		<< left << setw(20) << "Description"
		<< right << "Initial" << setw(11) << "Current" << endl;

	for (int i = 0; i < productCount; i++)
	{
		outFile << setw(4) << pStr[i] << setw(8) << products[i].id
			<< "    " << left << setw(20) << products[i].desc
			<< right << setw(5) << products[i].initQty << setw(11) << products[i].qty << endl;
	}

	outFile << endl;
}

void Machine::print(const string &fileName) const
{
	ofstream outFile(fileName);
	outFile.open(fileName);

	print(outFile);
}

Machine &Machine::operator=(const Machine &r)
{
	if (this != &r)
	{
		initDollarBill = r.initDollarBill;
		initQuarter = r.initQuarter;
		initDime = r.initDime;
		initNickel = r.initNickel;
		dollarBill = r.dollarBill;
		quarter = r.quarter;
		dime = r.dime;
		nickel = r.nickel;
		purchaseCount = r.purchaseCount;
		name = r.name;
		products = r.products;

		if (productCount != r.productCount)
		{
			productCount = r.productCount;

			if (productCount > 0)
			{
				if (pStr != nullptr)
					delete[] pStr;

				pStr = new string[productCount];
			}
			else
				pStr = nullptr;
		}

		for (int i = 0; i < productCount; i++)
			pStr[i] = r.pStr[i];
	}

	return *this;
}