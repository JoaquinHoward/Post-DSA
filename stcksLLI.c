#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int data;
    struct node* link; // or struct node* next;
}*nodePtr;

typedef nodePtr stack;

void initStack(stack* S);
bool isEmpty(stack S);
void display(stack S);

void push(stack* S, int data);
void pushUnique(stack* S, int data);
void pushFirst(stack* S, int data);

void pop(stack* S);
void popElem(stack* S, int data);






int main(void){
    printf("%d", 5);
}

void initStack(stack* S){
    *S = NULL;
}

bool isEmpty(stack S){
    return S==NULL ? true: false;
}

void display(stack S){
    for(nodePtr trav = S; trav!=NULL; trav=trav->link){
        printf("%d", trav->data);
    }
}

void push(stack* S, int data){
    nodePtr newNode = (nodePtr) malloc (sizeof(struct node));
    if(newNode!=NULL){
        newNode->data = data;
        newNode->link = *S;
        *S = newNode;
    }
}

void pushUnique(stack* S, int data){
    nodePtr trav;
    for(trav = *S; trav!=NULL && trav->data!=data; trav=trav->link){}
    if(trav!=NULL){
        nodePtr newNode = (nodePtr) malloc (sizeof(struct node));
        if(newNode!=NULL){
            newNode->data = data;
            newNode->link = *S;
            *S = newNode;
            printf("\nSuccessful insertion of element %d.\n", data);
        }else{
            printf("\nError in malloc, failed to insert %d.\n", data);
        }
    }else{
        printf("\nElement %d is not unique.\n", data);
    }
}

void pushFirst(stack* S, int data){
    nodePtr* trav;
    for(trav=S; *trav!=NULL; trav=&(*trav)->link){
        nodePtr newNode = (nodePtr) malloc (sizeof(struct node));
        if(newNode!=NULL){
            newNode->data = data;
            newNode->link = NULL;
            *trav = newNode;
            printf("\nSuccessful insertion of %d.\n", data);
        }else{
            printf("\nError in malloc, failed to insert %d.\n", data);
        }
    }
}

void pop(stack* S){
    if(isEmpty(*S) == false){
        nodePtr temp = *S;
        *S = (*S)->link;
        printf("\nSuccessful popping of %d.\n", temp->data);
        free(temp);
    }else{
        printf("\nStack is empty, nothing to delete.\n");
    }
}

void popElem(stack* S, int data){
    if(isEmpty(*S) == false){
        nodePtr* trav;
        for(trav = S; *trav!=NULL && (*trav)->data!=data; trav=&(*trav)->link){}
        if(*trav!=NULL){
            nodePtr temp = *trav;
            *trav = (*trav)->link;
            printf("\nSuccessful popping of %d.\n", data);
            free(temp); 
        }
    }else{
        printf("\nStack is empty: nothing to delete.\n");
    }
}