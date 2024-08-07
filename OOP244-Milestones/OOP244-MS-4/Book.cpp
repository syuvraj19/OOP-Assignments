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

#include "Book.h"
#include <iostream>
#include <cstring>
#include <iomanip>

namespace sdds {
    
Book::Book() : Publication()
{
    setBookEmpty();
}

Book::~Book() {//A book is created empty by default, in a safe empty state.
    delete[] authorName;
}

Book::Book(const Book& book) : Publication(book) {
    if (authorName) {
        delete[] authorName;
        authorName = nullptr;//The book class only has one attribute that is a pointer to a character to hold an author's name Dynamically.
    }

    authorName = new char[strlen(book.authorName) + 1];
    strcpy(authorName, book.authorName);
}

Book& Book::operator=(const Book& book) {
    Publication::operator=(book);

    if (authorName) {
        delete[] authorName;
        authorName = nullptr;
    }

    if (book.authorName) {
        authorName = new char[strlen(book.authorName) + 1];
        strcpy(authorName, book.authorName);
    }
    return *this;
}

void Book::setBookEmpty() {
    authorName = nullptr;
}

char Book::type() const {//Returns the character "B".
    return 'B';
};

std::ostream& Book::write(std::ostream& in) const {//First, it will invoke the write of its Base class.
    Publication::write(in);
    if (conIO(in)) {
        char author[SDDS_AUTHOR_WIDTH + 1] = { 0 };
        std::strncpy(author, authorName, SDDS_AUTHOR_WIDTH);
        in << " ";
        in << std::setw(SDDS_AUTHOR_WIDTH) << std::left << std::setfill(' ')<<  author << " |";
    }
    else {
        in << "\t" << authorName;
    }

    return in;//returns the incoming ostream.
}

std::istream& Book::read(std::istream& is) {
    char tmpAuthName[256] = { 0 }; // temporary variable

    Publication::read(is);

    if (authorName) {
        delete[] authorName;//Free the memory held for the author's name

        authorName = nullptr;
    }

    if (conIO(is)) {
        is.ignore();
        std::cout << "Author: ";//prompt "Author: "
    }
    else {
        is.ignore(1000, '\t');
    }

    is.get(tmpAuthName, 256);

    if (is) {//Then if the incoming istream object is not in a fail state, dynamically hold the author's name in the char pointer attribute of the book class.
        authorName = new char[strlen(tmpAuthName) + 1];
        strcpy(authorName, tmpAuthName);
    }

    return is;//At the end return the incoming istream object.
}

void Book::set(int member_id) {//invoke the set of the base class to set the member id

    Publication::set(member_id);
    Publication::resetDate();//reset the date to the current date.

}

Book::operator bool() const {//return true if the author's name exists and is not empty and the base class's operator bool() has returned true.
    return authorName && Publication::operator bool();
}
}

    

