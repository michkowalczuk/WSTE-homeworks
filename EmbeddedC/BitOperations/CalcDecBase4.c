/*
Decimal to n-base system and backawrds calculator
works for every base >= 2

@author Michał Kowalczuk
@version 2017-05-26
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "CalcDecBase4.h"

int calcArraySize(int number) {
    return number != 0 ? (int)(log(number) / log(BASE)) + 1 : 1;
}

void printArray(int *array, int arraySize) {
    printf("In base-%d system: ", BASE);
    for (int i = 0; i < arraySize; i++) {
        printf("%d",*(array + i));
    }
    printf("\n");
}

int* decToBase4(int number, int arraySize) {
    // dynamic allocate memory
    // we don't need reallocate because we calculate exact array size above
    int *array;
    array = (int*)malloc(sizeof(int) * arraySize);
    if(array == NULL) return NULL; // check if memory is successfully allocated
    int modulo;
    int i = arraySize - 1; // iterate from the end of array
    do{
        modulo = number % BASE;
        number = number / BASE;
        *(array + i) = modulo;
        i--; // decrement index, because we go down from the end of array
    } while(number != 0);
    return array;
}

int base4ToDec(int* array, int arraySize) {
    int decimal = 0;
    for (int i = 0; i < arraySize; i++) {
        decimal += *(array + i) * pow(BASE, arraySize - i - 1);
    }
    return decimal;
}

// convert char array to int array
int* base4CharToInt(char* charArr, int arraySize) {
    int *intArr = (int*)malloc(sizeof(int) * arraySize);
    for (int i = 0; i < arraySize; i++) {
        intArr[i] = (int)(charArr[i] - '0');
    }
    return intArr;
}

// check if input number has correct format
int isCorrectNumber(char* number, int arraySize) {
    int out = 1;
    if (strlen(number) == WIDTH) {
        for (int i = 0; i < arraySize; i++) {
            if (!isdigit(number[i])) {
                printf("Error: Input is not a digit!\n");
                out = 0;
                break;
            }
            if (!((int)(number[i] - '0') < BASE)) {
                printf("Error: Max value for digit in %d-base system is %d!\n", BASE, BASE-1);
                out = 0;
                break;
            }
        }
    } else {
        printf("Error: Only %d digits allowed!\n", WIDTH);
        out = 0;
    }
    return out;
}
