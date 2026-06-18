#include<stdio.h>

void display(int arr[], int size);
void insertionSort(int arr[], int size);

int main(void){
    int arr[8] = {0, 7, 4, 0, 4, 1, 4, 8};
    display(arr, 8);
    insertionSort(arr, 8);
    display(arr, 8);
}

void display(int arr[], int size){
    printf("\n");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int size){
    for(int i = 0; i < size; i++){
        int key = arr[i];
        int j;
        for(j = i - 1; j >= 0 && arr[j] > key; j--){
            arr[j + 1] = arr[j];
        }
        //after exiting the loop, the lowest possible value of j is -1, so we do j + 1 so arr[0] can receive the key.
        arr[j + 1] = key; 
    }
}