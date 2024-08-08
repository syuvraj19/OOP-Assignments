/***********************************************************************
 NAME : Yuvraj Singh
 CLASS : OOP244
 SECTION : ZBB
 STUDENT NUMBER : 155580210
 EMAIL : yuvraj-singh5@myseneca.ca
DATE CREATED ON : 22 JULY 2022
WORKSHOP 8 PART 1

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#include "ChequingAccount.h"
#include<iomanip>
#include<iostream>
namespace sdds {
	ChequingAccount::ChequingAccount(double bal, double tfee, double mfee):Account(bal){
		if (tfee > 0) {
			transaction_fee = tfee;
		}
		else {
			transaction_fee = 0.0;
		}
		if (mfee > 0) {
			monthly_fee = mfee;
		}
		else {
			monthly_fee = 0.0;
		}
	}
	bool ChequingAccount::credit(double val)
	{
		if (Account::credit(val)) {
			Account::debit(transaction_fee);
			return true;
		}
		return false;
	}
	bool ChequingAccount::debit(double val)
	{
		if (Account::debit(val)) {
			Account::debit(transaction_fee);
			return true;
		}
		return false;
	}
	void ChequingAccount::monthEnd()
	{
		Account::debit(monthly_fee);
	}
	void ChequingAccount::display(std::ostream& os) const
	{
		os << "Account type: Chequing" << endl;
		os << "Balance: $" << fixed << setprecision(2) << balance() << endl;
		os << "Per Transaction Fee: " << setprecision(2) << fixed << transaction_fee << endl;
		os << "Monthly Fee: " << setprecision(2) << fixed <<monthly_fee<< endl;
	}
}
