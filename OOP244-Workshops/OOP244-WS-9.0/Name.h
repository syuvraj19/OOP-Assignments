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

#ifndef SDDS_NAME_H
#define SDDS_NAME_H
#include <iostream>

namespace sdds {

    class Name {
        
        char* m_value;
        
    public:
        
        Name();//Creates an empty name
        
        Name(const char* name); //Keeps a dynamic copy of the name in the Name object.

        Name(Name const& var);

        Name& operator=(Name const& var);
        
        ~Name();

        operator const char* ()const;
        
        virtual operator bool()const;//Return true of name is not empty, otherwise, it returns false.
        
        virtual std::ostream& display(std::ostream& ostr = std::cout)const;//nserts the Cstring value into ostr without going to new line if the Name is valid and then returns the ostr;
        
        virtual std::istream& read(std::istream& istr = std::cin);//Dynamically reads the Cstring from istr without any spaces (stops at space) and keeps the address in the m_value pointer.If the read is successful it will ignore one character from istr.returns istr at end.
        
    };

    std::ostream& operator << (std::ostream& dis, const Name& x);

    std::istream& operator >> (std::istream& input, Name& x);
}

#endif

