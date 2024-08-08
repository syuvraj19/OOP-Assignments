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
#ifndef SDDS_Utils_h // replace with relevant names
#define SDDS_Utils_h

namespace sdds {

	void flushkeys();
	bool ValidYesResponse(char ch);
	bool yes();
	void readCstr(char cstr[], int len);
	int readInt(int min, int max);

}

#endif
