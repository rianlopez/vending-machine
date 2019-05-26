#include "Model100A.h"
#include "Model100B.h"
#include "Model100C.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	Machine *pMach[3];
	pMach[0] = new Model100A(2, 4, 4);
	pMach[1] = new Model100B(2, 4, 1);
	pMach[2] = new Model100C("100C1");

	pMach[0]->setName("100A1");
	pMach[0]->addProduct("1A", 1034, 5, 50, "candy bar");
	pMach[0]->addProduct("1B", 1000, 10, 35, "chocolate chips");
	pMach[0]->addProduct("1C", 1100, 1, 75, "cookies");
	pMach[0]->addProduct("1D", 1123, 20, 60, "brownie");
	pMach[0]->addProduct("1E", 1210, 5, 165, "protein bar");

	pMach[1]->setName("100B1");
	pMach[1]->addProduct("1A", 2180, 10, 80, "coke bottle");
	pMach[1]->addProduct("1B", 1283, 10, 45, "coke can 6 oz");
	pMach[1]->addProduct("1C", 3629, 5, 80, "diet coke bottle");

	pMach[2]->addProduct("1A", 6774, 5, 300, "ham sandwich");
	pMach[2]->addProduct("1B", 6869, 5, 275, "egg sandwich");
	pMach[2]->addProduct("1C", 6879, 2, 325, "tuna sandwich");

	pMach[0]->purchase();
	pMach[1]->purchase();
	pMach[1]->purchase();
	pMach[2]->purchase();

	pMach[0]->print("test.txt");
	pMach[1]->print("test.txt");
	pMach[2]->print("test.txt");

	cout << "Number of model 100A: " << pMach[0]->getNumOfModel() << endl
		<< "Number of model 100B: " << pMach[1]->getNumOfModel() << endl
		<< "Number of model 100C: " << pMach[2]->getNumOfModel() << endl;

	return 0;
}