/*
@author Michał Kowalczuk
@version 2017-05-19
*/
#ifndef CALCDECBASE4
#define CALCDECBASE4

#define BASE 4
#define WIDTH 2
#define DIGITS_NO 2

int calcArraySize(int number);
void printArray(int *array, int arraySize);
int* decToBase4(int number, int arraySize);
int base4ToDec(int* array, int arraySize);
int* base4CharToInt(char* charArr, int arraySize);
int isCorrectNumber(char* number, int arraySize);

#endif
