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

#ifndef SDDS_MINISTER_H
#define SDDS_MINISTER_H
#include <iostream>
#include "MemberParliament.h"

namespace sdds
{
    class Minister : public MemberParliament {
        
        char PM_Name[50+1];//The name of the Prime Minister the Minister reports toas a statically allocated array of characters of size 50.
        
        double PMO_year;//The year the minister assumed office.
        
    public:
        
        Minister(const char*, int, double, const char*, const char*);
        
        void changePM(const char*);//a mutator that updates the PM the minister reports to.
        
        void assumeOffice(double);//a mutator that updates the year the minister assumed office
        
        std::ostream& write(std::ostream& os) const;//a query that inserts into os the content of the object in the format

        std::istream& read(std::istream& in);//a mutator that reads from the stream in the data for the current object
        
    };
    std::ostream& operator<<(std::ostream& os, const Minister& Pri_min);

    std::istream& operator>>(std::istream& in, Minister& Pri_min);
}
#endif
