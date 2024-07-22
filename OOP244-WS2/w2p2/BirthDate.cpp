/***********************************************************************
 NAME : Yuvraj Singh
 CLASS : OOP244
 SECTION : ZBB
 STUDENT NUMBER : 155580210
 EMAIL : yuvraj-singh5@myseneca.ca
DATE CREATED ON : 29 MAY 2022

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
* *********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstdio>
#include<cstring>
namespace sdds {
    int noOfEmployees;
    struct Employee* employees;
    int search_month = -1;


    struct Employee {
        char* m_name;
        int dob_day;
        int dob_month;
        int dob_year;
    };


    //load function starts here 
    bool beginSearch(const char filename[]) {
        FILE* fptr;
        fptr = fopen(filename, "r");
        bool isOpened = fptr != NULL;


        //if file not opened , then return 
        if (!isOpened) {
            std::cout << "Data file " << filename << " not found\n";
            return false;
        }
        //calling noOfRecords
        noOfEmployees = 0;
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        noOfEmployees = noOfRecs;

        // Dynamically creating array of employees
        employees = new Employee[noOfEmployees];

        // Closed file 
        if (fptr) fclose(fptr);

        // open file
        fptr = fopen(filename, "r");
        for (int i = 0; i < noOfEmployees; i++)
        {
            struct Employee temp;
            char emp_name[1000];
            int emp_dob_day;
            int emp_dob_month;
            int emp_dob_year;
            fscanf(fptr, "%[^,],", emp_name);
            fscanf(fptr, "%d/", &emp_dob_month);
            fscanf(fptr, "%d/", &emp_dob_day);
            fscanf(fptr, "%d\n", &emp_dob_year);
            temp.dob_day = emp_dob_day;
            temp.dob_month = emp_dob_month;
            temp.dob_year = emp_dob_year;
            int len_of_name = std::strlen(emp_name);
            temp.m_name = new char[len_of_name + 1];
            std::strcpy(temp.m_name, emp_name);
            employees[i] = temp;
        }
        if (fptr) fclose(fptr);
        std::cout << "Birthdate search program\n";
        return true;
    }

    //bool readBirthDate(int month);
    bool readBirthDate(int month) {
        for (int i = 0; i < noOfEmployees; i++) {
            if (employees[i].dob_month == month) {
                search_month = month;
                return true;
            }
        }
        return false;
    }

    //void sort();
    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].dob_year > employees[j + 1].dob_year) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    //void displayBirthdays();
    void displayBirthdays() {
        int count = 0;

        for (int i = 0; i < noOfEmployees; i++)
        {
            if (search_month == employees[i].dob_month) {
                count++;
            }
        }
        std::cout << count << " birthdates found:\n";
        count = 0;

        for (int i = 0; i < noOfEmployees; i++) {
            if (search_month == employees[i].dob_month) {
                count++;
                std::cout << count << ") " << employees[i].m_name << ":\n";
                std::cout << employees[i].dob_year << "-" << employees[i].dob_month << "-" << employees[i].dob_day << "\n";
                std::cout << "===================================\n";
            }
        }
    }

    //void deallocate();
    void deallocate() {
        search_month = -1;
    }

    //void endSearch();

    void endSearch() {
        std::cout << "Birthdate Search Program Closed.\n";
        for (int i = 0; i < noOfEmployees; i++) {
            Employee temp = employees[i];
            delete[] temp.m_name;
        }
        delete[] employees;

    }
}
