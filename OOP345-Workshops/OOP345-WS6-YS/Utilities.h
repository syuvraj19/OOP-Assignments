/*
*****************************************************************************
                          Workshop - #6(P2)
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Date       : 6/11/2022
 
 I have done all the coding by myself and only copied the code that my
 professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#pragma once
#ifndef SDDS_UTILITIES_H_
#define SDDS_UTILITIES_H_
#include "Car.h"
#include "Van.h"
#include "Racecar.h"
#include "Luxuryvan.h"
namespace sdds {
	Vehicle* createInstance(std::istream& in);
}
#endif // !SDDS_UTILITIES_H_
