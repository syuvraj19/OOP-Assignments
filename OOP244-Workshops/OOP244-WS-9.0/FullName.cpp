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
#include "FullName.h"
#include "Name.h"

namespace sdds {
    FullName::FullName() :Name()
    {
        this->m_value = nullptr;
    }

    FullName::operator bool() const
    {
        if (this->m_value!=nullptr && Name::operator bool()) {
            return true;
        }
        else {
            return false;
        }
    }

    FullName::operator const char* () const
    {
        return m_value;
    }

    
    FullName::FullName(const char* name, const char* lastName) : Name(name)
    {
        if (lastName == nullptr) {
            m_value = nullptr;
        }
        else
        {
            m_value = new char[strlen(lastName) + 1];
            strcpy(m_value, lastName);
        }
    }

    FullName& FullName::operator=(const FullName& var)
    {
        if (this == &var)
            return *this;

        if (m_value != nullptr) {
            delete[] m_value;
            m_value = nullptr;
        }

        Name::operator=(var);

        if (var.m_value == nullptr) {
            m_value = nullptr;
        }
        else {
            m_value = new char[strlen(var.m_value) + 1];
            strcpy(m_value, var.m_value);
        }

        return *this;

    }

    FullName::FullName(const FullName& var) :Name(var)
    {
        if (var.m_value == nullptr) {
            m_value = nullptr;
        }
        else {
            m_value = new char[strlen(var.m_value) + 1];
            strcpy(m_value, var.m_value);
        }
    }
    
    FullName::~FullName()
    {
        if (m_value != nullptr) {
            delete[] m_value;
            m_value = nullptr;
        }
    }

    std::ostream& FullName::display(std::ostream& ostr) const
    {
        if (*this) {
            Name::display(ostr);
            ostr << " ";
            ostr << m_value;
        }
        return ostr;
    }

    std::istream& FullName::read(std::istream& istr)
    {
        char buffer_storage[500] = "";

        Name::read(istr);

        istr.getline(buffer_storage, 500);
        m_value = new char[strlen(buffer_storage) + 1];

        strcpy(m_value, buffer_storage);
        return istr;
    }

    std::istream& operator >> (std::istream& istr, FullName& name) {
        return name.read(istr);
    }

    std::ostream& operator << (std::ostream& ostr, const FullName& name) {
        return name.display(ostr);
    }

}

