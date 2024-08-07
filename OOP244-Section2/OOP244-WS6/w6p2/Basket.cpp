#include "Basket.h"
#include<cstring>
#include<iostream>
#include <iomanip>
namespace sdds {

Basket::Basket()
{
fruits_array = nullptr;
fruit_count = 0;
fruit_price = 0;
}

Basket::Basket(Fruit *fruits, int size, double price ): fruits_array(nullptr), fruit_count(0), fruit_price(0)
{
if((fruits != nullptr) && (size > 0) && (price > 0))
{
fruit_count = size;
fruits_array = new Fruit[size];
for(int i=0;i<size;i++)
{
std::strcpy(fruits_array[i].m_name, fruits[i].m_name);
fruits_array[i].m_qty = fruits[i].m_qty;
}
fruit_price = price;
}
}

Basket::Basket(const Basket &basket)
{
fruits_array = nullptr;
fruit_count = 0;
fruit_price = 0;
if(basket.fruits_array != nullptr)
{
fruit_count = basket.fruit_count;
fruit_price = basket.fruit_price;
fruits_array = new Fruit[fruit_count];
for(int i=0;i<fruit_count;i++)
{
std::strcpy(fruits_array[i].m_name,basket.fruits_array[i].m_name);
fruits_array[i].m_qty = basket.fruits_array[i].m_qty;
}
}
}

Basket::~Basket()
{
if(fruits_array != nullptr)
{
delete [] fruits_array;
}
}

void Basket:: setPrice(double price)
{
fruit_price = price;
}

Basket::operator bool() const { return fruits_array != nullptr;}
Basket& Basket:: operator+=(Fruit fruit)
{
if(fruits_array != nullptr)
{
Fruit *temp = new Fruit[fruit_count+1];
for(int i=0;i<fruit_count;i++)
{
strcpy(temp[i].m_name,fruits_array[i].m_name);
temp[i].m_qty = fruits_array[i].m_qty;
}

delete [] fruits_array;
fruit_count++;
fruits_array = new Fruit[fruit_count];
for(int i=0;i<fruit_count-1;i++)
{
std::strcpy(fruits_array[i].m_name,temp[i].m_name);
fruits_array[i].m_qty = temp[i].m_qty;
}
fruits_array[fruit_count-1] = fruit;
}else
{
fruit_count++;
fruits_array = new Fruit[fruit_count];
fruits_array[0] = fruit;
}

return *this; 

}

ostream& operator<<(ostream &out, const Basket &basket)
{
if(basket.fruit_count == 0)
{
out<<"The basket is empty!"<<endl;
}
else
{
out<<"Basket Content:"<<endl;
out<<fixed<<setprecision(2);
for(int i=0;i<basket.fruit_count;i++)
{
out<<right<<setw(15)<<basket.fruits_array[i].m_name<<": "<<basket.fruits_array[i].m_qty<<"kg"<<endl;
}

out<<"Price: "<<basket.fruit_price<<endl;
}

return out;
}

}