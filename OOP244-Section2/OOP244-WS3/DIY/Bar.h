/***********************************************************************
 NAME: Yuvraj Singh
 CLASS : OOP244
 SECTION : ZBB
 STUDENT NUMBER : 155580210
 EMAIL : yuvraj-singh5@myseneca.ca
DATE CREATED ON : 06 JUNE 2022
WORKSHOP 3 PART 2

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SUN_BAR_H
#define SUN_BAR_H


namespace sdds{
}

class Bar
{
char * name ;
int length;
char type;
    
public:
void set(const char* a, char b,int c);
void draw();
void deallocate();
};

#endif
