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

#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include <iostream>
#include "Chapter.h"

namespace sdds {
   const int MAX_NUM_CHAPTERS = 10;
   const int MAX_BOOK_TITEL = 40;
   const int MAX_AUTHOR_NAME = 20;
   class Book
    {
        char m_title[MAX_BOOK_TITEL+1];
        char m_author[MAX_AUTHOR_NAME+1];
        int m_num_chapters;
        int m_num_pages;
        double m_price;
        Chapter m_chapters[MAX_NUM_CHAPTERS];

        void init_book();
        int add_chapter(Chapter* chapter);
    public:
        Book();
       Book(const char* title_);
       Book(const char* title_, const char* author_, double price_);
        void summary();
        
        int operator++ (int);       //A postfix ++ operator overload to increase the number of chapters by one.
        
        operator int(){         // It will return the number of chapters of a book object.
           return m_num_chapters;
        }
        operator bool() { // It will return true if title and author, and num_chapters are non-empty and there is at least one chapter with number of pages greater than zero.
            int x = 0;
            if (m_title[0] != '\0' && m_num_chapters != 0 && m_author[0] != '\0' )
                while ( x < m_num_chapters){
                   if (int(m_chapters[x]) != 0)
                       return true;
                    x++;
                }
           return false;
        }
        operator const char*(){
           return m_title;
        }
        operator double() {         // It will return the book price.
           return m_price;
        }
        void operator-= (double);       //A -= operator overload to apply a dollar value discount to the book price.
        void operator+= (Chapter);      //to allow adding a chapter to a book.
        
       std::ostream& display(std::ostream&)const;
        
        friend std::ostream &operator<<(std::ostream &result, const Book& it)
        {
           return it.display(result);
        }
    };
}
#endif
