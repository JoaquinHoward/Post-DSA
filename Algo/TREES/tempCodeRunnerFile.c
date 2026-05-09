#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define RED 0
#define BLACK 1

typedef struct node {
    int data;
    struct node* parent;
    struct node* left;
    struct node* right;
    int color; // 0 for Red, 1 for Black
} *RBT;

void rotateLeft(RBT x);
void rotateRight(RBT x);

void insert(RBT *root, int data);

void transplant(RBT *root, RBT toBeDeleted, RBT replacement);
void delete(RBT *root, int data);
void deleteFixup(RBT *root, RBT node);

void preorder(RBT root);

int main() {
    RBT root = NULL;

    insert(&root, 10);preorder(root);printf("\n");
    insert(&root, 20);preorder(root);printf("\n");
    insert(&root, 30);preorder(root);printf("\n");
    insert(&root, 15);preorder(root);printf("\n");
    insert(&root, 25);preorder(root);printf("\n");
    insert(&root, 21);preorder(root);printf("\n");

    delete(&root, 20);
    printf("\nPreorder Traversal after deletion: ");
    preorder(root);

    delete(&root, 30);
    printf("\nPreorder Traversal after deletion: ");
    preorder(root);

    delete(&root, 15);
    printf("\nPreorder Traversal after deletion: ");
    preorder(root);

    delete(&root, 25);
    printf("\nPreorder Traversal after deletion: ");
    preorder(root);

    delete(&root, 10);
    printf("\nPreorder Traversal after deletion: ");
    preorder(root);

    delete(&root, 21);
    printf("\nPreorder Traversal after deletion: ");
    preorder(root);

    return 0;
}

void rotateLeft(RBT x) {
    RBT temp = x->right;

    x->right = temp->left;
    if (temp->left != NULL) {
        temp->left->parent = x;
    }

    temp->left = x;
    temp->parent = x->parent;

    if (x->parent != NULL) {
        if (x == x->parent->left) {
            x->parent->left = temp;
        } else {
            x->parent->right = temp;
        }
    }

    x->parent = temp;
}

void rotateRight(RBT x) {
    RBT temp = x->left;

    x->left = temp->right;
    if (temp->right != NULL) {
        temp->right->parent = x;
    }

    temp->right = x;
    temp->parent = x->parent;

    if (x->parent != NULL) {
        if (x == x->parent->left) {
            x->parent->left = temp;
        } else {
            x->parent->right = temp;
        }
    }

    x->parent = temp;
}

void insert(RBT *root, int data) {
    RBT * trav;
    RBT parent = NULL;
    for(trav = root; *trav != NULL; trav = data < (*trav)->data ? &(*trav)->left : &(*trav)->right){
        parent = *trav;
    }

    RBT newnode = (RBT) malloc (sizeof(struct node));
    if(newnode != NULL){
        newnode->data = data;
        newnode->right = NULL;
        newnode->right = NULL;
        newnode->parent = parent;
        newnode->color = RED;
        *trav = newnode;

        // case 1: parent and uncle are both red
        RBT grandparent = parent != NULL ? parent->parent : NULL;
        RBT uncle = grandparent == NULL ? NULL : grandparent->left != parent ? grandparent->left : grandparent->right;

        while(parent != NULL && parent->color == RED){
            if(uncle != NULL && uncle->color == RED){
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;

                newnode = grandparent;
                parent = newnode != NULL ? newnode->parent : NULL;
                grandparent = parent != NULL ? parent->parent : NULL;
                uncle = grandparent == NULL ? NULL : grandparent->left != parent ? grandparent->left : grandparent->right;
            } else {

                //case 3: left right red red
                if(grandparent != NULL && grandparent->left == parent && parent->right == newnode){
                    rotateLeft(parent);
                    rotateRight(grandparent);
                    newnode->color = BLACK;
                    grandparent->color = RED;
                }
                //case 4: right left red red
                else if(grandparent != NULL && grandparent->right == parent && parent->left == newnode){
                    rotateRight(parent);
                    rotateLeft(grandparent);
                    newnode->color = BLACK;
                    grandparent->color = RED;
                }

                // case 5: left left red red
                if(grandparent != NULL && grandparent->left == parent && parent->left == newnode){
                    rotateRight(grandparent);
                    parent->color = BLACK;
                    grandparent->color = RED;
                }

                // case 6: right right red red
                else if(grandparent != NULL && grandparent->right == parent && parent->right == newnode){
                    rotateLeft(grandparent);
                    parent->color = BLACK;
                    grandparent->color = RED;
                }
                parent = NULL;
            }
        }
        RBT temproot;
        for(temproot = newnode; temproot != NULL && temproot->parent != NULL; temproot = temproot->parent){}
        
        if(temproot != NULL){
            *root = temproot;
            (*root)->color = BLACK;
        }
    }
}

