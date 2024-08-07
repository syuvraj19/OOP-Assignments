/*
*****************************************************************************
                          Workshop - #6 (P2)
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Date       : 11/07/2022

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H
#include <iostream>

namespace sdds
{
    struct Fruit
    {
        char m_name[31];
        double m_qty;
    };
     class Basket
    {
        Fruit *m_fruits{};// a dynamically allocated array of objects of type Fruit
        int m_cnt{};//the size of the m_fruits array.
        double m_price{};// the price of the basket.

    public:
        Basket();//the default constructor
        
        Basket(Fruit *fruits, int sizeofArr, double b_price);//a custom constructor that receives as parameters- array of fruits, size of array and price.
        
        Basket(const Basket &CopResrc);//the copy constructor
        
        Basket &operator=(const Basket &CopResrc);//the copy assignment operator
        
        ~Basket();//the destructor
        
        void setPrice(double s_price);//updates the m_price attribute to the value received as parameter
        
        operator bool() const;// returns true if the basket contains any fruits, false otherwise.
        
        Basket &operator+=(const Fruit Frutz);//operator that receives as a parameter an object of type Fruit (by value) and adds it to the attribute m_fruits
        
        std::ostream &display(std::ostream &os = std::cout) const;
    };

    std::ostream& operator<<(std::ostream& os,const Basket& bskt);

}

#endif // !SDDS_BASKET_H
