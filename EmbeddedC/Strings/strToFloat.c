/*
STRINGS - HOMEWORK NO.3
function strToFloat
@author Michał Kowalczuk
@version 2017-06-11
*/

#include <stdio.h>
#include <math.h>
#include "strToFloat.h"

// converts char* (string) to float
float strToFloat(const char *string)
{
    int factor = 1;  // positive or negative value
    int fractDigits = 0;  // stores number of digits in fractional part
    long decPart = 0;  // decimal part value
    long fracPart = 0;  // fractional part value
    NumberPart numberPart = DECIMAL;  // stores current numberPart type

    // loop until end of string
    for ( ; *string != '\0'; string++)
    {
        if (*string == '-')  // negative value
        {
            factor = -1;
            continue;
        }
        else if (*string == '.' || *string == ',')  // change numberPart type
        {
            numberPart = FRACTIONAL;
            continue;
        }
        if (numberPart == DECIMAL)
        {
            decPart = decPart * 10 + (*string - '0');
        }
        else if (numberPart == FRACTIONAL)
        {
            fracPart = fracPart * 10 + (*string - '0');
            fractDigits++;
        }
    }
    return factor * (decPart + fracPart / pow(10, fractDigits));
}

int main()
{
    char string[MAX];
    printf("Enter a float as string (max %d chars): ", MAX);
    scanf("%s", string);

    float number = strToFloat(string);
    printf("Converted to float: %f\n", number);
}
