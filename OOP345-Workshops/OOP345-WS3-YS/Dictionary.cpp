/*
*****************************************************************************
                          Workshop - #3(P2)
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Date       : 02/10/2022
 
 I have done all the coding by myself and only copied the code that my
 professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Dictionary.h"
#include <iomanip>
namespace sdds
{
    Dictionary::Dictionary(){}

    bool Dictionary::operator==(const Dictionary &dictobj)
    {
        return (m_term == dictobj.m_term && m_definition == dictobj.m_definition);
    }

    std::ostream &operator<<(std::ostream &out, const Dictionary &dictobj)
    {
        out << std::setw(20) << std::right << dictobj.getTerm() << ": " << dictobj.getDefinition();
        return out;
    }

}

