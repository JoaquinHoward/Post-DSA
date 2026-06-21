#include<stdio.h>
#include<stdbool.h>
void display(int arr[], int size);
void combSort(int arr[], int size);

int main(void){
    int arr[8] = {11, 2, 3, 3, 1, 3, 5, 6};
    display(arr, 8);
    combSort(arr, 8);
    display(arr, 8);
}

void display(int arr[], int size){
    printf("\n");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}



void combSort(int arr[], int size){
    bool sorted = false;
    for(int gap = size/1.3 ; gap > 1 || sorted == false; gap/=1.3){
        if(gap < 1){
            gap = 1;
        }
        sorted = true;
        for(int i = 0; i + gap< size; i++){
            if(arr[i] > arr[i + gap]){
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                sorted = false;
            }
        }
    }
}

