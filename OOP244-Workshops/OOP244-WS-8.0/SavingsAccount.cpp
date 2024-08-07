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
#include "SavingsAccount.h"
#include <iostream>
#include <iomanip>

namespace sdds {

    SavingsAccount::SavingsAccount(double Bal_Amt, double x):Account(Bal_Amt) {
        
        if (x >= 0) {
            this->interestRate = x;
        }
        
        else {
            this->interestRate = 0;
        }
        
    }
    void SavingsAccount::monthEnd() {
        
        double T_Intrest = balance() * this->interestRate;
        credit(T_Intrest);
    }

    void SavingsAccount::display(std::ostream& d) const {
        d << "Account type: Savings";
        d << std::fixed << std::setprecision(2) << "\nBalance: $" << balance();
        d << "\nInterest Rate (%): " << std::fixed << std::setprecision(2) << this->interestRate*100 << std::endl;
    }
}

