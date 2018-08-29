#include "stdio.h"
#include "limits.h"
#include "float.h"

int main() {
    int intVar;
    float fVar;
    double dVar;

    intVar = INT_MAX;
    fVar = FLT_MAX;
    dVar = DBL_MAX;

    printf("Size of int - %lu, value of int - %d\nSize of float - %lu, value of float - %f\nSize of double - %lu, value of double - %f.", sizeof(intVar), intVar, sizeof(fVar), fVar, sizeof(dVar), dVar);
    return 0;
}  
