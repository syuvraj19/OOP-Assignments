/***********************************************************************
 NAME : Yuvraj Singh
 CLASS : OOP244
 SECTION : ZBB
 STUDENT NUMBER : 155580210
 EMAIL : yuvraj-singh5@myseneca.ca
DATE CREATED ON : 09 JUNE 2022
WORKSHOP 4 PART 1

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#include"Car.h"
#include<iostream>
#include <iomanip>
#include<cstring>

namespace sdds {
    bool has_similar(const Car car[], const int num_cars) {
        for (int i = 0; i < num_cars; i++) {
            for (int j = i + 1; j < num_cars; j++) {
                if (car[i].isValid() && car[j].isValid()) {
                    if (car[i].isSimilarTo(car[j])) {
                        return true;
                    }
                }
            }
        }
        return false;
    }


    bool has_invalid(const Car car[], const int num_cars) {
        for (int i = 0; i < num_cars; i++) {
            for (int j = i + 1; j < num_cars; j++) {
                if (!car[i].isValid()) {
                    return true;
                }
            }
        }
        return false;

    }


    void print(const Car car[], const int num_cars) {
        for (int i = 0; i < num_cars; i++) {
            if (car[i].isValid()) {
                car[i].printInfo();
            }
        }
    }
};


Car::Car() {
    m_type = nullptr;
    m_brand = nullptr;
    m_model = nullptr;
    m_year = 0;
    m_code = 0;
    m_price = 0;
}

void Car::resetInfo() {
    delete[] m_type;
    delete[] m_brand;
    delete[] m_model;
    m_type = nullptr;
    m_brand = nullptr;
    m_model = nullptr;
    m_year = 0;
    m_code = 0;
    m_price = 0;
}

Car::~Car() {
    if (m_type) {
        delete[] m_type;
    }
    if (m_brand) {
        delete[] m_brand;
    }
    if (m_model) {
        delete[] m_model;
    }
}



Car::Car(const char* type,
    const char* brand,
    const char* model,
    int year,
    int code,
    double price) {

    int n = 0;
    if (type) {
        n = std::strlen(type) + 1;
        m_type = new char[n];
        std::strcpy(m_type, type);
    }
    n = std::strlen(brand) + 1;
    m_brand = new char[n];
    std::strcpy(m_brand, brand);
    n = std::strlen(model) + 1;
    m_model = new char[n];
    std::strcpy(m_model, model);
    m_year = year;
    m_code = code;
    m_price = price;
}

Car::Car(const char* type,
    const char* brand,
    const char* model) {
    int n = std::strlen(type) + 1;
    m_type = new char[n];
    std::strcpy(m_type, type);
    n = std::strlen(brand) + 1;
    m_brand = new char[n];
    std::strcpy(m_brand, brand);
    n = std::strlen(model) + 1;
    m_model = new char[n];
    std::strcpy(m_model, model);
    m_year = 2022;
    m_code = 100;
    m_price = 1;
}

Car& Car::setInfo(const char* type,
    const char* brand,
    const char* model,
    int year,
    int code,
    double price) {
    resetInfo();
    int n = 0;
    if (type) {
        m_brand = nullptr;

        n = std::strlen(type) + 1;
        m_type = new char[n];
        std::strcpy(m_type, type);
    }
    if (brand) {
        n = std::strlen(brand) + 1;
        m_brand = new char[n];
        std::strcpy(m_brand, brand);
    }
    if (model) {
        n = std::strlen(model) + 1;
        m_model = new char[n];
        std::strcpy(m_model, model);
    }
    m_year = year;
    m_code = code;
    m_price = price;
    return *this;
}

void Car::printInfo() const {
    std::cout << std::setprecision(2) << std::fixed;
    if (!isValid()) {
        return;
    }
    std::cout << std::left;
    std::cout << "| " << std::setw(10) << m_type << " | " << std::setw(16) << m_brand << " | " << std::setw(16) << m_model << " | " << m_year << " |  " << m_code << " | " << std::setw(9) << std::right << m_price << " |";
    std::cout << "\n";
    std::cout << std::internal;
}


int countDigit(long long n)
{
    if (n == 0)
        return 1;
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}


bool Car::isValid() const {
    if (m_type && m_brand && m_model && m_year >= 1990 && countDigit(m_code) == 3 && m_price > 0) {
        return true;
    }
    return false;
}
bool Car::isSimilarTo(const Car& car) const {
    if (std::strcmp(m_type, car.m_type) == 0 && std::strcmp(m_model, car.m_model) == 0 && std::strcmp(m_brand, car.m_brand) == 0 && m_year == car.m_year) {
        return true;
    }
    return false;
}
