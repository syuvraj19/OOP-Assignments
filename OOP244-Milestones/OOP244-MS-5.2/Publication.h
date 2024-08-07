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


#ifndef SDDS_PUBLICATION_H_
#define SDDS_PUBLICATION_H_
#include<iostream>
#include"Date.h"
#include"Lib.h"
#include"Streamable.h"

using namespace std;
namespace sdds {
	class Publication:public Streamable{
	private:
        
		char* m_title;//m_title is a c-string to hold a dynamic title for the publication.
		char m_shelfId [SDDS_SHELF_ID_LEN+1];//Hold the location of the publication in the library
		int m_membership;//This attribute is an integer to hold a 5 digit membership number of members of the library.
		int m_libRef;//This serial number is used internally to uniquely identify each publication in the system.
        Date m_date;//The Date, by default, is set to the current date.
        
	public:
		Publication();//Sets all the attributes to their default values.
		Publication& operator = (const Publication&);
		Publication(const Publication&);
        
		virtual void set(int member_id); // Sets the membership attribute to either zero or a five-digit integer.
		void setRef(int value);  // Sets the **libRef** attribute value
		void resetDate(); // Sets the date to the current date of the system.
		virtual char type()const; //Returns the character 'P' to identify this object as a "Publication object"
		bool onLoan()const; //Returns true is the publication is checkout (membership is non-zero)
		Date checkoutDate()const; //Returns the date attribute
		bool operator==(const char* title)const; //Returns true if the argument title appears anywhere in the title of the
                                                 //publication. Otherwise, it returns false; (use strstr() function in <cstring>)
		operator const char* ()const; //Returns the title attribute
		
        int getRef()const;//Returns the libRef attirbute.
        
		ostream& write(ostream&)const;//If the os argument is a console IO object (use conIO()), print shelfId, title, membership and date attributes.
		istream& read(istream&);//Read all the values in local variables before setting the attributes to any values.
		bool conIO(ios&)const;//Returns true if the address of the io object is the same as the address of either the cin object or the cout object
        
		operator bool()const;//Returns true if neither of the title or shelfId attributes is null or empty. Otherwise, it will return false.
        
		virtual ~Publication();//the destructor
	};
	std::ostream& operator<<(std::ostream& os, const Publication& pub);
	std::istream& operator>>(std::istream& is, Publication& pub);
}
#endif
