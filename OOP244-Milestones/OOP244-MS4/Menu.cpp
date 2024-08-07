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

#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include "Menu.h"
#include"Utils.h"
#include<iostream>
#include<string.h>
namespace sdds {

	Menu::Menu() {
		title = new MenuItem();
		for (unsigned int i= 0; i < MAX_MENU_ITEMS; i++) {
            list_of_menu_items[i] = nullptr;
		}
        num_items = 0;
	}

	Menu::Menu(const char* menuitem) {
		{
		title = new MenuItem(menuitem);
		}
		for (unsigned int i= 0; i < MAX_MENU_ITEMS; i++) {
            list_of_menu_items[i] = nullptr;
		}
        num_items = 0;
	}

	std::ostream& Menu::display(std::ostream& os) const
	{
		if ((const char*)(*title) != nullptr) {
			os << (const char*)(*title);
			os << std::endl;
		}
		for (unsigned int i= 0; i < num_items; i++) {
			os <<" " << i + 1 << "- ";
			os<<(const char*)(*list_of_menu_items[i]);
			os << std::endl;
		}
		os << " 0- Exit" << std::endl<<"> ";

	
		return os;
	}

	unsigned int Menu::run()
	{
		display();
		return getIntInRange(0,num_items);
	}

	unsigned int Menu::operator~()
	{
		return run();
	}
	Menu& Menu::operator<<(const char* menuitemConent)
	{
		if (num_items < MAX_MENU_ITEMS) {
            list_of_menu_items[num_items] = new MenuItem(menuitemConent);
            num_items++;
		}

		return *this;
	}

	Menu::~Menu() {
		delete title;
		for (unsigned int i= 0; i <num_items; i++) {
			//itemList[i]->~MenuItem();
			delete list_of_menu_items[i];
            list_of_menu_items[i] = nullptr;
		}

	}
	Menu::operator int()
	{
		return num_items;
	}

	std::ostream& Menu::displayT(std::ostream& os)
	{
		if((const char*)(*title) != nullptr) {
			os <<(const char*)(*title);
		}
		return os;
	}

	Menu::operator unsigned int()
	{
		return num_items;
	}
	Menu::operator bool()
	{
		return num_items>=1;
	}

	const char* Menu::operator[](int i) const
	{
		return (const char*)(*list_of_menu_items[i % num_items]);
	}

	
	std::ostream& operator<<(std::ostream& os,Menu& menu) {
		return menu.displayT(os);
		
	}

	MenuItem::MenuItem() {
		item = nullptr;
	}
	MenuItem::MenuItem(const char* menuitem){

		item =new char[strlen(menuitem)+1];
		strcpy(item, menuitem);
	}

	MenuItem::operator char* () const{
		return item;
	}
	MenuItem::operator bool() const{
		return item != nullptr;
	}
	std::ostream& MenuItem::write(std::ostream& os)const{
		if (item != nullptr) {
			os << item;
		}
		return os;
	}
	MenuItem::~MenuItem() {
		if(item!=nullptr)
		delete[] item;
	}
}
