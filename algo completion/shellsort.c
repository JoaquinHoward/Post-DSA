#include<stdio.h>

void shellSort(int arr[], int size);
void display(int arr[], int size);

int main(void){
    int arr[8] = {123, 32, 2, 654, 6, 65, 34, 9};
    display(arr, 8);
    shellSort(arr, 8);
    display(arr, 8);
}

void shellSort(int arr[], int size){
    for(int gap = size / 2; gap >= 1; gap = gap / 2){
        for(int i = gap; i < size; i++){
            int key = arr[i];
            int j;
            for(j = i; j >= gap && key < arr[j-gap]; j=j-gap){
                arr[j] = arr[j-gap];
            }
            arr[j] = key;
        }
    }
}

void display(int arr[], int size){
    printf("\n");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}