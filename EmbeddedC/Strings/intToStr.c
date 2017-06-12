/*
STRINGS - HOMEWORK NO.1
function intToStr
@author Michał Kowalczuk
@version 2017-06-11
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// counts size for char  array (string)
int getSize(int number)
{
    int size = number != 0 ? size = (int)(log(abs(number)) / log(10)) + 1 : 1;
    if (number < 0)
        size++;
    return size;
}

// converts int to char array (string)
void intToStr(int number, char* string, int size)
{
    int temp;
    int decPosition;
    if (number < 0)
    {
        *string++ = '-';
        number *= -1;
        size--;
    }
    for (int i = size - 1; i >= 0; i--)
    {
        decPosition = round(pow(10, i));
        temp = number / decPosition;
        number -= temp * decPosition;
        *string++ = temp + '0';
    }
    *string++ = '\0';
}

int main()
{
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);
    int size = getSize(number);
    char *string = malloc(sizeof(int) * size);
    intToStr(number, string, size);
    printf("Converted to string: %s\n", string);
    free(string);
}
