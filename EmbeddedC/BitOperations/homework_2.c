/*
HOMEWORK NO.2
to build compile homework_2.c with CalcDecBase4.c
@author Michał Kowalczuk
@version 2017-05-26
*/

#include <stdio.h>
#include <stdlib.h>
#include "CalcDecBase4.h"

int main() {
    // Choose math operation
    char operation;
    do {
        printf("Choose arithmetic operation: +, - or n to exit. Type here: ");
        scanf("%c",&operation);
        if (operation == 'n') {return 0;}
    } while(operation != '+' && operation != '-');

    int result;
    char resultString[100];
    int resultStringId = 0;
    int decNumbers;
    char base4CharArr[WIDTH + 1]; // the end of array reserved for '\0'
    // get input from user
    for (int i = 0; i < DIGITS_NO ; i++) {
        do {
            printf("Enter %d. base-%d number (max 2 digits): ", i + 1, BASE);
            scanf("%s", base4CharArr);
        } while(!isCorrectNumber(base4CharArr, WIDTH));

        // append resultString
        for (int j = 0; j < WIDTH; j++) {
            resultString[resultStringId++] = base4CharArr[j];
        }
        resultString[resultStringId++] = ' ';
        if (i != DIGITS_NO - 1) {
            resultString[resultStringId++] = operation;
        }
        resultString[resultStringId++] = ' ';

        // convert to decimal
        int *base4IntArr = base4CharToInt(base4CharArr, WIDTH);
        decNumbers = base4ToDec(base4IntArr, WIDTH);

        // and make some math on decimals
        if (i == 0) {
            result = decNumbers;
        } else {
            switch (operation) {
                case '+':
                    result += decNumbers;
                    break;
                case '-':
                    result -= decNumbers;
                    break;
            }
        }
        free(base4IntArr);  // free memory
    }

    if (result >= 0) {
        // array size for result
        int arraySize = calcArraySize(result);

        // convert from decimal to base4
        int *resultArr = decToBase4(result, arraySize);

        // append resultString
        resultString[resultStringId++] = '=';
        resultString[resultStringId++] = ' ';
        for (int i = 0; i < arraySize; i++) {
            resultString[resultStringId++] = resultArr[i] + '0';
        }
        resultString[resultStringId++] = '\0';

        // print result
        printf("-----------------------------------------\n");
        printf("Your equation in %d-base system is:\n", BASE);
        printf("%s\n", resultString);

        free(resultArr); // free memory

    } else {printf("Negative values are not supported yet!\n");}

    return 0;
}
