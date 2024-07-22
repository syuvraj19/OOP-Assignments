/***********************************************************************
 NAME : Yuvraj Singh
 CLASS : OOP244
 SECTION : ZBB
 STUDENT NUMBER : 155580210
 EMAIL : yuvraj-singh5@myseneca.ca
DATE CREATED ON : 29 JULY 2022
WORKSHOP 9

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_NAME_H_
#define SDDS_NAME_H_
#include<iostream>
using namespace std;
namespace sdds {
    class Name {
        char* m_value;
    public:
        Name();
        Name(const char* name);
        // Rule of three goes here:
        Name(const Name& old_obj);
        Name& operator=(const Name& other);
        ~Name();

        operator const char* ()const;
        virtual operator bool()const;
        virtual std::ostream& display(std::ostream& ostr = std::cout)const;
        virtual std::istream& read(std::istream& istr = std::cin);
    };
    istream& operator>>(istream& in, Name& name);
    ostream& operator<<(ostream& out, Name& name);
}
#endif
