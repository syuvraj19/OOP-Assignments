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
#ifndef SDDS_FILE_H // replace with relevant names
#define SDDS_FILE_H

#include "ShoppingRec.h"

namespace sdds {

	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);
}

#endif
