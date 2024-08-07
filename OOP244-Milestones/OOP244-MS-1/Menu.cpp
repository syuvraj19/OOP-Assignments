/*
*****************************************************************************
                              milestone - 1
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Section    : OOP-244-ZBB

Authenticity Declaration:
 I have done all the coding by myself and only copied the code that my professor
 provided to complete my project milestones.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Menu.h"

using namespace std;

namespace sdds {

    MenuItem::MenuItem(const char* d) { //the class MenuItem is called here
        
        s_desc = new char[strlen(d) + 1];
        
        strcpy(s_desc, d);
    }

    MenuItem::operator const char*()const {
        
        return s_desc;
    }

    MenuItem::~MenuItem() {// the destructor of MenuItem is defined to deallocate memory
        
        delete[] s_desc;
    }

    MenuItem::operator bool()const {
        
        return (s_desc == nullptr);
    }

    ostream& MenuItem::display(ostream& os)const { // returns the os object
        
        if (s_desc != nullptr) {
            
            os << s_desc;
        }
        return os;
    }

    Menu::Menu(const char* tit) {
        
        s_tit = new MenuItem(tit);
        
        int x = 0;
        
        while ( x < MAX_MENU_ITEMS) {
            
            listofitems[x] = nullptr;
            x++;
        }
        s_alloc = 0;
    }

    Menu::~Menu() { //menu destructor is defined to deallocate memory
        int x = 0;
        
        while ( x < s_alloc) {
            
            delete listofitems[x];
            x++;
        }
    delete s_tit;
    }

    ostream& Menu::displayTitle(ostream& os) const{ //this function returns the object os
        
        s_tit->display(os);
        return os;
    }

    ostream& Menu::displayAllMenu(ostream& os) const { //this function returns the object os by displayAllMenu
        
        if (s_alloc > 1) {
            
            displayTitle(os) << ":" << endl;
            int x = 0;
            while ( x < s_alloc) {
                
                os << " " << x + 1 << "- " << listofitems[x]->s_desc << endl;
                x++;
            }
            os << " 0- Exit" << endl << "> ";
        } else {
            
            int x = 0;
            while ( x < s_alloc) {
                
                os << " " << x + 1 << "- " << listofitems[x]->s_desc << endl;
                x++;
            }
            os << " 0- Exit" << endl << "> ";
        }
        return os;
    }

    unsigned int Menu::run() { //this function return choice
        displayAllMenu();
        
        int cntr = 1,choice=0;
        
        while (cntr){
            
            cin >> choice;
            
            if (cin.fail()) {
                cout << "Invalid Selection, try again: ";
                cin.clear();
                
            } else if (choice < 0 || choice > s_alloc ) {
                cout << "Invalid Selection, try again: ";
                cin.clear();
                
            } else if (choice == 0) {
                cntr = 0;
                
            } else if (choice > 0 || choice <= s_alloc) {
                cntr = 0;
                
            }
            cin.ignore(1000, '\n');
        }
        return choice;
    }

    Menu& Menu::operator<<(const char* tmp) { //when menu is casted to "const char*" it should return the adress of the content Cstring
        
        if (s_alloc < MAX_MENU_ITEMS) {
            
            listofitems[s_alloc] = new MenuItem(tmp);
            
            s_alloc++;
        }
        return *this;
    }

    unsigned int Menu::operator~() {
        
        int z = run();
        
        return z;
    }

    Menu::operator bool()const { // function returns the s_alloc greater than 0.
        
        return s_alloc > 0;
    }

    Menu::operator unsigned int()const { // this function returns s_alloc
        
        return s_alloc;
    }

    const char* Menu::operator[](int cnt)const {
        
        return (const char*)*listofitems[cnt];
    }

    ostream& operator<<(ostream& os, const Menu& stor) {
        
        stor.displayTitle(os);
        
        return os;
    }
}
