/*
*****************************************************************************
                              milestone - 3
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Section    : OOP-244-ZBB
Date       : 29/07/2022

Authenticity Declaration:
 I have done all the coding by myself and only copied the code that my professor
 provided to complete my project milestones.
*****************************************************************************
*/
#ifndef SDDS_DATE_H__
#define SDDS_DATE_H__
#include <iostream>

namespace sdds {
  extern bool sdds_test;

  extern int sdds_year;

  extern int sdds_mon;

  extern int sdds_day;

  const int NUL_ERROR = 0;

  const int INPUT_FAILED = 1;

  const int Y_ERROR = 2;

  const int M_ERROR = 3;

  const int D_ERROR = 4;

  const char DATE_ERROR[5][16] = {
    "No Error",
    "cin Failed",
    "Bad Year Value",
    "Bad Month Value",
    "Bad Day Value"
  };

  const int MIN_YEAR = 1500;

  class Date {
      
    private:
      int m_year;
      
        int m_mon;
          
        int m_day;
          
        int m_ErrorCode;
          
        int m_CUR_YEAR;
      
    int daysSince0001_1_1() const;
      
    bool validate();
      
    void errCode(int);
      
    int systemYear() const;
      
    bool bad() const;
      
    int mdays() const;
      
    void setToToday();
      
  friend class Publication;
      
  public:
      
    Date();
      
  Date(int year, int mon, int day);
      
  int errCode() const;
      
  const char * dateStatus() const;
      
  int currentYear() const;

  std::istream & read(std::istream & is = std::cin);
      
  std::ostream & write(std::ostream & os = std::cout) const;
  
  bool operator == (const Date & var) const;
      
  bool operator != (const Date & var) const;
      
  bool operator >= (const Date & var) const;
      
  bool operator <= (const Date & var) const;
      
  bool operator < (const Date & var) const;
      
  bool operator > (const Date & var) const;
  
  int operator - (const Date & var) const;
  
  operator bool() const;
      
};

std::ostream & operator << (std::ostream & os,
  const Date & x);

std::istream & operator >> (std::istream & is, Date & x);

}
#endif

