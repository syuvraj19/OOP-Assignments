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
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Army.h"
#define MAX_NAME_LEN 50

using namespace std;
namespace sdds{

void battle(Army &arm1, Army &arm2)
{
    if(!(arm1.isEmpty() && arm2.isEmpty()))
    {
        cout<<"In battle of "<<arm1.checkNationality()<<" and "<<arm2.checkNationality()<<", ";
        if(arm1.isStrongerThan(arm2))
        {
            cout<<arm1.checkNationality();
            arm2.updateUnits(arm2.checkCapacity()*(-0.5));
        }
        else
        {
            cout<<arm2.checkNationality();
            arm1.updateUnits(arm1.checkCapacity()*(-0.5));
        }
        cout<<" is victorious!\n";
    }
}

void displayDetails(const Army*armies, int size)
{
    cout<<"Armies reporting to battle: \n";
    for(int i=0;i<size;i++){
        if (!armies[i].isEmpty())
        {
            cout << "Nationality: " << armies[i].checkNationality()
                << ", Units Count: " << armies[i].checkCapacity() << ", Power left: "
                << fixed << setprecision(1) << armies[i].checkPower() << endl;
        }
    
}
}
}
