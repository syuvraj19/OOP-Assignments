

#include "CrimeStatistics.h"
#include <fstream>
#include <numeric>
#include <algorithm>
#include <cstring>

namespace sdds {
   std::string& trim(std::string& str) {
      bool trimstr = false;

      while (!trimstr) {
          trimstr = true;
         if (str.find(' ') == 0) {
             trimstr = false;
            str.erase(str.begin());
         }
         if (str.size() > 0 &&
            str.substr(str.size() - 1, 1).find(' ') != std::string::npos) {
            str.erase(str.end() - 1);
             trimstr = false;
         }
      }
      return str;
   }

   CrimeStatistics::CrimeStatistics(const char* filename) {
      std::ifstream file(filename);

      if (file) {
         while (file) {
            Crime crime{};
            char buffer[26];
            std::string token{};
            file.get(buffer, 26);
            token = std::string(buffer);
            token = trim(token);
            crime.province = token;
            file.get(buffer, 26);
            token = std::string(buffer);
            token = trim(token);
            crime.district = token;
            file.get(buffer, 26);
            token = std::string(buffer);
            token = trim(token);
            crime.crime = token;
            file.get(buffer, 6);
            crime.year = atoi(buffer);
            file.get(buffer, 6);
            crime.numofCases = atoi(buffer);
            file.get(buffer, 6);
            crime.m_resolved = atoi(buffer);
            std::getline(file, token);
            m_crimes.push_back(crime);
         }
      }
      else {
         throw("Error: Invalid file name!");
      }

   }

   void CrimeStatistics::display(std::ostream& out) const {
      for (auto x = m_crimes.cbegin(); x < m_crimes.cend(); x++) {
         out << *x << std::endl;
      }
      unsigned total{};
      total = std::accumulate(m_crimes.cbegin(), m_crimes.cend(), 0, [](unsigned x, Crime y) {
         return x + y.numofCases;
      });
      out << "----------------------------------------------------------------------------------------" << std::endl;
      out << "|                                                                 Total Crimes:";
      out.width(7);
      out << std::right << total << " |" << std::endl;
      total = std::accumulate(m_crimes.cbegin(), m_crimes.cend(), 0, [](unsigned x, Crime y) {
         return x + y.m_resolved;
      });
      out << "|                                                         Total Resolved Cases:";
      out.width(7);
      out << std::right << total << " |" << std::endl;
   }

   void CrimeStatistics::sort(const char* field) {
      if (strcmp(field, "Province") == 0) {
         std::sort(m_crimes.begin(), m_crimes.end(), [](Crime p, Crime q) {
            return p.province < q.province;
         });
      }
      else if (strcmp(field, "Crime") == 0) {
         std::sort(m_crimes.begin(), m_crimes.end(), [](Crime p, Crime q) {
            return p.crime < q.crime;
         });
      }
      else if (strcmp(field, "Cases") == 0) {
         std::sort(m_crimes.begin(), m_crimes.end(), [](Crime p, Crime q) {
            return p.numofCases < q.numofCases;
         });
      }
      else if (strcmp(field, "Resolved") == 0) {
         std::sort(m_crimes.begin(), m_crimes.end(), [](Crime p, Crime q) {
            return p.m_resolved < q.m_resolved;
         });
      }
   }

   bool CrimeStatistics::inCollection(const char* crime) const {
      return std::count_if(m_crimes.cbegin(), m_crimes.cend(), [=](Crime c) {
         return c.crime == crime;
      }) > 0;
   }

   std::list<Crime> CrimeStatistics::getListForProvince(const char* province) const {
      std::size_t size = std::count_if(m_crimes.cbegin(), m_crimes.cend(), [=](Crime c) {
         return c.province.compare(province) == 0;
      });
      std::list<Crime> temp(size);
      std::copy_if(m_crimes.cbegin(), m_crimes.cend(), temp.begin(), [=](Crime c) {
         return strcmp(c.province.c_str(), province) == 0;
      });
      return temp;
   }

   void CrimeStatistics::cleanList() {
      std::vector<Crime> temp(m_crimes.size());
      std::transform(m_crimes.cbegin(), m_crimes.cend(), temp.begin(), [](Crime c) {
         if (c.crime.compare("[None]") == 0) {
            c.crime = "";
         }
         return c;
      });
      m_crimes = temp;
   }

   std::ostream& operator<<(std::ostream& out, const Crime& thecrime) {
      out << "| ";
      out.width(21);
      out.fill(' ');
      out << std::left << thecrime.province << " | ";
      out.width(15);
      out << thecrime.district << " | ";
      out.width(20);
      out << thecrime.crime << " | ";
      out.width(6);
      out << std::right << thecrime.year << " | ";
      out.width(4);
      out << thecrime.numofCases << " | ";
      out.width(3);
      out << thecrime.m_resolved << " |";
      return out;
   }
}
