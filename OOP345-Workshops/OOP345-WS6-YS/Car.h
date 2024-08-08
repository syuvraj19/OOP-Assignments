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
#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_
#include <string>
#include "Vehicle.h"
namespace sdds {
	class Car :public Vehicle
	{
		std::string m_maker = "";
		std::string m_condition = "";
		double m_topSpeed = 0;
	public:
		Car();
		Car(std::istream& in);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
	};
}
#endif // !SDDS_CAR_H_
