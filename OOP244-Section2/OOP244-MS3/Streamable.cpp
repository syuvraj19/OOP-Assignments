/***********************************************************************
 CLASS : OOP244
 SECTION : ZBB
 NAME          : Yuvraj Singh
 EMAIL         : yuvraj-singh5@myseneca.ca
 STUDENT ID    : 155580210
DATE CREATED ON : 29 JULY 2022
MILESTONE 3

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#include<iostream>
#include"Streamable.h"

using namespace std;

namespace sdds {
    ostream& operator<<(ostream& os, const Streamable& obj) {
        obj.write(os);
        return os;
    }

    istream& operator>>(istream& is, Streamable& obj) {
        obj.read(is);
        return is;
    }
}
