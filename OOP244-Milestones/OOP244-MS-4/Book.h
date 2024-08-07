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

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include "Publication.h"

namespace sdds {
    class Book : public Publication {
    private:
        char* authorName;//Implement what is needed to comply with the rule of three so a book can safely be copied or assigned to another book.

    public:
        Book();
        ~Book();
        Book(const Book& book);
        Book& operator=(const Book& book);
        void setBookEmpty();
        char type() const;

        std::ostream& write(std::ostream& os) const;//
        std::istream& read(std::istream& is);

        virtual void set(int member_id);
        operator bool() const;
    };
}

#endif // SDDS_BOOK_H
