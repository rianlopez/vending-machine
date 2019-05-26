// Implementation file of Model100B class

#include "Model100B.h"

int Model100B::numOfModel100B = 0;

void Model100B::printPaymentType() const
{
	cout << "This machine accepts coins or one-dollar bill." << endl;
}

bool Model100B::payment(int cost)
{
	bool valid = false;

	if (cost > 0 && cost % 5 == 0)
	{
		int option;

		do
		{
			cout << "Select an option (1 - dollar bill and 2 - coins) --> ";
			cin >> option;

			if (option != 1 && option != 2)
				cerr << "Error: Invalid option. Please try again." << endl;

		} while (option != 1 && option != 2);

		if (option == 1)
			cout << "Insert your money --> ";
		else
			cout << "Please insert your coins --> ";

		string input;
		cin.ignore();
		getline(cin, input);
		istringstream inString(input);
		int dollarCount = 0;
		int quarterCount = 0;
		int dimeCount = 0;
		int nickelCount = 0;
		int amount = 0;
		int value;

		while (inString >> value && value != 0)
		{
			if (option == 1 && value == 100)
			{
				amount += value;
				dollarCount++;
			}
			else if (option == 2)
			{
				if (value == 25)
				{
					amount += value;
					quarterCount++;
					quarter++;
				}
				else if (value == 10)
				{
					amount += value;
					dimeCount++;
					dime++;
				}
				else if (value == 5)
				{
					amount += value;
					nickelCount++;
					nickel++;
				}
			}
		}

		if (amount > 0)
		{
			cout << "You entered an amount of " << amount << " cents." << endl
				<< "Processing your purchase ..." << endl;

			amount -= cost;

			if (amount > 0)
			{
				int changeAmount = 0;
				int quarterBack = 0;
				int dimeBack = 0;
				int nickelBack = 0;


				while (changeAmount + QUARTER <= amount && quarterBack < quarter)
				{
					changeAmount += QUARTER;
					quarterBack++;
				}

				while (changeAmount + DIME <= amount && dimeBack < dime)
				{
					changeAmount += DIME;
					dimeBack++;
				}

				while (changeAmount + NICKEL <= amount && nickelBack < nickel)
				{
					changeAmount += NICKEL;
					nickelBack++;
				}

				if (changeAmount != amount && amount % 10 != 0 && quarter > 0) // for special cases
				{
					changeAmount = 25;
					quarterBack = 1;
					dimeBack = 0;
					nickelBack = 0;

					while (changeAmount + 2 * QUARTER < amount && quarterBack + 2 <= quarter)
					{
						changeAmount += 2 * QUARTER;
						quarterBack += 2;
					}

					while (changeAmount + DIME <= amount && dimeBack < dime)
					{
						changeAmount += DIME;
						dimeBack++;
					}

					while (changeAmount + NICKEL <= amount && nickelBack < nickel)
					{
						changeAmount += NICKEL;
						nickelBack++;
					}
				}

				if (changeAmount == amount)
				{
					dollar += dollarCount;
					quarter -= quarterBack;
					dime -= dimeBack;
					nickel -= nickelBack;

					valid = true;

					cout << "Your change of " << amount << " cents is given as:" << endl
						<< "    quarter(s):" << setw(2) << quarterBack << endl
						<< "    dime(s):" << setw(5) << dimeBack << endl
						<< "    nickel(s):" << setw(3) << nickelBack << endl;
				}
				else
					cout << "Insufficient changes!" << endl;
			}
			else if (amount == 0)
			{
				cout << "Exact change recieved." << endl;
				valid = true;
			}
			else
				cout << "Insufficient funds!" << endl;

			if (valid)
				cout << "Thank you! Please take your item." << endl;
			else
			{
				cout << "Your transaction cannot be processed." << endl;

				if (option == 1)
					cout << "Please take back your dollar bill." << endl;
				else
				{
					quarter -= quarterCount;
					dime -= dimeCount;
					nickel -= nickelCount;

					cout << "Please take back your coins." << endl;
				}
			}
		}
		else
			cout << "You chose to cancel your selection." << endl;

		cout << endl;
	}

	return valid;
}

Model100B::Model100B(int q, int d, int n) : Machine(q, d, n)
{
	numOfModel100B++;
}

Model100B::Model100B(const string &s) : Machine(s)
{
	numOfModel100B++;
}

Model100B::Model100B(const Model100B &a) : Machine(a)
{
	numOfModel100B++;
}

Model100B::~Model100B()
{
	Machine::~Machine();
	numOfModel100B--;
}

Model100B &Model100B::operator=(const Model100B &r)
{
	Machine::operator=(r);
	return *this;
}