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
#include<iostream>
#include<cstring>
#include <iomanip>
#include "Army.h"

namespace sdds{

void battle( Army& arm1, Army& arm2){

if(arm1.isStrongerThan(arm2)){
    std::cout<<"In battle of "<<arm1.checkNationality()<<" and "<<arm2.checkNationality()<<", "<<arm1.checkNationality()<<" is victorious!\n";
    arm2.updateUnits(-arm2.checkCapacity()/2);
    return;
}
std::cout<<"In battle of "<<arm1.checkNationality()<<" and "<<arm2.checkNationality()<<", "<<arm2.checkNationality()<<" is victorious!\n";
arm1.updateUnits(-arm1.checkCapacity()/2);

}
    void displayDetails(const Army* armies, int size){
        std::cout<<"Armies reporting to battle: \n";
        for(int i=0;i<size;i++){
            Army temp = armies[i];
            if (temp.isEmpty()){
                continue;
            }
            std::cout<<"Nationality: "<<temp.checkNationality()<<", Units Count: "
            <<temp.checkCapacity()<<", Power left: "<<temp.checkPower()<<"\n";
        }
    }

};

void Army::setEmpty(){
nationality[0]='\0';
power=0;
}

void Army::createArmy(const char* country, double pow, int troops){
    std::cout << std::setprecision(1) << std::fixed;
    if (country == nullptr || std::strlen(country)<1 || pow <= 0.0 || troops <=0){
        setEmpty();
        return;
    }
    int n = strlen(country)+1;
    if(n>MAX_NAME_LEN){
        n = MAX_NAME_LEN-1;
    }
    std::strncpy(nationality,country,n);
    power = pow;
    numberOfUnits = troops ;
}

void Army::updateUnits(int troops){
numberOfUnits +=troops;
power += 0.25*troops;
}

const char* Army::checkNationality() const{
return nationality;
}
int Army::checkCapacity() const{
    return numberOfUnits;
}

double Army::checkPower() const{
    return (double)power;
}

bool Army::isEmpty() const{
    if (power ==0 && nationality[0] == '\0'){
        return true;
    }
    return false;
}

bool Army::isStrongerThan(const Army& army)const{
    if(power > army.checkPower()){
        return true;
    }
    return false;
}
