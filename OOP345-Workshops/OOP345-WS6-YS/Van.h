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

#pragma once
#ifndef VAN_H
#define VAN_H
#include <iostream>
#include "Vehicle.h"

namespace sdds {
	class Van : public Vehicle {
		std::string m_maker{};
		std::string m_type;
		std::string m_condition;
		std::string m_purpose;
		double m_topSpeed;
	public:
		Van(std::istream& in);
		std::string condition()const;
		std::string type() const;
		std::string usage() const;
		double topSpeed()const;
		void display(std::ostream& out) const;
	};
}
#endif // !VAN_H

