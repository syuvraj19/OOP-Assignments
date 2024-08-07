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

#include "iAccount.h"
#include "Account.h"
#include "ChequingAccount.h"
#include <iomanip>
#include <iostream>

namespace sdds {

    ChequingAccount::ChequingAccount(double Bal_Amt, double p, double q):Account(Bal_Amt) { //constructor receives a double holding the initial account balance, a double holding the transaction fee to be applied to the balance and a double holding the month-end fee to be applied to the account.
        if (p >= 0) {
            this->transactionFee = p;
        }
        else {
            this->transactionFee = 0;
        }

        if (q >= 0) {
            this->monthlyFee = q;
        }
        else {
            this->monthlyFee = 0;
        }
    }

    bool ChequingAccount::debit(double Bal_Amt) { // this modifier debits the balance by the amount received and if successful debits the transaction fee from the balance.
        if (Account::debit(Bal_Amt)) {
            Account::debit(transactionFee);
            return true;
        }
        return false;
    }

    bool ChequingAccount::credit(double Bal_Amt) { // this modifier credits the balance by the amount received and if successful debits the transaction fee from the balance.
        if (Account::credit(Bal_Amt)) {
            Account::debit(transactionFee);
            return true;
        }
        return false;
    }

    void ChequingAccount::monthEnd() { // this modifier debits the monthly fee from the balance, but does not charge a transaction fee for this debit.
        Account::debit(monthlyFee);
    }

    void ChequingAccount::display(std::ostream& d) const { //receives a reference to an ostream object and inserts the following output on separate lines to the object.
        d << "Account type: Chequing" << std::endl;
        d <<std::fixed<<std::setprecision(2)<<"Balance: $" << balance() << std::endl;
        d << "Per Transaction Fee: " << std::fixed << std::setprecision(2) << transactionFee << std::endl;
        d <<"Monthly Fee: " << std::fixed << std::setprecision(2) << monthlyFee << std::endl;
    }

}
