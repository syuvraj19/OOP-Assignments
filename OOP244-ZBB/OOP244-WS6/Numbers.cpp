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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
#include "Numbers.h"  // intentional
using namespace std;
namespace sdds {

  
   Numbers::Numbers() { 
      setEmpty();
      m_isOriginal = false;
   }

   Numbers::Numbers(const char* filename) { 
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load()) {
         delete[] m_numbers;
         delete[] m_filename;
         setEmpty();
         m_isOriginal = false; 
      }
      else {
         sort();
      }
   }
   Numbers::~Numbers() {
      save();
      delete[] m_numbers;
      delete[] m_filename;
   }
   
   bool Numbers::isEmpty() const { 
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty() { 
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }
   void Numbers::setFilename(const char* filename) { 
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }
   void Numbers::sort() {
      int i, j;
      double temp;
      for (i = m_numCount - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (m_numbers[j] > m_numbers[j + 1]) {
               temp = m_numbers[j];
               m_numbers[j] = m_numbers[j + 1];
               m_numbers[j + 1] = temp;
            }
         }
      }
   }

   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }
   double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }
   double Numbers::max() const {
      double maxVal = 0.0;
      if (!isEmpty()) {
         maxVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }
   Numbers::Numbers(const Numbers& number){
       this->setEmpty();
       this->m_isOriginal = false;
       *this = number;
   }
   Numbers& Numbers::operator=(const Numbers& number) {
       delete[] this->m_numbers;
       this->m_numbers = new double[number.m_numCount];
       this->m_numCount = number.m_numCount;
       for (int i = 0; i < m_numCount; i++) {
           this->m_numbers[i] = number.m_numbers[i];
       }
       return *this;
   }
   int Numbers::numberCount()const {
       int i = 0;
       ifstream f(this->m_filename);
       char c;
       while (f.get(c)) {
           if (c == '\n') {
               i++;
           }
       }
       f.close();
       return i;
   }
   bool Numbers::load() {
       int loaded = 0;
       if (this->m_numCount > 0) {
           this->m_numbers = new double[this->m_numCount];
           ifstream f(this->m_filename);
           
           while (f >> this->m_numbers[loaded]) {
               loaded++;
           }
           f.close();
       }
       return loaded ==this->m_numCount;

   }
   void Numbers::save() {
       if (this->m_isOriginal && !this->isEmpty()) {
           ofstream f(this->m_filename);
           for (int i = 0; i < this->m_numCount; i++) {
               f<<this->m_numbers[i]<<'\n';
           }
           f.close();
       }
   }
   Numbers& Numbers::operator += (const double value) {
       if (!this->isEmpty()) {
           double* temp = new double[this->m_numCount + 1];
           for (int i = 0; i < this->m_numCount; i++) {
               temp[i] = this->m_numbers[i];
           }
           temp[m_numCount] = value;
           this->m_numCount++;
           delete[] this->m_numbers;
           this->m_numbers = temp;
           sort();
       }
       else {
           this->m_numbers = new double[1];
           this->m_numbers[0] = value;
           this->m_numCount = 1;
       }
       return *this;
   }
   std::ostream& Numbers::display(std::ostream& ostr) const {
       if (this->isEmpty()) {
           ostr << "Empty list";
       }
       else {
           ostr <<"=========================" << endl;
           if (this->m_isOriginal == true) {
               ostr << this->m_filename << endl;
           }
           else {
               ostr << "*** COPY ***" << endl;
           }
           for (int i = 0; i < this->m_numCount; i++) {
               ostr<<this->m_numbers[i];
               if (i != (m_numCount - 1)) {
                   ostr << ", ";
               }
               else {
                   ostr << endl;
               }
           }
           ostr << "-------------------------" << endl;
           ostr << "Total of " << m_numCount << " number(s)"<<endl;
           ostr <<"Largest number:  " << this->max()<<endl;
           ostr <<"Smallest number: " <<this->min() << endl;
           ostr <<"Average :        " << this->average() << endl;
           ostr <<"=========================";
       }
       return ostr;
   }
   ostream& operator<<(ostream& os, const Numbers& N) {
       return N.display(os);
   }
   istream& operator>>(istream& istr, Numbers& N) {
       double value;
       istr >> value;
       N += value;
       return istr;
   }

}
