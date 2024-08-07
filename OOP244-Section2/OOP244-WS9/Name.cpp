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
#define _CRT_SECURE_NO_WARNINGS
#include"Name.h"
#include<string.h>
namespace sdds {
    Name::Name() {
        this->m_value = nullptr;
    }
    Name::Name(const char* name) {
        this->m_value = new char[strlen(name) + 1];
        strcpy(m_value, name);
    }
    // Rule of three goes here:
    Name::Name(const Name& name) {
        this->m_value = new char[strlen(name.m_value) + 1];
        strcpy(m_value,name.m_value);
    }
    Name& Name::operator=(const Name& name) {
        if (m_value != nullptr) {
            delete[] m_value;
        }
        this->m_value = new char[strlen(name.m_value) + 1];
        strcpy(m_value, name.m_value);
        return *this;
    }
    Name::~Name() {
        if(m_value!=nullptr)
        delete[] m_value;
    }

    Name::operator const char* ()const {
        return m_value;
    }
    Name::operator bool()const {
        return m_value != nullptr;
    }
    std::ostream& Name::display(std::ostream& ostr)const {
        if (m_value != nullptr) {
            ostr << m_value;
        }
        return ostr;
    }
    std::istream& Name::read(std::istream& istr) {
        string name;
        istr>>name;
        if (!istr.fail()) {
            istr.ignore(1);
            if (m_value != nullptr) {
                delete[]m_value;
            }
            m_value = new char[strlen(name.c_str())+1];
            strcpy(m_value, name.c_str());
        }
        return istr;
    }
    istream& operator>>(istream& in, Name& name) {
        return name.read(in);
    }
    ostream& operator<<(ostream& out, Name& name) {
        return name.display(out);
    }
}
