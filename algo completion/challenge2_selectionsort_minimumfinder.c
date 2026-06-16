#include<stdio.h>

void display(int arr[], int size);
void selectionSort(int arr[], int size);

int main(void){
    int arr[5] = {29, 10, 14, 37, 13};
    display(arr, 5);
    selectionSort(arr, 5);
    display(arr, 5);
}

void display(int arr[], int size){
    printf("\n");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int size){
    for(int i = 0; i < size; i++){
        int minNdx = i;
        int j;
        for(j = i + 1; j < size; j++){
            if(arr[j] < arr[minNdx]){
                minNdx = j;
            }
        }
        if(minNdx != i){
            int temp = arr[i];
            arr[i] = arr[minNdx];
            arr[minNdx] = temp;
        }
    }
}