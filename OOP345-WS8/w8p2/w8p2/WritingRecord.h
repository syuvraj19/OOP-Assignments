

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
