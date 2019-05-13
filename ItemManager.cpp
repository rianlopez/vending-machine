// Implementation file of ItemManager class

#include "ItemManager.h"

ItemManager::ItemManager(int q, const string &c)
{
    if (q >= 0)
        quantity = q;
    else
        quantity = 0;
    code = c;
}

void ItemManager::setQuantity(int q)
{
    if (q >= 0)
        quantity = q;
}

void ItemManager::setCode(const string &c)
{
    code = c;
}

int ItemManager::getQuantity() const
{
    return quantity;
}

string ItemManager::getCode() const
{
    return code;
}

ItemManager &ItemManager::operator++()
{
    quantity++;
    return *this;
}

ItemManager ItemManager::operator++(int)
{
    ItemManager temp = *this;
    ++*this;
    return temp;
}

ItemManager &ItemManager::operator--()
{
    quantity--;
    return *this;
}

ItemManager ItemManager::operator--(int)
{
    ItemManager temp = *this;
    --*this;
    return temp;
}

ItemManager ItemManager::operator+(int r)
{
    ItemManager temp = *this;
    if (temp.quantity + r >= 0)
        temp.quantity += r;
    else
        temp.quantity = 0;
    return temp;
}

ItemManager ItemManager::operator-(int r)
{
    ItemManager temp = *this;
    if (temp.quantity - r >= 0)
        temp.quantity -= r;
    else
        temp.quantity = 0;
    return temp;
}

ItemManager operator+(int l, const ItemManager &r)
{
    ItemManager temp = r;
    if (temp.quantity + l >= 0)
        temp.quantity += l;
    else
        temp.quantity = 0;
    return temp;
}

ItemManager operator-(int l, const ItemManager &r)
{
    ItemManager temp = r;
    if (temp.quantity - l >= 0)
        temp.quantity -= l;
    else
        temp.quantity = 0;
    return temp;
}
