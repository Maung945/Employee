#include <stdio.h>
#include <stddef.h>

typedef struct{                              // Patting
    long number;                             // 4 byyes
    char *name;                              // 4 Bytes
    char *phone;
    double salary;                           // 8 Bytes
} Employee, *PtrToEmployee;

typedef const Employee *PtrToConstEmployee;  // Using differentname to define something