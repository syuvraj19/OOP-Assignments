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
#ifndef SDDS_HERO_H_
#define SDDS_HERO_H_
#include <iostream>
#include "Power.h"

namespace sdds
{
    const int MAX_NAME_LEN = 20;

    class Hero
    {
        char m_name[MAX_NAME_LEN + 1];
        
        Power* powers_x;
        
        int noofpow;
        
        int pow_lev;

        void init_hero();

    public:
        Hero();
        
        Hero(const char* hname, const Power* powers, int num);
        
        ~Hero();
        
        Hero& operator+=(const Power& vali);
        
        Hero& operator-=(const int valii);
        
        std::ostream& display() const;
        
        int getPowerLevel() const;
    };
    bool operator<(const Hero& uniti, const Hero& unitii);

    bool operator>(const Hero& uniti, const Hero& unitii);

    void operator>>(const Power& powerval, Hero& heroval);

    void operator<<(Hero& heroval, const Power& powerval);
}
#endif
