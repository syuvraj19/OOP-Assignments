/***********************************************************************
 NAME : Yuvraj Singh
 CLASS : OOP244
 SECTION : ZBB
 STUDENT NUMBER : 155580210
 EMAIL : yuvraj-singh5@myseneca.ca
DATE CREATED ON : 11 JULY 2022
WORKSHOP 6 PART 2

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H
#include <iostream>

namespace sdds {
    struct Fruit {
        char m_name[30 + 1]; // the name of the fruit
        double m_qty;        // quantity in kilograms
    };

    class Basket {
    private:
        Fruit* m_fruits;
        int m_cnt;
        double m_price;
    public:
        // Constructors
        // Default Constructor
        Basket(/* args */);
        // Custom Constructor
        Basket(Fruit* fruitArray, int arraySize, double basketPrice);
        // Copy Constructor
        Basket(const Basket& Basket);
        // The Destructor
        ~Basket();

        // Copy Assignment Operator
        Basket& operator=(const Basket& basket);

        void setPrice(double price);

        // Bool Operator
        operator bool() const;

        // An overload of the += operator
        Basket& operator+= (Fruit fruit);

        // Function to display the basket content
        std::ostream& display(std::ostream& ostr) const;

        // sets to empty
        void setEmpty();

    };
    // Friend Helper Functions
    // Overloading the insertion operator
    std::ostream& operator<<(std::ostream& os, const Basket& basket);
}
#endif // !SDDS_BASKET_H