void transplant(RBT *root, RBT toBeDeleted, RBT replacement) {
    if (toBeDeleted == *root) {
        *root = replacement;
    }
    else if (toBeDeleted->parent->left == toBeDeleted) {
        toBeDeleted->parent->left = replacement;
    } else {
        toBeDeleted->parent->right = replacement;
    }
}

void delete(RBT *root, int data) {
    RBT *trav = root, nodeToBeDeleted = NULL, replacement = NULL;

    // BST Traversal to find the node to be deleted
    while (*trav != NULL && (*trav)->data != data) {
        if (data < (*trav)->data) {
            trav = &(*trav)->left;
        } else {
            trav = &(*trav)->right;
        }
    }

    if (*trav == NULL) return;

    nodeToBeDeleted = *trav;
    int originalColor = nodeToBeDeleted->color;

    // Case 1: Left Child is NULL
    if (nodeToBeDeleted->left == NULL) {
        replacement = nodeToBeDeleted->right;
        transplant(root, nodeToBeDeleted, replacement);
    }

    // Case 2: Right Child is NULL
    else if (nodeToBeDeleted->right == NULL) {
        replacement = nodeToBeDeleted->left;
        transplant(root, nodeToBeDeleted, replacement);
    }

    // Case 3: Both Children are not NULL
    else {
        RBT temp;
        replacement = nodeToBeDeleted->right;

        while (replacement->left != NULL) {
            replacement = replacement->left;
        }

        originalColor = replacement->color;
        temp = replacement->right;

        transplant(root, replacement, replacement->right);
        
        replacement->right = nodeToBeDeleted->right;
        replacement->right->parent = replacement;

        transplant(root, nodeToBeDeleted, replacement);
        replacement->left = nodeToBeDeleted->left;
        replacement->left->parent = replacement;
        replacement->color = nodeToBeDeleted->color;

        replacement = temp;
    }


    if (originalColor == BLACK && replacement != NULL) {
        deleteFixup(root, replacement);
    }
    else if (originalColor == BLACK) {
        // nodeToBeDeleted is used as a temporary node to signify DOUBLE_BLACK
        deleteFixup(root, nodeToBeDeleted);
    }

    free(nodeToBeDeleted);
}

void deleteFixup(RBT *root, RBT node) {
    if (*root == NULL || node == NULL) return;

    while (node != *root && node->color == BLACK) {
        bool nodeIsLeft = (node == node->parent->left || (node->parent->right != node && node->parent->left == NULL)) ? true : false;
        RBT sibling = (nodeIsLeft) ? node->parent->right : node->parent->left;

        if (sibling == NULL) {
            node = node->parent;
            continue;
        }

        // Case 1: Sibling is Red
        if (sibling->color == RED) {
            sibling->color = BLACK;
            node->parent->color = RED;

            if (nodeIsLeft) {
                rotateLeft(node->parent);
                sibling = node->parent->right;
            } else {
                rotateRight(node->parent);
                sibling = node->parent->left;
            }
        }

        // Case 2: Sibling is Black with two black children
        if ((sibling->left == NULL || sibling->left->color == BLACK) && (sibling->right == NULL || sibling->right->color == BLACK)) {
            sibling->color = RED;
            node = node->parent;
        }
        else {
            // Case 3.A: Node is left, Sibling is Black, and sibling's right child is black
            if ((sibling->right == NULL || sibling->right->color == BLACK) && nodeIsLeft) {
                sibling->color = RED;

                sibling->left->color = BLACK;
                rotateRight(sibling);
                sibling = node->parent->right;

            }
            // Case 3.B: Node is right, Sibling is Black, and sibling's left child is black
            else if ((sibling->left == NULL || sibling->left->color == BLACK) && !nodeIsLeft) {
                sibling->color = RED;

                sibling->right->color = BLACK;
                rotateLeft(sibling);
                sibling = node->parent->left;
            }

            // Case 4: Sibling is black and sibling's right child is Red
            sibling->color = node->parent->color;
            node->parent->color = BLACK;

            if (nodeIsLeft) {
                sibling->right->color = BLACK;
                rotateLeft(node->parent);
            } else {
                sibling->left->color = BLACK;
                rotateRight(node->parent);
            }

            node = *root;
        }
    }

    node->color = BLACK;
}

void preorder(RBT root) {
    if (root == NULL) {
        printf("_ ");
        return;
    };

    printf("[%d-%s] ", root->data, root->color == RED ? "R" : "B");
    preorder(root->left);
    preorder(root->right);
}