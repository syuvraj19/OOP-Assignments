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
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;
#include "Date.h"

namespace sdds {

  bool sdds_test = false;

  int sdds_year = 2022;

  int sdds_mon = 8;

  int sdds_day = 7;

  bool Date::validate() {
      
    errCode(NUL_ERROR);
      
    if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) {
        
      errCode(Y_ERROR);
        
    } else if (m_mon < 1 || m_mon > 12) {
        
      errCode(M_ERROR);
        
    } else if (m_day < 1 || m_day > mdays()) {
        
      errCode(D_ERROR);
    }
    return !bad();
  }
  int Date::mdays() const {
    int days[] = {
      31,
      28,
      31,
      30,
      31,
      30,
      31,
      31,
      30,
      31,
      30,
      31,
      -1
    };
    int mnth = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
      
      mnth--;
      
    return days[mnth] + int((mnth == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
      
  }
 
  int Date::systemYear() const {
      
    int yearx = sdds_year;
      
    if (!sdds_test) {
        
      time_t x = time(NULL);
        
      tm loctime = * localtime( & x);
        
        yearx = loctime.tm_year + 1900;
        
    }
    return yearx;
      
  }
  void Date::setToToday() {
      
    if (sdds_test) {
        
      m_day = sdds_day;
        
      m_mon = sdds_mon;
        
      m_year = sdds_year;
        
    } else {
        
      time_t t = time(NULL);
        
      tm lt = * localtime( & t);
        
      m_day = lt.tm_mday;
        
      m_mon = lt.tm_mon + 1;
        
      m_year = lt.tm_year + 1900;
        
    }
      
    errCode(NUL_ERROR);
  }
  int Date::daysSince0001_1_1() const {
      
    int t_year = m_year;
      
    int t_mnth = m_mon;
      
    if (t_mnth < 3) {
        
        t_year--;
        
        t_mnth += 12;
    }
    return 365 * t_year + t_year / 4 - t_year / 100 + t_year / 400 + (153 * t_mnth - 457) / 5 +
      m_day - 306;
  }
  Date::Date(): m_CUR_YEAR(systemYear()) {
    setToToday();
  }
  Date::Date(int year, int mon, int day): m_CUR_YEAR(systemYear()) {
    m_year = year;
    m_mon = mon;
    m_day = day;
    validate();
  }
  
  ostream & operator << (ostream & os,
    const Date & x) {
    return x.write(os);
  }

  istream & operator >> (istream & is, Date & x) {
    return x.read(is);
  }
    const char * Date::dateStatus() const {
      return DATE_ERROR[errCode()];
    }
    int Date::currentYear() const {
      return m_CUR_YEAR;
    }
    void Date::errCode(int readErrorCode) {
      m_ErrorCode = readErrorCode;
    }
    int Date::errCode() const {
      return m_ErrorCode;
    }
    bool Date::bad() const {
      return m_ErrorCode != 0;
    }

  std::istream & Date::read(std::istream & is) {
    errCode(NUL_ERROR);
    is >> m_year;
    is.ignore();
    is >> m_mon;
    is.ignore();
    is >> m_day;
    if (is.fail()) {
      errCode(INPUT_FAILED);
      is.clear();
    } else {
        
      if (m_year >= MIN_YEAR && m_year <= currentYear()) {
          
        if (m_mon >= 1 && m_mon <= 12) {
            
          if (m_day <= mdays() && m_day >= 1)
            errCode(NUL_ERROR);
            
          else errCode(D_ERROR);
            
        } else
          errCode(M_ERROR);
          
      } else
        errCode(Y_ERROR);
    }
    
    return is;
  }
  std::ostream & Date::write(std::ostream & os) const {
    
    if (this -> bad()) {
      os << dateStatus();
    }
      
    else {
            os << m_year;
          
          os << "/";
        
          os << right << setw(2) << setfill('0') << m_mon;
         
          os << "/";
          
          os << right << setw(2) << setfill('0') << m_day;
        os << setfill(' ');
        
    }
    return os;
      
  }
  
  bool Date::operator == (const Date & var) const {
      
    if (this -> m_day == var.m_day)
      if (this -> m_mon == var.m_mon)
        if (this -> m_year == var.m_year)
          return true;
      
    return false;
  }
  bool Date::operator != (const Date & var) const {
      
    return (this -> m_year != var.m_year ||
      this -> m_mon != var.m_mon ||
      this -> m_day != var.m_day);
      
  }
  bool Date::operator >= (const Date & var) const {
      
    if (this -> m_day >= var.m_day)
      if (this -> m_mon >= var.m_mon)
        if (this -> m_year >= var.m_year)
          return true;
      
    return false;
  }
  bool Date::operator <= (const Date & var) const {
      
    if (this -> m_day <= var.m_day)
      if (this -> m_mon <= var.m_mon)
        if (this -> m_year <= var.m_year)
          return true;
      
    return false;
  }
  bool Date::operator < (const Date & var) const {
      
    return (this -> m_year < var.m_year ||
      this -> m_mon < var.m_mon ||
      this -> m_day < var.m_day);
      
  }
  bool Date::operator > (const Date & var) const {
      
    return (this -> m_year > var.m_year ||
      this -> m_mon > var.m_mon ||
      this -> m_day > var.m_day);
      
  }
  
  int Date::operator - (const Date & var) const {
      
    return (daysSince0001_1_1() - var.daysSince0001_1_1());
  }

  Date::operator bool() const {
      
    return (m_year >= 1500 && m_year <= m_CUR_YEAR &&
      m_mon >= 1 && m_mon <= 12 &&
      m_day >= 1 && m_day <= mdays());
      
  }
}


