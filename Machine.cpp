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

Machine::Machine(const std::string &s)
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
		pStr = new std::string[productCount];

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

void Machine::setName(const std::string &s)
{
	name = s;
}

void Machine::addProduct(const std::string &code, int id, int qty, int price, const std::string &desc)
{
	products.addItem(id, qty, price, desc);

	std::string *temp = new std::string[productCount + 1];

	for (int i = 0; i < productCount; i++)
		temp[i] = pStr[i];

	temp[productCount] = code;

	productCount++;

	if (pStr != nullptr)
		delete[] pStr;

	pStr = temp;
}

void Machine::addProduct(const std::string &code, const Inventory::Item &a, int qty)
{
	products.addItem(a, qty);

	std::string *temp = new std::string[productCount + 1];

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

}

void Machine::print(std::ofstream &outFile) const
{
	double initBalance = (initQuarter * QUARTER + initDime * DIME + initNickel * NICKEL) / 100.0;
	double currBalance = (quarter * QUARTER + dime * DIME + nickel * NICKEL) / 100.0;
	double cost = currBalance - initBalance;

	outFile << "Machine: " << name << std::endl
		<< std::fixed << std::showpoint << std::setprecision(2)
		<< "Initial balance: $" << initBalance;
	outFile << " (" << initDollarBill << " $, " << initQuarter << " Q, "
		<< initDime << " D, " << initNickel << " N)" << std::endl;
	outFile << "Number of valid transactions: " << purchaseCount << std::endl;
	outFile << std::fixed << std::showpoint << std::setprecision(2)
		<< "Total cost: $" << cost << std::endl
		<< "Current balance: $" << currBalance;
	outFile << " (" << dollarBill << " $, " << quarter << " Q, "
		<< dime << " D, " << nickel << " N)" << std::endl << std::endl
		<< "Machine inventory:" << std::endl
		<< "Code" << std::setw(8) << "Id" << "    "
		<< std::left << std::setw(20) << "Description"
		<< std::right << "Initial" << std::setw(11) << "Current" << std::endl;

	for (int i = 0; i < productCount; i++)
	{
		outFile << std::setw(4) << pStr[i] << std::setw(8) << products[i].id
			<< "    " << std::left << std::setw(20) << products[i].desc
			<< std::right << std::setw(5) << products[i].initQty
			<< std::setw(11) << products[i].qty << std::endl;
	}
}

void Machine::print(const std::string &fileName) const
{
	std::ofstream outFile(fileName);
	outFile.open(fileName);

	print(outFile);
}

Machine &Machine::operator=(const Machine &r)
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

	if (this != &r)
	{
		if (productCount != r.productCount)
		{
			productCount = r.productCount;

			if (productCount > 0)
			{
				if (pStr != nullptr)
					delete[] pStr;

				pStr = new std::string[productCount];
			}
			else
				pStr = nullptr;
		}

		for (int i = 0; i < productCount; i++)
			pStr[i] = r.pStr[i];
	}

	return *this;
}