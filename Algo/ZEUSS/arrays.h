#ifndef ARRAYS_H
#define ARRAYS_H

#include "general.h"

void printArray(int arr[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf(" ]\n");
}

bool isSorted(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) return false;
    }
    return true;
}

#endif