#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* link;
}*nodePtr;


void display(nodePtr list);
void insertFirst(nodePtr* list, int data);
void insertionSort(nodePtr* list);

int main(void){
    nodePtr* list;
    list = (nodePtr*) malloc (sizeof(nodePtr));
    *list = NULL;
    insertFirst(list, 1);
    insertFirst(list, 2);
    insertFirst(list, 3);
    insertFirst(list, 4);
    insertFirst(list, 5);
    display(*list);
    // insertionSort(arr, 8);
}

void display(nodePtr list){
    for(nodePtr trav = list; trav!=NULL; trav = trav->link){
        printf("%d ", trav->data);
    }
}

void insertFirst(nodePtr* list, int data){
    nodePtr newNode = (nodePtr) malloc (sizeof(struct node));
    if(newNode != NULL){
        newNode->data = data;
        newNode->link = *list;
        *list = newNode;
    }
}

void insertionSort(nodePtr* list){
    for(nodePtr* itrav = (*list)->link; *itrav != NULL; itrav = &(*itrav)->link){
        nodePtr key = *itrav;
        nodePtr *jtrav;
        for(jtrav = )
    }
}
