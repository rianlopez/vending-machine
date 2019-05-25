// Implementation file of Model 100A class

#include "Model100A.h"

int Model100A::numOfModel100A = 0;

void Model100A::printPaymentType() const
{
	cout << "This machine accepts one-dollar bill only." << endl;
}

bool Model100A::payment(int cost)
{
	bool valid = false;

	cout << "Insert your money --> ";

	string input;
	cin.ignore();
	getline(cin, input);
	istringstream inString(input);
	int amount = 0;
	int value;

	while (inString >> value && value != 0)
	{
		if (value == 100)
			amount += value;
	}

	if (amount > 0)
	{
		cout << "You entered an amount of " << amount << " cents." << endl
			<< "Processing your purchase ..." << endl;

		amount -= cost;

		int changeAmount = 0;
		int quarterBack = 0;
		int dimeBack = 0;
		int nickelBack = 0;


		while (changeAmount + QUARTER <= amount && quarterBack != quarter)
		{
			changeAmount += QUARTER;
			quarterBack++;
		}

		if (changeAmount != amount)
		{
			while (changeAmount + DIME <= amount && dimeBack != dime)
			{
				changeAmount += DIME;
				dimeBack++;
			}
		}

		if (changeAmount != amount)
		{
			while (changeAmount + NICKEL <= amount && nickelBack != nickel)
			{
				changeAmount += NICKEL;
				nickelBack++;
			}
		}

		if (changeAmount == amount)
		{
			dollar++;
			quarter -= quarterBack;
			dime -= dimeBack;
			nickel -= nickelBack;

			valid = true;

			cout << "Your change of " << amount << " cents is given as:" << endl
				<< "    quarter(s):" << setw(2) << quarterBack << endl
				<< "    dime(s):" << setw(5) << dimeBack << endl
				<< "    nickel(s):" << setw(3) << nickelBack << endl
				<< "Thank you! Please take your item." << endl;
		}
		else
		{
			cout << "Insufficient changes!" << endl
				<< "Your transaction cannot be processed." << endl
				<< "Please take back your dollar bill." << endl;
		}
	}
	else
		cout << "You chose to cancel your selection." << endl;

	cout << endl;

	return valid;
}

Model100A::Model100A(int q, int d, int n) : Machine(q, d, n)
{
	numOfModel100A++;
}

Model100A::Model100A(const string &s) : Machine(s)
{
	numOfModel100A++;
}

Model100A::Model100A(const Model100A &a) : Machine(a)
{
	numOfModel100A++;
}

Model100A::~Model100A()
{
	Machine::~Machine();
	numOfModel100A--;
}

Model100A &Model100A::operator=(const Model100A &r)
{
	Machine::operator=(r);
	return *this;
}