// Header file of Model100C class

#ifndef MODEL_100D_H
#define MODEL_100D_H

#include "Machine.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Model100D : public Machine
{
private:
	static int numOfModel100D;

protected:
	virtual void printPaymentType() const;
	virtual bool payment(int cost);

public:
	Model100D(int q = 0, int d = 0, int n = 0);
	Model100D(const string &s);
	Model100D(const Model100D &);
	~Model100D();
	Model100D &operator=(const Model100D &);

	virtual int getNumOfModel() const { return numOfModel100D; }

};

#endif
