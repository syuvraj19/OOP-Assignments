/***********************************************************************
 NAME: Yuvraj Singh
 CLASS : OOP244
 SECTION : ZBB
 STUDENT NUMBER : 155580210
 EMAIL : yuvraj-singh5@myseneca.ca
DATE CREATED ON : 03 JUNE 2022
WORKSHOP 3 PART 1

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SUN_H
#define SUN_H

const int MAX_NAME_LEN = 50;

class Army
{
char nationality [MAX_NAME_LEN];
int numberOfUnits;
double power;

public:
  void setEmpty();
  void createArmy(const char* country, double pow, int troops);
  void updateUnits(int troops); 
  const char* checkNationality() const;
int checkCapacity() const;
double checkPower() const;
bool isEmpty() const;
bool isStrongerThan(const Army& army)const;
};

namespace sdds{
    void battle( Army& arm1, Army& arm2);
    void displayDetails(const Army* armies, int size);
}



#endif
