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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Chapter.h"

using namespace std;

namespace sdds {
	void Chapter::init_chapter() {
		m_title[0] = '\0';
		m_num_pages = 0;
		m_num_words = 0;
		m_chapter_number = 0;
	}
	Chapter::Chapter() {
		init_chapter();
	}

	Chapter::Chapter(const char* title_) {
		init_chapter();
		strcpy(m_title , title_);
	}
	Chapter::Chapter(const char* title_, int chapter_num,  int n_pages, int n_words) {
		strcpy(m_title, title_);
		m_chapter_number = chapter_num;
		m_num_pages = n_pages;
		m_num_words = n_words;
	}
	ostream& Chapter::display(std::ostream& os)const
	{
		cout.setf(std::ios::left);
		os << "| Chapter ";
		os.width(2);
		os << m_chapter_number << " | ";
		os.width(MAX_CHAPTER_TITLE);
		os << m_title << " |" << endl;
		return os;
	}

	Chapter Chapter::operator=(Chapter* chapter){
		*this = chapter;
		return *this;
	}

	Chapter::operator int() const
    {
        return m_num_pages;
    }

	
	Chapter::operator double() const
    {
        return (double)m_num_words/(double)m_num_pages;
    }

	Chapter::operator const char *() const
    {
        return m_title;
    }

	Chapter Chapter::operator--(){
		m_num_pages--;
		return *this;
	}

	Chapter Chapter::operator++(){
		m_num_pages++;
		return *this;
	}

	std::ostream & operator << (std::ostream &out, const Chapter &c)
{
    c.display(out);
    return out;
}

		int Chapter::numPages() const{
            return m_num_pages;
        }
	
}

