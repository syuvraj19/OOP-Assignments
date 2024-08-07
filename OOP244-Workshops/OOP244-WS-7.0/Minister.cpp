/*
*****************************************************************************
                          Workshop - #7 (P2)
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Date       : 17/07/22

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/

#include<iostream>
#include <cstring>
#include "Minister.h"
#include "MemberParliament.h"
using namespace std;

namespace sdds
{
    Minister::Minister(const char* Num_Id, int Num_Age, double year_x, const char* name_x, const char* Dis_x) : MemberParliament(Num_Id, Num_Age)
    {
        strcpy(this->PM_Name, name_x);
        this->PMO_year = year_x;
        this->NewDistrict(Dis_x);
    }
    
    void Minister::changePM(const char* name_x) {//a mutator that updates the PM the minister reports to.
        strcpy(this->PM_Name, name_x);
    }
    
    void Minister::assumeOffice(double year_x) {// a mutator that updates the year the minister assumed office
        this->PMO_year = year_x;
    }

    std::istream& Minister::read(std::istream& in) //a mutator that reads from the stream in the data for the current object
    {
        MemberParliament::read(in);
        cout << "Reports TO: ";
        in >> this->PM_Name;
        cout << "Year Assumed Office: ";
        in >> this->PMO_year;
        return in;
    }
    
    std::ostream& Minister::write(std::ostream& os) const//a query that inserts into os the content of the object in the format


    {
        MemberParliament::write(os);
        os << " | ";
        os << this->PM_Name << "/" << this->PMO_year;
        return os;
    }

    istream& operator>>(istream& in, Minister& Pri_min)
    {
        return Pri_min.read(in);
    }

    ostream& operator<<(ostream& os, const Minister& Pri_min)
    {
        return Pri_min.write(os);
    }
}
