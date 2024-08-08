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
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include"iAccount.h"
namespace sdds {
	class Account:public iAccount{
	private:
		double c_balance;
	public:
		Account(double bal=0.0); 
		bool credit(double);
		bool debit(double);
	protected:
		double balance() const;
	};
}
#endif // !SDDS_ACCOUNT_H_
