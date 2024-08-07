/***********************************************************************
 NAME : Yuvraj Singh
 CLASS : OOP244
 SECTION : ZBB
 STUDENT NUMBER : 155580210
 EMAIL : yuvraj-singh5@myseneca.ca
DATE CREATED ON : 05 AUGUST 2022
MILESTONE 4

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include "Publication.h"
#include "Date.h"
#include "Lib.h"

namespace sdds {
    class Book : public Publication {
        char* Author_name;
    public:
        Book();
        Book(const Book& src);
        Book& operator=(const Book& src);
        ~Book();
        bool conIO(std::ios& io) const;
        char type() const;
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& is);
        void set(int member_id);
        operator bool() const;
    };
}


#endif //SDDS_BOOK_H
