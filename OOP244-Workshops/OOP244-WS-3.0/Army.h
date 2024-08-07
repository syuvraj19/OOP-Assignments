/*
*****************************************************************************
                          Workshop - #3 (Part-1)
Full Name  :yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Section    : OOP-244-ZBB
Date       : 06/06/2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef Army_h
#define Army_h

#include <stdio.h>
#include <iostream>
#include <cstring>
#define MAX_NAME_LEN 50

using namespace std;
namespace sdds{

class Army
{
    char nationality[MAX_NAME_LEN];
    int units;
    double power;

    public:

    void setEmpty()
    {
        strcpy(nationality,"");
        units=0;
    }

    void createArmy(const char* country, double pow, int troops)
    {
        if (country != nullptr && strlen(country) > 0 && pow > 0 && troops >> 0)
        {
            if (strlen(country) > MAX_NAME_LEN)
            {
                strncpy(nationality, country, MAX_NAME_LEN);
            }
            else
            {
                strcpy(nationality, country);
            }
            power = pow;
            units = troops;
        }
        else
        {
            setEmpty();
        }
    }
    void updateUnits(int troops)
    {
        units+=troops;
        power+=(0.25)*troops;
    }

    const char* checkNationality() const
    {
        return nationality;
    }

    int checkCapacity() const
    {
        return units;
    }

    double checkPower() const
    {
        return power;
    }

    bool isEmpty() const
    {
        return strlen(nationality) == 0 && units <= 0;
    }

    bool isStrongerThan(const Army& army)const
    {
        if(power>army.checkPower())
            return true;
        else
            return false;
    }
};

void battle(Army &arm1, Army &arm2);

void displayDetails(const Army*armies, int size);
}
#endif /* Army_h */
