#include<stdio.h>

void display(int arr[], int size);
void bubbleSort(int arr[], int size);

int main(void){
    int arr[8] = {0, 23, 43, 2, 12, 5, 7, 7};
    display(arr, 8);
    bubbleSort(arr, 8);
    display(arr, 8);
}

void bubbleSort(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1 - i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void display(int arr[], int size){
    printf("\n");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}