
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
