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

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <cstring>
#include "MemberParliament.h"

using namespace std;

namespace sdds {
    MemberParliament::MemberParliament(const char* Num_Id, int Num_Age){ //A custom constructor that receives as parameters the MP Id and age. Set the district the MP represents as Unassigned. Assume all data is valid.
        strcpy(this->ID, Num_Id);
        this->Age = Num_Age;
        strcpy(this->Dis, "Unassigned");
    }
    
    void MemberParliament::NewDistrict(const char* New_Dis) {
        cout << "|" << right << setw(8) << this->ID << "| |"
             << setw(20) << right << this->Dis
             << " ---> "
             << setw(23) << left << New_Dis << "|\n";
        strcpy(this->Dis, New_Dis);
    }
    
    ostream& MemberParliament::write(ostream& os) const {
        os << "| ";
        os << this->ID;
        os << " | ";
        os << this->Age;
        os << " | ";
        os << this->Dis;
        return os;
    }
    
    istream& MemberParliament::read(istream& in)
    {
        cout << "Age: ";
        in   >> this->Age;
        cout << "Id: ";
        in   >> this->ID;
        cout << "District: ";
        in   >> this->Dis;
        return in;
    }
    
    ostream &operator<<(ostream& os, const MemberParliament& Mem_Par) {
        return Mem_Par.write(os);
    }
    
    istream &operator>>(istream& in, MemberParliament& Mem_Par) {
        return Mem_Par.read(in);
    }
}

