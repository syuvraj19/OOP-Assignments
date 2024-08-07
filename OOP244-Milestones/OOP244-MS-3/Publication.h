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
#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H
#include"Date.h"
#include"Lib.h"

namespace sdds {
  class Publication {
      
    char * m_title {};
      
    char m_shelfId[SDDS_SHELF_ID_LEN + 1] {};
      
    int m_membership = 0;
      
    int m_libRef = -1;
      
    Date m_date;
      
    void extractChar(std::istream & istr, char ch) const;
      
    void set(const char * title,
        const char * shelfId, int membership, int libRef, Date date);
      
    public:
      Publication();
    
    virtual void set(int member_id);
    
    void setRef(int value);
      
    void resetDate();
    
    virtual char type() const;
    
    bool onLoan() const;
    
    Date checkoutDate() const;
    
    bool operator == (const char * title) const;

      operator const char * () const;
  
  int getRef() const;
      
  bool conIO(std::ios & io) const;
      
  std::ostream & write(std::ostream & os) const;
      
  std::istream & read(std::istream & istr);
      
  operator bool() const;
  
  Publication(const Publication & val);
      
  Publication & operator = (const Publication & val);
      
  ~Publication();
};
std::ostream & operator << (std::ostream & os,const Publication & piece);

std::istream & operator >> (std::istream & is, Publication & piece);
}
#endif
