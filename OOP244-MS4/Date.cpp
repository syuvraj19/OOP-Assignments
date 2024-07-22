/***********************************************************************
 NAME : Yuvraj Singh
 CLASS : OOP244
 SECTION : ZBB
 STUDENT NUMBER : 155580210
 EMAIL : yuvraj-singh5@myseneca.ca
DATE CREATED ON : 05 AUGUST 2022
MILESTONE 4

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;
#include "Date.h"
namespace sdds
{
    
    bool sdds_test = false;
    int sdds_year = 2022;
    int sdds_mon = 8;
    int sdds_day = 7;

   bool Date::validate()
   {
      errCode(Not_error);
      if (m_YEAR < MIN_YEAR || m_YEAR > m_CURRENT_YEAR + 1)
      {
         errCode(Error_Year);
      }
      else if (m_MONTH < 1 || m_MONTH > 12)
      {
         errCode(Error_Month);
      }
      else if (m_DAY < 1 || m_DAY > mdays())
      {
         errCode(Error_Day);
      }
      return !bad();
   }

   int Date::mdays() const
   {
      int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1};
      int mon = m_MONTH >= 1 && m_MONTH <= 12 ? m_MONTH : 13;
      mon--;
      return days[mon] + int((mon == 1) * ((m_YEAR % 4 == 0) && (m_YEAR % 100 != 0)) || (m_YEAR % 400 == 0));
   }

    int Date::systemYear()const {
        int theYear = sdds_year;
        if (!sdds_test) {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            theYear = lt.tm_year + 1900;
        }
        return theYear;
    }

    void Date::setToToday() {
        if (sdds_test) {
            m_DAY = sdds_day;
            m_MONTH = sdds_mon;
            m_YEAR = sdds_year;
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            m_DAY = lt.tm_mday;
            m_MONTH = lt.tm_mon + 1;
            m_YEAR = lt.tm_year + 1900;
        }
        errCode(Not_error);
    }

   int Date::daysSince0001_1_1() const
   { 
     int tempYear = m_YEAR;
        int tempMonth= m_MONTH;
        if (tempMonth < 3)
        {
            tempYear--;
            tempMonth += 12;
        }
        return 365 * tempYear + tempYear / 4 - tempYear / 100 + tempYear / 400 + (153 * tempMonth- 457) / 5 + m_DAY - 306;
   }

   Date::Date() : m_CURRENT_YEAR(systemYear())
   {
      setToToday();
   }

   Date::Date(int year, int mon, int day) : m_CURRENT_YEAR(systemYear())
   {
      m_YEAR = year;
      m_MONTH = mon;
      m_DAY = day;
      validate();
   }

   const char *Date::dateStatus() const
   {
      return Error_Date[errCode()];
   }

   int Date::currentYear() const
   {
      return m_CURRENT_YEAR;
   }

   void Date::errCode(int readErrorCode)
   {
      m_ERRORCODE = readErrorCode;
   }

   int Date::errCode() const
   {
      return m_ERRORCODE;
   }

   bool Date::bad() const
   {
      return m_ERRORCODE != 0;
   }


   std::istream &Date::read(std::istream &is)
   {
      
      errCode(Not_error);

   
      is >> m_YEAR;
      is.ignore();
      is >> m_MONTH;
      is.ignore();
      is >> m_DAY;

     
      if (!is)
      {
         errCode(input_Failed);
      }
     
      else
      {
         validate();
      }

      return is;
   }

 
   std::ostream &Date::write(std::ostream &os) const
   {
       if (bad()) {
           os << dateStatus();
       }
       else {
           os << m_YEAR << "/";
           os << setfill('0') << setw(2) << right << m_MONTH << "/";
           os << setfill('0') << setw(2) << right << m_DAY;
       }

      return os;
   }


   int Date::getdaysSince0001_1_1() const
   {
      return daysSince0001_1_1();
   }

   Date::operator bool() const
   {
      return (!bad()); 
   }

   ostream &operator<<(ostream &os, const Date &RO)
   {
      return RO.write(os);
   }

   istream &operator>>(istream &is, Date &RO)
   {
      return RO.read(is);
   }

 
   int numberOfDaysInMonth(int monthByNumber, int year)
   {
      int Days= 0;
      int array[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

     
      if (monthByNumber == 2 && ((year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0))))
      {
         Days = array[monthByNumber - 1] + 1;
      }

      else
      {
         Days = array[monthByNumber - 1];
      }

      return Days;
   }

   bool operator==(const Date &date1, const Date &date2)
   {
      return (date1.getdaysSince0001_1_1() == date2.getdaysSince0001_1_1());
   }

   bool operator!=(const Date &date1, const Date &date2)
   {
      return (date1.getdaysSince0001_1_1() != date2.getdaysSince0001_1_1());
   }

   bool operator>=(const Date &date1, const Date &date2)
   {
      return (date1.getdaysSince0001_1_1() >= date2.getdaysSince0001_1_1());
   }

   bool operator<=(const Date &date1, const Date &date2)
   {
      return (date1.getdaysSince0001_1_1() <= date2.getdaysSince0001_1_1());
   }

   bool operator<(const Date &date1, const Date &date2)
   {
      return (date1.getdaysSince0001_1_1() < date2.getdaysSince0001_1_1());
   }

   bool operator>(const Date &date1, const Date &date2)
   {
      return (date1.getdaysSince0001_1_1() > date2.getdaysSince0001_1_1());
   }

   int operator-(const Date &date1, const Date &date2)
   {
      int days = date1.getdaysSince0001_1_1() - date2.getdaysSince0001_1_1();
      return days;
   }
}
