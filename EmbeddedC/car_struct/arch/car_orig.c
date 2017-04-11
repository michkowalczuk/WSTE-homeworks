/*
Wprowadzenie do programowania w języku C pod systemy wbudowane
Zadanie domowe - 01.Struktura Samochód

@author Michał Kowalczuk
@version 2017-04-10
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define LENGTH(arr) (sizeof(arr) / sizeof (arr[0]))

typedef enum Member {WEIGHT=1, PRICE, COLOR, EQUIPMENT} Member;
typedef enum Color {BLACK=1, BLUE, RED, WHITE} Color;
typedef enum Equipment {BASIC=1, PREMIUM,  STANDARD} Equipment;
typedef struct Car
{
    int weight;
    int price;
    Color color;
    Equipment equipment;
} Car;

/* generate random intiger from range <min, max> */
int generateInt(int min, int max)
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
void generateCars(Car cars[], int n)
{
    printf("Generate cars...");
    for (int i = 0; i < n; i++)
    {
        cars[i] = (Car){
            .weight = generateInt(500, 1500),
            .price = generateInt(20000, 30000),
            .color = rand() % 4 + 1,
            .equipment = rand() % 3 + 1,
        };
    }
    printf("done!\n");
}

/* Print cars info */
void showCars(Car cars[], int carOrder[], int n)
{
    printf("Cars info\n");
    printf("ID\tWEIGHT\tPRICE\tCOLOR\tEQUIPMENT\n");
    printf("--\t------\t-----\t-----\t---------");

    int j;
    for (int i = 0; i < n; i++)
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
    printf("\n");
}

/* Bubble sort Algortihm */
void bubbleSort(int array[], int orderArray[], int n)
{
    // fill orderArray from 0 to n
    for (int i = 0; i < n; orderArray[i] = i++);
    // we need at most (n - 1) loops
    int i = 0, swapped, tmp;
    do
    {
        // does swap occur
        swapped = 0;

        // during main loop, we need (n - i - 1) pair comparisons
        for (int j = 0; j < n - i - 1; j++)
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
    } while (swapped && (i++ < n - 1));

    // print sorted array
    printf("\nsorted array:\n");
    for (int i = 0; i < n; printf("%d | ", array[i++]));
    printf("\n");
    for (int i = 0; i < n; printf("%d | ", orderArray[i++]));
    printf("\n");
}

/* sort cars by any field (struct member) */
void sortCars(Car cars[], int carOrder[], Member member, int n)
{
    int tmp;
    int memberArray[N] = {};
    // int orderArray[N] = {};
    for (int i = 0; i < n; i++)
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
    bubbleSort(memberArray, carOrder, n);
}

int main()
{
    // initialize random number generator
    srand(time(NULL));

    Car cars[N] = {};
    // carOrder use to print cars in defined order
    int carOrder[N] = {};
    for (int i = 0; i < N; i++) carOrder[i] = i;

    int n = LENGTH(cars); // delete?
    generateCars(cars, n);
    showCars(cars, carOrder, n);
    sortCars(cars, carOrder, WEIGHT, n);
    showCars(cars, carOrder, n);

    return 0;
}
