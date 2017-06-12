/*
POINTERS - HOMEWORK NO.2
function compareString
@author Michał Kowalczuk
@version 2017-06-11
*/

#include <stdio.h>
#include <string.h>

int compareString(const char* str1, const char* str2){
    int areEqual = 0;
    int lenStr1 = strlen(str1);
    int lenStr2 = strlen(str2);
    if ((lenStr1 == lenStr2)
        && (*(str1 + lenStr1 ) == '\0')
        && (*(str2 + lenStr2 ) == '\0')) {
        for (int i = 0; i < lenStr1; i++) {
            if (*(str1 + i) == *(str2 + i))
                areEqual = 1;
            else {
                areEqual = 0;
                break;
            }
        }
    }
    return areEqual;
}

int main(){
    int equalString(const char* str1, const char* str2);
    const char str1[] = "strings";
    const char str2[] = "strings";
    const char str3[] = "stringsq";
    const char str4[] = "string";

    printf("Comparing : |%s| wwith |%s| -> %d\n", str1, str2, compareString(str1, str2));
    printf("Comparing : |%s| wwith |%s| -> %d\n", str1, str3, compareString(str1, str3));
    printf("Comparing : |%s| wwith |%s| -> %d\n", str1, str4, compareString(str1, str4));

    return 0;
}
