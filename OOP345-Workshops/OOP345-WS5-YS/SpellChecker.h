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

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <string>
const int numOfWords = 6;
namespace sdds {
	class SpellChecker
	{
		std::string m_badWords[numOfWords]{};
		std::string m_goodWords[numOfWords]{};
		int replace_cnt[numOfWords]{};
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}

#endif
