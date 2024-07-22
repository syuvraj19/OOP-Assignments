/***********************************************************************
 NAME : Yuvraj Singh
 CLASS : OOP244
 SECTION : ZBB
 STUDENT NUMBER : 155580210
 EMAIL : yuvraj-singh5@myseneca.ca
DATE CREATED ON : 17 JUNE 2022
WORKSHOP 5 PART 1

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_CHAPTER_H_
#define SDDS_CHAPTER_H_
#include <iostream>
namespace sdds {
   const int MAX_CHAPTER_TITLE = 20;
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
        Chapter operator=(Chapter *chapter);
        operator int() const;
        operator double() const;
        operator const char *() const;
        Chapter operator++();
        Chapter operator--();
        friend std::ostream & operator<<( std::ostream &output,Chapter &c);
        int numPages() const;
    };
}
#endif


