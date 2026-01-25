#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 15
typedef struct{
    int arr[MAX];
    int lastNdx;
}minHeap;

void insert(minHeap* MH, int data);
void display(minHeap MH);

void heapifyUp(minHeap* MH, int data);
void heapifyDown(minHeap* MH, int data);

 

void deleteMin();
void deleteElem();



bool isEmpty();
bool isFull();

int size();
int getParent();
int getLeftChild();

int main(void){
    minHeap MH;
    MH.lastNdx = -1;
    for(int i=0; i<10; i++){
        insert(&MH, i);
    }
    display(MH);
}

void insert(minHeap* MH, int data){
    if(MH->lastNdx+1 < MAX){
        MH->arr[++MH->lastNdx] = data;
        int cNdx = MH->lastNdx;
        int pNdx = (MH->lastNdx - 1) / 2;
        while(pNdx >= 0 && MH->arr[cNdx] < MH->arr[pNdx]){
            int temp = MH->arr[cNdx];
            MH->arr[cNdx] = MH->arr[pNdx];
            MH->arr[pNdx] = temp;
            cNdx = pNdx;
            pNdx = (pNdx - 1) / 2;
        }
    }
}

void display(minHeap MH){
    for(int i=0; i<=MH.lastNdx; i++){
        printf("%d ", MH.arr[i]);
    }
}

void heapifyUp(minHeap* MH, int index){
    int cNdx = index;
    int pNdx = (index - 1) / 2;
    while(pNdx>=0 && MH->arr[cNdx] < MH->arr[pNdx]){
        // MH->arr[]
    }
}

