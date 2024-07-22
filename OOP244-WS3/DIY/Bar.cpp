/***********************************************************************
 NAME : Yuvraj Singh
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
#include "Bar.h"
using namespace sdds;
using namespace std;

void Bar::set(const char* a, char b,int c){
name = new char[21];
type=b;
length=c;
std::strcpy(name,a);
name[20]='\0';
int n= std::strlen(a);
while(n<20){
    name[n++]='.';
}
}
void Bar::draw(){
    if (length>100 || length<0){
        return;
    }
std::cout<<name<<"|";
for(int i=1;i<=length/2;i++){
std::cout<<type;
}
std::cout<<"\n";
}

void Bar::deallocate(){
    delete [] name;
}
