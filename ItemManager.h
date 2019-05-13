// Header file of ItemManager class

#ifndef ITEM_MANAGER_H
#define ITEM_MANAGER_H

#include <string>

using namespace std;

class ItemManager
{
private:
    int quantity;
    string code;

public:
    ItemManager(int q = 0, const string &c = " ");
    void setQuantity(int);
    void setCode(const string &);
    int getQuantity() const;
    string getCode() const;
    ItemManager &operator++();
    ItemManager operator++(int);
    ItemManager &operator--();
    ItemManager operator--(int);
    ItemManager operator+(int);
    ItemManager operator-(int);
    friend ItemManager operator+(int, const ItemManager &);
    friend ItemManager operator-(int, const ItemManager &);

};

#endif
