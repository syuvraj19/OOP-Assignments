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

#include <iostream>
using namespace std;
#include "Utils.h"

namespace sdds {
   
    int getIntegerInput(int minRange, int maxRange) {
        int INPUT;
        bool VALIDINTEGER = false;
        while (VALIDINTEGER == false)
        {
            cin >> INPUT;
            if (!cin || INPUT < minRange || INPUT > maxRange)
            {
                std::cout << "Invalid Selection, try again: ";
                cin.clear();
                cin.ignore(1000, '\n');
                VALIDINTEGER = false;
            }
            else
            {
                VALIDINTEGER = true;
            }

        }
        return INPUT;
    }
}
