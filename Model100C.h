// Header file of Model100C class

#ifndef MODEL_100C_H
#define MODEL_100C_H

#include "Machine.h"

class Model100C : public Machine
{
private:
	static int numOfModel100C;

protected:
	virtual void printPaymentType() const;
	virtual bool payment(int cost);

public:
	Model100C(const string &s = "");
	Model100C(const Model100C &);
	~Model100C();
	Model100C &operator=(const Model100C &);

	virtual int getNumOfModel() const { return numOfModel100C; }

};

#endif