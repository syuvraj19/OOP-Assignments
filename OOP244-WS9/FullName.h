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
#ifndef SDDS_FULLNAME_H_
#define SDDS_FULLNAME_H_
#include<iostream>
#include"Name.h"
using namespace std;
namespace sdds{
class FullName : public Name {
    char* m_value;
public:
    FullName();
    FullName(const char* name, const char* lastName);
    // Rule of three goes here:
    FullName(const FullName& obj);
    FullName& operator=(const FullName& other);
    ~FullName();


    operator const char* ()const;
    virtual operator bool()const;
    virtual std::ostream& display(std::ostream& ostr = std::cout)const;
    virtual std::istream& read(std::istream& istr = std::cin);
};
}
#endif
