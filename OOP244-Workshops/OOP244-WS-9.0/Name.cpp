/*
*****************************************************************************
                          Workshop - #9 (LAB)
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Date       : 29/07/2022

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Name.h"
#include <fstream>

namespace sdds {

    Name::Name() {
        
        this->m_value = new char[2];
        
        strcpy(this->m_value, "");
    }

    Name::Name(const char* name):m_value(new char[std::strlen(name) + 1]) {
        std::strcpy(this->m_value, name);
    }

    Name::Name(Name const& var): m_value(new char[std::strlen(var.m_value) + 1])
    {
        std::strcpy(this->m_value, var.m_value);
    }

    Name& Name::operator=(Name const& var)
    {
        delete[] this->m_value;
        m_value = new char[strlen(var.m_value) + 1];
        std::strcpy(this->m_value,var.m_value);
        return *this;
    }

    Name::~Name()
    {
        delete[] m_value;
    }

    Name::operator bool()const {
        if (strcmp(this->m_value, "") == 0) {
            return false;
        }
        else {
            return true;
        }
    }

    Name::operator const char* () const
    {
        return m_value;
    }

    std::istream& Name::read(std::istream& istr)
    {
        delete[] this->m_value;
        const int len = 20;
        this->m_value = new char[len+1];

        istr >> this->m_value;
        istr.ignore();

        return istr;
    }

    std::ostream& Name::display(std::ostream& ostr) const
    {
        if (strcmp(this->m_value, "") != 0) {
            ostr << this->m_value;
        }
        
        return ostr;
    }

    std::ostream& operator<<(std::ostream& dis, const Name& x)
    {
        return x.display(dis);
    }

    std::istream& operator>>(std::istream& input, Name& x)
    {
        return x.read(input);
    }

}

