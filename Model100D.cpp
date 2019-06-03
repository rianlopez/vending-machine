// Implementation file of Model100D class

#include "Model100D.h"

int Model100D::numOfModel100D = 0;

void Model100D::printPaymentType() const
{
	cout << "This machine accepts coins, one-dollar bill, or credit card." << endl;
}

bool Model100D::payment(int cost)
{
	bool valid = false;

	if (cost > 0 && cost % 5 == 0)
	{
		string option;

		do
		{
			cout << "Select an option (1 - dollar bill, 2 - coins, and 3 - credit card) --> ";
			cin.clear();
			cin.sync();
			getline(cin, option);

			if (option != "1" && option != "2" && option != "3")
				cerr << "Error: Invalid option. Please try again." << endl;


		} while (option != "1" && option != "2" && option != "3");

		if (option == "1")
			cout << "Insert your money --> ";
		else if (option == "2")
			cout << "Please insert your coins --> ";

		if (option == "1" || option == "2")
		{
			string input; //line store money
			cin.clear();
			cin.sync();
			getline(cin, input);
			istringstream inString(input); //string to first store value

			int dollarCount = 0;
			int quarterCount = 0;
			int dimeCount = 0;
			int nickelCount = 0;
			int amount = 0;
			int value; // amount of money input

			while (inString >> input && input != "0")
			{
				if (input.find_first_not_of("0123456789") == string::npos)
				{
					value = stoi(input);

					if (option == "1" && value == 100)
					{
						amount += value;
						dollarCount++;
					}
					else if (option == "2")
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

					if (option == "1")
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
			{
				cout << "You chose to cancel your selection." << endl;
			}
		}
		else
		{
			int attemptCount = 0;
			do
			{
				int CreditCard[16] = { 0 };

				cout << "Enter your credit card number --> ";
				string cardNumber;
				cin.clear();
				cin.sync();
				getline(cin, cardNumber);

				if (cardNumber.length() >= 13 && cardNumber.length() <= 16)
				{
					for (int i = 0, j = cardNumber.length() - 1; i < cardNumber.length(), j >= 0; i++, j--)
					{
						CreditCard[j] = cardNumber[i] - 48;
					}

					int sum = 0;
					for (int i = 1; i < cardNumber.length(); i++)
					{
						if (i % 2 == 0) {}
						else
						{
							CreditCard[i] *= 2;
						}
						if (CreditCard[i] >= 10)
						{
							CreditCard[i] -= 9;
						}
						sum = sum + CreditCard[i];
					}

					if (sum % 10 == CreditCard[0])
					{
						valid = true;
					}

					sum *= 9;
					string check = to_string(sum);

					if (check[check.length() - 1] - 48 == CreditCard[0])
					{
						valid = true;
					}
					else
					{
						valid = false;
					}
					if (!valid)
					{
						cout << "Invalid credit card number was entered." << endl;
						attemptCount++;
					}
				}
				else
				{
					attemptCount++;
					cout << "Invalid credit card number was entered." << endl;
				}

			} while (!valid && attemptCount < 2);

			if (valid)
			{
				cout << fixed << showpoint << setprecision(2)
					<< "Your credit card was successfully charged for $" << cost / 100.00 << "." << endl
					<< "Thank you! Please take your item." << endl;
			}
			else
				cout << "Too many invalid attempts. Your selection is cancelled." << endl;
		}

		cout << endl;
	}

	return valid;
}

Model100D::Model100D(int q, int d, int n) : Machine(q, d, n)
{
	numOfModel100D++;
}

Model100D::Model100D(const string &s) : Machine(s)
{
	numOfModel100D++;
}

Model100D::Model100D(const Model100D &a) : Machine(a)
{
	numOfModel100D++;
}

Model100D::~Model100D()
{
	Machine::~Machine();
	numOfModel100D--;
}

Model100D &Model100D::operator=(const Model100D &r)
{
	Machine::operator=(r);
	return *this;
}