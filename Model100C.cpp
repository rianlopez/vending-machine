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

	if (cost > 0)
	{
		int attemptCount = 0;
		string input;

		do
		{
			cout << "Enter your credit card number --> ";
			cin.ignore();
			getline(cin, input);

			// credit card validation

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