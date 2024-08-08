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
#include"MemberParliament.h"
#include<string.h>
#include<iomanip>
#include<iostream>
using namespace std;
namespace sdds {
	MemberParliament::MemberParliament(const  char* Pid, int age) {
		strcpy(id, Pid);
		this->age = age;
		strcpy(this->district,"Unassigned");
	}
	void MemberParliament::NewDistrict(const char* Pdistrict) {
		cout << "|" << setw(8) << right << id << "| |" <<setw(20)<<right<< this->district << " ---> ";
		strcpy(this->district,Pdistrict);
		cout<<setw(23) <<left<< district << "|" << endl;
	}
	ostream& MemberParliament::write(ostream& os) const{
		os << "| "<<id<<" | "<<age<<" | "<<district;
		return os;
	}
	istream& MemberParliament::read(istream& in) {
		cout << "Age: ";
		in>> age;
		cout << "Id: ";
		in >> id;
		cout << "District: ";
		in >> district;
		return in;
	}
	ostream& operator<<(ostream& os, const MemberParliament& M) {
		return  M.write(os);
	}
	istream& operator>>(istream& istr, MemberParliament& M) {
		return M.read(istr);
	}
}
