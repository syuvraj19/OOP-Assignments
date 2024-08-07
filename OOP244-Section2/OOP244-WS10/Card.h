/***********************************************************************
 NAME : Yuvraj Singh
 CLASS : OOP244
 SECTION : ZBB
 STUDENT NUMBER : 155580210
 EMAIL : yuvraj-singh5@myseneca.ca
DATE CREATED ON : 5 AUGUST 2022
WORKSHOP 10

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/

// Workshop 10:
// Card.h
// 2022-02-19
// Version: 1.0 
// Author: Nathan Misener
// Revised by: Sunpreet Kaur
/////////////////////////////////////////////
#include <iostream>
#ifndef SDDS_CARD_H_
#define SDDS_CARD_H_
#include "Write.h"
namespace sdds {
    class Card : public ReadWrite {
        char m_suit[10];
        int m_value;
    public:
        Card(const char* suit = "", const int value= 0);
        void set(const char* suit, const int value);
        std::ostream& display(std::ostream& os)const;
        bool operator==(const char* mmSubstr)const;
        bool operator==(const int mmVal)const;
    };
    std::ostream& operator<<(std::ostream& os, const Card& card);
}
#endif // !SDDS_CARD_H_
