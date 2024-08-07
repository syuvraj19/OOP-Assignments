

#pragma once
#ifndef SDDS_RACECAR_H_
#define SDDS_RACECAR_H_
#include <iostream>
#include "Car.h"
namespace sdds {

	class Racecar :public Car {
		double m_booster = 0;
	public:
		Racecar();
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
	};
}
#endif // !SDDS_RACECAR_H_
