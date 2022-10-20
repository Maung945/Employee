// Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c
// gcc employeeMain.c employeeTable.c employeeTwo.c
#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void) {
    // defined in employeeSearchOne.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);
    PtrToEmployee searchEmployeeByPhoneNumber(const Employee table[], int sizeTable, char *phoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

    // defined in employeeTable.c
    extern Employee EmployeeTable[];                        // Defined somewhere else
    extern const int EmployeeTableEntries;                  // This is also defined somewhere else

    PtrToEmployee matchPtr;                                 // Declaration

    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 4011);
    // Example not found
    if (matchPtr != NULL)
        printf("Employee ID 1045 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID is NOT found in the record\n");

    // Example foundsearchEmployeeByName
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");

    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "213-555-1212");
    if(matchPtr != NULL)
        printf("Employee 213-555-1212 is in record %ld\n", matchPtr - EmployeeTable);
    else 
        printf("Employee 213-555-1212 is NOT found in the record\n");

    // Example foundsearchEmployeeBySalary
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, (double)6.34);
    if (matchPtr != NULL)
        printf("Employee 6.34 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee 6.34 is NOT found in the record\n");

        
    return EXIT_SUCCESS;                                    // This is required becaue int main(void)
}