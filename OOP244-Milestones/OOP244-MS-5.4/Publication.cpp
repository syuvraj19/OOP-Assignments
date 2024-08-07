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
#include"Publication.h"
#include <ios>
#include<iomanip>
#include<cstring>
#include<string.h>

namespace sdds {
	Publication::Publication():m_date(){
		m_title = nullptr;
		m_shelfId[0] ='\0';
		m_membership = 0;
		m_libRef = -1;
	
	}
	Publication::Publication(const Publication& var) {
		if (var.m_title != nullptr) {
			m_title = new char[strlen(var.m_title) + 1];
			strcpy(m_title, var.m_title);
		}
		else
			m_title = nullptr;
		strcpy(m_shelfId, var.m_shelfId);
		m_membership = var.m_membership;
		m_date = var.m_date;
		m_libRef = var.m_libRef;
	}
	Publication& Publication::operator=(const Publication& var)
	{
		if (m_title != nullptr) {
			delete[] m_title;
		}
		if (var.m_title != nullptr) {
			m_title = new char[strlen(var.m_title) + 1];
			strcpy(m_title, var.m_title);
		}
		else
		m_title = nullptr;
		strcpy(m_shelfId, var.m_shelfId);
		m_membership = var.m_membership;
		m_date = var.m_date;
		m_libRef = var.m_libRef;
		return *this;
	}
	void Publication::set(int member_id){
		m_membership = member_id;
	}
	void Publication::setRef(int value)
	{
		m_libRef = value;
	}
	void Publication::resetDate(){
		m_date.setToToday();
	}
	char Publication::type() const
	{
		return 'P';
	}
	bool Publication::onLoan() const
	{
		return m_membership != 0;
		
	}
	Date Publication::checkoutDate() const
	{
		return m_date;
	}
	bool Publication::operator==(const char* title) const
	{
		return strstr(m_title,title)!=nullptr;
	}
	Publication::operator const char* () const
	{
		if (m_title != nullptr)
			return m_title;
		else
			return "";
	}
	int Publication::getRef() const
	{
		return m_libRef;
	}
	bool Publication::conIO(ios& io) const//Returns true if the address of the io object is the same as the address of either the cin object or the cout object
	{
		return (&io==&cin || &io==&cout);
	}
	std::ostream& Publication::write(std::ostream& os) const//If the os argument is a console IO object (use conIO()), print shelfId, title, membership and date attributes as the following format.
	{
		if (conIO(os)) {
			os << "| " << m_shelfId << " | ";
			string str =m_title;
			if (strlen(m_title) >SDDS_TITLE_WIDTH) {
				os << str.substr(0, SDDS_TITLE_WIDTH);
			}
			else {
				os << setw(30) << setfill('.') << left << m_title;
			}

			os<< right << " | ";
			
			if(m_membership!=0){
				os << m_membership;
			}
			else {
				os << " N/A ";
			}
			os << " | " << m_date<< " |";
		}
		else {
			os << type()<<'\t' <<m_libRef<< '\t'<<m_shelfId << '\t'
				<<m_title << '\t' << m_membership << '\t' << m_date;
		}
		return os;
		// // O: insert return statement here
	}
	std::istream& Publication::read(std::istream& istr)//Read all the values in local variables before setting the attributes to any values.
	{
		if(m_title!=nullptr)
		delete[] m_title;
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		m_date.setToToday();
		
		char title[100],shelfIdNum[100];
		Date date;
		int librefNum=-1,membershipNum=0;
		if (conIO(istr)) {
		cout<<"Shelf No: ";
		istr >> shelfIdNum;
		if (strlen(shelfIdNum) != SDDS_SHELF_ID_LEN) {
			istr.setstate(std::ios::failbit);
			cout << "Title: ";
			cout << "Date: ";
		}
		else {
		cout<<"Title: ";
		istr.clear();
		istr.ignore(1000, '\n');
		istr.getline(title,100,'\n');
		cout << "Date: ";
		date.read(istr);
		}			
		}
		else {
			istr >> librefNum;
			istr.ignore();
			istr >> shelfIdNum;
			istr.ignore();
			istr.getline(title,100, '\t');
			istr >> membershipNum;
			istr.ignore();
			date.read(istr);
		}
		if (date.errCode() != 0) {
			istr.setstate(std::ios::failbit);
		}
		if (!istr.fail()) {
			m_title = new char[strlen(title)+1];
			strcpy(m_title, title);
			strcpy(m_shelfId, shelfIdNum);
			m_membership = membershipNum;
			m_date = date;
			m_libRef = librefNum;
		}
		return istr;
	}
	Publication::operator bool() const{
		return (m_title!=nullptr &&m_shelfId[0]!='\0');
	}

	Publication::~Publication()
	{
		if (m_title != nullptr) {
			delete[] m_title;
		}
	}


	std::ostream& operator<<(std::ostream& os, const Publication& pub)
	{
		if((bool)pub)
		return pub.write(os);
		else {
			return os;
		}

	}

	std::istream& operator>>(std::istream& is, Publication& pub)
	{
		return pub.read(is);
}

}
