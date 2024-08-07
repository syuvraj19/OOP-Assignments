/*
*****************************************************************************
                          Workshop - #8 (LAB)
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Date       : 22/07/2022

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "iAccount.h"
#include "Account.h"
#include <iostream>

namespace sdds {

    class SavingsAccount :public Account { // PUBLIC DERIVATION of account class
        
    private:
        
        double interestRate;

    public:
        
        SavingsAccount(double, double); //constructor receives a double holding the initial account balance and a double holding the interest rate to be applied to the balance.
        
        void monthEnd(); // this modifier calculates the interest earned on the current balance and credits the account with that interest.
        
        void display(std::ostream&) const; // receives a reference to an ostream object and inserts the following output on separate lines to the object.
    };
}

#endif

