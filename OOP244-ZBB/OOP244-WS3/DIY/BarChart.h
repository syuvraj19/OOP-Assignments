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
#ifndef SUN_BAR_CHART_H
#define SUN_BAR_CHART_H

#include"Bar.h"

class BarChart{

    char *title;
    Bar *bars;
    char fillChar;
    int sizeOfBar;
    int numOfSamples;

    public:
    void init(const char* a, int b, char c);
    void add(const char* a, int b);
    void deallocate();
    void draw();
};

#endif
