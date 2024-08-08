/*
*****************************************************************************
                          Workshop - #5(P2)
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Date       : 16/10/2022
 
 I have done all the coding by myself and only copied the code that my
 professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include <algorithm>
#include <iomanip>
#include "Movie.h"

namespace sdds {
	const std::string& Movie::title() const {
		return movieTitle;
	}
	std::string Movie::trim(std::string& str) {
		const char* spaces = " \f\n\r\t\v";
		std::string tempstr;
        tempstr = str.substr(0, str.find(","));
        tempstr.erase(0, tempstr.find_first_not_of(spaces));
        tempstr.erase(tempstr.find_last_not_of(spaces) + 1);
		str.erase(0, str.find(",") + 1);
		return tempstr;
	}

	Movie::Movie(const std::string& strMovie) {
		std::string tempstr = strMovie;
        movieTitle = trim(tempstr);
        movieRelease = std::stoi(trim(tempstr));
        movieDesc = tempstr.substr(tempstr.find_first_not_of(" \f\n\r\t\v"), tempstr.find_last_not_of(" \f\n\r\t\v") + 1);;
	}

	std::ostream& operator<<(std::ostream& os, const Movie& movieobj) {
		if (!movieobj.title().empty()) {
			os << std::setw(40) << movieobj.title() << " | ";
			os << std::setw(4) << movieobj.movieRelease << " | ";
			os << movieobj.movieDesc << std::endl;
		}
		return os;
	}
}
