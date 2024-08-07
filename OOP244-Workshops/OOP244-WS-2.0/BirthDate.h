/*Name          : Yuvraj singh
  Student Number: 155580210
  Student Email : yuvraj-singh5@myseneca.ca
  Section       : OOP244-ZBB
  Date completed: 30th may 2022
 
  I have done all the coding by myself and only copied the code
  that my professor provided to complete my workshops and assignments.*/


#ifndef SDDS_BIRTHDATE_H_
#define SDDS_BIRTHDATE_H_
#define ARY_LEN 30

namespace sdds {

    struct Date {
        int month;
        int day;
        int year;
    };

    struct Employee {
        char* staff_Name;
        Date staff_DOB;
    };

    bool readBirthDate(int month);

    void displayBirthdays();

    bool beginSearch(const char* filename);

    void assignval(Employee* employee, int month, int matches);

    void sort();

    void endSearch();

    void deallocate();
}
#endif
