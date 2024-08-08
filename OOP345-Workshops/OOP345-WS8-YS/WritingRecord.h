/*
*****************************************************************************
                          Workshop - #8(P2)
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Date       : 20/11/2022
 
*****************************************************************************
*/

#ifndef SDDS_WRITINGRECORD_H
#define SDDS_WRITINGRECORD_H

#include <string>
#include <algorithm>
#include <iterator>
#include "GeneratingList.h"
#include "EmpProfile.h"

namespace sdds {
    GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal);
    GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal);
}


#endif // SDDS_WRITINGRECORD_H
