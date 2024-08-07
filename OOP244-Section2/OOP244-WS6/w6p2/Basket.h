#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H

#include <iostream>
#include <cstring>
using namespace std;
namespace sdds
{

struct Fruit
{
char m_name[30 + 1]; 
double m_qty;
};

class Basket
{

Fruit* fruits_array;
int fruit_count;
double fruit_price;

public:
Basket();
Basket(Fruit* fruits, int size, double price);
Basket(const Basket& basket);
~Basket(); 
void setPrice(double price);
operator bool() const ;
Basket& operator+=(Fruit fruit);
friend ostream& operator<<(ostream &out, const Basket &basket);
};

}
#endif