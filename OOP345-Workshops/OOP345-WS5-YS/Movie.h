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

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include<string>

namespace sdds {
	class Movie {
		std::string movieTitle{};
		int movieRelease{};
		std::string movieDesc{};
		std::string trim(std::string& str);
	public:
		Movie() {};
		const std::string& title() const;
		Movie(const std::string& strMovie);
		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(movieDesc);
			spellChecker(movieTitle);
		}
		friend std::ostream& operator<<(std::ostream&, const Movie&);
	};
}

#endif
