/*
Bubble Sort Algorithm

@author Michał Kowalczuk
@version 2017-04-10
*/
#include <stdio.h>
#include <stdlib.h>
# include <time.h>

#define N 5

int main()
{
    srand(time(NULL));

    // generate array
    int tab[N] = {};
    int tabOrder[N] = {};
    for (int i = 0; i < N; tabOrder[i] = i,tab[i++] = rand());

    // print array elements
    printf("original array:\n");
    for (int i = 0; i < N; printf("%d | ", tab[i++]));
    printf("\n");
    for (int i = 0; i < N; printf("%d | ", tabOrder[i++]));

    /* main algorithm */
    // we need at most (N - 1) loops
    int i = 0, swapped, tmp;
    do
    {
        // does swap occur
        swapped = 0;

        // during main loop, we need (N - i - 1) pair comparisons
        for (int j = 0; j < N - i - 1; j++)
        {
            // swap occurs
            if (tab[j] > tab[j+1])
            {
                tmp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = tmp;

                tmp = tabOrder[j];
                tabOrder[j] = tabOrder[j+1];
                tabOrder[j+1] = tmp;

                swapped = 1;
            }
            // printf("\ni=%d j=%d", i, j);
        }
    } while (swapped && (i++ < N - 1));

    // print sorted array
    printf("\nsorted array:\n");
    for (int i = 0; i < N; printf("%d | ", tab[i++]));
    printf("\n");
    for (int i = 0; i < N; printf("%d | ", tabOrder[i++]));

    return 0;
}
