// Header file of Item class

#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item
{
private:
    int id;
    int price;  // in cents
    string description;

public:
    Item(int i = 0, const string &d = " ", int p = 0);
    void setId(int);
    void setPrice(int);
    void setDescription(const string &);
    int getId() const;
    int getPrice() const;
    string getDescription() const;

};

#endif
