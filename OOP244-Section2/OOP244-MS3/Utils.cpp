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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <cstring>

#include <string>

#include <ctype.h>

#include "Utils.h"

using namespace std;
namespace sdds {
  void Utils::getChar(std::istream & is, char ch) {
    if (is.peek() == ch) is.get();
  }
  void Utils::getChar(std::istream & is) {
    if (isdigit(is.peek())) {
      is.setstate(ios::failbit);
    } else {
      is.get();
    }
  }
  int Utils::getInt(std::istream & is, int min, int max,
    const char * message) {
      int res = 0;
    bool flag = false;
    while (!flag) {
      is >> res;
      if (is && is.peek() == '\n') {
        if (res >= min && res <= max) {
          flag = true;
        } else {
          is.ignore(1000, '\n');
          cout << "Out of Range, try again: ";
        }
      } else {
        is.clear();
        is.ignore(1000, '\n');
        if (message) cout << message;
      }
    }
      return res;
  }
  void Utils::copyStr(char * & des,
    const char * src) {
    delete[] des;
    des = new char[strlen(src) + 1];
    strcpy(des, src);
  }
  char * Utils::readInput(istream & is, char delimeter) {
    char * str {};
    string toRead;
    getline(is, toRead, delimeter);
    if (is) {
      str = new char[strlen(toRead.c_str()) + 1];
      strcpy(str, toRead.c_str());
    }
    return str;
  }
}

