/***********************************************************************
 CLASS : OOP244
 SECTION : ZBB
 NAME          : Yuvraj Singh
 EMAIL         : yuvraj-singh5@myseneca.ca
 STUDENT ID    : 155580210
DATE CREATED ON : 22 JULY 2022
MILESTONE 2

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#include <iostream>
#include <cstring>
#include "Utils.h"
using namespace std;
using namespace sdds;
namespace sdds {


    int getInt(int minRange, int maxRange, const char* errorMessage) {
        int selectedItem = 0;
        bool trueInt = false;
        while (trueInt == false)
        {
            cin >> selectedItem;
            if (cin.fail() || selectedItem < minRange || selectedItem > maxRange)
            {
                cout << errorMessage;
                cin.clear();
                cin.ignore(1000, '\n');
                trueInt = false;
            }
            else
            {
                trueInt = true;
            }

        }
        return selectedItem;
    };
}
