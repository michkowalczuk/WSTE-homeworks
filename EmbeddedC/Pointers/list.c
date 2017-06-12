/*
POINTERS - HOMEWORK NO.2
Doubly linked list
@author Michał Kowalczuk
@version 2017-06-11
*/

#include <stdio.h>

int main() {
    struct listStruct {
        int id;
        struct listStruct *next;
        struct listStruct *prev;
    };

    struct listStruct elem1, elem2, elem3, elem4, elem5;
    struct listStruct *list =&elem1;

    elem1.id = 1;
    elem1.next = &elem2;
    elem1.prev = (struct listStruct*) 0;

    elem2.id = 2;
    elem2.next = &elem3;
    elem2.prev = &elem1;

    elem3.id = 3;
    elem3.next = &elem4;
    elem3.prev = &elem2;

    elem4.id = 4;
    elem4.next = &elem5;
    elem4.prev = &elem3;

    elem5.id = 5;
    elem5.next = (struct listStruct*) 0;
    elem5.prev = &elem4;

    printf("Using next...\n");
    while (list != (struct listStruct*) 0) {
        printf("%i\n", list -> id);
        list = list -> next;
    }
    printf("Using prev...\n");
    list = &elem5;
    while (list != (struct listStruct*) 0) {
        printf("%i\n", list -> id);
        list = list -> prev;
    }

    return 0;
}
