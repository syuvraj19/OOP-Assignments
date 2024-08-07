/*
*****************************************************************************
                              milestone - 3
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Section    : OOP-244-ZBB
Date       : 29/07/2022

Authenticity Declaration:
 I have done all the coding by myself and only copied the code that my professor
 provided to complete my project milestones.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include <string>
#include <cstring>
#include"Publication.h"
#include"Streamable.h"
#include"Lib.h"
#include"Date.h"

using namespace std;
namespace sdds {

  void Publication::extractChar(std::istream & istr, char chr) const {
    
  if (istr.peek() == chr) {
      
    istr.get();
      
  } else {
  
    istr.setstate(ios::failbit);
  }
}

void Publication::set(int member_id) {
    
  m_membership = member_id > 9999 && member_id <= 99999 ? member_id : 0;
}

void Publication::setRef(int ref) {
    
  m_libRef = ref;
    
}

char Publication::type() const {
    
  return 'P';
}

void Publication::resetDate() {
    
  m_date.setToToday();
    
}

bool Publication::onLoan() const {
    
  return m_membership != 0;
}

Date Publication::checkoutDate() const {
    
  return m_date;
}

bool Publication::operator == (const char * title) const {
    
    if (strstr(m_title, title) != NULL) {
        
      return true;
    }
    
    return false;
    
  }

Publication::operator const char * () const {
    
  return m_title;
}



bool Publication::conIO(ios & ios) const {

  return & ios == & cin || & ios == & cout;
    
}

int Publication::getRef() const {
    
  return m_libRef;
}

ostream & Publication::write(ostream & os) const {
    
  if (conIO(os)) {
      
    if (bool( * this)) {
        
      os << "| " <<
        setw(SDDS_SHELF_ID_LEN) << left << setfill(' ') <<
        m_shelfId <<
        " | " <<
        setw(SDDS_TITLE_WIDTH) << left << setfill('.') <<
        m_title <<
        " | ";
        
      m_membership == 0 ? os << " N/A " : os << m_membership;
   
        if(m_membership == 0)
        {
            os << " | " <<  m_date <<  " |";
        }
        else
        {
            os << " | " <<  m_date <<  " |";
        }
    }
  } else {
      
    if (bool( * this)) {
        
      os << type() << "\t" <<
        m_libRef << "\t" <<
        m_shelfId << "\t" <<
        m_title << "\t" <<
        m_membership << "\t" <<
        m_date;
    }
  }
    
  return os;
}
istream & Publication::read(istream & istr) {

  if (m_title != nullptr)
    delete[] m_title;
    
  m_title = nullptr;
    
  m_shelfId[0] = ' ';
    
  m_membership = 0;
    
  m_libRef = -1;
    
  m_date.setToToday();
    
  char * title = nullptr;
    
  title = new char[SDDS_TITLE_WIDTH + 1];
    
  char shelfId[SDDS_SHELF_ID_LEN + 1] {};
    
  int membership = 0;
    
  int libRef = -1;
    
  Date date;
    
  if (conIO(istr)) {
      
    cout << "Shelf No: ";
      
    istr.getline(shelfId, SDDS_SHELF_ID_LEN + 1, '\n');
      
    if (strlen(shelfId) != SDDS_SHELF_ID_LEN) {
        
      istr.setstate(ios::failbit);
        
    }
    cout << "Title: ";
      
    istr.getline(title, SDDS_TITLE_WIDTH + 1, '\n');
      
    cout << "Date: ";
      
    istr >> date;
      
    if (date.bad()) {
      istr.setstate(ios::failbit);
    }
      
  } else {
    istr >> libRef;
      
    extractChar(istr, '\t');
      
    istr >> shelfId;
      
    extractChar(istr, '\t');
      
    if (shelfId[0] == ' ') {
        
      istr.setstate(ios::failbit);
    }
      
    istr.getline(title, SDDS_TITLE_WIDTH + 1, '\t');
      
    if (title == nullptr || title[0] == ' ') {
        
      istr.setstate(ios::failbit);
        
    }
      
    if (istr.good()) {
        
      istr >> membership;
        
      istr >> date;
    }
  }
    
  if (istr.rdstate() == 0) {
      
    m_title = new char[strlen(title) + 1];
      
    strcpy(m_title, title);
      
    strcpy(m_shelfId, shelfId);
      
    m_membership = membership;
      
    m_date = date;
      
    m_libRef = libRef;
  }
    
  delete[] title;
  return istr;
}

Publication::Publication() {
    
  m_title = nullptr;
    
  m_shelfId[0] = ' ';
    
  m_membership = 0;
    
  m_libRef = -1;
    
  m_date.setToToday();
}

Publication::operator bool() const {
    
  return m_title != nullptr || m_shelfId[0] != ' ';
    
}

ostream & operator << (ostream & os,
  const Publication & piece) {
    
  piece.write(os);
    
  return os;
}

istream & operator >> (istream & is, Publication & piece) {
    
    piece.read(is);
    
  return is;
}

Publication::Publication(const Publication & prnt) {
    
  if (prnt.operator bool())
  {
    this -> set(prnt.m_title, prnt.m_shelfId, prnt.m_membership,prnt.m_libRef, prnt.m_date);
  }
}

Publication & Publication::operator = (const Publication & prnt) {
    
  if (this != & prnt) {
      
    this -> set(prnt.m_title, prnt.m_shelfId, prnt.m_membership,
                prnt.m_libRef, prnt.m_date);
  }
    
  return ( * this);
    
}

Publication::~Publication() {
    
  delete[] m_title;
}

void Publication::set(const char * title,
  const char * shelfId, int membership,
    int libRef, Date date) {
    
  if (m_title != nullptr)
      
    delete[] m_title;
    
  m_title = nullptr;
    
  if (title != nullptr) {
      
    m_title = new char[strlen(title) + 1];
      
    strcpy(m_title, title);
      
    strcpy(m_shelfId, shelfId);
      
    m_membership = membership;
      
    m_libRef = libRef;
      
    m_date = date;
      
  }
    
  else {
      
    m_shelfId[0] = ' ';
      
    m_membership = 0;
      
    m_libRef = -1;
      
    m_date.setToToday();
  }
}
}

