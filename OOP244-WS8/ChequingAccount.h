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
#ifndef SDDS_CHEQUINGACCOUNT_H_
#define SDDS_CHEQUINGACCOUNT_H_
#include<iostream>
#include"Account.h"
using namespace std;
namespace sdds {
	class ChequingAccount:public Account{
	private:
		double transaction_fee;
		double monthly_fee;
	public:
		ChequingAccount(double, double, double);
		bool credit(double);
		bool debit(double);
		void monthEnd();
		void display(std::ostream&) const;
	};
}
#endif
