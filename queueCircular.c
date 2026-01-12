#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 8
typedef struct{
    int array[MAX];
    int front;
    int rear;
}queue;

void initQueue(queue* Q);
void enqueue(queue* Q, int data);
int dequeue(queue* Q);

bool isEmpty(queue Q);
bool isFull(queue Q);

void dequeueDuplicate(queue* Q);

int main(void){

}

void initQueue(queue* Q){
    Q->front = -1;
    Q->rear = -1;
}


bool isEmpty(queue Q){
    return Q.front = -1 ? true: false;
}

bool isFull(queue Q){
    return (Q.rear + 1) % MAX == Q.front ? true: false;
}

void enqueue(queue* Q, int data){
    if(isFull(*Q)==false){
        if(isEmpty(*Q)==true){
            Q->front++;
            Q->rear++;
            Q->array[Q->front] = data;
        }else{
            Q->rear = (Q->rear + 1) % MAX;
            Q->array[Q->rear] = data;
        }
    }
}

int dequeue(queue* Q){
    int first = -1;
    if(isEmpty(*Q)==false){
        first = Q->array[]
    }
}
