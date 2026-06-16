#include<stdio.h>
#include<stdlib.h>

void insertionSort(int arr[], int size);
void display(int arr[], int size);
int main(void){
    int arr[8] = {1, 4, 2, 5, 7, 3, 6, 0};
    display(arr, 8);
    insertionSort(arr, 8);
    display(arr, 8);
}

void insertionSort(int arr[], int size){
    for(int i = 1; i < size; i++){
        int key = arr[i];
        int j;
        for(j = i - 1; j >= 0 && arr[j] > key; j--){
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

void display(int arr[], int size){
    printf("\n");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}


/*
    Insertion sort uses shifting instead of swapping. 
    Insertion sort starts with outer loop i = 1 because of the key.
*/