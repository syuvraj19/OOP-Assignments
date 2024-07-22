/***********************************************************************
 NAME : Yuvraj Singh
 CLASS : OOP244
 SECTION : ZBB
 STUDENT NUMBER : 155580210
 EMAIL : yuvraj-singh5@myseneca.ca
DATE CREATED ON : 5 AUGUST 2022
WORKSHOP 10

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/

// Workshop 10:
// Pet.h
// 2022-02-25
// Version: 1.0 
// Author: Nathan Misener
// Revised by: Sunpreet Kaur 
/////////////////////////////////////////////
#include <iostream>
#ifndef SDDS_PET_H_
#define SDDS_PET_H_
#include "Write.h"
namespace sdds {
    class Pet : public ReadWrite {
        char m_name[41];
        char m_type[41];
        int m_age;
    public:
        Pet();
        Pet(const char* name, const char* type, int age);
        void set(const char* name, const char* type, int age);
        std::ostream& display(std::ostream& os)const;
        bool operator==(const char* type)const;
        bool operator==(const int age)const;
    };
    std::ostream& operator<<(std::ostream& os, const Pet& Pet);
}
#endif // !SDDS_PET_H_

