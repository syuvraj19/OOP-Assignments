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
// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: Allocator.cpp
// Version: 2.0
// Date: 2018/11/02
// Author: Chris Szalwinski, based on work by Heidar Davoudi
// Description:
// This file allocates an Account object in dynamic memory
///////////////////////////////////////////////////
#include "SavingsAccount.h" 
#include "ChequingAccount.h" 

namespace sdds {

	// account rates and charges
	//
	const double interestRate = 0.05;
	const double transactionFee = 0.50;
	const double monthlyFee = 2.00;

	// calls the appropriate constructor
	//
	iAccount* CreateAccount(const char* str, double balance) {
		iAccount* account = nullptr;
		switch (str[0]) {
		case 'S':
			account = new SavingsAccount(balance, interestRate);
			break;
		case 'C':
			account = new ChequingAccount(balance, transactionFee, monthlyFee);
			break;
		}
		return account;
	}
}
