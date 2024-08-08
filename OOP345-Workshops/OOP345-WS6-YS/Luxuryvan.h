/*
*****************************************************************************
                          Workshop - #6(P2)
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Date       : 6/11/2022
 
 I have done all the coding by myself and only copied the code that my
 professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef LUXURYVAN_H
#define LUXURYVAN_H

#include "Van.h"
namespace sdds {
	class Luxuryvan : public Van {
		std::string m_consumption;
	public:
		Luxuryvan(std::istream& in);
		void display(std::ostream& out) const;
		std::string consumption() const;
	};
}


#endif // ! LUXURYVAN_H
