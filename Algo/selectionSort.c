#include<stdio.h>
#include<stdlib.h>
#define M 8
void display(int a[]);
void selectionSort(int a[]);
int main(void){
    int a[8] = {0, 7, 4, 0, 4, 1, 4, 8};
    display(a);
    selectionSort(a);
    display(a);
}

void display(int a[]){
    printf("\n");
    for(int i=0; i<M; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void selectionSort(int a[]){
    for(int i=0; i<M; i++){
        int ndx = i;
        int j; 
        for(j=i+1; j<M; j++){
            if(a[j] < a[ndx]){
                ndx = j;
            }
        }
        if(ndx!=i){
            int elem = a[ndx];
            a[ndx] = a[i];
            a[i] = elem;
        }
    }
}