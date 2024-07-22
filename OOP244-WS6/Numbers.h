/***********************************************************************
 NAME : Yuvraj Singh
 CLASS : OOP244
 SECTION : ZBB
 STUDENT NUMBER : 155580210
 EMAIL : yuvraj-singh5@myseneca.ca
DATE CREATED ON : 8 JULY 2022
WORKSHOP 6 PART 1

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
#include <fstream>
namespace sdds {
   class Numbers {
      double* m_numbers;
      char* m_filename;
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty()const;
      void setEmpty();
      void setFilename(const char* filename);
      void sort();
   public:
      Numbers();
      Numbers(const char* filename);
      Numbers(const Numbers& number);
      double average()const;
      double max()const;
      double min()const;
      Numbers& operator=(const Numbers& number);
      int numberCount()const;
      bool load();
      void save();
      Numbers& operator += (const double value);
      std::ostream& display(std::ostream& ostr) const;
      ~Numbers();

   };
   std::istream& operator>>(std::istream& istr, Numbers& N);
   std::ostream& operator<<(std::ostream& os, const Numbers& N);
}
#endif // !SDDS_NUMBERS_H_
