/*
*****************************************************************************
                              milestone - 5
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Section    : OOP-244-ZBB
Date       : 7/08/2022

Authenticity Declaration:
 I have done all the coding by myself and only copied the code that my professor
 provided to complete my project milestones.
*****************************************************************************
*/

#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__

#include"Publication.h"
#include <iostream>

namespace sdds {
	class Book :public Publication {//The Book class is derived from the Publication class.
	private:
		char* auth; // A book is a publication with an "Author name".
        
	public:	
		Book();
		Book(const Book& var);
		Book& operator = (const Book& var);
		char type()const;
		void set(int member_id);//invoke the set of the base class to set the member id
		operator bool()const;//return true if the author's name exists and is not empty and the base class's operator bool() has returned true.
        ostream& write(ostream&)const;//returns the incoming ostream.
        istream& read(istream&);//Read the author name in local variables before setting the attribute to any value.
		~Book();
	};
}
#endif
