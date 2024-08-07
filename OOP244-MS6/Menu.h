/*
*****************************************************************************
                              milestone - 5
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Section    : OOP-244-ZBB
Date       : 7/08/2022

Authenticity Declaration:
 I have done all the coding by myself and only copied the code that my professor
 provided to complete my project milestones.
*****************************************************************************
*/

#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>
#include"Utils.h"
const unsigned int MAX_MENU_ITEMS = 20;

namespace sdds {

	class MenuItem {
        
	private:
        
		char* item;
		MenuItem();
		MenuItem(const char* menuitem);
		operator char* () const;
		operator bool() const;
		std::ostream& write(std::ostream& os = std::cout)const;
		~MenuItem();
	public:
		friend class Menu;//which makes MenuItem class only accessible by the Menu class
	};

	class Menu { // A class that has several MenuItems to be displayed so the user can select one of them for an action to be executed in the program
	private:
		MenuItem *title;
        MenuItem *list_of_menu_items[MAX_MENU_ITEMS];
		unsigned int num_items;
    
	public:
		Menu();//Allocates and sets the content of the MenuItem to a Cstring value at the moment of instantiation
		Menu(const char* menuitem);
		std::ostream& display(std::ostream& os = std::cout)const;
		unsigned int run();
		unsigned int operator ~();
		Menu& operator<<(const char* menuitemConent);//This operator receives a C-style string containing the content of the MenuItem and returns the reference of the Menu object (*this).
		std::ostream& displayT(std::ostream& os);
		operator int();
		operator unsigned int();
		operator bool();
		const char* operator [](int i)const;

		~Menu();//Deallocates the content
	};
	std::ostream& operator<<(std::ostream& os,Menu& menu);
	
}
#endif // !
