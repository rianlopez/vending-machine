// Header file of Model 100A class

#ifndef MODEL_100A_H
#define MODEL_100A_H

#include "Machine.h"
#include <sstream>

class Model100A : public Machine
{
private:
	static int numOfModel100A;

	virtual void printPaymentType() const;
	virtual bool payment(int cost);

public:
	Model100A(int q = 0, int d = 0, int n = 0);
	Model100A(const string &);
	Model100A(const Model100A &);
	~Model100A();
	Model100A &operator=(const Model100A &);

	virtual int getNumOfModel() const { return numOfModel100A; }
};

#endif