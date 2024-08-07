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

#ifndef SDDS_STREAMABLE_H_
#define SDDS_STREAMABLE_H_

#include<iostream>
using namespace std;

namespace sdds {
	class Streamable{
        
	public:
        
        virtual ostream& write(std::ostream& os) const = 0;// write receives and returns a reference of an ostream object.
        virtual istream& read(std::istream& is) = 0;//read receives and returns a reference of an istream object.
        virtual bool conIO(std::ios& io) const = 0;//conIo receives a reference of an ios object and returns a Boolean.
        virtual operator bool() const = 0;
		~Streamable(){};
	};


}
#endif
