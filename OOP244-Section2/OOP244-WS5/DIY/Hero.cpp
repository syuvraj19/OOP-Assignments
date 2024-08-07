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
#define _CRT_SECURE_NO_WARNINGS
#include "Hero.h"
#include "Power.h"
#include <iostream>
#include <cstring>
using namespace sdds;

namespace sdds {
    Hero::Hero() {
        this->heroName[0] = '\0';
        this->powers = nullptr;
        this->numPowers = 0;
        this->powerLevel = 0;
    }

    Hero::Hero(const char* name, Power* powers, int numPowers) {
        std::strcpy(this->heroName, name);
        this->powers = powers;
        this->numPowers = numPowers;
        int sum = 0;

        for (int i = 0; i < numPowers; i++) {
            sum += this->powers[i].checkRarity();
        }
        this->powerLevel = sum * numPowers;
    }

    ostream& operator << (ostream& out, const Hero& hero) {
        out << "Name: " << hero.heroName << endl;
        displayDetails(hero.powers,hero.numPowers);
        out << "Power Level: " << hero.powerLevel;
        return out;
    }


    Hero& Hero::operator +=(const Power& power) {
        Power* p = new Power[this->numPowers + 1];
        for (int i = 0; i < this->numPowers; i++) {
            p[i] = this->powers[i];
        }
        p[this->numPowers] = power;
        this->numPowers += 1;
        this->powers = new Power[this->numPowers];
        for (int i = 0; i < this->numPowers; i++) {
            this->powers[i] = p[i];
        }
        delete[] p;
        int sum = 0;
        for (int i = 0; i < numPowers; i++) {
            sum += this->powers[i].checkRarity();
        }
        this->powerLevel = sum * numPowers;
        return (*this);
    }

    Hero& Hero::operator -=(const int& level) {
        this->powerLevel -= level;
        return (*this);
    }

    bool Hero::operator<(const Hero& hero) {
        return this->powerLevel < hero.powerLevel;
    }

    bool Hero::operator>(const Hero& hero) {
        return this->powerLevel > hero.powerLevel;
    }

    void operator >>(const Power& power, Hero& hero) {
        Power* p = new Power[hero.numPowers + 1];
        for (int i = 0; i < hero.numPowers; i++) {
            p[i] = hero.powers[i];
        }
        p[hero.numPowers] = power;
        hero.numPowers += 1;
        hero.powers = new Power[hero.numPowers];
        for (int i = 0; i < hero.numPowers; i++) {
            hero.powers[i] = p[i];
        }
        delete[] p;
        int sum = 0;
        for (int i = 0; i < hero.numPowers; i++) {
            sum += hero.powers[i].checkRarity();
        }
        hero.powerLevel = sum * hero.numPowers;
    }

    void operator <<(Hero& hero, const Power& power) {
        Power* p = new Power[hero.numPowers + 1];
        for (int i = 0; i < hero.numPowers; i++) {
            p[i] = hero.powers[i];
        }
        p[hero.numPowers] = power;
        hero.numPowers += 1;
        hero.powers = new Power[hero.numPowers];
        for (int i = 0; i < hero.numPowers; i++) {
            hero.powers[i] = p[i];
        }
        delete[] p;
        int sum = 0;
        for (int i = 0; i < hero.numPowers; i++) {
            sum += hero.powers[i].checkRarity();
        }
        hero.powerLevel = sum * hero.numPowers;
    }

    ostream& Hero::display() const {
        std::cout << "Name: " << this->heroName << endl;
        displayDetails(this->powers,numPowers);
        cout << "Power Level: " << this->powerLevel;

        return cout;

    }

    Hero::~Hero(){
        if(powers!=nullptr){
        delete [] powers;
        }
    }

}
