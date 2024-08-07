/*
*****************************************************************************
                              milestone - 5
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Section    : OOP-244-ZBB
Date       : 7/08/2022

Authenticity Declaration:
 I have done all the coding by myself and only copied the code that my professor
 provided to complete my project milestones.
*****************************************************************************
*/

#include <iostream>
using namespace std;

#include "Utils.h"
namespace sdds {

	unsigned int getIntInRange(int minimumRange, int maximumRange) {
		int x;
		cin >> x;
		if (cin.fail() || x<minimumRange || x>maximumRange) {
			cin.clear();
			char charr;
			while (cin.get(charr) && charr != '\n') {
				;
			}
			cout << "Invalid Selection, try again: ";
			return getIntInRange(minimumRange, maximumRange);
		}
		else {
			return x;
		}
	}
}
