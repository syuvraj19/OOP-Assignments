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
#ifndef SDDS_IACCOUNT_H_
#define SDDS_IACCOUNT_H_
#include<iostream>
using namespace std;
namespace sdds {
	class iAccount {
	public:
		virtual bool credit(double) = 0;
		virtual bool debit(double) = 0;
		virtual void monthEnd() = 0;
		virtual void display(ostream&) const = 0;
		virtual ~iAccount(){}
	
	};
		iAccount* CreateAccount(const char*, double);	
}
#endif
