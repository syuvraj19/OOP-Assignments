/***********************************************************************
 NAME : Yuvraj Singh
 CLASS : OOP244
 SECTION : ZBB
 STUDENT NUMBER : 155580210
 EMAIL : yuvraj-singh5@myseneca.ca
DATE CREATED ON : 22 JUNE 2022
WORKSHOP 5 PART 2

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_HERO_H
#define SDDS_HERO_H
#include "Power.h"
#include <iostream>
using namespace std;
namespace sdds {
class Hero {
private:
	char heroName[MAX_NAME_LENGTH];
	Power* powers;
	int numPowers;
	int powerLevel;
public:
	Hero();
	Hero(const char* name, Power* powers, int numPowers);
	Hero& operator +=(const Power& power);
	Hero& operator -=(const int& level);
    bool operator<(const Hero& hero);
	bool operator>(const Hero& hero);
	friend void operator >>(const Power& power, Hero& hero);
	friend void operator <<(Hero& hero, const Power& power);
    friend ostream& operator << (ostream& out, const Hero& hero);
	ostream& display() const;
	~Hero();
};
}
#endif
