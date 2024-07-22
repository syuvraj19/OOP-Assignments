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
#include<cstring>
#include<iostream>
#include "BarChart.h"
#include "Bar.h"
using namespace sdds;
using namespace std;

void BarChart::init(const char* a, int b, char c){
int n=std::strlen(a);
title = new char[n+1];
std::strcpy(title,a);
fillChar= c;
numOfSamples = b;
sizeOfBar =0;
bars = new Bar[numOfSamples];
}

void BarChart::add(const char* a, int b){
Bar bar;
bar.set(a,fillChar,b);
bars[sizeOfBar]= bar;
sizeOfBar++;
}

void BarChart::draw(){
if (sizeOfBar !=numOfSamples){
    std::cout<<"Invalid Chart!\n";
    return ;
}
std::cout<<title<<"\n";
std::cout<<"-----------------------------------------------------------------------\n";
for(int i=0;i<numOfSamples;i++){
    bars[i].draw();
}
std::cout<<"-----------------------------------------------------------------------\n";
}

void BarChart::deallocate(){
    delete [] title;
    for(int i=0;i<numOfSamples;i++){
        bars[i].deallocate();
    }
    delete [] bars;
}
