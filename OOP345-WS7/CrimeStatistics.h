

#ifndef SDDS_CRIMESTATISTICS_H
#define SDDS_CRIMESTATISTICS_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <list>
#define SIZE 25

namespace sdds
{
	struct Crime {
		char province[SIZE];
		char district[SIZE];
		char crime[SIZE];
		int numberOfCases = 0;
		int year = 0;
		int m_resolved = 0;
	};
	class CrimeStatistics {
		std::vector<Crime > crimeData;
	public:
		CrimeStatistics(std::string);
		void display(std::ostream&) const;
		void sort(std::string);
		void cleanList();
		bool inCollection(const char*) const;
		std::list<Crime> getListForProvince(const char*) const;
	};

	std::ostream& operator<<(std::ostream&, const Crime&);
}
#endif
