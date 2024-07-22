/***********************************************************************
 NAME: Yuvraj Singh
 CLASS : OOP244
 SECTION : ZBB
 STUDENT NUMBER : 155580210
 EMAIL : yuvraj-singh5@myseneca.ca
DATE CREATED ON : 06 JUNE 2022
WORKSHOP 3 PART 2

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
/*----------------------------------------------------
Workshop 3:
Version: 1.0
Author: Fardad Soleimanloo
Description:
This file tests the Bar class of your DIY workshop
----------------------------------------------------*/
#include "Bar.h"
using namespace sdds;
int main() {
   Bar b;
   for (int i = 1; i <= 5; i++) {
      b.set("the bar", '=', i*20);
      b.draw();
   }
   b.set("Bad Bar", '=', -200);
   b.draw();
   b.set("Bad Bar", '=', 200);
   b.draw();
   return 0;
}
