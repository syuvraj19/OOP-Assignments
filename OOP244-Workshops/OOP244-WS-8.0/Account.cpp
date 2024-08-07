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

#include "Account.h"
#include "iAccount.h"

namespace sdds {

    Account::Account(double Bal_Amt) { //constructor receives either a double holding the initial account balance or nothing.
        if (Bal_Amt <= 0) {
            this->current_Bal = 0;
        }
        else {
            this->current_Bal = Bal_Amt;

        }
    }
    
    bool Account::credit(double amt) {//receives an amount to be credited (added) to the account balance and returns the success of the transaction.
        if (amt >= 0) {
            this->current_Bal += amt;
            return true;
        }

        return false;
    }

    double Account::balance() const { //returns the current balance of the account.

        return this->current_Bal;
        
    }

    bool Account::debit(double amt) { //receives an amount to be debited (subtracted) from the account balance and returns the success of the transaction.
        if (amt >= 0) {
            this->current_Bal -= amt;
            return true;
        }

        return false;
    }

    iAccount::~iAccount() {

    }
}
