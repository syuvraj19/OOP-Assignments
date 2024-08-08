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
#include <iostream>
#include "Utils.h"
#include "ShoppingRec.h"

using namespace std;

namespace sdds {

	const int MAX_QUANTITY_VALUE = 50;


	ShoppingRec getShoppingRec()
	{
		ShoppingRec R = {};
		cout << "Item name: ";
		readCstr(R.m_title, MAX_TITLE_LENGTH);
		cout << "Quantity: ";
		R.m_quantity = readInt(1, MAX_QUANTITY_VALUE);
		return R;
	}
	void displayShoppingRec(const ShoppingRec* shp) {
		cout << "[" << (shp->m_bought ? 'X' : ' ') << "]" << shp->m_title <<
			" qty:(" << shp->m_quantity << ")" << endl;
	}
	void toggleBoughtFlag(ShoppingRec* rec) {
		rec->m_bought = !rec->m_bought;

	}
	bool isShoppingRecEmpty(const ShoppingRec* shp) {
		return shp->m_title[0] == 0;
	}



}
