

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
