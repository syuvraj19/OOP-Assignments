/***********************************************************************
 CLASS : OOP244
 SECTION : ZBB
 NAME          : Yuvraj Singh
 EMAIL         : yuvraj-singh5@myseneca.ca
 STUDENT ID    : 155580210
DATE CREATED ON : 29 JULY 2022
MILESTONE 3

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>

namespace sdds {
  class Utils {
    public:
      Utils() = delete;
    static void getChar(std::istream & is, char ch); //extract a given char
    static void getChar(std::istream & is); //if next char is digit set istr fail or extract it otherwise
    static int getInt(std::istream & is, int min, int max,
      const char *
        message = nullptr); //get a int with validation and error message
    static void copyStr(char * & des,
      const char * src); //copy a string of dynamic length
    static char * readInput(std::istream & is, char delimeter = '\n'); //read a dynamic string from istr
  };
}
#endif // SDDS_UTILS_H__

