/*
*****************************************************************************
                              milestone - 4
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Section    : OOP-244-ZBB
Date       : 5/08/2022

Authenticity Declaration:
 I have done all the coding by myself and only copied the code that my professor
 provided to complete my project milestones.
*****************************************************************************
*/

#include "Streamable.h"

namespace sdds {
    
    Streamable::~Streamable(){};//Add an empty virtual destructor to this interface to guaranty that the descendants of the Streamable are removed from memory with no leak.

    std::ostream& operator<<(std::ostream& os, const Streamable& stramvar) {
    
        if (stramvar) {
            stramvar.write(os);
        }
        return os;
    }

    std::istream& operator>>(std::istream& is, Streamable& stramvar) {
        return (stramvar.read(is));
    }
}
