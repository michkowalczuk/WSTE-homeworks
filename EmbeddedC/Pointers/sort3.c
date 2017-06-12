/*
POINTERS - HOMEWORK NO.1
function sort3 - works for N elements defined in preprocessor
@author Michał Kowalczuk
@version 2017-06-10
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort3.h"

/* simple bubble sort algortihm */
void sort3(int* array)
{
    // we need at most (n - 1) loops
    int i = 0, swapped, tmp;
    do
    {
        // does swap occur
        swapped = 0;

        // during main loop, we need (n - i - 1) pair comparisons
        for (int j = 0; j < N - i - 1; j++)
        {
            // swap occurs
            if (*(array + j) > *(array + j + 1))
            {
                swapped = 1;
                // swap main array
                tmp = *(array + j);
                *(array + j) = *(array + j + 1);
                *(array + j + 1) = tmp;
            }
        }
    } while (swapped && (i++ < N - 1));
}

int main(int argc, char const *argv[]) {

    // initialize random number generator
    srand(time(NULL));

    // generate 3-element array and fill with random numbers
    int *array;
    array = (int*) malloc(sizeof(int) * N);
    printf("Random values:\n");
    for (int i = 0; i < N; i++) {
        *(array + i) = rand();
        printf("%d) %d\n", i + 1, *(array + i));
    }

    // do sort on array
    sort3(array);

    // print resuklts
    printf("\nAfter sorting:\n");
    for (int i = 0; i < N; i++) {
        printf("%d) %d\n", i + 1, *(array + i));
    }

    free(array);

    return 0;
}
