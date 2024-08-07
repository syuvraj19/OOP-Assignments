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

#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>

namespace sdds {

  class Utils {
      
    public:
      
      Utils() = delete;
      
    static void getChar(std::istream & sho, char chr);
      
    static void getChar(std::istream & sho);
      
    static int getInt(std::istream & sho, int min_lim, int max_lim,
      const char *
                      Msg = nullptr);
      
    static void copyStr(char * & dup,
      const char * server);
      
    static char * readInput(std::istream & sho, char spacer = '\n');
      
  };
}
#endif // SDDS_UTILS_H__

