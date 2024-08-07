/*
*****************************************************************************
                          Workshop - #5 - P1
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Section    : OOP-244-ZBB

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Book.h"

using namespace std;
namespace sdds {

void Book::init_book()
{
    m_title[0] = '\0';
    m_author[0] = '\0';
    m_num_chapters=0;
    m_num_pages=0;
}

Book::Book(){
    init_book();
}

Book::Book(const char* title_){
    init_book();
    strcpy(m_title, title_);
}

Book::Book(const char* title_, const char* author_, double price_){
    init_book();
    strcpy(m_title, title_);
    strcpy(m_author, author_);
    m_price = price_;
}

// Print a book summary
    void Book::summary() {
        cout.setf(ios::left);
        cout << "| ";
        cout.width(MAX_BOOK_TITEL);
        cout << m_title << " | ";
        cout.width(MAX_AUTHOR_NAME);
        cout << m_author << " | ";
        cout.width(3);
        cout << m_num_chapters << "  ";
        cout.width(4);
        cout << m_num_pages << " | ";
        cout.width(6);
        cout << m_price << " |" << endl;
    }
                
int Book::add_chapter(Chapter* chapter) {
    m_chapters[m_num_chapters++] = *chapter;
    m_num_pages = m_num_pages + int(*chapter);
    return int(m_num_chapters);
}
  
void Book::operator-= (double price) {
    m_price = m_price - price;
}

void Book::operator+= (Chapter chapter) {
    add_chapter(&chapter);
}

int Book::operator++ (int) {
    return m_num_chapters++;
}
   
ostream& Book::display(std::ostream& ostr)const {
    ostr << "Title:'" << m_title << "'\n";
    ostr << "Author: '" << m_author << "'\n";
    int x = 0;
    while ( x < m_num_chapters){
        ostr << m_chapters[x];
        x++;
    }
    return ostr;
    }
}
