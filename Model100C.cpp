// Implementation file of Model100C class

#include "Model100C.h"

int Model100C::numOfModel100C = 0;

void Model100C::printPaymentType() const
{
	cout << "This machine accepts credit card only." << endl;
}

bool Model100C::payment(int cost)
{
	bool valid = false;
	int CreditCard[16] = {0};

	if (cost > 0)
	{
		int attemptCount = 0;
		string input;

		do
		{
			cout << "Enter your credit card number --> ";
			//cin.ignore(); //doesn't get all the number
			getline(cin, input);

			// credit card validation
	for (i = 0, j = input.length() - 1; i < input.length(), j >= 0; i++, j--)
	{
		CreditCard[j] = input[i] - 48;
	}
	
	int sum = 0;
	for (int i = 1; i < input.length(); i++)
	{
		if (i % 2 == 0)
		{

		}
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

	for (int i = 0; i < input.length(); i++)
	{
	}
	if (sum % 10 == CreditCard[0])
	{
		valid = true;
	}
	else
	{
		valid = false;
	}

			if (!valid)
			{
				attemptCount++;
				cout << "Invalid credit card number was entered." << endl;
			}

		} while (!valid && attemptCount < 2);

		if (valid)
		{
			cout << fixed << showpoint << setprecision(2)
				<< "Your credit card was successfully charged for $" << cost / 100.0 << "." << endl
				<< "Thank you! Please take your item." << endl;
		}
		else
			cout << "Too many invalid attempts. Your selection is cancelled." << endl;

		cout << endl;
	}

	return valid;
}

Model100C::Model100C(const string &s) : Machine(s)
{
	numOfModel100C++;
}

Model100C::Model100C(const Model100C &a) : Machine(a)
{
	numOfModel100C++;
}

Model100C::~Model100C()
{
	Machine::~Machine();
	numOfModel100C--;
}

Model100C &Model100C::operator=(const Model100C &r)
{
	Machine::operator=(r);
	return *this;
}
