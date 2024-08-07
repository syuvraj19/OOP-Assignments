/*
*****************************************************************************
                              milestone - 3
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Section    : OOP-244-ZBB
Date       : 29/07/2022

Authenticity Declaration:
 I have done all the coding by myself and only copied the code that my professor
 provided to complete my project milestones.
*****************************************************************************
*/
#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H

namespace sdds {
    class Streamable {
    public:
        
        virtual std::ostream& write(std::ostream& os)const = 0;
        
        virtual std::ostream& read(std::istream& is) = 0;
        
        virtual bool conIO(std::ios& io)const = 0;
        
        virtual operator bool()const = 0;
        
        virtual ~Streamable() {};
        
    };

    std::ostream& operator<<(std::ostream& dis, const Streamable& piece);

    std::istream& operator>>(std::istream& dis2, Streamable& piece);
}

#endif
