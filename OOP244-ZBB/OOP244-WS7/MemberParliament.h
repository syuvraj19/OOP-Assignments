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
#ifndef SDDS_MEMBERPARLIAMENT_H__
#define SDDS_MEMBERPARLIAMENT_H__ 
#include<iostream>
using namespace std;
namespace sdds {
	class MemberParliament {
	private:
		char id[32];
		char district[64];
		int age;
	public:
		MemberParliament(const  char *id,int age);
		void NewDistrict(const char* district);
		ostream& write(ostream& os)const;
		istream& read(istream& in);
	};
	ostream& operator<<(ostream& os, const MemberParliament& M);
	istream& operator>>(istream& istr, MemberParliament& M);
}
#endif // !_SDDS_MINISTER_H_
