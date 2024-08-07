/***********************************************************************
 NAME : Yuvraj Singh
 CLASS : OOP244
 SECTION : ZBB
 STUDENT NUMBER : 155580210
 EMAIL : yuvraj-singh5@myseneca.ca
DATE CREATED ON : 15 JULY 2022
WORKSHOP 7 PART 1

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#pragma once
#ifndef SDDS_MINISTER_H__
#define SDDS_MINISTER_H__
#include"MemberParliament.h"
#include<iostream>
namespace sdds {
	class Minister :public MemberParliament{
	private:
		char PM[50];
		double year;
	public:

		Minister(const char *idd,int age,double yearAO, const char* primeMinister, const char* district);
		void changePM(const char* pm);
		void assumeOffice(double year);
		ostream& write(ostream& os)const;
		istream& read(istream& in);
	};
	ostream& operator<<(ostream& os, const Minister& M);
	istream& operator>>(istream& istr, Minister& M);
}
#endif // !_SDDS_MINISTER_H_
