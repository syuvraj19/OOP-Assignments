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

#ifndef CHEQUINGACCOUNT_H
#define CHEQUINGACCOUNT_H

#include "iAccount.h"
#include "Account.h"
#include <iostream>

namespace sdds {

    class ChequingAccount :public Account {
        
    private:
        
        double transactionFee;
        
        double monthlyFee;

    public:
        
        ChequingAccount(double, double, double); //constructor receives a double holding the initial account balance, a double holding the transaction fee to be applied to the balance and a double holding the month-end fee to be applied to the account.
        
        bool credit(double); //this modifier credits the balance by the amount received and if successful debits the transaction fee from the balance.
        
        bool debit(double); //this modifier debits the monthly fee from the balance, but does not charge a transaction fee for this debit.
        
        void monthEnd(); //this modifier debits the monthly fee from the balance, but does not charge a transaction fee for this debit.
        
        void display(std::ostream&) const; //receives a reference to an ostream object and inserts the following output on separate lines to the object.
    };
}

#endif
