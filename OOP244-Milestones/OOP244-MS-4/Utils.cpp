/*
*****************************************************************************
                              milestone - 4
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Section    : OOP-244-ZBB
Date       : 5/08/2022

Authenticity Declaration:
 I have done all the coding by myself and only copied the code that my professor
 provided to complete my project milestones.
*****************************************************************************
*/

#include <iostream>
using namespace std;
#include "Utils.h"

namespace sdds {

    int getIntegerInput(int minLimit, int maxLimit) {
        int entry;
        bool entryvalid = false;
        while (entryvalid == false)
        {
            cin >> entry;
            if (!cin || entry < minLimit || entry > maxLimit)
            {
                std::cout << "Invalid Selection, try again: ";
                cin.clear();
                cin.ignore(1000, '\n');
                entryvalid = false;
            }
            else
            {
                entryvalid = true;
            }
        }
        return entry;
    }
}

