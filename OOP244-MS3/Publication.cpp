/***********************************************************************
 CLASS : OOP244
 SECTION : ZBB
 NAME          : Yuvraj Singh
 EMAIL         : yuvraj-singh5@myseneca.ca
 STUDENT ID    : 155580210
DATE CREATED ON : 29 JULY 2022
MILESTONE 3

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
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
  void Publication::extractChar(std::istream & istr, char ch) const {
    // First, it will peek and see if the next character in the keyboard buffer is the same as the ch argument
    // If yes, it will read and remove it from the keyboard. (it throws it away!)
  if (istr.peek() == ch) {
    istr.get();
  } else {
    // If not, it will set the istream into a fail state.
    istr.setstate(ios::failbit);
  }
}
// Modifiers
void Publication::set(int member_id) {
  m_membership = member_id > 9999 && member_id <= 99999 ? member_id : 0;
}
// Sets the membership attribute to either zero or a five-digit integer.
void Publication::setRef(int value) {
  m_libRef = value;
}
// Sets the **libRef** attribute value
void Publication::resetDate() {
  m_date.setToToday();
}
// Sets the date to the current date of the system.
char Publication::type() const {
  return 'P';
}
//Returns the character 'P' to identify this object as a "Publication object"
bool Publication::onLoan() const {
  return m_membership != 0;
}
//Returns true is the publication is checkout (membership is non-zero)
Date Publication::checkoutDate() const {
    
  return m_date;
}
//Returns the date attribute
bool Publication::operator == (const char * title) const {
    if (strstr(m_title, title) != NULL) {
      return true;
    }
    return false;
  }
  //Returns true if the argument title appears anywhere in the title of the
  //publication. Otherwise, it returns false; (use strstr() function in < cstring > )
Publication::operator const char * () const {
  return m_title;
}
//Returns the title attribute
int Publication::getRef() const {
  return m_libRef;
}
//Returns the libRef attirbute.
bool Publication::conIO(ios & ios) const {
  // This method is not capable of modifying the Streamable object. conIo receives a reference of an ios object and returns a Boolean.
  // Functions overriding this function will determine if the incoming ios object is a console IO object or not.
  return & ios == & cin || & ios == & cout;
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
    // P 2001 P001 The Toronto Star 34037 2021/11/17
  }
  return os;
}
istream & Publication::read(istream & istr) {
  // First, clear all the attributes by freeing the memory
  // and setting everything to their default values.
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
    // Otherwise, assume reading begins with libRef attribute as if the type 'P' is not in the file.
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
// HELPER
ostream & operator << (ostream & os,
  const Publication & obj) {
  obj.write(os);
  return os;
}
istream & operator >> (istream & is, Publication & obj) {
  obj.read(is);
  return is;
}
// RULE OF THREE : Copy Constructor, User Defined Copy Assignment Operator,Destructor
Publication::Publication(const Publication & pub) {
  if (pub.operator bool())
  {
    this -> set(pub.m_title, pub.m_shelfId, pub.m_membership,pub.m_libRef, pub.m_date);
  }
}
Publication & Publication::operator = (const Publication & pub) {
  if (this != & pub) {
    this -> set(pub.m_title, pub.m_shelfId, pub.m_membership,
      pub.m_libRef, pub.m_date);
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
  } else {
    m_shelfId[0] = ' ';
    m_membership = 0;
    m_libRef = -1;
    m_date.setToToday();
  }
}
}
