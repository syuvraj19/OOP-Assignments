/*==============================================
 NAME : Yuvraj Singh
 CLASS : OOP244
 SECTION : ZBB
 STUDENT NUMBER : 155580210
 EMAIL : yuvraj-singh5@myseneca.ca
 Workshop       : Workshop1
 Date completed : 20 May 2022
 I have done all the coding by myself and only
 copied the code that my professor provided to
 complete my workshops and assignments.
==============================================*/
#ifndef SDDS_ShoppingList_h// replace with relevant names
#define SDDS_ShoppingList_h

namespace sdds {

	bool loadList();
	bool saveList();
	void removeItem(int index);
	void clearList();
	void toggleBought();
	void addItemToList();
	bool listIsEmpty();
	void removeItemfromList();
	void displayList();
	void removeBoughtItems();


}

#endif
