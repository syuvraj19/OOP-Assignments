/***********************************************************************
 NAME : Yuvraj Singh
 CLASS : OOP244
 SECTION : ZBB
 STUDENT NUMBER : 155580210
 EMAIL : yuvraj-singh5@myseneca.cas
DATE CREATED ON : 5 AUGUST 2022
WORKSHOP 10

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/

// Workshop 10:
// Write.cpp
// 2022-02-25
// Version: 1.0 
// Author: Nathan Misener
// Revised by: Sunpreet Kaur 
/////////////////////////////////////////////
#include <iostream>
#include "Write.h"
using namespace std;
namespace sdds {
   ostream& operator<<(ostream& os, const ReadWrite& c) {
      return c.display(os);
   }
}
