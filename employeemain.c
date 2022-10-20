// Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c
// gcc employeeMain.c employeeTable.c employeeTwo.c
#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void) {
    // defined in employeeSearchOne.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);

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

    // Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");
        
    return EXIT_SUCCESS;                                    // This is required becaue int main(void)
}