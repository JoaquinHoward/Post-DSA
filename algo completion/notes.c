#include<stdio.h>
#include<stdlib.h>

void display(int arr[], int size);
void shellsort(int arr[], int size);
void insertionsort(int arr[], int size);
void combsort(int arr[], int size);
void bubblesort(int arr[], int size);
void countingsort(int arr[], int size);
void selectionsort(int arr[], int size);
void gnomesort(int arr[], int size);
//void strandsort(int arr[], int size);
//void radixsort(int arr[], int size);
//void bucketsort(int arr[], int size);
//void tournamentsort(int arr[], int size);
void mergesort(int arr[], int size);
// void quicksort(int arr[], int size);

int main(void){
    int arr[8] = {0, 7, 4, 0, 4, 1, 4, 8};
    display(arr, 8);
    shellsort(arr, 8);
    display(arr, 8);
}

void display(int arr[], int size){
    printf("\n");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}

void shellsort(int arr[], int size){
    for(int gap = size / 2; gap >= 1; gap = gap / 2){
        for(int i = gap; i < size; i++){
            int key = arr[i];
            int j;
            for(j = i; j >= gap && key < arr[j-gap]; j = j - gap){
                arr[j] = arr[j-gap];
            }
            arr[j] = key;
        }
    }
}