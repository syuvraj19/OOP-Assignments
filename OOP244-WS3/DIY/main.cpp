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
/* ----------------------------------------------------
Workshop 3:
Version: 1.0
Author: Fardad Soleimanloo
Description:
This file tests the BarChart section of your DIY workshop
-----------------------------------------------------*/

#include <iostream>
#include "BarChart.h"
using namespace sdds;
using namespace std;
int main() {
   BarChart bc;
   bc.init("How much students like this lab.", 5, '=');
   bc.add("Best Lab Ever", 2);
   bc.add("Good Lab", 10);
   bc.add("Doable Lab", 63);
   cout << "Premature draw call:"<< endl; 
   bc.draw(); // will not draw; it will print an error instead
   bc.add("Bad Lab", 10);
   bc.add("Worst Lab Ever", 5);
   cout << "Proper draw call after all samples are entered:" << endl;
   bc.draw();
   bc.deallocate();
   return 0;
}
