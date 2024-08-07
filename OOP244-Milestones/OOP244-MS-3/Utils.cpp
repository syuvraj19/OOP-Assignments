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
#include <iostream>
#include <cstring>
#include <string>
#include <ctype.h>
#include "Utils.h"

using namespace std;
namespace sdds {

  void Utils::getChar(std::istream & sho, char chr) {
      
    if (sho.peek() == chr) sho.get();
      
  }
  void Utils::getChar(std::istream & sho) {
      
    if (isdigit(sho.peek())) {
        
        sho.setstate(ios::failbit);
        
    } else {
        
        sho.get();
        
    }
  }
  int Utils::getInt(std::istream & sho, int min_lim, int max_lim,
    const char * Msg) {
      
      int Fin = 0;
    bool flag = false;
      
    while (!flag) {
        
        sho >> Fin;
        
      if (sho && sho.peek() == '\n') {
          
        if (Fin >= min_lim && Fin <= max_lim) {
            
          flag = true;
            
        } else {
            
            sho.ignore(1000, '\n');
            
          cout << "Out of Range, try again: ";
            
        }
      } else {
          
          sho.clear();
          
          sho.ignore(1000, '\n');
          
        if (Msg) cout << Msg;
          
      }
    }
      return Fin;
      
  }
  void Utils::copyStr(char * & dup,
    const char * server) {
      
    delete[] dup;
      
      dup = new char[strlen(server) + 1];
      
    strcpy(dup, server);
      
  }
  char * Utils::readInput(istream & sho, char spacer) {
      
    char * str {};
      
    string inspect;
      
    getline(sho, inspect, spacer);
      
    if (sho) {
        
      str = new char[strlen(inspect.c_str()) + 1];
        
      strcpy(str, inspect.c_str());
        
    }
    return str;
  }
}


