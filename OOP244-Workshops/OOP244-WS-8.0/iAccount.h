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

#ifndef IACCOUNT_H
#define IACCOUNT_H
#include <iostream>

namespace sdds
 {
    class iAccount
    {
    public:
        
        virtual bool credit(double)=0; //adds a positive amount to the account balance.
        
        virtual bool debit(double)=0; //subtracts a positive amount from the account balance
        
        virtual void monthEnd()=0; //applies month-end transactions to the account
        
        virtual void display(std::ostream&) const=0; //inserts account information into an ostream object
        
        virtual ~iAccount(); //public empty virtual destructor.
        
    };
    iAccount* CreateAccount(const char*, double); //receives a C-style string identifying the type of account and the initial account balance, creates the account with the starting balance and returns its address.

}

#endif
