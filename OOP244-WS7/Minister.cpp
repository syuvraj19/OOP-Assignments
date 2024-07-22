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
#define _CRT_SECURE_NO_WARNINGS
#include "Minister.h"
#include<string.h>
namespace sdds {
	Minister::Minister(const char* idd, int age, double yearAO,
		const char* primeMinister, const char* Mdistrict):MemberParliament(idd, age){
		year = yearAO;
		this->NewDistrict(Mdistrict);
		strcpy(PM,primeMinister);
	}

	void Minister::changePM(const char* pm)
	{
		strcpy(PM, pm);
	}

	void Minister::assumeOffice(double yearAO)
	{
		this->year = yearAO;
	}

	ostream& Minister::write(ostream& os) const
	{
		MemberParliament::write(os);
		os << " | " << PM << "/" << year;

		return os;
	}

	istream& Minister::read(istream& in)
	{
		MemberParliament::read(in);
		cout << "Reports TO: ";
		in >> PM;
		cout << "Year Assumed Office: ";
		in >> year;
		return in;
	}
	ostream& operator<<(ostream& os, const Minister& M) {
		return M.write(os);
	}
	istream& operator>>(istream& istr, Minister& M) {
		return M.read(istr);
	}

}
