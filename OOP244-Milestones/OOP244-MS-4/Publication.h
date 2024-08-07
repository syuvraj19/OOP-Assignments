/*
*****************************************************************************
                              milestone - 4
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Section    : OOP-244-ZBB
Date       : 5/08/2022

Authenticity Declaration:
 I have done all the coding by myself and only copied the code that my professor
 provided to complete my project milestones.
*****************************************************************************
*/

#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H

#include "Date.h"
#include "Streamable.h"
#include "Lib.h"

namespace sdds {
    class Publication : public Streamable {
    private:
        char* m_title;//m_title is a c-string to hold a dynamic title for the publication.

        char m_shelfId[SDDS_SHELF_ID_LEN + 1];//Hold the location of the publication in the library. m_shelfId is a c-string that is exactly 4 characters long.
    
        int m_membership;//This attribute is an integer to hold a 5 digit membership number of members of the library.
        
        int m_libRef;//This serial number is used internally to uniquely identify each publication in the system.
    
        Date m_date;
        
    public:
        Publication();//Sets all the attributes to their default values.
        
        ~Publication();//destructor

        Publication(const Publication& publication);
        Publication& operator=(const Publication& publication);

        void setDefault();
        virtual void set(int member_id);
           // Sets the membership attribute to either zero or a five-digit integer.
        void setRef(int value);
           // Sets the **libRef** attribute value
        void resetDate();
           // Sets the date to the current date of the system.
        virtual char type()const;
           //Returns the character 'P' to identify this object as a "Publication object"
        bool onLoan()const;
           //Returns true is the publication is checkout (membership is non-zero)
        Date checkoutDate()const;
           //Returns the date attribute
        bool operator==(const char* title)const;
           //Returns true if the argument title appears anywhere in the title of the
           //publication. Otherwise, it returns false; (use strstr() function in <cstring>)
        operator const char* ()const;
           //Returns the title attribute
        int getRef()const;
           //Returns the libRef attirbute.
        bool conIO(std::ios& io) const;//Returns true if the address of the io object is the same as the address of either the cin object or the cout object.
        
        std::ostream& write(std::ostream& os) const;//If the os argument is a console IO object (use conIO()), print shelfId, title, membership and date attributes as the following format (title is left-justified padded with dots)
        
        std::istream& read(std::istream& is);//Read all the values in local variables before setting the attributes to any values.

        operator bool() const;
    };
}

#endif //SDDS_PUBLICATION_H
