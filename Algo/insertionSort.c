#include<stdio.h>
#include<stdlib.h>
#define M 8
void display(int a[]);
void insertionSort(int a[], int s);

int main(void){
    int a[M]={0, 7, 4, 0, 4, 1, 4, 8};
    display(a);
    insertionSort(a, M);
    display(a);

}

void display(int a[]){
    printf("\n");
    for(int i=0; i<M; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insertionSort(int a[], int s){
    for(int i=1; i<s; i++){
        int elem = a[i];
        int j = i-1;
        while(j>=0 && elem < a[j]){
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j+1] = elem;
    }
}