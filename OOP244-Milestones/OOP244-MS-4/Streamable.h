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

#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H

#include <iostream>

namespace sdds {
    class Streamable {
        
    public:
        virtual std::ostream& write(std::ostream& os) const = 0;//This method is not capable of modifying the Streamable object. write receives and returns a reference of an ostream object.

        virtual std::istream& read(std::istream& is) = 0;//read receives and returns a reference of an istream object.
        virtual bool conIO(std::ios& io) const = 0;//This method is not capable of modifying the Streamable object. conIo receives a reference of an ios object and returns a Boolean.
        virtual operator bool() const = 0;
        virtual ~Streamable();//Add an empty virtual destructor to this interface to guaranty that the descendants of the Streamable are removed from memory with no leak.
    };
    std::ostream& operator<<(std::ostream& os, const Streamable& streamvar);
    std::istream& operator>>(std::istream& is, Streamable& streamvar);
}

#endif //SDDS_STREAMABLE_H
