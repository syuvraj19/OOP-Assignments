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

#ifndef SDDS_FULLNAME_H
#define SDDS_FULLNAME_H
#include <iostream>
#include "Name.h"

namespace sdds {

    class FullName : public Name {
        
        char* m_value;
        
    public:
        
        FullName();//Creates an empty FullName.
        
        FullName(const char* name, const char* lastName);//Passess name to the constructor of the base class and dynamically keeps a copy of lastName in the m_value of FullName

        FullName(FullName const& var);
        
        FullName& operator=(FullName const& var);
        
        ~FullName();

        operator const char* ()const;//Returns the address in the m_value of the FullName.
        
        virtual operator bool()const;//Returns true only if both FullName and Name are not empty.
        
        virtual std::ostream& display(std::ostream& ostr = std::cout)const;//If the FullName is not empty it will insert the Name, one space and then the m_value of the FullName into the ostream reference without going to the new line.
        
        virtual std::istream& read(std::istream& istr = std::cin);//Reads the Name and then dynamically reads a Cstring into the m_value of FullName from istream until it reaches the newline character.
    };
}

#endif

