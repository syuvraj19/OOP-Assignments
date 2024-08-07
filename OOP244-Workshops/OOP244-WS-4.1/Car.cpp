/*
*****************************************************************************
                          Workshop - #4 (P1)
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Section    : OOP-244-ZBB
Date       : 08/06/2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Car.h"
#include<iomanip>
#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

namespace sdds{

    void Car::resetInfo(){
        m_type = NULL;
        m_brand = NULL;
        m_model = NULL;
        m_year = 0;
        m_code = 0;
        m_price = 0;
    }
    Car::Car(){
        resetInfo();
    }
    Car::Car(const char* type, const char* brand, const char* model, int year, int code, double price){
        if(type != nullptr && brand != nullptr && model != nullptr && year > 0 && code > 0 && price > 0){
            m_type = const_cast<char *>(type);
                m_brand = const_cast<char *>(brand);
                m_model = const_cast<char *>(model);
                m_year = year;
                m_code = code;
            m_price = price;
        }
        else{
            cout << "any time here\n";
            resetInfo();
        }
    }
    Car::~Car(){
        m_type = NULL;
        m_brand = NULL;
        m_model = NULL;
    }
    
    Car& Car::setInfo(const char *type,const char *brand, const char *model,int year,int code,double price){
        this->m_type = const_cast<char *>(type);
            this->m_brand = const_cast<char *>(brand);
            this->m_model = const_cast<char *>(model);
            this->m_year = year;
            this->m_code = code;
            this->m_price = price;
            return *this;
    }

bool Car::isValid()const{
    if(m_type != NULL && m_brand != NULL && m_model != NULL && m_year >= 1990 && m_price > 0 && m_code >= 100){
        return true;
    }
    else{
        return false;
    }
}

    void Car::printInfo()const{
            if(m_type != NULL && m_brand != NULL && m_model != NULL && m_year >= 1990 && m_price > 0 && m_code > 99){
            printf("| %-10s | %-15s  | %-15s  | %-4d | %4d |  %8.2lf |\n",m_type,m_brand,m_model,m_year,m_code,m_price);
        }
        
    }

    bool Car::isSimilarTo(const Car& car) const{
        bool similar = false;
           if (this->m_type == car.m_type &&
                   this->m_brand == car.m_brand &&
                 this->m_model == car.m_model &&
               this->m_year== car.m_year
                 ){
                      similar = true;}
        
           return similar;
       }

bool has_similar(const Car car[],const int num_cars){
        for(int i = 0; i < num_cars; i++){
            for(int j = i + 1; j < num_cars; j++){
                if(car[i].isSimilarTo(car[j])){
                    return true;
                }
            }
        }
        return false;
    }

bool has_invalid(const Car car[], const int num_cars){
    
    int x = 0;
    while(x < num_cars){
        if(!car[x].isValid()){
        return true;
        }x++;
    }
    return false;
}

   void print(const Car car[], const int num_cars){
       int x = 0;
        while( x < num_cars){
            car[x].printInfo();
            x++;
        }
    }
}
