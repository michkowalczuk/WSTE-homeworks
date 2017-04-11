/*
@author Michał Kowalczuk
@version 2017-04-11
*/
#ifndef CAR_H
#define CAR_H

#include <stdio.h>
#include <stdlib.h>

#define N 10
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

void resetOrder(int carOrder[]);
int randRange(int min, int max);
void generateCars(Car cars[]);
void showCars(Car cars[], int carOrder[]);
void bubbleSort(int array[], int orderArray[]);
void sortCars(Car cars[], int carOrder[], Member member);

#endif
