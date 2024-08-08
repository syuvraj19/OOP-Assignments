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

#include "Luxuryvan.h"

namespace sdds {
	Luxuryvan::Luxuryvan(std::istream& in) :Van(in) {
		char value = '\0';
		in >> value;
		if (value == 'e') {

			m_consumption = "electric van ";
		}
		else {
			throw std::string("Invalid record!");
		}
		in.ignore(1000, '\n');
	}

	void Luxuryvan::display(std::ostream& out) const {
		Van::display(out);
		out << " " << m_consumption << " *";
	}

	std::string Luxuryvan::consumption() const {
		return m_consumption;
	}
}
