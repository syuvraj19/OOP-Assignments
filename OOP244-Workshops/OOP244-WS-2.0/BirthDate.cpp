/*Name          : Yuvraj singh
  Student Number: 155580210
  Student Email : yuvraj-singh5@myseneca.ca
  Section       : OOP244-ZBB
  Date completed: 30th may 2022
 
  I have done all the coding by myself and only copied the code
  that my professor provided to complete my workshops and assignments.*/

#include "BirthDate.h"
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

namespace sdds {
    FILE* fp;

    Employee* employees;
    int empnos;
    int matches = 0;

    int noOfRecords() {
        int recnos = 0;
        char chaar;
        while (fscanf(fp, "%c", &chaar) == 1) {
            recnos += (chaar == '\n');
        }
        rewind(fp);
        return recnos;
    }

    bool readBirthDate(int month) {
        bool result;
        empnos = noOfRecords();

        char arr_tmp[ARY_LEN];
        int din, mah, saal,x = 0;
        while( x < empnos){
            if (fscanf(fp, "%[^,],%d/%d/%d\n", arr_tmp, &mah, &din, &saal) == 4) {
                if (mah == month) {
                    matches++;
                }x++;
            }
        }
        assignval(employees, month, matches);

        if (matches > 0) {
            result = true;
        }
        else {
            result = false;
        }

        return result;
    }

    void displayBirthdays() {
        cout << matches << " birthdates found:" << endl;
        int x = 0;
        while( x < matches) {
            cout << x + 1 << ") " << employees[x].staff_Name << ":" << endl;
            cout << employees[x].staff_DOB.year << "-" << employees[x].staff_DOB.month << "-"
                 << employees[x].staff_DOB.day << endl;
            cout << "===================================" << endl;
            x++;
        }
    }

    bool beginSearch(const char* filename) {
        bool result;
        fp = fopen(filename, "r");

        if (fp != nullptr) {
            cout << "Birthdate search program" << endl;
            result = true;
        }
        else {
            cout << "Data file \"" << filename << "\" not found!" << endl;
            result = false;
        }
        return result;
    }

    void assignval(Employee* employee, int month, int matches) {
        char arr_tmp[ARY_LEN];
        int din, mah, saal;
        employees = new Employee[matches];
        rewind(fp);
        int x = 0, matchedRecs = 0;
        while( x < empnos) {
            if ((fscanf(fp, "%[^,],%d/%d/%d\n", arr_tmp, &mah, &din, &saal) == 4) && (mah == month)) {
                employees[matchedRecs].staff_DOB.day = din;
                employees[matchedRecs].staff_DOB.month = mah;
                employees[matchedRecs].staff_DOB.year = saal;
                employees[matchedRecs].staff_Name = new char[strlen(arr_tmp) + 1];
                strcpy(employees[matchedRecs].staff_Name, arr_tmp);

                matchedRecs++;
            }x++;
        }
    }

    void sort() {
        int k= matches - 1, j;
        Employee x;

        while( k > 0) {
            j = 0;
            while(j < k) {
                if (employees[j].staff_DOB.year > employees[j + 1].staff_DOB.year) {
                    x = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = x;
                }j++;
            } k--;
        }
    }

    void endSearch() {
        
        if (fp) fclose(fp);
        cout << "Birthdate Search Program Closed." << endl;
    }

    void deallocate() {
        int x = 0;
        while( x < matches) {
            delete[] employees[x].staff_Name;
            x++;
        }
        delete[] employees;
    }

}
