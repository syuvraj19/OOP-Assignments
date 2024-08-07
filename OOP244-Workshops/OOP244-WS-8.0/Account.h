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

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "iAccount.h"
namespace sdds {
    class Account:public iAccount {
    private:
        double current_Bal;

    public:
        Account(double); //constructor receives either a double holding the initial account balance or nothing.
        
        bool credit(double);// receives an amount to be credited (added) to the account balance and returns the success of the transaction.
        
        bool debit(double);//receives an amount to be debited (subtracted) from the account balance and returns the success of the transaction.

    protected:
        double balance() const;  //returns the current balance of the account.
    };
}

#endif
