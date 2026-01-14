#include<stdio.h>
#include<stdlib.h>
#define M 8

void display(int a[]);
void bubbleSort(int a[]);

int main(void){
    int a[M] = {0, 7, 4, 0, 4, 1, 4, 8};
    display(a);
    bubbleSort(a);
    display(a);
}

void display(int a[]){
    printf("\n");
    for(int i=0; i<M; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubbleSort(int a[]){
    for(int i=0; i<M; i++){
        for(int j=i; j<M-1; j++){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}