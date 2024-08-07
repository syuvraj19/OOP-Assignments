

#define _CRT_SECURE_NO_WARNINGS

#include "CrimeStatistics.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <iterator>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <numeric>
namespace sdds {
	CrimeStatistics::CrimeStatistics(std::string fileName) {

		std::ifstream inFile(fileName);

		try {
			if (!inFile) {
				throw std::runtime_error(fileName + " not found!");
			}
			Crime c;
			char myChar = '1';
			//inFile.get(myChar);

			while (!inFile.eof()) {
				for (int i = 0; i < 25; i++) {
					inFile.get(myChar);
					c.province[i] = myChar;
				}
				c.province[25] = '\0';

				for (int i = 0; i < 25; i++) {
					inFile.get(myChar);
					c.district[i] = myChar;

				}
				c.district[25] = '\0';

				for (int i = 0; i < 25; i++) {
					inFile.get(myChar);
					c.crime[i] = myChar;
				}
				c.crime[25] = '\0';

				inFile >> c.year;

				inFile >> c.numberOfCases;

				inFile >> c.m_resolved;


				this->crimeData.push_back(c);

				inFile.get(myChar);

				if (inFile.eof()) {
					break;
				}

				while (myChar != '\n' && myChar != '\0') {
					inFile.get(myChar);
				}
			}

		}
		catch (std::runtime_error&) {
			std::cout << "Not Found";
		}

	}

	void CrimeStatistics::display(std::ostream& os) const {
		std::copy(this->crimeData.begin(),
			this->crimeData.end(),
			std::ostream_iterator<Crime>(os, "\n"));

		int totalCases = std::accumulate(crimeData.begin(), crimeData.end(), 0,
			[](int sum, const Crime curr) { return sum + curr.numberOfCases; });

		int totalDeaths = std::accumulate(crimeData.begin(), crimeData.end(), 0,
			[](int sum, const Crime curr) { return sum + curr.m_resolved; });

		os << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		os << "| " << std::right << std::setw(79) << "Total Crimes:  " << totalCases << std::right << " |\n";
		os << "| " << std::right << std::setw(79) << "Total Resolved Cases:  " << totalDeaths << std::right << " |\n";

	}

	void CrimeStatistics::sort(std::string type)
	{
		if (type == "Province") {
			std::sort(crimeData.begin(), crimeData.end(),
				[](const Crime a, const Crime b) -> bool
				{
					return strcmp(a.province, b.province) < 0;
				});
		}

		if (type == "Crime") {
			std::sort(crimeData.begin(), crimeData.end(),
				[](const Crime a, const Crime b) -> bool
				{
					return strcmp(a.crime, b.crime) < 0;
				});
		}

		if (type == "Cases") {
			std::sort(crimeData.begin(), crimeData.end(),
				[](const Crime a, const Crime b) -> bool
				{
					return a.numberOfCases < b.numberOfCases;
				});
		}

		if (type == "Resolved") {
			std::sort(crimeData.begin(), crimeData.end(),
				[](const Crime a, const Crime b) -> bool
				{
					return a.m_resolved < b.m_resolved;
				});
		}
	}

	void CrimeStatistics::cleanList()
	{
		char old_name[] = "[None]";
		char new_name[] = "                         ";

		std::for_each(this->crimeData.begin(), this->crimeData.end(),
			[old_name, new_name](Crime& i) {
				if (strncmp(i.crime, old_name, strlen(old_name)) == 0) {
					strcpy(i.crime, new_name);
				}

			});
	}

	bool CrimeStatistics::inCollection(const char* key) const
	{
		auto iter = std::find_if(this->crimeData.begin(), this->crimeData.end(), [key](Crime s) { return strncmp(s.crime, key, strlen(key)) == 0; });
		return iter != crimeData.end();
	}

	std::list<Crime> CrimeStatistics::getListForProvince(const char* key) const
	{
		std::list<Crime> newList;
		std::copy_if(crimeData.begin(), crimeData.end(), std::back_inserter(newList), [key](Crime c) {return strncmp(c.province, key, strlen(key)) == 0; });
		return newList;
	}


	std::ostream& operator<<(std::ostream& out, const Crime& theCrime)
	{
		out << "| " << std::left;
		for (int i = 0; i <= 21; i++) {
			std::cout << theCrime.province[i];
		}

		out << "| " << std::left;
		for (int i = 0; i <= 15; i++) {
			std::cout << theCrime.district[i];
		}
		out << "| " << std::left;
		for (int i = 0; i <= 20; i++) {
			std::cout << theCrime.crime[i];
		}
		if (theCrime.year < 0) {
			out << "| " << std::right << std::setw(6) << " ";
		}
		else {
			out << "| " << std::right << std::setw(6) << theCrime.year << " ";
		}

		out << "| " << std::right << std::setw(4) << theCrime.numberOfCases << " ";
		out << "| " << std::right << std::setw(3) << theCrime.m_resolved << " |";
		return out;
	}
}
