/*
@author Michał Kowalczuk
@version 2017-05-08
*/
#ifndef CAR_H
#define CAR_H

#define WEIGHT_MIN 500
#define WEIGHT_MAX 1500
#define PRICE_MIN 20000
#define PRICE_MAX 30000
#define NO_COLORS 4
#define NO_EQUIPMENTS 3
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
