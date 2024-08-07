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


#ifndef SDDS_LIBAPP_H__
#define SDDS_LIBAPP_H__
#include"Publication.h"
#include"Menu.h"
#include"Book.h"
#include"Lib.h"

namespace sdds {

	class LibApp{
        
	private:
        
		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;
        
		char file_name[256];//Add an array of 256 characters to hold the publication data file name.
		Publication* PPA[SDDS_LIBRARY_CAPACITY];//Publication Pointers Array "PPA" for short.
		int NOLP;//Number Of Loaded Publications "NOLP" for short.
		int LLRN;//Last Library Reference Number "LLRN" for short.
		Menu m_pubMenu;//type of publication menu
        
		bool confirm(const char* message);
		void load();  //First print "Loading Data" and then open the data file for reading and read all the publications in dynamic instances pointed by the PPA Array.
		void save();  // First print "Saving Data" and then open the data file stream for overwriting. (ofstream) Go through the elements of PPA up to the N0LP
		int search(int version); 
		void returnPub();  //  Calls the search() method.prints "Returning publication"<NEWLINE>, prints "Publication returned"<NEWLINE>, sets m_changed to true;
        
	public:
        
		LibApp(const char*);
		void newPublication();//to add a new pulication.
		void removePublication();// to remove an existing publication.
		void checkOutPub();
		void run();
		Publication* getPub(int libRef);//return the address of a Publication object in the PPA that has the library reference number matching the "libRef" argument.
		~LibApp();// the destructor
	};
}
#endif // !
