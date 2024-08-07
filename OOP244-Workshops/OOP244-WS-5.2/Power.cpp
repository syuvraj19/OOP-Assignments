/*
*****************************************************************************
                          Workshop - #5 (P2)
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Date    : 2022/06/23

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include "Power.h"
#include "Hero.h"

using namespace std;

namespace sdds {

    Power::Power() {
        this->setEmpty();
    }
    Power::Power(const char* name, int rarity) {
        this->createPower(name, rarity);
    }
    void Power::setEmpty() {
        m_name[0] = '\0';
        m_rarity = 0;
    }
    void Power::createPower(const char* name, int rarity) {
        if (name && name[0] != '\0' && rarity > 0) {
            strncpy(this->m_name, name, MAX_NAME_LENGTH);
            this->m_rarity = rarity;
        }
        else {
            this->setEmpty();
        }
    }
    const char* Power::checkName() const {
        return m_name;
    }
    int Power::checkRarity() const {
        return m_rarity;
    }
    bool Power::isEmpty() const {
        return ( m_rarity == 0 || m_name[0] == '\0');
    }
    void displayDetails(Power* powers, int size) {
            cout << "List of available powers: " << endl;
            for (int i = 0; i < size; i++) {
                if (!powers[i].isEmpty()) {
                    cout << "  Name: " << powers[i].checkName() << ", "
                        << "Rarity: " << powers[i].checkRarity() << endl;
                }
            }
        }
    }
