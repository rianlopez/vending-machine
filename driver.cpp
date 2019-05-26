#include "Model100A.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	Machine *pMach = new Model100A(2, 4, 4);

	pMach->setName("100A1");
	pMach->addProduct("1A", 1034, 5, 50, "candy bar");
	pMach->addProduct("1B", 1000, 10, 35, "chocolate chips");
	pMach->addProduct("1C", 1100, 1, 75, "cookies");
	pMach->addProduct("1D", 1123, 20, 60, "brownie");
	pMach->addProduct("1E", 1210, 5, 165, "protein bar");

	pMach->purchase();
	pMach->print("test.txt");

	cout << "Number of model 100A: " << pMach->getNumOfModel() << endl;

	return 0;
}