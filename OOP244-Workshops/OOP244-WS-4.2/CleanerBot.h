/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Section    : OOP-244-ZBB

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef CLEANERBOT_H
#define CLEANERBOT_H

class CleanerBot {
private:
    char* location;
    
    int brush;
    
    double battery;
    
    bool active;

public:
    CleanerBot();
    
    ~CleanerBot();

    void setLocation(char*);
    
    CleanerBot(const char*, double, int, bool);
    
    void set(const char*, double, int, bool);
    
    char* getLocation();
    
    double getBattery();
    
    void setActive(bool);
    
    bool isActive();
    
    int getBrush();
    
    void display();
    
    bool isValid();
};

namespace sdds
{
    int report(CleanerBot*, short);
}

#endif
