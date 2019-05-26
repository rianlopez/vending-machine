// Header file of Item class

#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item
{
private:
    int id;
    int quantity;
    int price;  // in cents
    string description;

public:
    Item(int id = 0, int qty = 0, int price = 0, const string &desc = " ");
    void setId(int);
    void setQuantity(int);
    void setPrice(int);
    void setDescription(const string &);
    int getId() const;
    int getQuantity() const;
    int getPrice() const;
    string getDescription() const;

};

#endif
