/*
"Wprowadzenie do programowania w języku C pod systemy wbudowane"
Zadanie domowe - 01.Struktura Samochód

@author Michał Kowalczuk
@version 2017-04-11
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "car.h"

int main()
{
    // initialize random number generator
    srand(time(NULL));

    Car cars[N] = {};
    // carOrder array use to print cars in defined order
    int carOrder[N] = {};
    resetOrder(carOrder);

    // initialize struct array
    generateCars(cars);
    showCars(cars, carOrder);

    // sort by WEIGHT / PRICE / COLOR / EQUIPMENT
    printf("\nSorting examples:");
    printf("\n# Sort by WEIGHT");
    sortCars(cars, carOrder, WEIGHT);
    showCars(cars, carOrder);

    printf("\n# Sort by PRICE");
    sortCars(cars, carOrder, PRICE);
    showCars(cars, carOrder);

    printf("\n# Sort by COLOR");
    sortCars(cars, carOrder, COLOR);
    showCars(cars, carOrder);

    printf("\n# Original order");
    resetOrder(carOrder);
    showCars(cars, carOrder);

    return 0;
}
