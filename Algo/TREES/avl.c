#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
    int height;
}*AVL;

int max(int a, int b);
int getHeight(AVL tree);
int getNewHeight(AVL tree);
int getBalanceFactor(AVL tree);
void rotateLeft(AVL* tree);
void rotateRight(AVL* tree);
void balance(AVL* root);
void insert(AVL* root, int data);

int main(void){
    
}

int max(int a, int b){
    return a > b ? a : b;
}

int getHeight(AVL tree){
    return tree!=NULL ? tree->height : -1;
}

int getNewHeight(AVL tree){
    return tree->height = max(getHeight(tree->left), getHeight(tree->right) + 1);
}

int getBalanceFactor(AVL tree){
    return tree!= NULL ? getHeight(tree->left) - getHeight(tree->right) : 0; 
}

void rotateLeft(AVL* tree){
    AVL x = *tree;
    AVL y = x->right;
    x->right = y->left;
    y->left = x;
    x->height = getNewHeight(x);
    y->height = getNewHeight(y); 
    *tree = y;
}

void rotateRight(AVL* tree){
    AVL x = *tree;
    AVL y = x->left;
    x->left = y->right;
    y->right = x;
    x->height = getNewHeight(x);
    y->height = getNewHeight(y);
    *tree = x;
}

void balance(AVL* root){
    if(*root != NULL){
        int balanceFactor = getBalanceFactor(*root);
        if(balanceFactor > 1 && getBalanceFactor((*root)->left) >= 0){
            rotateRight(root);
        }else if(balanceFactor > 1 getBalanceFactor((*root)->left) < 0){
            rotateLeft(&(*root)->left);
            rotateRight(root);
        }else if(balanceFactor < -1 && getBalanceFactor((*root)->right) <= 0){
            rotateLeft(root);
        }else if(balanceFactor < -1 && getBalanceFactor((*root)->right) > 0){
            rotateRight(&(*root)->right);
            rotateLeft(root);
        }
    }
}

void insert(AVL* tree, int data){
    if(*tree == NULL){
        AVL newNode = (AVL) malloc (sizeof(struct node));
        if(newNode != NULL){
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            *tree = newNode;
        }
    }else if(data < (*tree)->data){
        insert(&(*tree)->left, data);
    }else if(data >= (*tree)->data){
        insert(&(*tree)->right, data);
    }
    getNewHeight(*tree);
    balance(tree);
}

 void delete(AVL* tree, int data){
     if(*tree != NULL){
         if(data < (*tree)->left->data){
             delete(&(*tree)->data, data);
         }else if(data > (*tree)->right->data){
             delete(&(*tree)->data, data);
         }else{
             if((*root)->left == NULL || (*root)->right == NULL){
                 AVL temp = *root;
                 *root = ((*root)->left)
             }
         }
     }
 }























