// Header file of Model100B class

#ifndef MODEL_100B_H
#define MODEL_100B_H

#include "Machine.h"
#include <sstream>

class Model100B : public Machine
{
private:
	static int numOfModel100B;

protected:
	virtual void printPaymentType() const;
	virtual bool payment(int cost);

public:
	Model100B(int q = 0, int d = 0, int n = 0);
	Model100B(const string &);
	Model100B(const Model100B &);
	~Model100B();
	Model100B &operator=(const Model100B &);

	virtual int getNumOfModel() const { return numOfModel100B; }
};

#endif