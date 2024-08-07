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
#ifndef SDDS_CHAPTER_H_
#define SDDS_CHAPTER_H_
#include <iostream>
#define MAX_CHAPTER_TITLE 20
namespace sdds {
    class Chapter
    {
        char m_title[MAX_CHAPTER_TITLE+1];
        int m_num_pages;
        int m_num_words;
        unsigned int m_chapter_number;
        void init_chapter();
    public:
       Chapter();
       Chapter(const char* title_);
       Chapter(const char* title_, int chapter_num, int n_pages, int n_words);
       std::ostream& display(std::ostream&)const;
        operator int()      // It will return the number of the pages in the Chapter object.
        {
            return m_num_pages;
                }
        operator double()       // It will return the average number of words per page.
        {
           return double(double(m_num_words) / double(m_num_pages));
        }
        operator const char* ()     //It will return the title of a chapter object.
        {
           return m_title;
        }
        void operator = (const Chapter&);
        
        int operator ++ ();     //It will increase the number of pages for a chapter object by one.
        
        int operator -- ();     // It will decrease the number of pages for a chapter object by one.
        
        friend std::ostream &operator<<(std::ostream &result, const Chapter& it)
        {
           return it.display(result);
        }
       
    };
}
#endif
