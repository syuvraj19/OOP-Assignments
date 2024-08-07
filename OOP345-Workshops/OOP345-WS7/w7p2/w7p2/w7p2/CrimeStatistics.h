

#ifndef SDDS_CRIMESTATISTICS_H
#define SDDS_CRIMESTATISTICS_H
#include <string>
#include <vector>
#include <list>

namespace sdds {

   struct Crime {
      std::string province{};
      std::string district{};
      std::string crime{};
      unsigned numofCases{};
      unsigned year{};
      unsigned m_resolved{};
   };

   class CrimeStatistics {
      std::vector<Crime> m_crimes;
   public:
      CrimeStatistics(const char* filename);
      void display(std::ostream& out) const;
      void sort(const char*);
      bool inCollection(const char*) const;
      std::list<Crime> getListForProvince(const char*) const;
      void cleanList();
   };

   std::ostream& operator<<(std::ostream& out, const Crime& crime);
}
#endif
