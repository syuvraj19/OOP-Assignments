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

#include <iomanip>
#include <sstream>
#include "Racecar.h"

using namespace std;
namespace sdds {
	Racecar::Racecar()
	{
	}
	Racecar::Racecar(std::istream& in) :Car(in)
	{
		string temp;
		getline(in, temp);
		m_booster = stod(temp.substr(0, temp.find('\n')));
	}
	void Racecar::display(std::ostream& out) const
	{
		std::string racecar;
		std::stringstream str_racecar;

		Car::display(str_racecar);
		racecar = str_racecar.str();
		racecar.erase(racecar.size() - 8);
		out << racecar;
		out << setw(6) << setprecision(2) << fixed << topSpeed();
		out << " |*";
	}
	double Racecar::topSpeed() const
	{
		return Car::topSpeed() * (1 + m_booster);
	}
}
