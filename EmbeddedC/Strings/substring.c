/*
STRINGS - HOMEWORK NO.2
function substring
@author Michał Kowalczuk
@version 2017-06-12
*/

#include <stdio.h>
#include <string.h>

int substring(const char* source, int beginning, int number, char* result)
{
    int i;
    int sourceLen = strlen(source);
    // checks input
    if(beginning < 0 || beginning > sourceLen ||
        (beginning + number) > sourceLen)
    {
        printf("Invalid Input");
        return 0;
    }
    for(i = 0; i < number; i++)
    {
        // result[i] = source[beginning + i];
        *(result + i) = *(source + beginning + i);
    }
    result[i] = '\0';
    return 1;
}

int main()
{
    char source[100], result[100];
    int beginning, number;
    printf("Enter a string: \n");
    scanf("%s", source);
    printf("Enter beginning index: \n");
    scanf("%d", &beginning);
    printf("Enter number of chars \n");
    scanf("%d", &number);

    printf("Your source string: %s\n", source);
    printf("Beginning index: %d\n", beginning);
    printf("Number of chars: %d\n", number);

    if (substring(source, beginning, number, result))
    {
        printf("Substring is : %s\n", result) ;
    }

    return 0;
}
