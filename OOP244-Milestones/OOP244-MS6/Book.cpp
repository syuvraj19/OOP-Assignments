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
#include"Book.h"
#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

namespace sdds {

	Book::Book():Publication(){
		auth = nullptr;//The book class only has one attribute that is a pointer to a character to hold an author's name Dynamically.
	}

	Book::Book(const Book& var):Publication(var) {
		auth = nullptr;
		if (var.auth != nullptr) {
			auth = new char[strlen(var.auth)+1];
			strcpy(auth, var.auth);
		}
	}

	Book& Book::operator=(const Book& var)
	{
		this->Publication::operator=(var);
		if (auth != nullptr)
			delete[] auth;
		auth = nullptr;
		if (var.auth != nullptr) {
			auth = new char[strlen(var.auth)+1];
			strcpy(auth, var.auth);
		}
		return *this;
	}

	char Book::type() const
	{
		return 'B';//type method Returns the character "B".
	}

	ostream& Book::write(ostream& os) const
	{
		Publication::write(os);
		if (conIO(os)) {
			os << " ";
			string str = auth;
			if (strlen(auth) > SDDS_AUTHOR_WIDTH) {
				os << str.substr(0, SDDS_AUTHOR_WIDTH);
			}
			else {
				os <<left << setw(SDDS_AUTHOR_WIDTH) << auth;
			}
			os<< " |";
		}
		else {
			os << "\t" << auth;
		}
		return os;//returns the incoming ostream.
	}

	istream& Book::read(istream& is)//Read the author name in local variables before setting the attribute to any value.
	{
		Publication::read(is);
		if (auth != nullptr)
			delete[] auth;
		auth = nullptr;
		char author[257];
		if (conIO(is)) {
			is.ignore();
			cout << "Author: ";
			is.getline(author,250);
		}
		else {
			is.ignore();
			is.get(author,250,'\n');
		}

		if (!is.fail()) {
			auth = new char[strlen(author)+1];
			strcpy(auth, author);
		}
		return is;
	}

	void Book::set(int member_id)
	{
		Publication::set(member_id);//invoke the set of the base class to set the member id
		resetDate();//reset the date to the current date.
	}

	Book::operator bool() const //return true if the author's name exists and is not empty and the base class's operator bool() has returned true.
	{
		return (this->Publication::operator bool()  && auth !=nullptr );
	}

	Book::~Book()
	{
		if(auth!=nullptr) {
			delete[] auth;
		}
	}
}
