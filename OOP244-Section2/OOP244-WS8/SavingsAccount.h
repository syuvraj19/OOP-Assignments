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
#ifndef SDDS_SAVINGSACCOUNT_H_
#define SDDS_SAVINGSACCOUNT_H_
#include<iostream>
#include"Account.h"
using namespace std;
namespace sdds {
	class SavingsAccount:public Account{
	private:
		double interestRate;
	public:
		SavingsAccount(double, double);
		void monthEnd();
		void display(std::ostream&) const;
	};
}
#endif
