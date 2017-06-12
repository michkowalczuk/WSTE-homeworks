/*
@author Michał Kowalczuk
@version 2017-06-11
*/

#define MAX 10

typedef enum NumberPart {DECIMAL = 1, FRACTIONAL} NumberPart;

float strToFloat(const char *string);
