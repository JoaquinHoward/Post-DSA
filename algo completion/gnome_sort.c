#include<stdio.h>


void gnome_sort(int arr[], int size);
void display(int arr[], int size);

int main(void){
    int arr[8] = {11, 22, 33, 2, 3, 42, 1, 3};
    display(arr, 8);
    gnome_sort(arr, 8);
    display(arr, 8);
}

void display(int arr[], int size){
    printf("\n");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void gnome_sort(int arr[], int size){
    int pos = 0;
    while(pos < size){
        if(pos == 0 || arr[pos] >= arr[pos-1]){
            pos++;
        }else{
            int temp = arr[pos];
            arr[pos] = arr[pos-1];
            arr[pos-1] = temp;
            pos--;
        }
    }
}