/*
*****************************************************************************
                          Workshop - #6 (P1)
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Section    : OOP-244-ZBB

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {

   class Numbers {
       
      double* m_numbers;
       
      char* m_filename;
       
      bool m_isOriginal;
       
      int m_numCount;
       
      bool isEmpty()const; //returns true if m_numbers is null.
       
      void setEmpty(); //sets m_numbers and m_filename to nullptr. sets m_numCount to zero.
       
      void setFilename(const char* filename); //Copies the data file name to the newly allocated memory.
       
      void sort(); // this returns the double values sorted in ascending order
       
   public:
      Numbers(); 
       
      Numbers(const char* filename);
       
      Numbers(const Numbers& n);
       
      double average()const; //Returns the average of the double numbers in the list.
       
      double max()const; //Returns the largest double number in the list
       
      double min()const; //Returns the smallest double number in the list
       
      Numbers& operator=(const Numbers& n);
       
      int numberCount(); //Return the number of counted newlines when all characters in the file are scanned
      
      void save();
       
      bool load();//return true if the number of read doubles, is equal to the m_numCount member variable.

      Numbers& operator+=(double value);
       
      std::ostream& display(std::ostream& ostr) const; //At the end this returns the ostr object.
       
      ~Numbers();//deletes the memory pointed by m_numbers and m_filename

   };

   std::istream& operator>>(std::istream& istr, Numbers& N); //this returns istr;

   std::ostream& operator<<(std::ostream& os, const Numbers& N); //this calls the display fucntion of N and return it
   
}
#endif // !SDDS_NUMBERS_H_
