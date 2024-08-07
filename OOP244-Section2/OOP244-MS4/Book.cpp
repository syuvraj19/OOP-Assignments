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

#include "Book.h"
#include <iostream>
#include <iomanip>
#include <cstring>

namespace sdds {
    Book::Book() {
        Author_name = nullptr;
    }

    Book::Book(const Book &src) {
        *this = src;
    }

    Book &Book::operator=(const Book &src) {
        Publication::operator=(src);
        if(Author_name) {
            delete[] Author_name;
            Author_name = nullptr;
        }

        if(src.Author_name != nullptr) {
            Author_name = new char[strlen(src.Author_name) + 1];
            strcpy(Author_name, src.Author_name);
        } else {
            Author_name = nullptr;
        }
        return *this;
    }

    Book::~Book() {
        delete[] Author_name;
    }

    bool Book::conIO(std::ios &io) const {
        return &io == &std::cin || &io == &std::cout;
    }

    char Book::type() const {
        return 'B';
    }

    std::ostream &Book::write(std::ostream &os) const {
        Publication::write(os);
        if(conIO(os)) {
            os << " ";
            int i = 0;
            for(i = 0; i < SDDS_AUTHOR_WIDTH; i++) {
                if(Author_name[i] == '\0') {
                    break;
                } else {
                    os << Author_name[i];
                }
            }
            for(i = i; i < SDDS_AUTHOR_WIDTH; i++) {
                os << " ";
            }
            os << " |";
        } else {
            os << '\t' << Author_name;
        }
        return os;
    }

    std::istream &Book::read(std::istream &is) {
        char TEMP[256]{};

        Publication::read(is);

        if(Author_name) {
            delete[] Author_name;
        }
        Author_name = nullptr;

        if(conIO(is)) {
            is.ignore();
            std::cout << "Author: ";
            is.getline(TEMP, 256);
        } else {
            is.ignore();
            is.get(TEMP, 256);
        }

        if(is) {
            Author_name = new char[strlen(TEMP) + 1];
            strcpy(Author_name, TEMP);
        }
        return is;
    }

    void Book::set(int member_id) {
        Publication::set(member_id);
        resetDate();
    }

    Book::operator bool() const {
        if(Author_name != nullptr && Publication::operator bool()) {
            return true;
        } else return false;
    }


}

