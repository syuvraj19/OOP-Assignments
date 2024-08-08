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
#include "Book.h"

using namespace std;
namespace sdds {
	void Book::init_book() {
		m_title[0] = '\0';
		m_author[0] = '\0';
		m_num_chapters=0;
		m_num_pages=0;
	}

	Book::Book() {
		init_book();
	}

	Book::Book(const char* title_) {
		init_book();
		strcpy(m_title, title_);
	}

	Book::Book(const char* title_, const char* author_, double price_) {
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

	Book Book::operator++()
    {
       m_num_chapters++;
	   return *this;
    }

	Book Book::operator+=(Chapter py_chapter)
    {
       add_chapter(py_chapter);
	   return *this;
    }

	Book Book::operator-=(double price)
    {
       m_price -=price;
       return *this;
    }

	void Book::add_chapter(Chapter chapter){
		m_chapters[m_num_chapters]=chapter;
		m_num_pages+=chapter.numPages();
		m_num_chapters++;
	}

std::ostream & operator << (std::ostream &out, Book &c)
{
	std::cout<<"Title:'"<<c.m_title<<"'\n";
std::cout<<"Author: '"<<c.m_author<<"'\n";
	// std::cout<<c.getNumChapters()<<" test \n";
	for (int i = 0; i < c.getNumChapters(); i++)
	{
		
		// std::cout<<c.getChapters()[i].numPages()<<"pages\n";
		c.getChapters()[i].display(out);		
	}
               return out;
}

int Book::getNumChapters(){
		return m_num_chapters;
}
        const Chapter* Book::getChapters(){
				return m_chapters;
		}


			Book::operator int() const
    {
        return m_num_chapters;
    }

	
	Book::operator double() const
    {
        return m_price;
    }

	Book::operator bool() const
    {
        if(m_author[0]=='\0' || m_title[0]=='\0' || m_num_chapters==0){
			return false;
		}
		for (int i = 0; i < m_num_chapters; i++)
		{
			const int pages = m_chapters[i].numPages();
			if(pages>0){
				return true;
			}
		}
		return false;
		
    }

	Book::operator const char *() const
    {
        return m_title;
    }

}
