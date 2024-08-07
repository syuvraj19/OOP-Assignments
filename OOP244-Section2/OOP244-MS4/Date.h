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

#ifndef SDDS_DATE_H__
#define SDDS_DATE_H__
#include <iostream>
namespace sdds
{
   const int Not_error = 0;
   const int input_Failed = 1;
   const int Error_Year = 2;
   const int Error_Month = 3;
   const int Error_Day = 4;
   const char Error_Date[5][16] = {
       "No Error",
       "cin Failed",
       "Bad Year Value",
       "Bad Month Value",
       "Bad Day Value"};
   const int MIN_YEAR = 1500;
   class Date
   {
   private:
      int m_YEAR;
      int m_MONTH;
      int m_DAY;
      int m_ERRORCODE;
      int m_CURRENT_YEAR;
      int daysSince0001_1_1() const; 
      bool validate();              
      void errCode(int);            
      int systemYear() const;        
      bool bad() const;             
      int mdays() const;            
      void setToToday();             
   public:
      Date();                           
      Date(int year, int mon, int day); 
      int errCode() const;              
      const char *dateStatus() const;   
      int currentYear() const;         
      int getdaysSince0001_1_1() const;

     
      operator bool() const;

      std::istream &read(std::istream &is = std::cin);

     
      std::ostream &write(std::ostream &os = std::cout) const;
   };

   
   std::ostream &operator<<(std::ostream &os, const Date &RO);
   std::istream &operator>>(std::istream &is, Date &RO);

   int numberOfDaysInMonth(int monthByNumber, int year);

   bool operator==(const Date &date1, const Date &date2);
   bool operator!=(const Date &date1, const Date &date2);
   bool operator>=(const Date &date1, const Date &date2);
   bool operator<=(const Date &date1, const Date &date2);
   bool operator<(const Date &date1, const Date &date2);
   bool operator>(const Date &date1, const Date &date2);

  
   int operator-(const Date &date1, const Date &date2);

   
    extern bool sdds_test;
    extern int sdds_year;
    extern int sdds_mon;
    extern int sdds_day;
}
#endif
