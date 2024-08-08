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

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <string>

namespace sdds {
	class Book
	{
		std::string bk_author{};
		std::string bk_title{};
		std::string pub_country{};
		size_t pub_year{};
		double bk_price{};
		std::string bk_desc{};
		std::string trim(std::string& str);
	public:
		Book() {};
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);

		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(bk_desc);
		};

		friend std::ostream& operator<<(std::ostream&, const Book&);
	};
}
#endif
