/*
@author Michał Kowalczuk
@version 2017-04-11
*/
#include <stdio.h>
#include <stdlib.h>

#include "car.h"

/* generate array elements from 0 to N - 1 */
void resetOrder(int carOrder[])
{
    for (int i = 0; i < N; i++) carOrder[i] = i;
}

/* generate random intiger from range <min, max> */
int randRange(int min, int max)
{
    int tmp, out;
    if (min > max)
    {
        tmp = max;
        max = min;
        min = tmp;
    }
    return (min==max ? min
        : (int)((double)rand() / (RAND_MAX + 1) * (max - min + 1) + min));
}

/* fill cars arrayle with random cars */
void generateCars(Car cars[])
{
    printf("Generating %d cars... ", N);
    for (int i = 0; i < N; i++)
    {
        cars[i] = (Car){
            .weight = randRange(500, 1500),
            .price = randRange(20000, 30000),
            .color = rand() % 4 + 1,
            .equipment = rand() % 3 + 1,
        };
    }
    printf("done!\n");
}

/* Print cars info */
void showCars(Car cars[], int carOrder[])
{
    printf("\n=============== CARS INFO ===============\n");
    printf("ID\tWEIGHT\tPRICE\tCOLOR\tEQUIPMENT\n");
    printf("--\t------\t-----\t-----\t---------");

    int j;
    for (int i = 0; i < N; i++)
    {
        j = carOrder[i];
        printf("\n%d\t%d\t%d\t%s\t%s\t", j , cars[j].weight, cars[j].price,
            (cars[j].color == 1) ? "BLACK"
            : (cars[j].color == 2) ? "BLUE"
            : (cars[j].color == 3) ? "RED"
            : (cars[j].color == 4) ? "WHITE" : "---",
            (cars[j].equipment == 1) ? "BASIC"
            : (cars[j].equipment == 2) ? "PREMIUM"
            : (cars[j].equipment == 3) ? "STANDARD" : "---");
    }
    printf("\n=========================================\n");
}

/* Bubble sort Algortihm */
void bubbleSort(int array[], int orderArray[])
{
    // fill orderArray from 0 to n
    for (int i = 0; i < N; orderArray[i] = i++);
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
            if (array[j] > array[j+1])
            {
                swapped = 1;
                // swap main array
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
                // swap order array
                tmp = orderArray[j];
                orderArray[j] = orderArray[j+1];
                orderArray[j+1] = tmp;
            }
        }
    } while (swapped && (i++ < N - 1));
}

/* sort cars by any field (struct member) */
void sortCars(Car cars[], int carOrder[], Member member)
{
    int tmp;
    int memberArray[N] = {};
    for (int i = 0; i < N; i++)
    {
        switch (member)
        {
            case WEIGHT:
                tmp = cars[i].weight;
                break;
            case PRICE:
                tmp = cars[i].price;
                break;
            case COLOR:
                tmp = cars[i].color;
                break;
            case EQUIPMENT:
                tmp = cars[i].equipment;
                break;
            default:
                tmp = 0;
                break;
        }
        memberArray[i] = tmp;
    }
    // sort memberArray and show sorted indexes in orderArray
    bubbleSort(memberArray, carOrder);
}
