/***********************************************************************
 NAME : Yuvraj Singh
 CLASS : OOP244
 SECTION : ZBB
 STUDENT NUMBER : 155580210
 EMAIL : yuvraj-singh5@myseneca.ca
DATE CREATED ON : 13 JUNE 2022
WORKSHOP 4 Part-2

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#include "CleanerBot.h"
#include<iostream>
#include <iomanip>
#include<cstring>
namespace sdds{
void report(CleanerBot* bot, const short num_bots){
    std::cout<<"         ------ Cleaner Bots Report -----\n";
    std::cout<<"     ---------------------------------------\n";
    std::cout<<"| Location   | Battery |  Number of Brushes | Active |\n";
    std::cout<<"|------------+---------+--------------------+--------|\n";
    for(int i=0;i<num_bots;i++){
        bot[i].display();
    }
    std::cout<<"\n|====================================================|\n";
std::cout<<"| LOW BATTERY WARNING:                               |\n";
std::cout<<"|====================================================|\n";
int count =0;
for(int i=0;i<num_bots;i++){
    if(!bot[i].isValid() && bot[i].getBattery()<30){
        count++;
    }
}
std::cout<<"| Number of robots to be charged: "<<count<<"                  |\n";
std::cout<<"| Sorting robots based on their available power:     |\n";
std::cout<<"| Location   | Battery |  Number of Brushes | Active |\n";
std::cout<<"|------------+---------+--------------------+--------|\n";
    for(int i=0;i<num_bots;i++){
        int max_bot=i;
        int max_count=bot[i].getBattery();
        for(int j=i+1;j<num_bots;j++){
            if(bot[j].getBattery()>max_count){
                max_bot = j;
                max_count = bot[j].getBattery();
            }
        }
        CleanerBot temp = bot[i];
        bot[i] = bot[max_bot];
        bot[max_bot] = temp;
    }
for(int i=0;i<num_bots;i++){
        bot[i].display();
    }
std::cout<<"|====================================================|\n";
}

void sort_bots(CleanerBot* bot, const short num_bots){
    if(num_bots<2){
        return ;
    }

    for(int i=0;i<num_bots;i++){
        int max_bot=i;
        int max_count=bot[i].getBattery();
        for(int j=i+1;j<num_bots;j++){
            if(bot[j].getBattery()>max_count){
                max_bot = j;
                max_count = bot[j].getBattery();
            }
        }
        CleanerBot temp = bot[i];
        bot[i] = bot[max_bot];
        bot[max_bot] = temp;
    }
}

int getLowBatteryBots(CleanerBot* bot, const short num_bots){
int count =0;
for(int i=0;i<num_bots;i++){
    if(!bot[i].isValid() && bot[i].getBattery()<30){
        count++;
    }
}
return count;
}

}


CleanerBot::CleanerBot(){
location[0] = '\0';
battery=0;
brush=0;
is_active = false;
}

CleanerBot::CleanerBot(const char loc[],double bat,int brsh,bool active){
    location[0] = '\0';
    if(loc){
        //int n=std::strlen(loc)+1;
        std::strcpy(location,loc);
    }
    battery = bat;
    brush = brsh;
    is_active = active;
}
CleanerBot::~CleanerBot(){
}
void CleanerBot::set(const char loc[],double bat,int brsh,bool active){
        if(loc){
      //  int n=std::strlen(loc)+1;
        std::strcpy(location,loc);
    }
    battery = bat;
    brush = brsh;
    is_active = active;
}
void CleanerBot::setLocation(const char loc[]){
        if(loc){
        //int n=std::strlen(loc)+1;
        std::strcpy(location,loc);
    }

}
void CleanerBot::setActive(bool isActive){
    is_active = isActive;
}
const char* CleanerBot::getLocation(){
    return location;
}
double CleanerBot::getBattery(){
    return battery;
}
int CleanerBot::getBrush(){
    return brush;
}
bool CleanerBot::isActive(){
    return is_active;
}
bool CleanerBot::isValid(){
    if(location[0]!='\0' && battery >=0 && brush >=0 ){
        return true;
    }
    return false;
}
void CleanerBot::display(){
std::cout << std::setprecision(1) << std::fixed;
        if (!isValid()){
            return;
        }
        std::cout<<std::left;
        if (isActive()){
        std::cout<<"| "<<std::setw(10)<<getLocation()<<" | "<<std::setw(7)<<std::right<<getBattery()<<" | "<<std::setw(18)<<std::right<<getBrush()<<" | "<<std::setw(6)<<std::left<<"YES"<<" |";
        }else{
            std::cout<<"| "<<std::setw(10)<<getLocation()<<" | "<<std::setw(7)<<std::right<<getBattery()<<" | "<<std::setw(18)<<std::right<<getBrush()<<" | "<<std::setw(6)<<std::left<<"NO"<<" |";
        }
        std::cout<<"\n";
        std::cout<<std::internal;
}
