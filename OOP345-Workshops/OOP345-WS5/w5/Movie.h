

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
