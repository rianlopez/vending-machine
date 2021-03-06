#include "Model100A.h"
#include "Model100B.h"
#include "Model100C.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	Machine *pMach[5];
	pMach[0] = new Model100A(2, 4, 4);
	pMach[1] = new Model100A(20, 10, 10);
	pMach[2] = new Model100B(2, 4, 1);
	pMach[3] = new Model100C("100C1");
	pMach[4] = new Model100C("100C2");

	pMach[0]->setName("100A1");
	pMach[0]->addProduct("1A", 1034, 5, 50, "candy bar");
	pMach[0]->addProduct("1B", 1000, 10, 35, "chocolate chips");
	pMach[0]->addProduct("1C", 1100, 1, 75, "cookies");
	pMach[0]->addProduct("1D", 1123, 20, 60, "brownie");
	pMach[0]->addProduct("1E", 1210, 5, 165, "protein bar");

	pMach[1]->setName("100A2");
	pMach[1]->addProduct("1A", 2180, 20, 80, "coke bottle");
	pMach[1]->addProduct("1B", 1283, 20, 45, "coke can 6 oz");
	pMach[1]->addProduct("1C", 3629, 5, 80, "diet coke bottle");
	pMach[1]->addProduct("1D", 3649, 3, 95, "12 oz orange juice");
	pMach[1]->addProduct("1E", 4051, 15, 75, "8 oz orange juice");
	pMach[1]->addProduct("1F", 4211, 1, 65, "apple juice");
	pMach[1]->addProduct("1G", 5318, 5, 100, "gatorade");

	pMach[2]->setName("100B1");
	pMach[2]->addProduct("1A", 2180, 10, 80, "coke bottle");
	pMach[2]->addProduct("1B", 1283, 10, 45, "coke can 6 oz");
	pMach[2]->addProduct("1C", 3629, 5, 80, "diet coke bottle");

	pMach[3]->addProduct("1A", 6774, 5, 300, "ham sandwich");
	pMach[3]->addProduct("1B", 6869, 3, 275, "egg sandwich");
	pMach[3]->addProduct("1C", 6879, 2, 325, "tuna sandwich");

	pMach[4]->addProduct("1A", 6774, 2, 300, "ham sandwich");
	pMach[4]->addProduct("1B", 6869, 0, 275, "egg sandwich");
	pMach[4]->addProduct("1C", 6879, 1, 325, "tuna sandwich");
	pMach[4]->addProduct("1D", 7555, 10, 200, "healthy salad");

	pMach[0]->purchase();
	pMach[0]->purchase();
	pMach[0]->purchase();
	pMach[0]->purchase();
	pMach[3]->purchase();
	pMach[2]->purchase();
	pMach[2]->purchase();
	pMach[4]->purchase();

	pMach[0]->print("test.txt");
	pMach[1]->print("test.txt");
	pMach[2]->print("test.txt");
	pMach[3]->print("test.txt");
	pMach[4]->print("test.txt");

	cout << "Number of model 100A: " << pMach[0]->getNumOfModel() << endl
		<< "Number of model 100B: " << pMach[2]->getNumOfModel() << endl
		<< "Number of model 100C: " << pMach[3]->getNumOfModel() << endl;

	return 0;
}