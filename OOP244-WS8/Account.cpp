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
#include "Account.h"
namespace sdds {
	Account::Account(double bal){
		if (bal >= 0) {
			c_balance = bal;
		}
		else {
			c_balance = 0.0;
		}
	}
	bool Account::credit(double val)
	{
		if (val > 0) {
			c_balance += val;
			return true;
		}
		return false;
	}
	bool Account::debit(double val)
	{
		if (val > 0) {
			c_balance -= val;
			return true;
		}

		return false;
	}
	double Account::balance() const
	{
		return c_balance;
	}
}
