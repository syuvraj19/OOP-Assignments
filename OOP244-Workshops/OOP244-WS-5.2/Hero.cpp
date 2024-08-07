/*
*****************************************************************************
                          Workshop - #5 (P2)
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Date    : 2022/06/23

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Hero.h"
#include "Power.h"

using namespace std;
namespace sdds
{
    void Hero::init_hero()
    {
        m_name[0] = '\0';
        noofpow = 0;
        powers_x = nullptr;
        pow_lev = 0;
    }
    Hero::Hero()
    {
        init_hero();
    }
    
    Hero::Hero(const char *hname, const Power *powers, int num)
    {
        int rarity = 0;
        init_hero();
        strcpy(m_name, hname);
        powers_x = new Power[num];
        int x = 0;
        while ( x < num)
        {
            powers_x[x] = powers[x];
            rarity = rarity + powers_x[x].checkRarity();
            x++;
        }
        noofpow = num;
        pow_lev = rarity * num;
    }

    Hero::~Hero()
    {
        delete[] powers_x;
    }

    Hero &Hero::operator+=(const Power &vali)
    {
        int rarity = 0;
        Power *strptr = new Power[noofpow + 1];
        int x = 0;
        while ( x < noofpow)
        {
            rarity = rarity + powers_x[x].checkRarity();
            strptr[x] = powers_x[x];
            x++;
        }
        
        strptr[noofpow] = vali;
        noofpow++;
        
        delete[] powers_x;
        
        powers_x = strptr;
        rarity = rarity + vali.checkRarity();
        pow_lev = rarity * noofpow;
        return *this;
    }

    Hero &Hero::operator-=(const int valii)
    {
        pow_lev = pow_lev - valii;
        return *this;
    }

    ostream &Hero::display() const
    {
        cout << "Name: " << m_name << "\n";
        displayDetails(powers_x, noofpow);
        cout << "Power Level: " << pow_lev;
        return cout;
    }

    int Hero::getPowerLevel() const
    {
        return pow_lev;
    }

    bool operator>(const Hero &uniti, const Hero &unitii)
    {
        return unitii.getPowerLevel() < uniti.getPowerLevel();
    }

    bool operator<(const Hero &uniti, const Hero &unitii)
    {
        return unitii.getPowerLevel() > uniti.getPowerLevel();
    }
    
    void operator<<(Hero &heroval, const Power &powerval)
    {
        heroval += powerval;
    }

    void operator>>(const Power &powerval, Hero &heroval)
    {
        heroval += powerval;
    }
}
