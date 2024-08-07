/*
*****************************************************************************
                          Workshop - #6 (P1)
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Section    : OOP-244-ZBB

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
#include "Numbers.h"  // intentional

using namespace std;
namespace sdds {

    Numbers::Numbers() {
        setEmpty();
        m_isOriginal = false;
    }

    Numbers::Numbers(const char* filename) {
        setEmpty();
        m_isOriginal = true;
        setFilename(filename);
        m_numCount = numberCount();
        if (m_numCount == 0 || !load()) {
            delete[] m_numbers;
            delete[] m_filename;
            setEmpty();
            m_isOriginal = false;
        }
        else {
            sort();
        }
    }
    Numbers::Numbers(const Numbers& n)
    {
        setEmpty();
        m_isOriginal = false;

        *this = n;
    }

    Numbers::~Numbers() {
        save();
        delete[] m_numbers;
        delete[] m_filename;
    }

    bool Numbers::isEmpty() const {
        return m_numbers == nullptr;
    }

    void Numbers::setEmpty() {
        m_numbers = nullptr;
        m_filename = nullptr;
        m_numCount = 0;
    }
    void Numbers::setFilename(const char* filename) {
        
        delete[] m_filename; //Frees the memory pointed by m_filename pointer

        m_filename = new char[strlen(filename) + 1]; //Allocates memory to hold the data file name as a Cstring.
        
        strcpy(m_filename, filename); //Copies the data file name to the newly allocated memory.

    }
    void Numbers::sort() { //Sorts the double values in ascending order
        int i, j;
        double temp;
        for (i = m_numCount - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (m_numbers[j] > m_numbers[j + 1]) {
                    temp = m_numbers[j];
                    m_numbers[j] = m_numbers[j + 1];
                    m_numbers[j + 1] = temp;
                }
            }
        }
    }

    double Numbers::average() const { //Returns the average of the double numbers in the list.
        
        double aver = 0.0;
        if (!isEmpty()) {
            for (int i = 0; i < m_numCount; i++)
                aver += m_numbers[i];
            aver = aver / m_numCount;
        }
        return aver;
    }
    double Numbers::min() const { //Returns the smallest double number in the list
        
        double minVal = 0.0;
        if (!isEmpty()) {
            minVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (minVal > m_numbers[i]) minVal = m_numbers[i];
        }
        return minVal;
    }

    double Numbers::max() const { //Returns the largest double number in the list
        
        double maxVal = 0.0;
        if (!isEmpty()) {
            maxVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
        }
        return maxVal;
    }

    Numbers& Numbers::operator=(const Numbers& p)
    {
        delete[] this->m_numbers;
        this->m_numbers = new double[p.m_numCount];
        int x = 0;
        while (x < p.m_numCount) {
            this->m_numbers[x] = p.m_numbers[x];
            x++;
        }
        this->m_numCount = p.m_numCount;
        setFilename(p.m_filename);
        return *this;
    }

    int Numbers::numberCount()
    {
        ifstream inFile(this->m_filename); //Create an instance of ifstream to open the data file name.
        int counterlines = 0;

        if (inFile.is_open()) {
            double i = 0;

            while (inFile >> i) { //While the ifstream object has not failed keep reading single characters from the file.
                counterlines = counterlines + 1;
            }
        }
        return counterlines; //Return the number of counted newlines when all characters in the file are scanned.
    }

    void Numbers::save()
    {
        if (this->m_isOriginal && !this->isEmpty()) {
            ofstream outFile("numbers.txt"); //Create an instance of ofstream to overwrite the dat afile
            int x = 0;
            while (x < m_numCount) {
                outFile << m_numbers[x] << endl; // Write all the elements of the m_numbers array using the ofstream object.

                x++;
            }
        }
    }

    Numbers& Numbers::operator+=(double value)
    {
        if (!this->isEmpty()) {
            double* temp = new double[m_numCount + 1];
            int a = 0;
            while (a < m_numCount) {
                temp[a] = m_numbers[a];
                a++;
            }
            m_numCount = m_numCount + 1;
            temp[m_numCount - 1] = value;
            delete[] m_numbers; //delete the original allocated memory
            m_numbers = temp;
            sort();
        }
    return (*this);
    }

    bool Numbers::load() //return true if the number of read doubles, is equal to the m_numCount member variable.
    {
        if (m_numCount > 0) {
            this->m_numbers = new double[m_numCount];

            ifstream inFile(this->m_filename);

            double x = 0;
            int cnt = 0;

            if (inFile.is_open()) {
                while (inFile >> x) {

                    m_numbers[cnt] = x;
                    cnt = cnt + 1;
                }
            }return (m_numCount == cnt);
        }return false;
    }

    ostream& Numbers::display(ostream& ostr) const
    {

        if (this->isEmpty()) {
            ostr << "Empty list";
        }
        else {
            ostr << "=========================" << endl;
            if (!m_isOriginal) {
                ostr << "*** COPY ***" << endl;
            }
            else {
                ostr << this->m_filename << endl;
            }
            int x = 0;
            while (x < m_numCount) {
                ostr << m_numbers[x];

                if (x != m_numCount - 1) {
                    ostr << ", ";
                }
                x++;
            }
            ostr << endl;
            ostr << "-------------------------" << endl;
            ostr << "Total of " << m_numCount << " number(s)" << endl;
            ostr << "Largest number:  " << this->max() << endl;
            ostr << "Smallest number: " << this->min() << endl;
            ostr << "Average :        " << this->average() << endl;
            ostr << "=========================";

        }
        return ostr;
    }

    istream& operator>>(istream& istr, Numbers& N)
    {
        double x = 0;
        
        istr >> x; //read a double value using istr

        N += x;//add the double value to N using += operator
        
        return istr;
    }

    ostream& operator<<(ostream& os, const Numbers& N)
    {
        return N.display(os); //call the display fucntion of N and return it

    }

   
}
