/*
*****************************************************************************
                              milestone - 3
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Section    : OOP-244-ZBB
Date       : 29/07/2022

Authenticity Declaration:
 I have done all the coding by myself and only copied the code that my professor
 provided to complete my project milestones.
*****************************************************************************
*/
#include<iostream>
#include"Streamable.h"
using namespace std;

namespace sdds {
    ostream& operator<<(ostream& dis, const Streamable& piece) {
        
        piece.write(dis);
        
        return dis;
    }

    istream& operator>>(istream& dis2, Streamable& piece) {
        
        piece.read(dis2);
        
        return dis2;
    }
}

