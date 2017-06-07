/*
HOMEWORK NO.1
to build compile homework_1.c with CalcDecBase4.c
@author Michał Kowalczuk
@version 2017-05-26
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "CalcDecBase4.h"

int main() {
    int number = 125346;
    printf("Input decimal number: %d\n", number);
    // use some math to calculate size of array
    int arraySize = calcArraySize(number);

    // convert from decimal to base4
    int *array = decToBase4(number, arraySize);
    // print it
    printArray(array, arraySize);

    // convert from base4 to decimal
    int convertedNumber = base4ToDec(array, arraySize);
    // print it
    printf("Converted from base %d system to decimal: %d\n", BASE, convertedNumber);

    // free memory
    free(array);
}
