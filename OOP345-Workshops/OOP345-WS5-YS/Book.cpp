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
#include "Book.h"

namespace sdds {

	Book::Book(const std::string& strBook) {
		std::string bookref = strBook;
		bk_author = trim(bookref);
		bk_title = trim(bookref);
		pub_country = trim(bookref);
		bk_price = std::stod(trim(bookref));
		pub_year = std::stoi(trim(bookref));
		bk_desc = bookref.substr(bookref.find_first_not_of(" \f\n\r\t\v"), bookref.find_last_not_of(" \f\n\r\t\v") + 1);
	}

	std::string Book::trim(std::string& str) {
		const char* spaces = " \f\n\r\t\v";
		std::string tmpref;
        tmpref = str.substr(0, str.find(","));
        tmpref.erase(0, tmpref.find_first_not_of(spaces));
        tmpref.erase(tmpref.find_last_not_of(spaces) + 1);
		str.erase(0, str.find(",") + 1);
		return tmpref;
	}

	const std::string& Book::title() const {
		return bk_title;
	}

	const std::string& Book::country() const {
		return pub_country;
	}

	const size_t& Book::year() const {
		return pub_year;
	}

	double& Book::price() {
		return bk_price;
	}
	std::ostream& operator<<(std::ostream& os, const Book& bkobj) {
		if (bkobj.year() != 0) {
			os << std::setw(20) << bkobj.bk_author << " | ";
			os << std::setw(22) << bkobj.title() << " | ";
			os << std::setw(5) << bkobj.country() << " | ";
			os << std::setw(4) << bkobj.year() << " | ";
            os << std::fixed << std::setw(6) << std::setprecision(2) << bkobj.bk_price << " | ";
			os << bkobj.bk_desc << std::endl;
		}
		return os;
	}
}
