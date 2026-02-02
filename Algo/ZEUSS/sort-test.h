#ifndef SORT_TEST_H
#define SORT_TEST_H

// Changed: Direct includes since they are neighbors
#include "general.h"
#include "arrays.h"

typedef void (*SortFunction)(int[], int);

void test_sort_w_size(SortFunction sortFunc) {
    printf("\n=== Running Sort Test ===\n");
    int data[] = { 15, 3, 9, 8, 5, 2, 7, 1, 10, 25, 4 };
    int size = sizeof(data) / sizeof(data[0]);

    printf("Original: ");
    printArray(data, size);

    sortFunc(data, size);

    printf("Sorted:   ");
    printArray(data, size);

    if (isSorted(data, size)) {
        printf("Status:   SUCCESS\n");
    } else {
        printf("Status:   FAILED\n");
    }
    printf("=========================\n\n");
}

#endif